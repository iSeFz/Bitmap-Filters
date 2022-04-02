/* 
Authors: Seif Yahia - Mohamed Amgad - Omar Elgammal
Program Name: Bitmap Filters
Last Modification Date: 2 April 2022
Version: 1.1
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();
void mergeImage();

int main()
{
    char choice[20];
    cout << "Welcome to the bitmap filters program!\n";
    // Import the image from user to work on
    // loadImage();
    cout << "Choose one of the following filters to apply or \"0\" to exit:\n"
            "1. Black & White filter\n2. Invert filter\n3. Merge filter\n"
            "4. Flip Image\n5. Darken or Lighten Image\n6. Rotate Image\n"
            "7. Detect Image Edges\n8. Enlarge Image\n9. Shrink Image\n"
            "a. Mirror 1/2 Image\nb. Shuffle Image\nc. Blur Image\n"
            "s. Save Image to a new file\n0. Exit\n";
    // cin >> choice;
    // Export the image if the user wants to
    // saveImage();
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
    unsigned char first, second;
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
            first = image[i][j];
            second = mergedImage[i][j];
            // Gets the mean between the values of pixels
            // of the original and the image to merge
            image[i][j] = (first + second) / 2;
        }
    }
    cout << "Two images merged successfully!\n";
}