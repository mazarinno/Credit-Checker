// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

unsigned int hashNum;
unsigned int wordCount;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
// this is the function that takes up the most time for me
bool check(const char *word)
{
    hashNum = hash(word);
    node *n = table[hashNum];

    while (n) // going through every node in each letter bucket in hash, not sure how to do it quicker
    {
        if (strcasecmp(word, n->word) == 0) // if word = word in node return true
        {
            return true;
        }
        n = n->next; // else keep going until we find a match or false if we don't
    }
    return false;
}

// Hashes word to a number
// hash function from http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c = 0;

    while (c == tolower(*word++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // opening the dictionary to read from it
    FILE *dict = fopen(dictionary, "r");
    if(dict == NULL) // if not opened successfully, return false
    {
        return false;
    }

    char word[LENGTH + 1];

    // loop to read one string at a time for all strings until EOF
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        else
        {
            // if malloc works, the word in this node will be the word being looked at in dictionary
            strcpy(n->word, word);
            hashNum = hash(word);
            n->next = table[hashNum];
            table[hashNum] = n;
            wordCount++;
        }
    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (wordCount > 0)
    {
        return wordCount;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];

        while (n)
        {
            node *temp = n;
            n = n->next;
            free(temp);
        }

        if (i == N - 1 && n == NULL)
        {
            return true;
        }
    }
    return false;
}
