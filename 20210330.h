/*
Author: Mohamed Amgad - 20210330
*/

// Filter #1
// Convert image into black and white image
void black_white(){
    long avg = 0;
    // Iterate on each pixel to collect the sum of pixels values
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            avg += image[i][j];
        }
    }

    // Get average of values of pixels
    avg /= (SIZE * SIZE);

    // Turn image into black and white
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            // Pixel that has value greater than avg turn into white
            if (image[i][j] > avg){
                image[i][j] = 255;
            }
            // Pixel that has value smaller than avg turn into black
            else{
                image[i][j] = 0;
            }
        }
    }
    cout << "Black & white filter applied to the image successfully!\n";
}

// Filter #4
// Flip image horizontally or vertically
void flip_image(){
    string choice;
    cout << "Do you want to flip (H)orizontally or (V)ertically? ";
    cin >> choice;

    if(choice == "V"){
        // Iterate on half number of pixels and swap them vertically
        for(int i = 0; i < SIZE / 2; ++i){
            for (int j = 0; j < SIZE; ++j){
                swap(image[i][j], image[(SIZE - 1) - i][j]);
            }
        }
        cout << "Image flipped vertically!\n";
    }
    else if(choice == "H"){
        // Iterate on half number of pixels and swap them horizontally
        for(int i = 0; i < SIZE; ++i){
            for (int j = 0; j < SIZE / 2; ++j){
                swap(image[i][j], image[i][(SIZE - 1) - j]);
            }
        }
        cout << "Image flipped horizontally!\n";
    }
    else{
        cout << "Enter ONlY \"H\" or \"V\"\n";
        flip_image();
    }
}
