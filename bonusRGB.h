/*
Authors:
Seif Yahia - 20210172
Mohamed Amgad - 20210330
Omar Elgammal - 20210271
*/

// Filter #1 : Function that turn image into black & white
void blackWhiteRGB(){
    double avg = 0.0;
    long r, g, b;

    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            // Separate rgb chanels and store each value individually
            for (int k = 0; k < RGB; k++){
                if (k == 0){
                    r = imageRGB[i][j][k];
                }
                else if (k == 1){
                    g = imageRGB[i][j][k];
                }
                else{
                    b = imageRGB[i][j][k];
                }
            }
            // Make value of rgb channels similar
            for (int l = 0; l < RGB; l++){
                imageRGB[i][j][l] = round(sqrt((r * 0.2989 + g * 0.5870 + b * 0.1140) / 3));
            }
        }
    }
    // Calculate average of pixels
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            for (int k = 0; k < RGB; k++){
                avg += imageRGB[i][j][k];
            }
        }
    }
    avg /= (SIZE * SIZE * RGB);
    // Turn image into black and white
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            for (int k = 0; k < RGB; ++k){
                // Pixel that has value greater than avg turn into white
                if (imageRGB[i][j][k] > avg){
                    imageRGB[i][j][k] = 255;
                }
                // Pixel that has value greater than avg turn into black
                else{
                    imageRGB[i][j][k] = 0;
                }
            }
        }
    }
    cout << "Black & White filter applied successfully!\n";
}

// Filter #2 : Function that inverts image colour
void invertRGB(){
    // Iterates on each pixel and inverts its color
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            for(int k = 0; k < RGB; ++k){
                // NOT the value of each pixel
                imageRGB[i][j][k] = ~imageRGB[i][j][k];
            }
        }
    }
    cout << "Invert filter was applied successfully!\n";
}

// Filter #3 : Merge filter to merge two colored photos together
void mergeRGB(){
    char imageToMerge[100];
    unsigned char mergedImage[SIZE][SIZE][RGB];
    // Get the file name to merge with the original image
    cout << "Please enter image file name to merge with: ";
    cin >> imageToMerge;
    // Concatenate the extention of bitmap with file name
    strcat(imageToMerge, ".bmp");
    // Read contents of the bitmap into a 3D array/matrix
    readRGBBMP(imageToMerge, mergedImage);
    // Nested loops that get the average between the values of pixels
    // of the original and the image to merge
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            for(int k = 0; k < RGB; ++k){
                imageRGB[i][j][k] = (imageRGB[i][j][k] + mergedImage[i][j][k]) / 2;
            }
        }
    }
    cout << "Two images merged successfully!\n";
}

// Filter #4 - Flip image horizontally or vertically
void flipRGB(){
    string choice;
    cout << "Do you want to flip (H)orizontally or (V)ertically? ";
    cin >> choice;

    if(choice == "V"){
        // Iterate on half number of pixels and swap them vertically
        for(int i = 0; i < SIZE / 2; ++i){
            for (int j = 0; j < SIZE; ++j){
                for(int k = 0; k < RGB; ++k){
                    swap(imageRGB[i][j][k], imageRGB[(SIZE - 1) - i][j][k]);
                }
            }
        }
        cout << "Image flipped vertically!\n";
    }
    else if(choice == "H"){
        // Iterate on half number of pixels and swap them horizontally
        for(int i = 0; i < SIZE; ++i){
            for (int j = 0; j < SIZE / 2; ++j){
                for(int k = 0; k < RGB; ++k){
                    swap(imageRGB[i][j][k], imageRGB[i][(SIZE - 1) - j][k]);
                }
            }
        }
        cout << "Image flipped horizontally!\n";
    }
    else{
        cout << "Enter ONlY \"H\" or \"V\"\n";
        flipRGB();
    }
}

// Filter #5 : Darken or Lighten the image by 50%
void darkenLightenRGB(){
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
        darkenLightenRGB();
    }
    // Iterate over every pixel and merge it with black/white pixel
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            for(int k = 0; k < RGB; ++k){
                imageRGB[i][j][k] = (imageRGB[i][j][k] + filter) / 2;
            }
        }
    }
}

// Filter #6 : Function that rotates image anticlockwise
void rotateRGB(){
    // Initializing empty array to use for rotation
    unsigned char temp[SIZE][SIZE][RGB];
    // Initializing user input variables
    string input;
    int nRotations = 0;
    // Loop to take amount of rotation from user and to make sure input is correct
    while(!nRotations){
        cout << "Enter the amount of rotation (90, 180, 270): ";
        cin >> input;
        if(input == "90"){
            nRotations = 3;
        }
        else if(input == "180"){
            nRotations = 2;
        }
        else if(input == "270"){
            nRotations = 1;
        }
        else{
            cout << "Invalid input! Please enter 90 or 180 or 270.\n";
        }
    }
    // Loop that does n cycles (anticlockwise 90 degrees in each cycle)
    while(nRotations){
        // Nested loops to assign temporary array
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                for(int k = 0; k < RGB; ++k){
                    temp[i][j][k] = imageRGB[i][j][k];
                }
            }
        }
        // Loop that iterates on each pixel in temp
        // and puts it back into main image in its new location to rotate
        for(int i = 0, jnew = SIZE - 1; i < SIZE; i++, jnew--){
            for(int j = 0, inew = 0; j < SIZE; inew++, j++){
                for(int k = 0; k < RGB; ++k){
                    imageRGB[inew][jnew][k] = temp[i][j][k];
                }
            }
        }
        nRotations--;
    }
    cout << "Image rotated by " << input << " degrees successfully!\n";
}

// Filter #7 : Detect image edges
void edgeDetectRGB(){
    int Gx, Gy, avg;
    long r, g, b;
    double threshold = 0.0;
    int kernal_x[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    int kernal_y[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            // Separate rgb channels and collect each value individually
            for(int k = 0; k < RGB; k++){
                if(k == 0){
                    r = imageRGB[i][j][k];
                }
                else if(k == 1){
                    g = imageRGB[i][j][k];

                }
                else{
                    b = imageRGB[i][j][k];
                }
            }
            // Make value of rgb channels similar
            for (int l = 0; l < RGB; l++){
                imageRGB[i][j][l] = round(sqrt((r * 0.2989 + g * 0.5870 + b * 0.1140) / 3));
            }
        }
    }
    for(int i = 1, k = 0; i < SIZE - 1 && k < SIZE - 2; i++, k++){
        for(int j = 1, l = 0; j < SIZE - 1 && l < SIZE - 2; j++, l++){
            for(int m = 0; m < RGB; m++){
                // Calculate change in x
                Gx = imageRGB[i][j][m] * kernal_x[1][1] + imageRGB[i][j - 1][m] * kernal_x[1][0] +
                    imageRGB[i][j + 1][m] * kernal_x[1][2] +
                    imageRGB[i - 1][j - 1][m] * kernal_x[0][0] +
                    imageRGB[i - 1][j][m] * kernal_x[0][1] +
                    imageRGB[i - 1][j + 1][m] * kernal_x[0][2] +
                    imageRGB[i + 1][j - 1][m] * kernal_x[2][0] +
                    imageRGB[i + 1][j][m] * kernal_x[2][1] +
                    imageRGB[i + 1][j + 1][m] * kernal_x[2][2];
                // Calculate change in y
                Gy = imageRGB[i][j][m] * kernal_y[1][1] + imageRGB[i][j - 1][m] * kernal_y[1][0] +
                    imageRGB[i][j + 1][m] * kernal_y[1][2] +
                    imageRGB[i - 1][j - 1][m] * kernal_y[0][0] +
                    imageRGB[i - 1][j][m] * kernal_y[0][1] +
                    imageRGB[i - 1][j + 1][m] * kernal_y[0][2] +
                    imageRGB[i + 1][j - 1][m] * kernal_y[2][0] +
                    imageRGB[i + 1][j][m] * kernal_y[2][1] +
                    imageRGB[i + 1][j + 1][m] * kernal_y[2][2];
                threshold += lround(sqrt(Gx * Gx + Gy * Gy));
                imageRGB[k][l][m] = lround(sqrt(Gx * Gx + Gy * Gy));
            }
        }
    }
    // Get the average of summation of changes in x and y
    avg = lround(threshold / (SIZE * SIZE));
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int m = 0; m < RGB; m++){
                // Value greater than avg turn it into black
                if(imageRGB[i][j][m] > avg){
                    imageRGB[i][j][m] = 0;
                }
                // Value smaller than avg turn it into white
                else{
                    imageRGB[i][j][m] = 255;
                }
            }
        }
    }
    cout << "Edges detected successfully!\n";
}

// Filter #8 - Enlarge filter to enlarge any quarter of the images
void enlargeRGB(){
    // Initializing temporary image array
    unsigned char temp[SIZE][SIZE][RGB];
    // Copying original image to temporary array
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for(int k = 0; k < RGB; k++){
                temp[i][j][k] = imageRGB[i][j][k];
            }
        }
    }
    // Initializing user input variables
    string input;
    int correct = 0;
    // Loop that takes input from user 
    // and sets up the iterator variables accordinng to user's choice
    int i_str_temp, j_str_temp;
    while(!correct){
        cout << "Please choose which quarter you would like to enlarge (1, 2, 3, 4): ";
        cin >> input;
        if (input == "1"){
            i_str_temp = 0, 
            j_str_temp = 0;
        }
        else if (input == "2"){
            i_str_temp = 0, 
            j_str_temp = 128;
        }
        else if (input == "3"){
            i_str_temp = 128, 
            j_str_temp = 0;
        }
        else if (input == "4"){
            i_str_temp = 128, 
            j_str_temp = 128;
        }
        else{
            cout << "Invalid input! Please enter a number from 1 to 4.\n";
            continue;
        }
        correct++;
    }
    // Copying the quarter from the temporary image to the original image but enlarged
    for(int i = 0, i_quarter = i_str_temp; i < SIZE; i += 2, i_quarter++){
        for(int j = 0, j_quarter = j_str_temp; j < SIZE; j += 2, j_quarter++){
            for(int k = 0; k < RGB; ++k){
                imageRGB[i][j][k] = imageRGB[i + 1][j][k] = imageRGB[i][j + 1][k]
                = imageRGB[i + 1][j + 1][k] = temp[i_quarter][j_quarter][k];
            }
        }
    }
    cout << "Image enlarged successfully!\n";
}

// Filter #9 : Shrink filter to shrink image to 1/2, 1/3 or 1/4
void shrinkRGB(){
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
        shrinkRGB();
    }
    // Iterate over every pixel and write the new pixels
    // in the new dimensions according to the amount of shrink
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            for(int k = 0; k < RGB; ++k){
                temp = imageRGB[i][j][k];
                imageRGB[i][j][k] = 255;
                imageRGB[i / amount][j / amount][k] = temp;
            }
        }
    }
}

// Filter #a - Mirror image left or right or up or down
void mirrorRGB(){
    string choice = "";
    cout << "Do you want to Mirror (l)eft, (r)ight, (u)pper or (d)own side? ";
    cin >> choice;
    // iterate on each pixel
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            for(int k = 0; k < RGB; ++k){
                if (choice == "r"){
                    // make right side equal to left
                    imageRGB[i][(SIZE - 1) - j][k] = imageRGB[i][j][k];
                }
                else if (choice == "l"){
                    // make left side equal to right
                    imageRGB[i][j][k] = imageRGB[i][(SIZE - 1) - j][k];
                }
                else if (choice == "u"){
                    // make upper side equal to lower side
                    imageRGB[i][j][k] = imageRGB[(SIZE - 1) - i][j][k];
                }
                else if (choice == "d"){
                    // make lower side equal to upper side
                    imageRGB[(SIZE - 1) - i][j][k] = imageRGB[i][j][k];
                }
            }
        }
    }
    cout << "Mirror filter applied to the image successfully!\n";
}

// Filter #b - Shuffle quarters of image
void shuffleRGB(){
    // Initializing temporary image array
    unsigned char temp[SIZE][SIZE][RGB];
    // Copying original image to temporary array
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            for(int k = 0; k < RGB; k++){
                temp[i][j][k] = imageRGB[i][j][k];
            }
        }
    }
    // Initializing user input variables
    string input[4];
    int correct = 0;
    // Loop that takes input from user 
    // and checks if input is correct
    int i_str_temp, j_str_temp, i_str_original, j_str_original;
    while(!correct){
        cout << "Please enter the order of quarters in the new image\n(4 space separated numbers from 1 to 4): ";
        for (int i = 0; i < 4; i++){
            cin >> input[i];
        }    
        correct = 1;
        for(int i = 0; i < 4; i++){
            if(!(input[i] == "1" || input[i] == "2" || input[i] == "3" || input[i] == "4")){
                correct = 0;
            }
        }
        if(!correct){
            cout << "Invalid input! Input example: 4 2 1 3\n";
        }
    }
    for(int i = 0; i < 4; i++){
        if (input[i] == "1"){
            i_str_temp = 0, 
            j_str_temp = 0;
        }
        else if (input[i] == "2"){
            i_str_temp = 0,
            j_str_temp = 128;
        }
        else if (input[i] == "3"){
            i_str_temp = 128,
            j_str_temp = 0;
        }
        else if (input[i] == "4"){
            i_str_temp = 128,
            j_str_temp = 128;
        }
        if (i == 0){
            i_str_original = 0, 
            j_str_original = 0;
        }
        else if (i == 1){
            i_str_original = 0,
            j_str_original = 128;
        }
        else if (i == 2){
            i_str_original = 128,
            j_str_original = 0;
        }
        else if (i == 3){
            i_str_original = 128,
            j_str_original = 128;
        }
        for(int i_origin = i_str_original, i_temp = i_str_temp; i_origin < i_str_original + 128; i_origin++, i_temp++){
            for(int j_origin = j_str_original, j_temp = j_str_temp; j_origin < j_str_original + 128; j_origin++, j_temp++){
                for(int k = 0; k < RGB; k++){
                    imageRGB[i_origin][j_origin][k] = temp[i_temp][j_temp][k];
                }
            }
        }
    }
    cout << "Image shuffled successfully!\n";
}

// Filter #c - Convert the image into its blurred version
void blurRGB(){
    long avg;
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            for(int k = 0; k < RGB; ++k){
                avg = // Gets the average of a 7x7 matrix of neighboring pixels
                imageRGB[i][j][k] + imageRGB[i][j - 1][k] + imageRGB[i][j - 2][k] + imageRGB[i][j - 3][k] +
                imageRGB[i][j + 1][k] + imageRGB[i][j + 2][k] + imageRGB[i][j + 3][k] +
                imageRGB[i - 1][j][k] + imageRGB[i - 1][j - 1][k] + imageRGB[i - 1][j - 2][k] + imageRGB[i - 1][j - 3][k] +
                imageRGB[i - 1][j + 1][k] + imageRGB[i - 1][j + 2][k] + imageRGB[i - 1][j + 3][k] +
                imageRGB[i - 2][j][k] + imageRGB[i - 2][j - 1][k] + imageRGB[i - 2][j - 2][k] + imageRGB[i - 2][j - 3][k] +
                imageRGB[i - 2][j + 1][k] + imageRGB[i - 2][j + 2][k] + imageRGB[i - 2][j + 3][k] +
                imageRGB[i - 3][j][k] + imageRGB[i - 3][j - 1][k] + imageRGB[i - 3][j - 2][k] + imageRGB[i - 3][j - 3][k] +
                imageRGB[i - 3][j + 1][k] + imageRGB[i - 3][j + 2][k] + imageRGB[i - 3][j + 3][k] +
                imageRGB[i + 1][j][k] + imageRGB[i + 1][j - 1][k] + imageRGB[i + 1][j - 2][k] + imageRGB[i + 1][j - 3][k] +
                imageRGB[i + 1][j + 1][k] + imageRGB[i + 1][j + 2][k] + imageRGB[i + 1][j + 3][k] +
                imageRGB[i + 2][j][k] + imageRGB[i + 2][j - 1][k] + imageRGB[i + 2][j - 2][k] + imageRGB[i + 2][j - 3][k] +
                imageRGB[i + 2][j + 1][k] + imageRGB[i + 2][j + 2][k] + imageRGB[i + 2][j + 3][k] +
                imageRGB[i + 3][j][k] + imageRGB[i + 3][j - 1][k] + imageRGB[i + 3][j - 2][k] + imageRGB[i + 3][j - 3][k] +
                imageRGB[i + 3][j + 1][k] + imageRGB[i + 3][j + 2][k] + imageRGB[i + 3][j + 3][k];
                // Write the average into the current pixel
                imageRGB[i][j][k] = avg / 49;
            }
        }
    }
    cout << "Image blurred successfully!\n";
}
