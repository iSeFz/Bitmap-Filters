/* 
Authors: Seif Yahia - Mohamed Amgad - Omar Elgammal
Program Name: Bitmap Filters
Last Modification Date: 3 April 2022
Version: 1.2
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];

void loadImage();
void saveImage();
void mergeImage();
void darkenLighten();

int main()
{
    cout << "Welcome to the bitmap filters program!\n";
    /*
    // Import the image from user to work on
    loadImage();
    cout << "Choose one of the following filters to apply or \"0\" to exit:\n"
            "1. Black & White filter\n2. Invert filter\n3. Merge filter\n"
            "4. Flip Image\n5. Darken or Lighten Image\n6. Rotate Image\n"
            "7. Detect Image Edges\n8. Enlarge Image\n9. Shrink Image\n"
            "a. Mirror 1/2 Image\nb. Shuffle Image\nc. Blur Image\n"
            "s. Save Image to a new file\n0. Exit\n";
    char choice;
    cin >> choice;
    // Export the image if the user wants to
    saveImage();
    */
}

// Load file name and contents of the image
void loadImage()
{
    char imageFileName[100];
    // Get greyscale file name
    cout << "Please enter the source image file name: ";
    cin >> imageFileName;
    // Concatenate the extention of bitmap with file name
    strcat(imageFileName, ".bmp");
    // Read contents of the bitmap into a 2D array/matrix
    readGSBMP(imageFileName, image);
}

// Save the new image after changes
void saveImage()
{
    char imageFileName[100];
    // Get the new file name to be saved
    cout << "Enter the output image file name: ";
    cin >> imageFileName;
    // Concatenate the extention of bitmap with file name
    strcat(imageFileName, ".bmp");
    // Write contents of the bitmap into a new file
    writeGSBMP(imageFileName, image);
}

// Merge filter to merge two photos together
void mergeImage()
{
    char imageToMerge[100];
    unsigned char mergedImage[SIZE][SIZE];
    // Get the file name to merge with the original image
    cout << "Please enter image file name to merge with: ";
    cin >> imageToMerge;
    // Concatenate the extention of bitmap with file name
    strcat(imageToMerge, ".bmp");
    // Read contents of the bitmap into a 2D array/matrix
    readGSBMP(imageToMerge, mergedImage);
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            // Gets the mean between the values of pixels
            // of the original and the image to merge
            image[i][j] = (image[i][j] + mergedImage[i][j]) / 2;
        }
    }
    cout << "Two images merged successfully!\n";
}

// Darken or Lighten the image by 50%
void darkenLighten()
{
    char choice;
    unsigned char darken[SIZE][SIZE];
    unsigned char lighten[SIZE][SIZE];
    cout << "Do you want to (D)arken or (L)ighten the image? ";
    cin >> choice;
    // Darken the image
    if(choice == 'D')
    {
        for(int i = 0; i < SIZE; ++i)
        {
            for(int j = 0; j < SIZE; ++j)
            {
                darken[i][j] = 0;
                image[i][j] = (image[i][j] + darken[i][j]) / 2;
            }
        }
        cout << "Darken filter was applied successfully!\n";
    }
    // Lighten the image
    else if(choice == 'L')
    {
        for(int i = 0; i < SIZE; ++i)
        {
            for(int j = 0; j < SIZE; ++j)
            {
                lighten[i][j] = 255;
                image[i][j] = (image[i][j] + lighten[i][j]) / 2;
            }
        }
        cout << "Lighten filter was applied successfully!\n";
    }
    else
    {
        cout << "Enter only either \"D\" or \"L\"\n";
        darkenLighten();
    }
}
