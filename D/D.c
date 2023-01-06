#include <stdio.h>
#include <string.h>

void reverse_numbers(const char* str) {
    int last_space = strlen(str);
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == ' ' || i == 0) {
            int start = i;
            if (str[i] == ' ') {
                start++;
            }
            for (int j = start; j < last_space; j++) {
                printf("%c", str[j]);
            }
            printf(" ");
            last_space = i;
        }
    }
    printf("\n");
}

int main() {
    const char* str = "10 20 50";
    reverse_numbers(str);
    return 0;
}