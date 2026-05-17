#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack declaration
float stack[MAX];
int top = -1;

// Push function
void push(float value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = value;
    }
}

// Pop function
float pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return 0;
    } else {
        return stack[top--];
    }
}

// Display stack
void displayStack() {
    int i;

    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("\nCurrent Stack:\n");

    for (i = top; i >= 0; i--) {
        printf("| %.2f |\n", stack[i]);
    }

    printf("-------\n");
}

int main() {

    char input[20];
    float a, b, number;

    printf("=====================================\n");
    printf("     REVERSE POLISH CALCULATOR\n");
    printf("=====================================\n");

    printf("\nInstructions:\n");
    printf("?  -> Enter a number\n");
    printf("+  -> Addition\n");
    printf("-  -> Subtraction\n");
    printf("*  -> Multiplication\n");
    printf("/  -> Division\n");
    printf("=  -> Display top value\n");
    printf("q  -> Quit program\n");

    while (1) {

        printf("\nEnter instruction: ");
        scanf("%s", input);

        // Quit
        if (strcmp(input, "q") == 0) {
            printf("Program terminated.\n");
            break;
        }

        // Read and push number
        else if (strcmp(input, "?") == 0) {

            printf("Enter number: ");
            scanf("%f", &number);

            push(number);

            printf("%.2f pushed into stack.\n", number);

            displayStack();
        }

        // Addition
        else if (strcmp(input, "+") == 0) {

            b = pop();
            a = pop();

            push(a + b);

            printf("Performed: %.2f + %.2f\n", a, b);

            displayStack();
        }

        // Subtraction
        else if (strcmp(input, "-") == 0) {

            b = pop();
            a = pop();

            push(a - b);

            printf("Performed: %.2f - %.2f\n", a, b);

            displayStack();
        }

        // Multiplication
        else if (strcmp(input, "*") == 0) {

            b = pop();
            a = pop();

            push(a * b);

            printf("Performed: %.2f * %.2f\n", a, b);

            displayStack();
        }

        // Division
        else if (strcmp(input, "/") == 0) {

            b = pop();
            a = pop();

            if (b == 0) {
                printf("Error! Division by zero.\n");
                push(a);
                push(b);
            } else {
                push(a / b);

                printf("Performed: %.2f / %.2f\n", a, b);

                displayStack();
            }
        }

        // Print top value
        else if (strcmp(input, "=") == 0) {

            if (top == -1) {
                printf("Stack is empty.\n");
            } else {
                printf("\nTop Value = %.2f\n", stack[top]);
            }
        }

        // Invalid input
        else {
            printf("Invalid instruction!\n");
        }
    }

    return 0;
}
