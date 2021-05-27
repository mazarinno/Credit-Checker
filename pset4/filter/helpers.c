#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // averaging the values and setting all to that avg
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            float avg = round((round(red) + round(blue) + round(green)) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // changing values to the new ones from sepia formulas
            // if they are over 255, make sure they go back to 255
            float red = image[i][j].rgbtRed;
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float redtwo = 0;
            float bluetwo = 0;
            float greentwo = 0;

            redtwo = round((0.393 * red) + (0.769 * green) + (0.189 * blue));
            if (redtwo > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = redtwo;
            }
            bluetwo = round((0.272 * red) + (0.534 * green) + (0.131 * blue));
            if (bluetwo > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = bluetwo;
            }
            greentwo = round((0.349 * red) + (0.686 * green) + (0.168 * blue));
            if (greentwo > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = greentwo;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // switching one half of the image with the other horizontally
            int tempred = 0;
            int tempblue = 0;
            int tempgreen = 0;
            tempred = image[i][j].rgbtRed;
            tempblue = image[i][j].rgbtBlue;
            tempgreen = image[i][j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][width - 1 - j].rgbtRed = tempred;
            image[i][width - 1 - j].rgbtBlue = tempblue;
            image[i][width - 1 - j].rgbtGreen = tempgreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    struct newImage // placeholder struct to make sure blurred pixels dont get mixed in with averages of non-blurred pixels
    {
        float rgbtBlue;
        float rgbtGreen;
        float rgbtRed;
    };
    struct newImage newImage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float tempred = 0;
            float tempblue = 0;
            float tempgreen = 0;
            int count = 1;

            tempred = image[i][j].rgbtRed;
            tempblue = image[i][j].rgbtBlue;
            tempgreen = image[i][j].rgbtGreen;

            if (j + 1 < width) // right square
            {
                tempred = tempred + image[i][j + 1].rgbtRed;
                tempblue = tempblue + image[i][j + 1].rgbtBlue;
                tempgreen = tempgreen + image[i][j + 1].rgbtGreen;
                count = count + 1;
            }
            if (j - 1 < width && j - 1 > -1) // left square
            {
                tempred = tempred + image[i][j - 1].rgbtRed;
                tempblue = tempblue + image[i][j - 1].rgbtBlue;
                tempgreen = tempgreen + image[i][j - 1].rgbtGreen;
                count = count + 1;
            }
            if (i + 1 < height) // bottom square
            {
                tempred = tempred + image[i + 1][j].rgbtRed;
                tempblue = tempblue + image[i + 1][j].rgbtBlue;
                tempgreen = tempgreen + image[i + 1][j].rgbtGreen;
                count = count + 1;
            }
            if (i - 1 < height && i - 1 > -1) // top square
            {
                tempred = tempred + image[i - 1][j].rgbtRed;
                tempblue = tempblue + image[i - 1][j].rgbtBlue;
                tempgreen = tempgreen + image[i - 1][j].rgbtGreen;
                count = count + 1;
            }
            if (i - 1 < height && i - 1 > -1 && j - 1 < width && j - 1 > -1) // top left
            {
                tempred = tempred + image[i - 1][j - 1].rgbtRed;
                tempblue = tempblue + image[i - 1][j - 1].rgbtBlue;
                tempgreen = tempgreen + image[i - 1][j - 1].rgbtGreen;
                count = count + 1;
            }
            if (i - 1 < height && i - 1 > -1 && j + 1 < width) // top right
            {
                tempred = tempred + image[i - 1][j + 1].rgbtRed;
                tempblue = tempblue + image[i - 1][j + 1].rgbtBlue;
                tempgreen = tempgreen + image[i - 1][j + 1].rgbtGreen;
                count = count + 1;
            }
            if (i + 1 < height && j - 1 < width && j - 1 > -1) // bottom left
            {
                tempred = tempred + image[i + 1][j - 1].rgbtRed;
                tempblue = tempblue + image[i + 1][j - 1].rgbtBlue;
                tempgreen = tempgreen + image[i + 1][j - 1].rgbtGreen;
                count = count + 1;
            }
            if (i + 1 < height && j + 1 < width) // bottom right
            {
                tempred = tempred + image[i + 1][j + 1].rgbtRed;
                tempblue = tempblue + image[i + 1][j + 1].rgbtBlue;
                tempgreen = tempgreen + image[i + 1][j + 1].rgbtGreen;
                count = count + 1;
            }

            int newred = round(tempred / count);
            int newblue = round(tempblue / count);
            int newgreen = round(tempgreen / count);

            // making sure the averages stay under 255
            if (newred > 255)
            {
                newred = 255;
            }
            if (newblue > 255)
            {
                newblue = 255;
            }
            if (newgreen > 255)
            {
                newgreen = 255;
            }

            // inputting final values into placeholder array for later
            newImage[i][j].rgbtRed = round(newred);
            newImage[i][j].rgbtBlue = round(newblue);
            newImage[i][j].rgbtGreen = round(newgreen);
        }
    }

    // going back over the whole image a second time after all newimage values are complete and then replacing them all
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = newImage[i][j].rgbtRed;
            image[i][j].rgbtBlue = newImage[i][j].rgbtBlue;
            image[i][j].rgbtGreen = newImage[i][j].rgbtGreen;
        }
    }
    return;
}
