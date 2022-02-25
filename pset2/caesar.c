#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char c, int n);

int main(int argc, string argv[])
{
    //Returns exit error if more than two arguments promted
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Checks if input is digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Makes key an integer
    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //Promt user for plaintext
    string p = get_string("plaintext:  ");

    //For loop to rotate each char
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        printf("%c", rotate(p[i], k));
    }

    //newline at the end of the program
    printf("\n");
}

char rotate(char c, int n)
{
    //If char is lowercase subtract 97 (ASCII Value, to make a - 0, b - 1 etc...) and add 97 again at the end
    if (isalpha(c) && islower(c))
    {
        return ((c + n - 97) % 26 + 97);
    }
    //If char is uppercase subtract 65 (ASCII Value, to make A - 0, B - 1 etc...) and add 65 again at the end
    else if (isalpha(c) && isupper(c))
    {
        return ((c + n - 65) % 26 + 65);
    }
    else
    {
        return c;
    }
}
