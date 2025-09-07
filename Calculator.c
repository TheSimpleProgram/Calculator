#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Clear the console screen depending on OS
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Draw a simple calculator layout
void draw_calculator() {
    printf("  _________________________  \n");
    printf(" |  _____________________  | \n");
    printf(" | |                   0.| | \n");
    printf(" | |_____________________| | \n");
    printf(" |  ___   ___   ___   ___  | \n");
    printf(" | | 7 | | 8 | | 9 | | + | | \n");
    printf(" | |___| |___| |___| |___| | \n");
    printf(" | | 4 | | 5 | | 6 | | - | | \n");
    printf(" | |___| |___| |___| |___| | \n");
    printf(" | | 1 | | 2 | | 3 | | * | | \n");
    printf(" | |___| |___| |___| |___| | \n");
    printf(" | | . | | 0 | | = | | / | | \n");
    printf(" | |___| |___| |___| |___| | \n");
    printf(" |_________________________| \n");
}

int main() {
    double num1, num2, result;
    char op;
    char dummy;

    clear_screen();
    draw_calculator();

    printf("\nEnter calculation (e.g. 3 + 4): ");
    if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
        printf("Invalid input\n");
        return 1;
    }

    switch(op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': 
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2; 
            break;
        default:
            printf("Invalid operator.\n");
            return 1;
    }

    printf("\nResult: %.2lf %c %.2lf = %.2lf\n", num1, op, num2, result);
    return 0;
}
