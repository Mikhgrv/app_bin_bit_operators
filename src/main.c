#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "converts.h"
#include "bit_operations.h"

void menu();


void answer_check(int answer){

    switch (answer) {
        case 1:
            printf("You have chosen action 1.\n");
            convert_decimal_to_bin();
            break;
        case 2:
            printf("You have chosen action 2\n");
            convert_bin_to_decimal();
            break;
        case 3:
            printf("You have chosen action 3.\n");
            bit_operations();
            menu();
            break;
        case 4:
            printf("Exit.\n");
            exit(0);// terminates the program immediately. 0 is the exit status
        default:
            printf("Incorect choice. Try again.\n");
            menu();
        }
}

void menu()
{
   
    printf("%s","\nType the number of action:\n\
    1 -- convert_decimal_bin\n\
    2 -- convert_bin_to_decimal\n\
    3 -- bit_operations\n\
    4 -- escape from program\n");

    int answer;
    char input[2]; 

    // Отримуємо вибір користувача як рядок
    printf("You choice: ");
    fgets(input, sizeof(input), stdin);

    // Конвертуємо рядок в ціле число використовуючи sscanf
    // sscanf -- String Scan Formatted -- int sscanf(const char *str, const char *format, ...);

    if (sscanf(input, "%d", &answer) != 1) { 
        answer = -1; // Якщо конвертація не вдалася, встановлюємо некоректне значення
    }

    // Clear the stdin buffer (My safety block)
    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF);
    // end of block

    answer_check(answer);
}

int main() 
{
    menu();
    return 0;
}

