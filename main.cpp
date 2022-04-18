/*
FCAI – Programming 1 – 2022 - Assignment 3 - Part 2
Group: S13
Author1 and ID: Seif Yahia - 20210172
Author2 and ID: Mohamed Amgad - 20210330
Author3 and ID: Omar Elgammal - 20210271
Program Name: Bitmap Filters
Last Modification Date: 17 April 2022
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
#include "20210330.h"
#include "20210271.h"
#include "20210172.h"

using namespace std;

// Functions prototype
void load_image();
void save_image();

// Main function to start the program
int main(){
    string choice, decision;
    cout << "Welcome to the bitmap filters program!\n";

    // Import the image from user to work on
    load_image();

    // Output the menu to the user
    cout << "The program can apply the following filters to bitmap grayscale images:\n"
            "1. Black & White\n2. Invert Image\n"
            "3. Merge Two Images\n4. Flip Image\n"
            "5. Darken or Lighten Image\n6. Rotate Image\n"
            "8. Enlarge Image\n9. Shrink Image\n10. Mirror Image\n"
            "s. Save Image to a new file\n0. Exit\n";

    // Check the input of the user and reject bad inputs
    while(choice != "0"){
        cout << "Choose one of the above filters to apply or 0 to EXIT: ";
        cin >> choice;
        if(choice == "1"){
            black_white();
        }
        else if(choice == "2"){
            invert_image();
        }
        else if(choice == "3"){
            merge_image();
        }
        else if(choice == "4"){
            flip_image();
        }
        else if(choice == "5"){
            darken_lighten();
        }
        else if(choice == "6"){
            rotate_image();
        }
        else if(choice == "8"){
            enlarge_image();
        }
        else if(choice == "9"){
            shrink_image();
        }
        else if (choice == "10")
        {
            mirror();
        }
        else if(choice == "s"){
            save_image();
        }
        else if(choice == "0"){
            cout << "Do you want to save? (y/n) ";
            cin >> decision;
            if(decision == "y"){
                save_image();
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
void load_image(){
    char imageFileName[100];
    // Get grayscale file name
    cout << "Please enter the grayscale source image file name: ";
    cin >> imageFileName;
    // Concatenate the extension of bitmap with file name
    strcat(imageFileName, ".bmp");
    // Read contents of the bitmap into a 2D array/matrix
    readGSBMP(imageFileName, image);
}

// Save the new image after changes
void save_image(){
    char imageFileName[100];
    // Get the new file name to be saved
    cout << "Enter the output image file name: ";
    cin >> imageFileName;
    // Concatenate the extension of bitmap with file name
    strcat(imageFileName, ".bmp");
    // Write contents of the bitmap into a new file
    writeGSBMP(imageFileName, image);
    // Output a message to the user to confirm the saving proccess
    cout << "Image was saved successfully as \"" << imageFileName << "\"\n";
}
