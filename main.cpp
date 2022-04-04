/*
Authors: Seif Yahia - Mohamed Amgad - Omar Elgammal
Program Name: Bitmap Filters
Last Modification Date: 4 April 2022
Version: 1.2
*/

// Including necessary libraries:
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

// Assigning a global 2d Array for image
unsigned char image[SIZE][SIZE];

// Functions prototype:
void loadImage();
void saveImage();
void mergeImage();
void darkenLighten();
void invertImage();
void rotateImage();
void black_white();
void horizontal_flip();
void vertical_flip();

int main()
{
    cout << "Welcome to the bitmap filters program!\n";

    // Import the image from user to work on
    loadImage();
    cout << "Choose one of the following filters to apply or \"0\" to exit:\n"
            "1. Black & White filter\n2. Invert Image\n3. Merge filter\n"
            "4. Flip Image\n5. Darken or Lighten Image\n6. Rotate Image\n"
            "7. Detect Image Edges\n8. Enlarge Image\n9. Shrink Image\n"
            "a. Mirror 1/2 Image\nb. Shuffle Image\nc. Blur Image\n"
            "s. Save Image to a new file\n0. Exit\n";
    char choice;
    cin >> choice;

    // Export the image if the user wants to
    saveImage();

}

// Load file name and contents of the image
void loadImage()
{
    char imageFileName[100];
    // Get greyscale file name
    cout << "Please enter the source image file name: ";
    cin >> imageFileName;
    // Concatenate the extension of bitmap with file name
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
    // Concatenate the extension of bitmap with file name
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
    // Concatenate the extension of bitmap with file name
    strcat(imageToMerge, ".bmp");
    // Read contents of the bitmap into a 2D array/imagerix
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

// Function that inverts image colour
void invertImage()
{
    // iterates on each pixel and inverts its colour
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
    cout << "Invert Image filter was applied successfully!" << endl;
}

// Function that rotates image clockwise
void rotateImage()
{
    // initializing empty array to use for rotation
    char temp[SIZE][SIZE];
    // initializing user input variables
    string input;
    int nRotations = 0;

    // loop to take amount of rotation from user and to make sure input is correct
    while(!nRotations)
    {
        cout << "Enter the amount of rotation (90, 180, 270):";
        cin>>input;
        if(input == "90")
            nRotations = 1;
        else if(input == "180")
            nRotations = 2;
        else if(input == "270")
            nRotations = 3;
        else
            cout<<"Invalid input! Please enter 90 or 180 or 270.\n";
    }

    // loop that does n cycles (a clockwise 90 degrees in each cycle)
    while(nRotations)
    {
        // nested loops to assign temporary array
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                temp[i][j] = image[i][j];
            }
        }

        // loop that iterates on each pixel in temp and puts it back into main image in its new location to rotate
        for(int i = 0, jnew = SIZE - 1; i < SIZE;i++,jnew--)
        {
            for(int j = 0, inew = 0; j < SIZE; inew++,j++)
            {
                image[inew][jnew] = temp[i][j];
            }
        }

        nRotations--;
    }
}
//convert image into black and white image
void black_white()
{
    long avg = 0;
    //iterate on each pixel to collect the sum of pixels values
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {

            avg += image[i][j];

        }
    }
    //get average of values of pixels
    avg /= (SIZE*SIZE);
    //turn image into black and white
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //pixel that has value greater than avg turn into white
            if (image[i][j] > avg)
            {
                image[i][j] = 255;
            }
            //pixel that has value greater than avg turn into black
            else
            {
                image[i][j] = 0;
            }
        }
    }

}
// flip image horizontally
void horizontal_flip()
{
    //iterate on half number of pixels and swap them horizontally
    for(int i=0;i<SIZE/2;++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            swap(image[i][j],image[(SIZE - 1) - i][j]);
            
        }
        
    }
}
// flip image vertically
void vertical_flip()
{
    //iterate on half number of pixels and swap them vertically
    for(int i=0;i<SIZE;++i)
    {
        for (int j = 0; j < SIZE/2; ++j)
        {
            swap(image[i][j],image[i][(SIZE - 1) - j]);
            
        }
        
    }
}


