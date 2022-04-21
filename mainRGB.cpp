/*
FCAI – Programming 1 – 2022 - Assignment 3 - Part 2
Group: S13
Author1 and ID: Seif Yahia - 20210172
Author2 and ID: Mohamed Amgad - 20210330
Author3 and ID: Omar Elgammal - 20210271
Program Name: Colored Bitmap Filters
Last Modification Date: 20 April 2022
Version: 2.3
*/

// Including necessary libraries
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include "bmplib.cpp"
// Including necessary headers
#include "bmplib.h"
#include "bonusRGB.h"

using namespace std;

// Functions prototype
void loadImage();
void saveImage();

// Declare some variables
string choice, decision,place;

// Main function to start the program
int main(){
    cout << "Welcome to the colored bitmap filters program!\n";

    // Import the image from user to work on
    loadImage();

    // Output the menu to the user
    cout << "The program can apply the following filters to bitmap colored images:\n"
            "1. Black & White\t\t2. Invert Image\n"
            "3. Merge Two Images\t\t4. Flip Image\n"
            "5. Darken or Lighten Image\t6. Rotate Image\n"
            "7. Detect Image Edges\t\t8. Enlarge Image\n"
            "9. Shrink Image\t\t\ta. Mirror 1/2 Image\n"
            "b. Shuffle Image\t\tc. Blur Image\n"
            "s. Save Image to a new file\t0. Exit\n";

    // Check the input of the user and reject bad inputs
    while(choice != "0"){
        cout << "Choose one of the above filters to apply or 0 to EXIT: ";
        cin >> choice;
        if(choice == "1"){
            black_whiteRGB();
        }
        else if(choice == "2"){
            invertRGB();
        }
        else if(choice == "3"){
            mergeRGB();
        }
        else if(choice == "4"){
            flipRGB();
        }
        else if(choice == "5"){
            darkenLightenRGB();
        }
        else if(choice == "6"){
            rotateRGB();
        }
        else if (choice == "7"){
            edge_detectorRGB();
            place = "7";
        }
        else if(choice == "8"){
            enlargeRGB();
        }
        else if(choice == "9"){
            shrinkRGB();
        }
        else if(choice == "a"){
            mirrorRGB();
        }
        else if(choice == "b"){
            shuffleRGB();
        }
        else if(choice == "c"){
            blurRGB();
        }
        else if(choice == "s"){
            saveImage();
        }
        else if(choice == "0"){
            cout << "Do you want to save? (y/n) ";
            cin >> decision;
            if(decision == "y"){
                saveImage();
            }
            else if(decision == "n"){
                break;
            }
        }
        else{
            cout << "INVALID INPUT!!\n";
        }
    }
    cout << "Thank you for using the bitmap filters program!\n";
    return 0;
}

// Load file name and contents of the image
void loadImage(){
    char imageFileName[100];
    // Get RGB file name
    cout << "Please enter the colored source image file name: ";
    cin >> imageFileName;
    // Concatenate the extention of bitmap with file name
    strcat(imageFileName, ".bmp");
    // Read contents of the bitmap into a 3D array/matrix
    readRGBBMP(imageFileName, imageRGB);
}

// Save the new image after changes
void saveImage(){
    char imageFileName[100];
    // Get the new file name to be saved
    cout << "Enter the output image file name: ";
    cin >> imageFileName;
    // Concatenate the extention of bitmap with file name
    strcat(imageFileName, ".bmp");
    if(place == "7"){
        // Write contents of the bitmap into a new file
        writeRGBBMP(imageFileName, result);
    }
    else{
        // Write contents of the bitmap into a new file
        writeRGBBMP(imageFileName, imageRGB);
    }
    // Output a message to the user to confirm the saving proccess
    cout << "Image was saved successfully as \"" << imageFileName << "\"\n";
}
