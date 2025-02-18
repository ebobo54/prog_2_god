#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000

bool is_correct_bracket_seq(const char *sequence) {
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; sequence[i] != '\0'; i++) {
        char ch = sequence[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            if (top >= MAX_SIZE - 1) {
                return false;
            }
            stack[++top] = ch;
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1) {
                return false;
            }

            char open = stack[top--];
            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                return false;
            }
        } else {
            return false;
        }
    }

    return top == -1;
}

int main() {
    char sequence[MAX_SIZE];

    printf("Enter the parenthesis sequence: ");
    scanf("%s", sequence);

    if (is_correct_bracket_seq(sequence)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
