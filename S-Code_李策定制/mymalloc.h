#ifndef MYMALLOC_H
#define MYMALLOC_H
#include <stdio.h>
#include <stdlib.h>

void mymalloc(char *variable_info, void **ptr, size_t size);
void myrealloc(char *variable_info, void **ptr, size_t size);
void myfree(char *variable_info, void **ptr);
#endif // MYMALLOC_H
