#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //takes input from the user to get the card number
    long long input = get_long("Enter the card number: ");
    int total = 0;
    //Luhn's algorithm
    //Calculating checksum
    //Adds the checksum to the total
    total = input % 10;
    //Removes the checksum from the cardnumber
    long long cardnum = input / 10;
    while (cardnum > 0)
    {
        int doubled = (cardnum % 10) * 2;
        if (doubled > 9)
        {
            doubled -= 9;
        }
        total += doubled;
        //Then cuts off the farmost right number so we can get the next one
        cardnum = cardnum / 10;
        //Then gets the farmost right number and adds it undoubled to the total
        int undoubled = cardnum % 10;
        total += undoubled;
        //Then chops off the farmost right digit again for the next iteration
        cardnum = cardnum / 10;
    }
    //Check is card number is valid

    if ((total % 10) != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        //Now checking card length and starting digits
        //Reassign cardnum
        cardnum = input;
        long long temp = cardnum;
        int length = 0;
        do
        {
            temp /= 10;
            ++length;
        }
        while(temp != 0);
        int firstDigit;
        int secondDigit;
        if (length % 2 == 0)
        {
            //If Even
            long long count = log10(cardnum);
            firstDigit = cardnum / pow(10, count);
            secondDigit = cardnum / pow(10, (count - 1));
            secondDigit = secondDigit % 10;
        }
        else
        {
            //If Odd
            //firstDigit = cardnum / (pow(10,((length + 1)/2)));
            //secondDigit = cardnum / (pow(10,((length)/2)));
            long long count = log10(cardnum);
            firstDigit = cardnum / pow(10, count);
            secondDigit = cardnum / pow(10, (count - 1));
            secondDigit = secondDigit % 10;
        }
        if ((length == 15) && (firstDigit == 3) && ((secondDigit == 4) || (secondDigit == 7)))
        {
            printf("AMEX\n");
        }
        if ((length == 16) && (firstDigit == 5))
        {
            if ((secondDigit == 1) || (secondDigit == 2) || (secondDigit == 3) || (secondDigit == 4) || (secondDigit == 5))
            {
                printf("MASTERCARD\n");
            }
        }
        if (((length == 13) || (length == 16)) && (firstDigit == 4))
        {
            printf("VISA\n");
        }
    }
}
