// This is a base converter.
// It is only converts integers positive or negative.
// The maximum base is 16.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE_OF_INPUT 10
#define MAX_SIZE_OF_OUTPUT 20

int IN_OUT_BASES[2]; // This array stores input and output bases.
char INPUT[MAX_SIZE_OF_INPUT + 1];
char OUTPUT[MAX_SIZE_OF_OUTPUT];

void getBases(); // Gets bases from user.
int power(int base, unsigned int power);
int convertToBaseOfTen(int isNegative);
void findOutput(int number, int base, int isNegative);

int main()
{
    int isNegative;
    int INPUT_BASE_OF_TEN;
    printf("\n\n\n * * * * * * * * * * \tWelcome to Base Converter\t* * * * * * * * * *\n\n\n");

    getBases();

    printf("\nPlease enter the integer (You can enter max %d digits.Included minus sign. Please use CapsLock. :) ): ", MAX_SIZE_OF_INPUT);
    scanf("%10s", INPUT);

    if (INPUT[0] == '-') // This line checks the input is negative
        isNegative = 1;

    else
        isNegative = 0;

    INPUT_BASE_OF_TEN = convertToBaseOfTen(isNegative);
    findOutput(INPUT_BASE_OF_TEN, IN_OUT_BASES[1], isNegative);
    printf("\n%s in base of %d is equal to %s in base of %d\n", INPUT, IN_OUT_BASES[0], OUTPUT, IN_OUT_BASES[1]);

    return 0;
}

void findOutput(int number, int base, int isNegative)
{
    char numbers[] = "0123456789ABCDEF";
    char outputBuffer[19];
    int value;

    unsigned int counter = 0;

    do
    {

        value = number % base;
        outputBuffer[counter] = numbers[value];
        counter++;
        number = number / base;

    } while (number != 0);

    int counterBuffer = counter;

    for (int i = 0; i < counterBuffer; i++)
    {
        counter--;
        OUTPUT[i + isNegative] = outputBuffer[counter];
    }
    if (isNegative)
        OUTPUT[0] = '-';
}

void getBases() // Gets bases from user.
{
    printf("\nEnter the input base: ");
    scanf("%u", IN_OUT_BASES);
    printf("\nEnter the output base: ");
    scanf("%u", IN_OUT_BASES + 1);
}

int convertToBaseOfTen(int isNegative) // This function converts the number to base of ten with absolute value.
{
    unsigned int counter = 0;
    int number = 0;
    int base = IN_OUT_BASES[0];

    for (int i = MAX_SIZE_OF_INPUT - 1; i >= isNegative; i--)
    {
        // printf("\n%u\n", counter); //FIXME:
        if (INPUT[i] == '\0')
            continue;

        if ((INPUT[i] <= '9') && (INPUT[i] > '0'))
        {
            number += (INPUT[i] - '0') * (power(base, counter));
            // printf("\n Sayi"); //FIXME:
            // printf("            counter: %u         INPUT[%d]: %c       number: %d      BASE: %d\n", counter, i, INPUT[i], number, power(base, counter));
        }

        else if ((INPUT[i] <= 'Z') && (INPUT[i] >= 'A'))
        {
            number += ((INPUT[i] - 'A') + 10) * (power(base, counter));
            // printf("\n Harf");//FIXME:
            // printf("            counter: %u         INPUT[%d]: %c       number: %d      BASE: %d\n", counter, i, INPUT[i], number, power(base, counter));
        }

        counter++;
    }

    return number;
}

int power(int base, unsigned int power)
{
    int value = 1;

    for (int i = 0; i < power; i++)
    {
        value *= base;
    }

    return value;
}