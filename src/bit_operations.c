#include <stdio.h>
#include <math.h>

void menu();
void bit_operations();

                    //READ_BIT

void read_bit() {

    int decimal; int position; int bit;
    char input[10];

    // NUM INPUT
    printf("Enter the number: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &decimal) != 1) { 
            decimal = -1; 
        }

    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF);


    // POSITION INPUT
    printf("Enter position: ");
    fgets(input, sizeof(input), stdin);

    while ((clean = getchar()) != '\n' && clean != EOF);

    if (sscanf(input, "%d", &position) != 1) { 
            position = -1; 
        }
    printf("Decimal you'v entered: %d\n" ,position);

    //MAIN BLOCK

    if (position < 0 || position >= 24) {
        printf("Invalid bit position\n");
    } else {
        bit = (decimal >> position) & 1;
        printf("%d",bit);
    }
}

                    //SET_BIT

void set_bit() {

    int decimal; int position;
    char input[10];

    // NUM INPUT
    printf("Enter the number: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &decimal) != 1) { 
            decimal = -1; 
        }

    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF);


    // POSITION INPUT
    printf("Enter position: ");
    fgets(input, sizeof(input), stdin);

    while ((clean = getchar()) != '\n' && clean != EOF);

    if (sscanf(input, "%d", &position) != 1) { 
            position = -1; 
        }
    printf("Decimal you'v entered: %d\n" ,position);

    //MAIN BLOCK

    if (position < 0 || position >= 24) {
        printf("Invalid bit position\n");
    } else {
        // Create a mask with only the bit at the specified position set to 1
        int mask = 1 << position;
    
        // Use bitwise OR to set the bit to 1
        int result = decimal | mask;
        printf("%d",result);
    }
}

                //RESET_BIT


void reset_bit() {

    int decimal; int position;
    char input[10];

    // NUM INPUT
    printf("Enter the number: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &decimal) != 1) { 
            decimal = -1; 
        }

    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF);


    // POSITION INPUT
    printf("Enter position: ");
    fgets(input, sizeof(input), stdin);

    while ((clean = getchar()) != '\n' && clean != EOF);

    if (sscanf(input, "%d", &position) != 1) { 
            position = -1; 
        }
    printf("Decimal you'v entered: %d\n" ,position);

    //MAIN BLOCK

    if (position < 0 || position >= 24) {
        printf("Invalid bit position\n");
    } else {
        // Create a mask with only the bit at the specified position set to 0
        int mask = ~(1 << position);
    
        // Use bitwise AND to set the bit to 0
        int result = decimal & mask;
        printf("%d",result);
    }
}

                //TOGGLE_BIT


void toggle_bit() {

    int decimal; int position;
    char input[10];

    // NUM INPUT
    printf("Enter the number: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &decimal) != 1) { 
            decimal = -1; 
        }

    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF);


    // POSITION INPUT
    printf("Enter position: ");
    fgets(input, sizeof(input), stdin);

    while ((clean = getchar()) != '\n' && clean != EOF);

    if (sscanf(input, "%d", &position) != 1) { 
            position = -1; 
        }
    printf("Decimal you'v entered: %d\n" ,position);

    //MAIN BLOCK

    if (position < 0 || position >= 24) {
        printf("Invalid bit position\n");
    } else {
        // Create a mask with only the bit at the specified position set to 1
        int mask = 1 << position;
    
        // Use bitwise XOR (^) to toggle the bit
        int result = decimal ^ mask;
        printf("%d",result);
    }
}


void  bit_answer_check(int answer){

    switch (answer) {
        case 1:
            printf("You have chosen read_bit.\n");
            read_bit();
            break;
        case 2:
            printf("You have chosen set_bit.\n");
            set_bit();
            break;
        case 3:
            printf("You have chosen reset_bit.\n");
            reset_bit();
            break;
        case 4:
            printf("You have chosen toggle_bit.\n");
            toggle_bit();
            break;
        case 5:
            printf("Come back to main menu.\n");
            menu();
            break;
        default:
            printf("Incorect choice. Try again.\n");
            bit_operations();
        }
}


void bit_operations()
{
    printf("%s","\nChose the number of operation:\n\
    1 -- read_bit\n\
    2 -- set_bit\n\
    3 -- reset_bit\n\
    4 -- toggle_bit\n\
    5 -- menu\n");

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

    bit_answer_check(answer);
}
