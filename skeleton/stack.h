#include <stdlib.h>


struct stack{
    double* stack_nums;
    int max_size;
    int current_size;
};

/* This function will malloc the memory needed for the stack
 * using max_Size as the maximum amount of values that stack_nums
 * can hold.
 *
 * Return a pointer to the stack upon success and NULL otherwise
 *
 * Remember: only (a) certain element/elements within the stack need
 * to be malloc'd.  What is it/are they?
 */

struct stack* create_stack(int max_size);

/* This function will destroy the stack, freeing the elements which
 * were initially malloc'd.
 *
 * Return 1 upon success and 0 otherwise.
 */

int destroy_stack(struct stack* s);

/* This function will peek the value from the stack if the stack 
 * isn't empty.
 *
 * Return the number peeking if successful and -1 otherwise (even
 * though -1 could be in the stack, we are keeping things simple)
 */

double peek(struct stack* s);

/* This function will pop the value from the stack if the stack
 * isn't empty.
 *
 * Return the number popped if successful and -1 otherwise (even 
 * though -1 could be in the stack, we are keeping things simple)
 */

double pop(struct stack* s);

/* This function will push the value onto the stack if there is
 * room for it.
 *
 * Return 1 upon success and 0 upon failure
 */

int push(struct stack* s, double value);

/* This function will clear the elements of the stack, setting
 * them all to -1.
 *
 * Return 1 upon success and 0 upon failure.
 *
 * Don't forget to reset the current_size var!
 */

int clear(struct stack* s);

/* This function returns 1 if the stack is full and 0 otherwise.
 */

int is_full(struct stack* s);

/* This function returns 1 if the stack is empty and 0 otherwise.
 */

int is_empty(struct stack* s);

/* This function returns 1 if there are 2 or more numbers within 
 * the stack and 0 otherwise.
 *
 * This function helps with checking for a valid equation.  For 
 * instance, if only one or no numbers are on the stack and an
 * operand is seen, then the equation is invalid.
 */

int has_atleast_two_nums(struct stack* s);

/* This function is already implemented for you.  It is to help
 * test and debug your stack implementation.
 */

void print_stack(struct stack* s);
