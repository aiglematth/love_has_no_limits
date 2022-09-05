//
// This file provide a little fifo implementation
//

#ifndef FIFO
#define FIFO

//
// Structs
//
typedef struct FifoElement {
    //
    // This struct is an element of this fifo implementation
    //
    // Fields:
    //  - previousElement<struct FifoElement *> : The previous element of the fifo
    //  - element<*void>                        : The element (that's the programmers responsability to cast this field)
    //
    struct FifoElement *previousElement;
    void *element;
} FifoElement;

typedef struct Fifo {
    //
    // This is the base struct of the fifo
    //
    // Fields:
    //  - top<struct FifoElement *>  : The top of the fifo
    //  - down<struct FifoElement *> : The down of the fifo
    //  - leaving_size<size_t>       : The size of elements that can be allocated (decremented at every push, incremented at every pop) 
    //
    struct FifoElement *top;
    struct FifoElement *down;
    size_t leaving_size;
} Fifo;

//
// Functions
//
void fifo_push(Fifo *f, void *e);
    //
    // Function to push an element in a fifo
    //
    // Parameters:
    //  - f<*Fifo> : The fifo to push in
    //  - e<*void> : The element to push
    //
    // fifo_errno:
    //  - FIFO_OK:   If no error occurs
    //  - FIFO_FULL: If the leaving_size is zero
    //

void *fifo_pop(Fifo *f);
    //
    // Function to pop an element from a fifo
    //
    // Parameters:
    //  - f<*Fifo>        : The fifo to pop from
    //
    // fifo_errno:
    //  - FIFO_OK:    If no error occurs
    //  - FIFO_EMPTY: If the top is NULL
    //
    // Return:
    //  - e<*void> : The element poped
    //

#endif