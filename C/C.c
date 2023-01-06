#include <stdio.h>
#include <string.h>

void reverse_numbers(char* str) {
    // First, we need to find the last number in the string.
    // We can do this by starting at the end of the string and going backwards until
    // we find the first space, which will be end of the last number.
    int last_number_end = -1;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            last_number_end = i;
            break;
        }
    }

    // If we didn't find any space in the string the last number ends in the last character
    if (last_number_end == -1) {
        last_number_end = strlen(str);
    }

    // Now, we can loop through the string again, starting from the end of the last number
    // and going backwards, printing out each number as we find it and break it in spaces
    int number_end = last_number_end;
    for (int i = last_number_end - 1; i >= -1; i--) {
        if (str[i] == ' ' || i == -1) {
            // We've reached the end of a number, so we can print it out.
            for (int j = i + 1; j <= number_end; j++) {
                printf("%c", str[j]);
            }
            if (i != -1) {
                printf(" ");
            }

            // The next number ends at the space we found.
            number_end = i - 1;
        }
    }
    printf("\n");
}

int main() {
    char str1[] = "10 20 50";
    reverse_numbers(str1); // should print "50 20 10"

    char str2[] = "1";
    reverse_numbers(str2); // should print "1"

    return 0;
}