#include <stdio.h>
#include <string.h>

void reverse_numbers(char* str) {
    // First, we need to find the last number in the string.
    // We can do this by starting at the end of the string and going backwards until
    // we find the first non-space character, which will be the start of the last number.
    int last_number_start = -1;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            last_number_start = i;
            break;
        }
    }

    // If we didn't find any numbers in the string, we can stop here.
    if (last_number_start == -1) {
        return;
    }

    // Now, we can loop through the string again, starting from the last number
    // and going backwards, printing out each number as we find it.
    // We'll keep track of the start and end of each number as we go,
    // and print the number out once we reach the end of it.
    int number_start = last_number_start;
    for (int i = last_number_start - 1; i >= 0; i--) {
        if (str[i] == ' ' || i == 0) {
            // We've reached the end of a number, so we can print it out.
            // If we're at the beginning of the string, we need to include the
            // first character (which may not be a space) in the number.
            int end = (i == 0) ? i : i + 1;
            for (int j = end; j <= number_start; j++) {
                printf("%c", str[j]);
            }
            printf(" ");

            // The next number starts just after the space we found, or at the
            // beginning of the string if we're at the end.
            number_start = end;
        }
    }

    // We've reached the end of the string, so we can print out the first number.
    for (int j = 0; j <= number_start; j++) {
        printf("%c", str[j]);
    }
    printf("\n");
}

int main() {
    char str[] = "10 20 50";
    reverse_numbers(str); // should print "50 20 10"

    return 0;
}