#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid input\n");
        return 1;
    }
    // array of 512 bytes
    unsigned char buffer[512];
    // opening card.raw and reading when the code starts
    FILE *input = fopen(argv[1], "r");
    FILE *output = NULL; // file for outputs used in read loop

    int jpgfound = 0; // bool value, starts false

    int jpgcount = 0; // counter for jpgs found

    // while reading 512 bytes at a time, check for jpg headers
    while (fread(buffer, 512, 1, input) == 1) // return value for fread is 1 while it is reading
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpgfound == 0) // if we haven't found a jpg yet, now we have
            {
                jpgfound = 1;
            }
            else // if not first jpg, close this one and out of else will begin new one
            {
                fclose(output);
            }
            // once jpg is found, give file a name and write to it
            char name[8];
            sprintf(name, "%03i.jpg", jpgcount);
            output = fopen(name, "w"); //open output and prepare writing
            jpgcount++;
        }
        if (jpgfound == 1) //in 512 byte chunks, write to output
        {
            fwrite(buffer, 512, 1, output);
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}