#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int x=0; x<width ; x++)
    {
        for(int y=0; y<height; y++)
        {
            unsigned int colour = 0.299*image[x][y].rgbtRed + 0.587*image[x][y].rgbtGreen + 0.114*image[x][y].rgbtBlue;
            image[x][y].rgbtRed = colour & 0xFF;
            image[x][y].rgbtBlue = colour & 0xFF;
            image[x][y].rgbtGreen = colour & 0xFF;
         }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE oimage[height][width];

   for (int i = 0; i < height; i++)
   {
       for (int j = 0; j < width; j++)
       {
           oimage[i][j] = image[i][j];
       }
   }
   int sepiaRed, sepiaBlue, sepiaGreen;
   for (int i = 0; i < height; i++)
   {
       for (int j = 0; j < width; j++)
       {
           sepiaRed = round(.393 * oimage[i][j].rgbtRed + .769 * oimage[i][j].rgbtGreen + .189 * oimage[i][j].rgbtBlue);
           sepiaBlue = round(.272 * oimage[i][j].rgbtRed + .534 * oimage[i][j].rgbtGreen + .131 * oimage[i][j].rgbtBlue);
           sepiaGreen = round(.349 * oimage[i][j].rgbtRed + .686 * oimage[i][j].rgbtGreen + .168 * oimage[i][j].rgbtBlue);
           image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
           image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
           image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
       }
   }
   return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
   int start, end;
   RGBTRIPLE temp;
   for (int i = 0; i < height; i++)
   {
       start = 0, end = width - 1;
       while (start < end)
       {
           temp = image[i][start];
           image[i][start] = image[i][end];
           image[i][end] = temp;
           start++;
           end--;
       }
   }
   return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE oimage[height][width];

 for (int i = 0; i < height; i++)
 {
 for (int j = 0; j < width; j++)
 {
 oimage[i][j] = image[i][j];
 }
 }

 for (int i = 0; i < height; i++)
 {
 for (int j = 0; j < width; j++)
 {
 if (i == 0 && j == 0)
 {
 image[i][j].rgbtRed = round((oimage[i][j].rgbtRed + oimage[i + 1][j].rgbtRed
 + oimage[i][j + 1].rgbtRed + oimage[i + 1][j + 1].rgbtRed) / 4.0);

 image[i][j].rgbtGreen = round((oimage[i][j].rgbtGreen + oimage[i + 1][j].rgbtGreen
 + oimage[i][j + 1].rgbtGreen + oimage[i + 1][j + 1].rgbtGreen) / 4.0);
 }
 }}
    return;
}
