// Author: Seif Yahia - 20210172

// Filter #3 - Merge filter to merge two photos together
void merge_image(){
    char imageToMerge[100];
    unsigned char mergedImage[SIZE][SIZE];
    // Get the file name to merge with the original image
    cout << "Please enter image file name to merge with: ";
    cin >> imageToMerge;
    // Concatenate the extension of bitmap with file name
    strcat(imageToMerge, ".bmp");
    // Read contents of the bitmap into a 2D array/imagerix
    readGSBMP(imageToMerge, mergedImage);
    // Nested loops that get the average between the values of pixels
    // of the original and the image to merge
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            image[i][j] = (image[i][j] + mergedImage[i][j]) / 2;
        }
    }
    cout << "Two images merged successfully!\n";
}

// Filter #5 - Darken or Lighten the image by 50%
void darken_lighten(){
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
        darken_lighten();
    }
    // Iterate over every pixel and merge it with black/white pixel
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            image[i][j] = (image[i][j] + filter) / 2;
        }
    }
}

// Filter #9 - Shrink filter to shrink image to 1/2, 1/3 or 1/4
void shrink_image(){
    string choice;
    int amount;
    unsigned char temp;
    cout << "Shrink to (1/2), (1/3) or (1/4)? ";
    cin >> choice;
    // Check the inputs of the user and reject bad inputs
    if(choice == "1/2"){
        amount = 2;
        cout << "Image shrinked to 1/2 successfully!\n";
    }
    else if(choice == "1/3"){
        amount = 3;
        cout << "Image shrinked to 1/3 successfully!\n";
    }
    else if(choice == "1/4"){
        amount = 4;
        cout << "Image shrinked to 1/4 successfully!\n";
    }
    else{
        cout << "INVALID INPUT!!\n";
        shrink_image();
    }
    // Iterate over every pixel and write the new pixels
    // in the new dimensions according to the amount of shrink
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            temp = image[i][j];
            image[i][j] = 255;
            image[i / amount][j / amount] = temp;
        }
    }
}

// Filter #c - Convert the image into its blurred version
void blur_image(){
    long avg;
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            avg = // Gets the average of a 7x7 matrix of neighboring pixels
            image[i][j] + image[i][j - 1] + image[i][j - 2] + image[i][j - 3] +
            image[i][j + 1] + image[i][j + 2] + image[i][j + 3] +
            image[i - 1][j] + image[i - 1][j - 1] + image[i - 1][j - 2] + image[i - 1][j - 3] +
            image[i - 1][j + 1] + image[i - 1][j + 2] + image[i - 1][j + 3] +
            image[i - 2][j] + image[i - 2][j - 1] + image[i - 2][j - 2] + image[i - 2][j - 3] +
            image[i - 2][j + 1] + image[i - 2][j + 2] + image[i - 2][j + 3] +
            image[i - 3][j] + image[i - 3][j - 1] + image[i - 3][j - 2] + image[i - 3][j - 3] +
            image[i - 3][j + 1] + image[i - 3][j + 2] + image[i - 3][j + 3] +
            image[i + 1][j] + image[i + 1][j - 1] + image[i + 1][j - 2] + image[i + 1][j - 3] +
            image[i + 1][j + 1] + image[i + 1][j + 2] + image[i + 1][j + 3] +
            image[i + 2][j] + image[i + 2][j - 1] + image[i + 2][j - 2] + image[i + 2][j - 3] +
            image[i + 2][j + 1] + image[i + 2][j + 2] + image[i + 2][j + 3] +
            image[i + 3][j] + image[i + 3][j - 1] + image[i + 3][j - 2] + image[i + 3][j - 3] +
            image[i + 3][j + 1] + image[i + 3][j + 2] + image[i + 3][j + 3];
            // Write the average into the current pixel
            image[i][j] = avg / 49;
        }
    }
    cout << "Image blurred successfully!\n";
}
