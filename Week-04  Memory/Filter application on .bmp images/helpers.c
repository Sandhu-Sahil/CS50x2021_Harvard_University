#include "helpers.h"
#include<math.h>

//



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round(((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00));

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;

        }
    }

    return;
}




//
//




// hit max limit
int limit(int rgb)
{
    if (rgb > 255)
    {
        rgb = 255;
    }
    return rgb;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed, sepiaGreen, sepiaBlue;

            sepiaRed = limit(round(.393 * image[i][j].rgbtRed  + .769 * image[i][j].rgbtGreen  + .189 * image[i][j].rgbtBlue));
            sepiaGreen = limit(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            sepiaBlue = limit(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }

    return;
}





//
//


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        int n = (width);
        for (int j = 0; j < n / 2; j++)
        {
            int k = n - j;

            temp.rgbtRed = image[i][j].rgbtRed;
            temp.rgbtGreen = image[i][j].rgbtGreen;
            temp.rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][k - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][k - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][k - 1].rgbtBlue;

            image[i][k - 1].rgbtRed = temp.rgbtRed;
            image[i][k - 1].rgbtGreen = temp.rgbtGreen;
            image[i][k - 1].rgbtBlue = temp.rgbtBlue;

        }
    }

    return;
}






//
//

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float sumblue;
    float sumgreen;
    float sumred;

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sumblue = 0.0;
            sumgreen = 0.0;
            sumred = 0.0;
            
            for (int row = i - 1 ; row <= i + 1 ; row++)
            {
                for (int col = j - 1 ; col <= j + 1 ; col++)
                {
                    if (row < 0 || row > (height - 1))
                    {
                        continue;
                    }
                    
                    if (col < 0 || col > (width - 1))
                    {
                        continue;
                    }
                    
                    sumblue += image[row][col].rgbtBlue;
                    sumgreen += image[row][col].rgbtGreen;
                    sumred += image[row][col].rgbtRed;
                }
            }
           
            if ((i == 0 && j == 0) || (i == (height - 1) && j == (width - 1)) || (i == 0 && j == (width - 1)) || (i == (height - 1) && j == 0))
            {
                temp[i][j].rgbtBlue = round(sumblue / 4);
                temp[i][j].rgbtGreen = round(sumgreen / 4);
                temp[i][j].rgbtRed = round(sumred / 4);
            }
            else if ((i > 0 && i < (height - 1) && j == 0) || (i > 0 && i < (height - 1) && j == (width - 1)) || (j > 0 && j < (width - 1) 
                     && i == 0) || (j > 0 && j < (width - 1) && i == (height - 1)))
            {
                temp[i][j].rgbtBlue = round(sumblue / 6);
                temp[i][j].rgbtGreen = round(sumgreen / 6);
                temp[i][j].rgbtRed = round(sumred / 6);
            }
            else
            {
                temp[i][j].rgbtBlue = round(sumblue / 9);
                temp[i][j].rgbtGreen = round(sumgreen / 9);
                temp[i][j].rgbtRed = round(sumred / 9);
            }

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;

        }
    }

    return;
}



//
//
//
//
//
//
//


// Detect edges
// Sobel operator
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    // Declaring gx and gy kernels
    int gxArray[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gyArray[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE edgeImage[height][width];

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            float gxRed = 0, gxGreen = 0, gxBlue = 0;
            float gyRed = 0, gyGreen = 0, gyBlue = 0;

            for (int row = i - 1 ; row <= i + 1 ; row++)
            {
                for (int col = j - 1 ; col <= j + 1 ; col++)
                {
                    if (row < 0 || row > (height - 1) || col < 0 || col > (width - 1))
                    {
                        continue;
                    }

                    gxRed += image[row][col].rgbtRed * gxArray[row - (i - 1)][col - (j - 1)];
                    gxGreen += image[row][col].rgbtGreen * gxArray[row - (i - 1)][col - (j - 1)];
                    gxBlue += image[row][col].rgbtBlue * gxArray[row - (i - 1)][col - (j - 1)];

                    gyRed += image[row][col].rgbtRed * gyArray[row - (i - 1)][col - (j - 1)];
                    gyGreen += image[row][col].rgbtGreen * gyArray[row - (i - 1)][col - (j - 1)];
                    gyBlue += image[row][col].rgbtBlue * gyArray[row - (i - 1)][col - (j - 1)];

                }
            }

            int red = round(sqrt((gxRed * gxRed) + (gyRed * gyRed)));
            int green = round(sqrt((gxGreen * gxGreen) + (gyGreen * gyGreen)));
            int blue = round(sqrt((gxBlue * gxBlue) + (gyBlue * gyBlue)));


            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            edgeImage[i][j].rgbtRed = red;
            edgeImage[i][j].rgbtGreen = green;
            edgeImage[i][j].rgbtBlue = blue;
        }
    }


    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            image[i][j] = edgeImage[i][j];
        }
    }

    return;
}
//
//