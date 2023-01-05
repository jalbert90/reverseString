#include <stdio.h>
#include <string.h>

void reverse_numbers(char* str) {
    // To find the start of the last number.
    // We can do this searching for the last space in the string, starting from the end.
    int last_number_start = strlen(str);
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            last_number_start = i + 1;
            break;
        }
    }

    int number_start = last_number_start;
    // loop through the string again, starting from the last number
    for (int i = last_number_start - 1; i >= -1; i--) {
        if (i == -1 || str[i] == ' ') {
            // We print the number 
            for (int j = i + 1; j < number_start; j++) {
                printf("%c", str[j]);
            }
            printf(" ");
            // The next number starts after the space.
            number_start = i;
        }
    }
}

int main() {
    char str[] = "10 20 50";
    reverse_numbers(str); // should print "50 20 10"

    return 0;
}