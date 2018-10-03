#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    }
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *data = ptr;
    ptr = malloc(size);
    memcpy(ptr, data, size);
    free(data);
    return ptr;

}