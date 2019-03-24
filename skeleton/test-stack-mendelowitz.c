/* DO NOT MODIFY THIS FILE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Use the -I flag when compiling to set an include directory to find this */
#include <stack.h>

#define MAX_SIZE 5

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
        double fourth_value = 20;
	double fifth_value = 25;
        double sixth_value = 30;
        double eps = 0.01;
        struct stack *s;

        s = create_stack(MAX_SIZE);
        ASSERT(s, "Testing we can create a stack...");

        /* Test some basic properties when the stack is empty */
        ASSERT(s->current_size == 0, "Testing that the queue starts as size 0...");
        ASSERT(peek(s) >= -1-eps && peek(s) <= -1+eps, "Testing peek() returns -1 when empty...");

	//tests is_empty	(NEW TEST)
	ASSERT(is_empty(s) == 1, "Testing is_empty() returns 1 when empty...");

        printf("\n");

        /* Insert an item in the stack */
        printf("Inserting an item in the stack...");
        
        ASSERT(push(s,first_value) == 1, "Testing first push...");
        ASSERT((s->current_size) == 1, "Testing the stack size is now 1...");
        printf("\n");


	//testing is empty again	(NEW TEST)
	ASSERT(is_empty(s) == 0, "Testing is_empty() returns 0 when not empty...");
	//testing has_atleast_two_nums()	(NEW TEST)
	ASSERT(has_atleast_two_nums(s) == -1, "Testing the stack does not have at least 2 numbers...");



        ASSERT(push(s,second_value) == 1, "Testing second push...");

        ASSERT((s->current_size) == 2, "Testing the stack size is now 2...");
        ASSERT(peek(s) >= second_value-eps && peek(s) <= second_value+eps, "Testing we can peek at the next item...");
        ASSERT((s->current_size) == 2, "Testing the stack size is still 2...");
        printf("\n");

	//testing has_atleast_two_nums()     	(NEW TEST)
	ASSERT(has_atleast_two_nums(s) == 1, "Testing the stack does have at least 2 numbers...");


        ASSERT(push(s,third_value) == 1, "Testing third push...");
        ASSERT((s->current_size) == 3, "Testing the stack size is now 3...");
        ASSERT(peek(s) >= third_value-eps && peek(s) <= third_value+eps, "Testing we can peek at the next item...");
        ASSERT((s->current_size) == 3, "Testing the stack size is still 3...");
        printf("\n");
        
	//add the other two numbers	(NEW TEST)
	ASSERT(push(s,fourth_value) == 1, "Testing fourth push...");
	//	(NEW TEST)
	ASSERT(is_full(s) == 0, "Testing is_full() returns 0 when not full...");
	//	(NEW TEST)
	ASSERT(push(s,fifth_value) == 1, "Testing fifth push...");
	//test is_full()	(NEW TEST)
	ASSERT(is_full(s) == 1, "Testing is_full() returns 1 when full...");

	//test for pushing while stack is full	(NEW TEST)
	ASSERT(push(s,sixth_value) == -1, "Testing sixth push should be -1...");


        /* Testing first pop */

        ASSERT(peek(s) >= fifth_value-eps && pop(s) <= fifth_value+eps, "Testing the first popped value...");
        
        ASSERT((s->current_size) == 4, "Testing the size is now 4...");
        printf("\n");
        

        /* Testing second pop */
        ASSERT(peek(s) >= fourth_value-eps && pop(s) <= fourth_value+eps, "Testing the second popped value...");
        
        ASSERT((s->current_size) == 3, "Testing the size is now 3...");
        printf("\n");

        /* Testing third pop */
        ASSERT(peek(s) >= third_value-eps && pop(s) <= third_value+eps, "Testing the third popped value...");
        
        ASSERT((s->current_size) == 2, "Testing the size is now 2...");
        printf("\n");


	//test clear()	(NEW TEST)
	ASSERT(clear(s) == 1, "Clear should be 1...");
	//test peek()	(NEW TEST)
	ASSERT(peek(s) >= -1-eps && peek(s) <= -1+eps, "Testing peek() returns -1 when empty...");
	//tests is_empty	(NEW TEST)
	ASSERT(is_empty(s) == 1, "Testing is_empty() returns 1 when empty...");



        printf("Testing we can free the stack...");
        destroy_stack(s);
        printf("OK\n");

        printf("All personal stack tests passed\n\n");
        return 0;
}
