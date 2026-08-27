#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_stack(char **stack, unsigned int *stack_size, int stack_capacity, char *input) {
    if (*stack_size >= stack_capacity) {
        printf("ERROR: Stack Overflow\n");
        return;
    }
    stack[*stack_size] = (char*) malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(stack[*stack_size], input);
    (*stack_size)++;
}

char* pop_stack(char **stack, unsigned int *stack_size){
    if (*stack_size == 0){
        printf("ERROR: Stack Underflow\n");
        return NULL;
    }

    char *stack_top = stack[*stack_size - 1];
    *stack_size -= 1;
    return stack_top;
}

char* get_stack_top(char **stack, unsigned int stack_size){
    if (stack_size == 0){
        printf("ERROR: Stack Underflow\n");
        return NULL;
    }

    return stack[stack_size - 1];
}

void print_stack(char **stack, unsigned int stack_size) {
    if (stack_size == 0) {
        printf("Stack is empty\n");
        return;
    }
    for (unsigned int i = 0; i < (stack_size) - 1; i++)
        printf("%s -> ", stack[i]);
    printf("%s\n", stack[stack_size - 1]);
}

int main() {
    unsigned int stack_capacity, stack_size = 0;
    scanf("%u", &stack_capacity);
    char **stack = (char**) malloc(sizeof(char*) * stack_capacity);
 
    char command, temp[101], *return_temp;
    while (1) {
        scanf(" %c: %[^\n]", &command, temp);
 
        if (command == 'q')
            break;
        else if (command == 'w')
            push_stack(stack, &stack_size, stack_capacity, temp);
        else if (command == 'p') {
            return_temp = pop_stack(stack, &stack_size);
            if (return_temp) {
                printf("Pop returns: %s\n", return_temp);
                free(return_temp);
            }
        }
        else if (command == 's')
            print_stack(stack, stack_size);
        else if (command == 't') {
            return_temp = get_stack_top(stack, stack_size);
            if (return_temp)
                printf("Stack Top: %s\n", return_temp);
        }
        else if (command == 'n')
            printf("Stack Size: %u\n", stack_size);
        else
            printf("ERROR: Invalid Command\n");
 
    }
    print_stack(stack, stack_size);
}