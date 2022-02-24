#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //For each row
    for (int i = 0; i < n; i++)
    {
        //For each columm add space
        for (int j = i + 1; j < n; j++)
        {
            printf(" ");
        }
        //For each columm first pyramid
        for (int j = n + 1; j > n - i; j--)
        {
            printf("#");
        }
        //Add two spaces between each pyramid
        printf("  ");
        //For each columm second pyramid
        for (int j = n + 1; j > n - i; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}
