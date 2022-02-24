#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    // Get text from the user
    string text = get_string("Text: ");

    //Calculate Grade based on formula (index = 0.0588 * L - 0.296 * S - 15.8)
    float l = (float)(count_letters(text) / (float)count_words(text)) * 100;
    float s = (float)(count_sentences(text) / (float)count_words(text)) * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);

    //Print grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string s)
{
    int letter_amount = 0;
    //Go through each letter in the string to check if a letter is alphabetic. (if it is alphabetic it adds to count)
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            letter_amount++;
        }
    }
    return letter_amount;
}

int count_words(string s)
{
    // When space is found add 1 to word count (since words are divided by spaces)
    int words_amount = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]))
        {
            words_amount++;
        }
    }
    return words_amount;
}

int count_sentences(string s)
{
    // Compare the splitters to the letter in word to check if its a sentence splitter
    char splitters[3] = {'.', '!', '?'};
    int sentences_amount = 0;

    //Loop to go through letters
    for (int i = 0; i < strlen(s); i++)
    {
        //Loop to go through array
        for (int j = 0; j < 3; j++)
        {
            if (s[i] == splitters[j])
            {
                sentences_amount++;
            }
        }
    }
    return sentences_amount;
}
