#ifndef BMPLIB_H
#define BMPLIB_H

const int SIZE = 256;
const int RGB = 3;

// Declaring a global 2D array for image
unsigned char image[SIZE][SIZE];

// Declaring a global 3D array for image
unsigned char imageRGB[SIZE][SIZE][RGB];

// read full-color image from the file specified by filename, into inputImage
int readRGBBMP(const char* filename, unsigned char inputImage[][SIZE][RGB]);

// write full-color image to the file specified by filename, from outputImage
int writeRGBBMP(const char* filename, unsigned char outputImage[][SIZE][RGB]);

// read grayscale image from the file specified by filename, into inputImage
int readGSBMP(const char* filename, unsigned char inputImage[][SIZE]);

// write grayscale image to the file specified by filename, from outputImage
int writeGSBMP(const char* filename, unsigned char outputImage[][SIZE]);

#endif
