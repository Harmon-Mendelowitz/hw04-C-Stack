#include <stdio.h>
#include "stack.h"

struct stack* create_stack(int max_size){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
    
    return NULL;
}

int destroy_stack(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

double peek(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

double pop(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

int push(struct stack* s, double value){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

int clear(struct stack *s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

int is_full(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

int is_empty(struct stack* s){

    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

int has_atleast_two_nums(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */

    return -1;
}

void print_stack(struct stack* s){
    int i = 0;
    printf("The contents of the stack are: ");
    
    if(is_empty(s)){
        printf("empty\n");
        return;
    }
   
    for (i = 0; i < s->current_size; i++){
        printf("%f ", s->stack_nums[i]);
    } 

    printf("\n");
}

