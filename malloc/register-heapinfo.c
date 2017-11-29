#include <stdio.h>

/*
if new_error_info_flag == -1, the error_info_flag has been registered before
if subheap_size = -1, delete the subheap

*/

void register_heap_info (int mem_allocator_identifier, void* arena_start_ptr,
                         void* subheap_start_ptr, size_t subheap_size,
                         int* new_error_info_flag) 
{  
  FILE *f = fopen("/home/anan/log","ab+");
  fputs("in register_heap_info func\n",f);
  fclose(f);
}