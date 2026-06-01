#include "debug.h"
#include "mymalloc.h"

/*
    通过 mtrace、muntrace 等调试有时相对比较复杂，这里自定义一个简单的追踪方式
*/

void mymalloc(char *variable_info, void **ptr, size_t size)
{
    if( *ptr != NULL ) {
        warn_printf("(%s) detected that the current pointer memory has not been released !\n", variable_info);
    }

    *ptr = malloc(size);
    if( *ptr == NULL ) {
        err_printf("%s malloc fail !\n", variable_info);
    }
    else {
        malloc_printf("(-alloc track): %s malloc success, size:%d   Address:%p-%p !\n",
                        variable_info, size, (*ptr), (char *)(*ptr)+size-1);
    }
}


void myrealloc(char *variable_info, void **ptr, size_t size)
{
    void *p_ptr = *ptr;

    *ptr = realloc(*ptr, size);
    if( *ptr == NULL ) {
        err_printf("%s realloc fail !\n", variable_info);
    }
    else {
        if( p_ptr != *ptr ) {
            malloc_printf("(-alloc track): %s realloc success, size:%d   old Address:%p   new Address:%p-%p !\n",
                            variable_info, size, p_ptr, (*ptr), (char *)(*ptr)+size-1);
        }
        else {
            malloc_printf("(-alloc track): %s realloc success, size:%d   new Address:%p-%p !\n",
                        variable_info, size, (*ptr), (char *)(*ptr)+size-1);
        }
    }
}


void myfree(char *variable_info, void **ptr)
{
    if( *ptr == NULL ) {
        // warn_printf("The incoming pointer is empty !\n");
        return;
    }
    malloc_printf("(-alloc track): %s free, Address:%p ", variable_info, *ptr);

    free(*ptr);
    *ptr = NULL;

    malloc_printf("free success !\n");
}
