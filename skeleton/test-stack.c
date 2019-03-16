/*****************************************************
 *              CSCI 3410, HW 4
 *             Stack && File I/O
 *
 * Copyright (c) 2018 Phil Lopreiato && John Shepherd
 *****************************************************/

/* DO NOT MODIFY THIS FILE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Use the -I flag when compiling to set an include directory to find this */
#include <stack.h>

#define MAX_SIZE 10

#define ASSERT(exp, desc)       \
do {                            \
        printf(desc);           \
        assert(exp);            \
        printf("OK\n");         \
} while(0)


int main() {
        double first_value = 5;
        double second_value = 10;
        double third_value = 15;
        double eps = 0.01;
        struct stack *s;

        s = create_stack(MAX_SIZE);
        ASSERT(s, "Testing we can create a stack...");

        /* Test some basic properties when the stack is empty */
        ASSERT(s->current_size == 0, "Testing that the queue starts as size 0...");
        ASSERT(peek(s) >= -1-eps && peek(s) <= -1+eps, "Testing peek() returns -1 when empty...");
        ASSERT(pop(s) >= -1-eps && pop(s) <= -1+eps, "Testing pop() returns -1 when empty...");
        printf("\n");

        /* Insert an item in the stack */
        printf("Inserting an item in the stack...");
        
        ASSERT(push(s,first_value) == 1, "Testing first push...");
        ASSERT((s->current_size) == 1, "Testing the stack size is now 1...");
        ASSERT(peek(s) >=first_value-eps && peek(s) <= first_value+eps, "Testing we can peek at the next item...");
        ASSERT((s->current_size) == 1, "Testing the stack size is still 1...");
        printf("\n");

        ASSERT(push(s,second_value) == 1, "Testing second push...");

        ASSERT((s->current_size) == 2, "Testing the stack size is now 2...");
        ASSERT(peek(s) >= second_value-eps && peek(s) <= second_value+eps, "Testing we can peek at the next item...");
        ASSERT((s->current_size) == 2, "Testing the stack size is still 2...");
        printf("\n");

        
        ASSERT(push(s,third_value) == 1, "Testing third push...");
        ASSERT((s->current_size) == 3, "Testing the stack size is now 3...");
        ASSERT(peek(s) >= third_value-eps && peek(s) <= third_value+eps, "Testing we can peek at the next item...");
        ASSERT((s->current_size) == 3, "Testing the stack size is still 3...");
        printf("\n");
        
        /* Testing first pop */

        ASSERT(peek(s) >= third_value-eps && pop(s) <= third_value+eps, "Testing the first popped value...");
        
        ASSERT((s->current_size) == 2, "Testing the size is now 2...");
        printf("\n");
        

        /* Testing second pop */
        ASSERT(peek(s) >= second_value-eps && pop(s) <= second_value+eps, "Testing the second popped value...");
        
        ASSERT((s->current_size) == 1, "Testing the size is now 1...");
        printf("\n");

        /* Testing third pop */
        ASSERT(peek(s) >= first_value-eps && pop(s) <= first_value+eps, "Testing the third popped value...");
        
        ASSERT((s->current_size) == 0, "Testing the size is now 0...");
        printf("\n");


        printf("Testing we can free the stack...");
        destroy_stack(s);
        printf("OK\n");

        printf("All instructor stack tests passed\n\n");
        return 0;
}
