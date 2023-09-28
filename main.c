#include <stdio.h>

int main() {
    int num;

    // Prompt the user to enter a 4-digit number with distinct digits
    printf("Enter a 4-digit number with distinct digits: ");
    scanf("%d", &num);

    // Check if the entered number has exactly 4 digits and distinct digits
    if (num < 1000 || num > 9999 ||
        (num / 1000 == (num / 100) % 10) ||
        (num / 1000 == (num / 10) % 10) ||
        (num / 1000 == num % 10) ||
        ((num / 100) % 10 == (num / 10) % 10) ||
        ((num / 100) % 10 == num % 10) ||
        ((num / 10) % 10 == num % 10)) {
        printf("Invalid input. Please enter a valid 4-digit number with distinct digits.\n");
        return 1; // Exit the program with an error code
    }

    // Perform Kaprekar's constant calculations
    int count = 0;
    while (num != 6174) {
        int digits[4];
        digits[0] = num / 1000;
        digits[1] = (num / 100) % 10;
        digits[2] = (num / 10) % 10;
        digits[3] = num % 10;

        // Sort the digits in ascending and descending order
        int asc_num = 0, desc_num = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (digits[i] > digits[j]) {
                    int temp = digits[i];
                    digits[i] = digits[j];
                    digits[j] = temp;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            asc_num = asc_num * 10 + digits[i];
            desc_num = desc_num * 10 + digits[3 - i];
        }

        // Calculate the next number
        num = desc_num - asc_num;
        printf("%04d - %04d = %04d\n", desc_num, asc_num, num);
        count++;
    }

    printf("Kaprekar's constant (6174) reached in %d steps.\n", count);

    return 0; // Exit the program successfully
}

