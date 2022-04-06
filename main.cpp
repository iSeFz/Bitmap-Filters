/*
Authors: Seif Yahia - Mohamed Amgad - Omar Elgammal
Program Name: Bitmap Filters
Last Modification Date: 5 April 2022
Version: 1.6
*/

// Including necessary libraries
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include "bmplib.cpp"

using namespace std;

// Declaring a global 2D array for image
unsigned char image[SIZE][SIZE];

// Functions prototype
void loadImage();
void saveImage();
void mergeImage();
void darkenLighten();
void invertImage();
void rotateImage();
void black_white();
void flip();

// Main function to start the program
int main()
{
    string choice;
    cout << "Welcome to the bitmap filters program!\n";
    // Import the image from user to work on
    loadImage();
    // Output the menu to the user
    cout << "The program can apply the following filters to bitmap greyscale images:\n"
            "1. Merge Two Images\n2. Darken or Lighten Image\n"
            "3. Invert Image\n4. Rotate Image\n"
            "5. Black and white filter\n6. Horizontal or Vertical flip\n"
            "s. Save Image to a new file\n0. Exit\n";
    // Check the input of the user and reject bad inputs
    while(choice != "0")
    {
        cout << "Choose one of the above filters to apply or 0 to EXIT: ";
        cin >> choice;
        if(choice == "1")
            { mergeImage(); }
        else if(choice == "2")
            { darkenLighten(); }
        else if(choice == "3")
            { invertImage(); }
        else if(choice == "4")
            { rotateImage(); }
        else if(choice == "5")
            { black_white(); }
        else if(choice == "6")
            { flip(); }
        else if(choice == "s")
            { saveImage(); }
        else if(choice == "0")
            { break; }
        else
            { cout << "INVALID INPUT!!\n"; }
    }
    cout << "Thank you for using the bitmap filters program!\n";
    return 0;
}

// Load file name and contents of the image
void loadImage()
{
    char imageFileName[100];
    // Get greyscale file name
    cout << "Please enter the greyscale source image file name: ";
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
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j)
            // Gets the average between the values of pixels
            // of the original and the image to merge
            { image[i][j] = (image[i][j] + mergedImage[i][j]) / 2; }
    }
    cout << "Two images merged successfully!\n";
}

// Darken or Lighten the image by 50%
void darkenLighten()
{
    string choice;
    int filter;

    cout << "Do you want to (D)arken or (L)ighten the image? ";
    cin >> choice;
    // Darken the image by merging it with a black image
    if(choice == "D"){
        filter = 0;
        cout << "Darken filter was applied successfully!\n";
    }
    // Lighten the image by merging it with a white image
    else if(choice == "L"){
        filter = 255;
        cout << "Lighten filter was applied successfully!\n";
    }
    else{
        cout << "Enter only either \"D\" or \"L\"\n";
        darkenLighten();
    }
    // Iterate over every pixel and merge it with black/white pixel
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j)
            { image[i][j] = (image[i][j] + filter) / 2; }
    }
}

// Function that inverts image colour
void invertImage()
{
    // Iterates on each pixel and inverts its colour
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j)
            { image[i][j] = 255 - image[i][j]; }
    }
    cout << "Invert Image filter was applied successfully!\n";
}

// Function that rotates image anticlockwise
void rotateImage()
{
    // Initializing empty array to use for rotation
    unsigned char temp[SIZE][SIZE];
    // Initializing user input variables
    string input;
    int nRotations = 0;

    // Loop to take amount of rotation from user and to make sure input is correct
    while(!nRotations)
    {
        cout << "Enter the amount of rotation (90, 180, 270): ";
        cin >> input;
        if(input == "90")
            { nRotations = 3; }
        else if(input == "180")
            { nRotations = 2; }
        else if(input == "270")
            { nRotations = 1; }
        else
            { cout << "Invalid input! Please enter 90 or 180 or 270.\n"; }
    }

    // Loop that does n cycles (anticlockwise 90 degrees in each cycle)
    while(nRotations)
    {
        // Nested loops to assign temporary array
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++)
                { temp[i][j] = image[i][j]; }
        }
        // Loop that iterates on each pixel in temp
        // and puts it back into main image in its new location to rotate
        for(int i = 0, jnew = SIZE - 1; i < SIZE; i++, jnew--){
            for(int j = 0, inew = 0; j < SIZE; inew++, j++)
                { image[inew][jnew] = temp[i][j]; }
        }
        nRotations--;
    }
    cout << "Image rotated successfully!\n";
}

// Convert image into black and white image
void black_white()
{
    long avg = 0;
    // Iterate on each pixel to collect the sum of pixels values
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j)
            { avg += image[i][j]; }
    }
    // Get average of values of pixels
    avg /= (SIZE * SIZE);
    // Turn image into black and white
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            // Pixel that has value greater than avg turn into white
            if (image[i][j] > avg)
                { image[i][j] = 255; }
            // Pixel that has value smaller than avg turn into black
            else
                { image[i][j] = 0; }
        }
    }
    cout << "Black and white filter applied to the image successfully!\n";
}

// Flip image horizontally or vertically
void flip()
{
    string choice;
    cout << "Do you want to flip (H)orizontally or (V)ertically? ";
    cin >> choice;

    if(choice == "V"){
        // Iterate on half number of pixels and swap them vertically
        for(int i = 0; i < SIZE / 2; ++i){
            for (int j = 0; j < SIZE; ++j)
                { swap(image[i][j], image[(SIZE - 1) - i][j]); }
        }
        cout << "Image flipped vertically!\n";
    }
    else if(choice == "H"){
        // Iterate on half number of pixels and swap them horizontally
        for(int i = 0; i < SIZE; ++i){
            for (int j = 0; j < SIZE / 2; ++j)
                { swap(image[i][j], image[i][(SIZE - 1) - j]); }
        }
        cout << "Image flipped horizontally!\n";
    }
    else{
        cout << "Enter ONlY \"H\" or \"V\"\n";
        flip();
    }
}
