#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg_rgb =
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = round(avg_rgb);
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
            float sepiaRed = (.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) +
                             (.189 * image[i][j].rgbtBlue);
            float sepiaGreen = (.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) +
                               (.168 * image[i][j].rgbtBlue);
            float sepiaBlue = (.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) +
                              (.131 * image[i][j].rgbtBlue);

            sepiaRed = fmin(255, sepiaRed);
            sepiaGreen = fmin(255, sepiaGreen);
            sepiaBlue = fmin(255, sepiaBlue);

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumR = 0.0, sumG = 0.0, sumB = 0.0;
            int count = 0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumR += copy[ni][nj].rgbtRed;
                        sumG += copy[ni][nj].rgbtGreen;
                        sumB += copy[ni][nj].rgbtBlue;
                        count++;
                    }
                }
            }

            float avgR = sumR / count;
            float avgG = sumG / count;
            float avgB = sumB / count;

            image[i][j].rgbtRed = round(avgR);
            image[i][j].rgbtGreen = round(avgG);
            image[i][j].rgbtBlue = round(avgB);
        }
    }
    return;
}
