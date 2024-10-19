#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Stack structure
typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// Function to push an item onto the stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

// Function to pop an item from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Function to check if the given pair of characters is a matching pair
int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || (opening == '{' && closing == '}');
}

// Function to check if the parentheses and braces are properly nested
void checkParenthesesAndBraces(const char *expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; ++i) {
        char currentChar = expression[i];

        // If the character is an opening parenthesis or brace, push it onto the stack
        if (currentChar == '(' || currentChar == '{') {
            push(&stack, currentChar);
        }
        // If the character is a closing parenthesis or brace, check for a match
        else if (currentChar == ')' || currentChar == '}') {
            if (isEmpty(&stack)) {
                printf("Parentheses/braces are not properly nested\n");
                return;
            }

            char poppedChar = pop(&stack);
            if (!isMatchingPair(poppedChar, currentChar)) {
                printf("Parentheses/braces are not properly nested\n");
                return;
            }
        }
    }

    // If the stack is empty at the end, the parentheses/braces are matched properly
    if (isEmpty(&stack)) {
        printf("Parentheses/braces are nested properly\n");
    } else {
        printf("Parentheses/braces are not properly nested\n");
    }
}

int main() {
    char expression[MAX_STACK_SIZE];

    printf("Enter parentheses and/or braces: ");
    fgets(expression, MAX_STACK_SIZE, stdin);

    checkParenthesesAndBraces(expression);

    return 0;
}
