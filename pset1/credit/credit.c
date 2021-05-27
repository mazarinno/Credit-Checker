#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Input
    long credit = get_long("Insert credit card number:\n");
    // Length Checker
    long creditlength = 1 + log10(credit);
    // Beginning number checker.
    long creditstartchecker = credit;
    while (creditstartchecker >= 10)
    {
        creditstartchecker = creditstartchecker / 10;
    }
    // Second number checker, necessary for AMEX and MC
    long secondnumber = credit;
    int counttwo = 0;
    //This is an int acting as a bool for final output
    int invalid = 0;
    //Checking for AMEX numbers
    if (creditlength == 15 && creditstartchecker == 3)
    {
        while (secondnumber > 100)
        {
            counttwo++;
            int digittwo = (int)(secondnumber % 10);
            secondnumber = secondnumber / 10;
        }
        if (secondnumber == 34 || secondnumber == 37)
        {
            invalid = 0;

        else
        {
            invalid = 1;
        }
    }
    //Checking for MC numbers
    if (creditlength == 16 && creditstartchecker == 5)
    {
        while (secondnumber > 100)
        {
            counttwo++;
            int digittwo = (int)(secondnumber % 10);
            secondnumber = secondnumber / 10;
        }
        if (secondnumber < 51 || secondnumber > 55)
        {
            invalid = 1;
        }
    }
    // Checksum formulas
    int sum = 0;
    int sumtwo = 0;
    int count = 0;
    while (credit > 0)
    {
        count++;
        int digit = (int)(credit % 10);
        // Numbers which must be multiplied by 2
        if (count % 2 == 0)
        {
            if (2 * digit < 10)
            {
                sum = sum + (2 * digit);
            }
            // Next line checks to see if product must be broken down, i.e. 12 into 1 and 2
            else if ((2 * digit) >= 10)
            {
                int result = 0;
                result = (2 * digit % 10) + (2 * digit / 10);
                sum = sum + result;
            }
        }
        // The other numbers which must only be added
        if (count % 2 == 1)
        {
            sumtwo = sumtwo + digit;
        }
        credit = credit / 10;
    }
    // Adding the two together. Modulo for checksum is checked in final output
    int checksum = 0;
    checksum = sum + sumtwo;
    //printf("%i \n", sum);
    //printf("%i \n", sumtwo);
    //printf("%i \n", checksum);
    // Final outputs
    if (checksum % 10 == 0 && creditlength == 15 && secondnumber == 34)
    {
        printf("AMEX\n");
    }

    if (checksum % 10 == 0 && creditlength == 15 && secondnumber == 37)
    {
        printf("AMEX\n");
    }

    if (checksum % 10 == 0 && creditlength == 13 && creditstartchecker == 4)
    {
        printf("VISA\n");
    }

    if (checksum % 10 == 0 && secondnumber == 51 && creditlength == 16)
    {
        printf("MASTERCARD\n");
    }

    if (checksum % 10 == 0 && secondnumber == 52 && creditlength == 16)
    {
        printf("MASTERCARD\n");
    }

    if (checksum % 10 == 0 && secondnumber == 53 && creditlength == 16)
    {
        printf("MASTERCARD\n");
    }

    if (checksum % 10 == 0 && secondnumber == 54 && creditlength == 16)
    {
        printf("MASTERCARD\n");
    }

    if (checksum % 10 == 0 && secondnumber == 55 && creditlength == 16)
    {
        printf("MASTERCARD\n");
    }

    if (checksum % 10 == 0 && creditstartchecker == 4 && creditlength == 16)
    {
        printf("VISA\n");
    }

    if (checksum % 10 != 0 || invalid == 1 || creditlength == 10)
    {
        printf("INVALID\n");
    }
}