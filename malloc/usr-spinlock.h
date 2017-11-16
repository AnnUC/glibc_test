#ifndef _USR_SPINLOCK_H
#define _USR_SPINLOCK_H
#endif

typedef struct {
    volatile unsigned int lock;
    volatile pid_t thread_id;
} usr_spinlock;

#define SPINLOCK_ATTR static __inline __attribute__((always_inline, no_instrument_function))

/* Pause instruction to prevent excess processor bus usage */
#define cpu_relax() asm volatile("pause\n": : :"memory")

SPINLOCK_ATTR char __testandset(usr_spinlock *p, long old_val, long new_val)
{
    char result = 0;
    asm volatile (
            "lock; cmpxchgq %4, %1"
            : "=q" (result), "=m" (*p)
            : "m" (*p), "a" (old_val), "r" (new_val)
            : "memory");
    return result;
}

SPINLOCK_ATTR void spin_lock(usr_spinlock *lock)
{
    while (__testandset(lock, 0, (30064771073))) {
        cpu_relax();
    }
}

SPINLOCK_ATTR void spin_unlock(usr_spinlock *s)
{
    long new_val = 0;
    asm volatile ("xchgq %0,%1"
                :
                :"m" (*s), "r" (new_val)
                :"memory");
}

SPINLOCK_ATTR void spin_init(usr_spinlock *s)
{
    spin_unlock(s); 
}

#define SPINLOCK_INITIALIZER { 0 }
