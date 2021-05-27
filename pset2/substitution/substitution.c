#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int placeholder = strlen(argv[1]); // int of the strlen of argv1 to check if it is 26 or not 
        int j;
        char temp;
        string key = argv[1];

        // If the string entered is not 26 characters, it is rejected
        if (strlen(argv[1]) != 26)
        {
            printf("Invalid cypher length\n");
            return 1;
        }
        else
        {
            //this loop checks for repeated alphabet characters
            int check = 0;
            for (char c = 'a'; c <= 'z'; c++)
            {
                for (int r = 0; r < 26; r++)
                {
                    if (tolower(key[r]) == c)
                    {
                        check++;
                        break;
                    }
                    if (check == 26) // this would mean that it has gone through the alphabet and found every letter only once
                    {
                        break;
                    }
                }
            }
            if (check != 26)
            {
                printf("Repeated character error\n");
                return 1;
            }
        }
        //checks for numbers and rejects if any are found
        for (int a = 0; a < placeholder; a++)
        {
            if (isalpha(key[a]) == 0)
            {
                printf("Non-alphabet characters\n");
                return 1;
            }
        }

        string plaintext = get_string("plaintext: ");
        int plainlen = strlen(plaintext); // getting the length of the plaintext to go through it for the encription loop
        string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // using the alphabet as its own array to match numbers up with the cipher key itself
        
        //plaintext to cyphertext conversion happens in this loop
        printf("ciphertext: ");
        for (int b = 0; b < plainlen; b++)
        {
            char p = plaintext[b];
            if (isalpha(p) != 0)
            {
                if (isupper(p) != 0)
                {
                    for (int a = 0; a < 26; a++)
                    {
                        if (alph[a] == p)
                        {
                            printf("%c", toupper(key[a]));
                        }
                    }
                }
                else 
                {
                    for (int a = 0; a < 26; a++)
                    {
                        if (tolower(alph[a]) == p)
                        {
                            printf("%c", tolower(key[a]));
                        }
                    }
                }
            }
            else
            {
                printf("%c", p); //if it is not alphabetical, the character is printed as is 
            }
        }   
        printf("\n");
        return 0;
    }
    //rejects if there is no key or more than 2 arguments
    else
    {
        printf("Missing command-line argument\n");
        return 1;
    }
}