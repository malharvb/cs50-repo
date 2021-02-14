#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double new_val = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.000);
            image[i][j].rgbtBlue = new_val;
            image[i][j].rgbtRed = new_val;
            image[i][j].rgbtGreen = new_val;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE temp[3];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if (j < width/2)
            {
              temp[0] = image[i][j].rgbtBlue;
              temp[1] = image[i][j].rgbtGreen;
              temp[2] = image[i][j].rgbtRed;

              image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
              image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
              image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;


              image[i][width-j-1].rgbtBlue = temp[0];
              image[i][width-j-1].rgbtGreen = temp[1];
              image[i][width-j-1].rgbtRed = temp[2];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   //Had a very big issue didn't take into account that while calc the value of any pixel other than 1st it would take the previously blurred pixels value for the neighbouring pixels
    RGBTRIPLE ogimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ogimage[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_add_red = 0;
            int total_add_green = 0;
            int total_add_blue = 0;

            double total_no = 0;

            total_add_red += ogimage[i][j].rgbtRed;
            total_add_green += ogimage[i][j].rgbtGreen;
            total_add_blue += ogimage[i][j].rgbtBlue;
            total_no++;

            if(j-1 >= 0)
            {
                total_add_blue += ogimage[i][j-1].rgbtBlue;
                total_add_green += ogimage[i][j-1].rgbtGreen;
                total_add_red += ogimage[i][j-1].rgbtRed;
                total_no++;
            }
            if(j+1 < width)
            {
                total_add_blue += ogimage[i][j+1].rgbtBlue;
                total_add_green += ogimage[i][j+1].rgbtGreen;
                total_add_red += ogimage[i][j+1].rgbtRed;
                total_no++;
            }

            if (i-1 >= 0)
            {
                total_add_blue += ogimage[i-1][j].rgbtBlue;
                total_add_green += ogimage[i-1][j].rgbtGreen;
                total_add_red += ogimage[i-1][j].rgbtRed;
                total_no++;
                if(j-1 >= 0)
                {
                    total_add_blue += ogimage[i-1][j-1].rgbtBlue;
                    total_add_green += ogimage[i-1][j-1].rgbtGreen;
                    total_add_red += ogimage[i-1][j-1].rgbtRed;
                    total_no++;
                }
                if(j+1 < width)
                {
                    total_add_blue += ogimage[i-1][j+1].rgbtBlue;
                    total_add_green += ogimage[i-1][j+1].rgbtGreen;
                    total_add_red += ogimage[i-1][j+1].rgbtRed;
                    total_no++;
                }
            }
            if (i+1 < height)
            {
                total_add_blue += ogimage[i+1][j].rgbtBlue;
                total_add_green += ogimage[i+1][j].rgbtGreen;
                total_add_red += ogimage[i+1][j].rgbtRed;
                total_no++;
                if(j-1 >= 0)
                {
                    total_add_blue += ogimage[i+1][j-1].rgbtBlue;
                    total_add_green += ogimage[i+1][j-1].rgbtGreen;
                    total_add_red += ogimage[i+1][j-1].rgbtRed;
                    total_no++;
                }
                if(j+1 < width)
                {
                    total_add_blue += ogimage[i+1][j+1].rgbtBlue;
                    total_add_green += ogimage[i+1][j+1].rgbtGreen;
                    total_add_red += ogimage[i+1][j+1].rgbtRed;
                    total_no++;
                }
            }

            int redavg = round(total_add_red / total_no);
            int greenavg = round(total_add_green / total_no);
            int blueavg = round(total_add_blue / total_no);

            if (redavg > 255)
            {
                redavg = 255;
            }
            if (greenavg > 255)
            {
                greenavg = 255;
            }
            if (blueavg > 255)
            {
                blueavg = 255;
            }

            image[i][j].rgbtBlue = blueavg;
            image[i][j].rgbtRed = redavg;
            image[i][j].rgbtGreen = greenavg;

        }
    }
    return;
}
