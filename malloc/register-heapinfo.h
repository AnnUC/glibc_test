#ifndef _REGISTER_HEAPINFO_H
#define _REGISTER_HEAPINFO_H

/*
if new_error_info_flag == -1, the error_info_flag has been registered before
if subheap_size = -1, delete the subheap

*/

extern mutex_t register_heap_info_lock;
extern heap_info_flag* register_heap_info_flag;
extern int flag_counter;


#endif