// Author: Omar Elgammal - 20210271

// Filter #2 - Function that inverts image colour
void invert_image(){
    // Iterates on each pixel and inverts its color
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            image[i][j] = 255 - image[i][j];
        }
    }
    cout << "Invert filter was applied successfully!\n";
}

// Filter #6 - Function that rotates image anticlockwise
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

// Filter #8 - Enlarge filter to enlarge any quarter of the images
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
    for(int i=0, i_quarter = i_str_temp; i < SIZE; i += 2, i_quarter++){
        for(int j=0, j_quarter = j_str_temp; j < SIZE; j += 2, j_quarter++){
            image[i][j] = image[i + 1][j] = image[i][j + 1] 
            = image[i + 1][j + 1] = temp[i_quarter][j_quarter];
        }
    }

    cout << "Image enlarged successfully!\n";
}

// Filter #b - Function that shuffles image quraters according to the user's input
void shuffle_image(){

    // initializing temporary image array
    unsigned char temp[SIZE][SIZE];

    // Copying original image to temporary array
    for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                temp[i][j] = image[i][j];
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

    // Loop that sets the iterator variables according to the user's input in the temp image 
    // and copy it into the original image quarter
    for(int i = 0; i < 4; i++){

        // Conditions to set up the iterator variables on temporary image
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

        // Conditions to set up the iterator variables for the original image
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

        // loop that iterates over both quarters and copies from temporary to original image
        for(int i_origin = i_str_original, i_temp = i_str_temp; i_origin < i_str_original + 128; i_origin++, i_temp++){
            for(int j_origin = j_str_original, j_temp = j_str_temp; j_origin < j_str_original + 128; j_origin++, j_temp++){
                image[i_origin][j_origin] = temp[i_temp][j_temp];

            }
        }
    }
    cout << "Image shuffled successfully!\n";
}
