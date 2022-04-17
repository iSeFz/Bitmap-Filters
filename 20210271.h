/*
Author: Omar Elgammal - 20210271
*/

// Filter #2
// Function that inverts image colour
void invert_image(){
    // Iterates on each pixel and inverts its color
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            image[i][j] = 255 - image[i][j];
        }
    }
    cout << "Invert filter was applied successfully!\n";
}

// Filter #6
// Function that rotates image anticlockwise
void rotate_image(){

    // Initializing empty array to use for rotation
    unsigned char temp[SIZE][SIZE];

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
                temp[i][j] = image[i][j];
            }
        }

        // Loop that iterates on each pixel in temp
        // and puts it back into main image in its new location to rotate
        for(int i = 0, jnew = SIZE - 1; i < SIZE; i++, jnew--){
            for(int j = 0, inew = 0; j < SIZE; inew++, j++){
                image[inew][jnew] = temp[i][j];
            }
        }
        nRotations--;
    }
    cout << "Image rotated by " << input << " successfully!\n";
}

// Filter #8
// Enlarge filter to enlarge any quarter of the images
void enlarge_image(){

    // initializing temporary image array
    unsigned char temp[SIZE][SIZE];

    // Copying original image to temporary array
    for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                temp[i][j] = image[i][j];
            }
        }

    // Initializing user input variables
    string input;
    int correct = 0;

    // Loop that takes input from user 
    // and sets up the iterator variables accordinng to user's choice
    int i_start, i_end, j_start, j_end;
    while(!correct){
        cout << "Please choose which quarter you would like to enlarge (1, 2, 3, 4): ";
        cin >> input;
        
        if (input == "1"){
            i_start = 0, i_end = 128, 
            j_start = 0,  j_end = 128;
        }
        else if (input == "2"){
            i_start = 0, i_end = 128, 
            j_start = 128,  j_end = 256;
        }
        else if (input == "3"){
            i_start = 128, i_end = 256, 
            j_start = 0,  j_end = 128;
        }
        else if (input == "4"){
            i_start = 128, i_end = 256, 
            j_start = 128,  j_end = 256;
        }
        else{
            cout << "Invalid input! Please enter a number from 1 to 4.\n";
            continue;
        }
        correct++;
    }
    
    // Copying the quarter from the temporary image to the original image but enlarged
    for(int i=0, i_quarter = i_start; i < SIZE; i += 2, i_quarter++){
        for(int j=0, j_quarter = j_start; j < SIZE; j += 2, j_quarter++){
            image[i][j] = image[i + 1][j] = image[i][j + 1] 
            = image[i + 1][j + 1] = temp[i_quarter][j_quarter];
        }
    }

    cout << "Image enlarged successfully!\n";
}
