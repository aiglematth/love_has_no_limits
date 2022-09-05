//
// Includes
//
#include <stdlib.h>
#include "teddy_errors.h"
#include "fifo.h"

//
// Functions
//
void fifo_push(Fifo f, void *e) {
    FifoElement *elem = NULL;

    fifo_errno = FIFO_OK;
    if(f->leaving_size == 0) {
        fifo_errno = FIFO_FULL;
        return;
    }

    elem                  = malloc(sizeof(FifoElement));
    elem->previousElement = NULL;
    elem->element         = e;

    if(f->top == NULL) {
        f->top = elem;
    } else {
        f->down->previousElement  = elem;
    }
    f->down          = elem;
    f->leaving_size -= 1;
}

void *fifo_pop(Fifo *f) {
    void *e          = NULL;
    FifoElement *tmp = NULL;

    fifo_errno = FIFO_OK;
    if(f->top == NULL) {
        fifo_errno = FIFO_EMPTY
        return;
    }

    e = f->top->element;

    if(f->top->previousElement == NULL) {
        free(f->top);
        f->down = NULL;
        f->top  = NULL;
    } else {
        tmp    = f->top;
        f->top = f->top->previousElement;
        free(tmp);
    }

    f->leaving_size += 1;
    return e;
}