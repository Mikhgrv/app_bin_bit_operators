#include <stdio.h>
#include <math.h>

void menu();


void convert_decimal_to_bin()
{
    int num;
    char input[10];
    int aditional;
    int bin[32];

    printf("Enter the number: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d", &num) != 1) { 
            num = -1; // встановлюємо некоректне значення
        }
    printf("Decimal you'v entered: %d\n" ,num);

    // Clear the stdin buffer (My safety block)
    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF);
    // end of block

    for (int i = 0; i < 32; i++)
        {
            bin[i] = 3;
        }

    for (int i = 0; num > 0; i++)
        {
            aditional = num % 2;
            bin[i] = aditional;
            num = num / 2;
        }
    
    printf("Your binary: ");
    
    for (int i = 31; i > -1; i--)
        { 
            if(bin[i] != 3){
               printf("%d", bin[i]);
            }
        }

    menu();
}


void convert_bin_to_decimal()
{
    int step = 0;
    int decimal = 0;
    char input[24];

    printf("Enter the number: ");
    fgets(input, sizeof(input), stdin);

    // Clear the stdin buffer (My safety block)
    int clean;
    while ((clean = getchar()) != '\n' && clean != EOF);
    // end of block

    for (int i = 23; i >= 0; i--){
        if(input[i] == '1' || input[i] == '0'){
            if(input[i] == '1'){
                decimal += pow(2, step) * 1;   
            }
        step += 1;
        }
    }

    printf("\nDecimal result: %d", decimal);
    menu();
}

