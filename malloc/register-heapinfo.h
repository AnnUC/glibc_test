#ifndef _REGISTER_HEAPINFO_H
#define _REGISTER_HEAPINFO_H

void register_heap_info (int mem_allocator_identifier, void* arena_start_ptr,
                         void* subheap_start_ptr, size_t subheap_size,
                         int* new_error_info_flag) 
{ 
  FILE *f = fopen("/home/anan/log","ab+");
  fputs("in register_heap_info func\n",f);
  fclose(f);
}

#endif