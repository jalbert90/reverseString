#include <stdio.h>
#include <string.h>

void reverse_numbers(char* str) {
    int l = strlen(str);
    int number_start = strlen(str);

    //traverse the string until we find a space or hit the beggining, then print what came after
    for (int i = l - 1; i >= 0; --i) {
        if (str[i] == ' ' || i == 0) {
            for (int j = (i == 0 ? i : i + 1); j <= number_start - 1; j++) {
                printf("%c", str[j]);
            }
            printf("%c", ' ');
            number_start = i;
        }
    }
    printf("\n");
}

int main() {
    char str[] = "10 20 50";
    reverse_numbers(str); // should print "50 20 10 "

    char str2[] = "25 50 42 100";
    reverse_numbers(str2); //should print "100 42 50 25 "
    return 0;
}