#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // input
    string text = get_string("Insert text here:\n");
    
    int placeholder = strlen(text);
    float letters = 0;
    float words = 1;
    float sentences = 0;
    // for loop for finding letters, words, and sentences
    for (int i = 0; i < placeholder; i++)
    {
        //tried doing this by using restrictions based on the ASCII code. ended up finding isalpha after that didn't work
        if (isalpha(text[i]))
        {
            letters = letters + 1;
        }
        
        //sentences based on number of exclamation points, periods, and question marks
        if ((int) text[i] == 33 || (int) text[i] == 63 || (int) text[i] == 46)
        {
            sentences = sentences + 1;
        }
        
        //words based on amnt of spaces. the int words starts at 1 to account for the first word of every sentence, which doesn't follow a space
        if ((int) text[i] == 32)
        {
            words = words + 1;
        }
    }
    
    //printf("Letters: %f \n", letters);
    //printf("Sentences: %f \n", sentences);
    //printf("Words: %f \n", words);
    
    //time to implement the grading function
    float index = 0;
    
    index = index + (0.0588 * ((letters * 100) / words) - 0.296 * ((sentences * 100) / words) - 15.8);
    //printf("index: %f\n", index);
    index = round(index);
    //printf("index: %f\n", index);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 1 && index < 17)
    {
        printf("Grade %i\n", (int) index);   
    }
}