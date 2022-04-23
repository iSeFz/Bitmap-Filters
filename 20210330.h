// Author: Mohamed Amgad - 20210330

// Filter #1 - Convert image into black and white image
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

// Filter #4 - Flip image horizontally or vertically
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

// Filter #7 - Detect image edges
void edge_detector() {
    int Gx, Gy, avg , sum;
    double threshold = 0.0;
    // x_mask to calculate varition in x_axis
    int kernal_x[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
    // y_mask to calculat varition in y_axis
    int kernal_y[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };

    // remove noise
    for (int i = 1, k = 0; i < SIZE - 1 && k < SIZE - 2; i++, k++) {
        for (int j = 1, l = 0; j < SIZE - 1 && l < SIZE - 2; j++, l++) {
            sum = image[i][j] + image[i][j - 1] + image[i][j + 1] +
                image[i - 1][j - 1] + image[i - 1][j] + image[i - 1][j + 1] +
                image[i + 1][j - 1] + image[i + 1][j] + image[i + 1][j + 1];

            image[k][l] = lround(sum / 9);
        }
    }

    for (int i = 1, k = 0; i < SIZE - 1 && k < SIZE - 2; i++, k++) {
        for (int j = 1, l = 0; j < SIZE - 1 && l < SIZE - 2; j++, l++) {
            // calculate varition in x with respect to each pixel
            Gx = image[i][j] * kernal_x[1][1] + image[i][j - 1] * kernal_x[1][0] +
                image[i][j + 1] * kernal_x[1][2] +
                image[i - 1][j - 1] * kernal_x[0][0] +
                image[i - 1][j] * kernal_x[0][1] +
                image[i - 1][j + 1] * kernal_x[0][2] +
                image[i + 1][j - 1] * kernal_x[2][0] +
                image[i + 1][j] * kernal_x[2][1] +
                image[i + 1][j + 1] * kernal_x[2][2];
            // calculate varition in y with respect to each pixel
            Gy = image[i][j] * kernal_y[1][1] + image[i][j - 1] * kernal_y[1][0] +
                image[i][j + 1] * kernal_y[1][2] +
                image[i - 1][j - 1] * kernal_y[0][0] +
                image[i - 1][j] * kernal_y[0][1] +
                image[i - 1][j + 1] * kernal_y[0][2] +
                image[i + 1][j - 1] * kernal_y[2][0] +
                image[i + 1][j] * kernal_y[2][1] +
                image[i + 1][j + 1] * kernal_y[2][2];
            threshold += lround(sqrt(Gx * Gx + Gy * Gy));
            image[k][l] = lround(sqrt(Gx * Gx + Gy * Gy));
        }
    }
    // calculate average
    avg = lround(threshold / (SIZE * SIZE));
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            // turn pixel to black if it is greater than avg
            if (image[i][j] > avg) {
                image[i][j] = 0;
            }
            // turn pixel to white if it is smaller than or equal avg
            else {
                image[i][j] = 255;
            }
        }
    }
}

// Filter #a - Mirror image left or right or up or down
void mirror_image(){
    string choice = "";
    cout << "Do you want to Mirror (l)eft, (r)ight, (u)pper or (d)own side? ";
    cin >> choice;
    // iterate on each pixel
    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            if (choice == "r"){
                // make right side equal to left
                image[i][(SIZE - 1) - j] = image[i][j];
            }
            else if (choice == "l"){
                // make left side equal to right
                image[i][j] = image[i][(SIZE - 1) - j];
            }
            else if (choice == "u"){
                // make upper side equal to lower side
                image[i][j] = image[(SIZE - 1) - i][j];
            }
            else if (choice == "d"){
                // make lower side equal to upper side
                image[(SIZE - 1) - i][j] = image[i][j];
            }
        }
    }
    cout << "Mirror filter applied to the image successfully!\n";
}
