/* 
Filename: Assignment6.cpp 
Author: Kevin Pfeil
Date: June 10th 2019
Description: This program is the game minesweeper
Input: Rows, columns, and bombs wanted at the beginning and then either flag or open cells for the rest
Output: The game board with either the opened cell or flagged cell, end game screen
** MUST BE COMPILED WITH C++ 11 **
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

/*
Function: welcome
Description: Introduces the game and gives the user the rules
Parameters: Nothing is passed
Pre-Conditions: There really isnt anything required, it just kinda prints stuff out
Post-Conditions: Now the user knows the rules
*/

void welcome() {
    cout << "Welcome to minesweeper!" << endl;
    cout << "You will be given the choice to either flag a cell or open it." << endl;
    cout << "You will be entering a row and column value." << endl;
    cout << "The value must be between the number rows and columns, this is where the cell will be opened or flagged." << endl;
    cout << "If you open a cell with a bomb in it, the game will end." << endl;
    cout << endl;
}

/*
Function: command_line_args
Description: Takes in command line arguments and stores them as the rows, columns, and number of bombs wanted by the user
Parameters: Gets the number of command line args, the array of them, and the variables that will be made from the entered values
Pre-Conditions: There must be 3 inputs, they must be integers, and they must be entered on the command line
Post-Conditions: 3 variables that are used almost everywhere in the program (rows, columns, and bombs)
*/

void command_lines_args(int &count, char* args[], int &rows, int &columns, int &bombs) {
    if (count != 4) {
        cout << "You did not enter 3 arguments on the command line!" << endl;
        cout << "You entered " << count << " commands" << endl;
        cout << "You need to enter a value for rows, columns, and bombs wanted." << endl;
        cout << "For example, 10 10 8" << endl;
        exit(0);
    }
    else {
        for (int i = 1; i < count; i++) {
            rows = atoi(args[1]);
            columns = atoi(args[2]);
            bombs = atoi(args[3]);
            }  
        }
        cout << "You will have " << rows << " rows, " << columns << " columns, and " << bombs << " bombs!" << endl;
}

/*
Function: create_matrix
Description: creates the matrix that is used throughout the game
Parameters: The variables fron the command line and the matrix that was declared in main
Pre-Conditions: The inputs are numbers if they made it through command_line_args and the matrix is already declared
Post-Conditions: The matrix is initialized and can be used and manipulated through the program. Bombs are also placed randomly
*/

void create_matrix(int &rows, int &columns, int &bombs, string** &matrix) {
    matrix = new string*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new string[columns];
    }
    
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < columns; k++) {
            matrix[j][k] = " ";
            cout << matrix[j][k] << "|";
        }
        cout << endl;
    }
    
    for (int d = 0; d < bombs; d++) {
        matrix[rand() % rows][rand() % columns] = "*"; // this line places the bombs in the hidden matrix, but does not show them
    }
}

void create_blank_matrix(int &rows, int &columns, string** &blank_matrix) {
    blank_matrix = new string*[rows];
    for (int i = 0; i < rows; i++) {
        blank_matrix[i] = new string[columns];
    }
    
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < columns; k++) {
            blank_matrix[j][k] = " ";
            //cout << blank_matrix[j][k] << "|";
        }
        //cout << endl;
    }
}

/*
Function: distance_from_bomb
Description: Checks all of the boxes around the opened cell to see if they hold an "*"
Parameters: The matrix, the command line args, and a variable that can be displayed in the matrix
Pre-Conditions: The entered values that are checked by this function must be on the matrix
Post-Conditions: The number of bombs in the vicinity of the opened cell is displayed
** This function is over 20 lines as i did not want to check the conditions elsewhere **
*/

int distance_from_bombs(int &rows, int &columns, int &bombs_around, string** &matrix, int &guessed_row, int &guessed_column) {
    if (guessed_row < (rows -1) && guessed_column > 0) {
        if (matrix[guessed_row+1][guessed_column-1] == "*") {
            bombs_around++;
        }
    }
    if (guessed_row < (rows - 1)) {
        if (matrix[guessed_row+1][guessed_column] == "*") {
            bombs_around++;
        }
    }
    if (guessed_row < (rows - 1) && guessed_column < (columns - 1)) {
        if (matrix[guessed_row+1][guessed_column+1] == "*") {
            bombs_around++;
        }
    }
    if (guessed_column > 0) {
        if (matrix[guessed_row][guessed_column-1] == "*") {
            bombs_around++;
        }
    }
    if (guessed_column < (columns - 1)) {
        if (matrix[guessed_row][guessed_column+1] == "*") {
            bombs_around++;
        }
    }
    if (guessed_row > 0 && guessed_column > 0) {
        if (matrix[guessed_row-1][guessed_column-1] == "*") {
            bombs_around++;
        }
    }
    if (guessed_row > 0) {
        if (matrix[guessed_row-1][guessed_column] == "*") {
            bombs_around++;
        }
    }
    if (guessed_row > 0 && guessed_column < (columns - 1)) {
        if (matrix[guessed_row-1][guessed_column+1] == "*") {
            bombs_around++;
        }
    }
    return bombs_around;
}

/*
Function: print_matrix
Description: It prints the matrix after the user opens or flags a cell
Parameters: lots of things to do all of the many tasks it does
Pre-Conditions: The numbers entered for rows and columns must be valid
post-conditions: It prints the new matrix yay!!
*/

void print_matrix(int &rows, int &columns, string** &matrix, int &guessed_row, int &guessed_column, int &bombs_around, string &num_to_display, string** &blank_matrix) {
    num_to_display = to_string(distance_from_bombs(rows, columns, bombs_around, matrix, guessed_row, guessed_column));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[guessed_row][guessed_column] != "*") {
            blank_matrix[guessed_row][guessed_column] = num_to_display;
            cout << blank_matrix[i][j] << "|"; 
            }
            else if (matrix[guessed_row][guessed_column] == "*") {
                matrix[i][j] = to_string(distance_from_bombs(rows, columns, bombs_around, matrix, guessed_row, guessed_column));
                cout << matrix[i][j] << "|";
            }
        }
        cout << endl;
    }
}

/*
Function: end_game
Description: dispays a message at the end of the game
Parameters: only thing taken in is the nnumber of bombs found
Pre-Conditions: The number of bombs found must be known and is taken in by this function
Post-Conditions: The game is ended and the user knows how many bombs they found
*/

void end_game(int &bombs_found, int &rows, int &columns, string** &matrix, int &bombs_around, int &guessed_row, int &guessed_column, bool &game_not_over) {

    cout << "You opened a cell with a bomb in it. Oops." << endl;
    cout << "You correctly flagged " << bombs_found << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << "|";
        }
        cout << endl;
    }
    game_not_over = false;
}

/*
Function: open_or_flag
Description: Takes in a value from the user that determines if they want to open a cell or flag it instead
Parameters: A variable that cab be used elsewhere is taken in
Pre-Conditions: The user is asked and it must be after the game board is displayed
Post-Conditions: whether the user wants to open a cell or flag it, this value is stored in a variable
*/

int open_or_flag(int &guess) {
bool go_again = true;
    do {
        cout << "Would you like to open a cell (1) or place a flag(2)?" << endl;
        cin >> guess;
            if (guess != 1 && guess != 2) {
                cout << "You did not enter 1 or 2! Try again." << endl;
                go_again = false;
            }
            else {
                go_again = true;
                return guess;
            }
    } while (go_again == false);
}

/*
Function: open_cell
Description: Opens a cell and changes it if need be
Parameters: Lots of variables are taken in, these help to locate the guess of the user and change it or end the game
Pre-Conditions: All of these variables must be the correct type and the matrix muse be able to be manipulated
Post-Conditions: The matrix is changed in the area that the user specified and the game will end if they open up a cell containing a bomb
*/

void open_cell(string** &matrix, int &rows, int &columns, int &guess, int &guessed_column, int &guessed_row, int &bombs_found, int &bombs_around, int &bombs, string &num_to_display, string** &blank_matrix, bool &game_not_over) {
    if (guess == 1) {
        do {
        cout << "Please enter the row and column you want to open: " << endl;
        cin >> guessed_row;
        cin >> guessed_column;
        } while (guessed_row > (rows - 1) && guessed_column > (columns - 1));
            if (matrix[guessed_row][guessed_column] == "*") {
                end_game(bombs_found, rows, columns, matrix, bombs_around, guessed_row, guessed_column, game_not_over);
            }
            else if (matrix[guessed_row][guessed_column] == " ") {
                print_matrix(rows, columns, matrix, guessed_row, guessed_column, bombs_around, num_to_display, blank_matrix);
            }
            else {
                cout << "The entered values were not on the board not numbers, or you already entered that cell! Try again." << endl;
            }
    }
}

/*
Function: flag_a_cell
Description: Flags the cell the user entered
Parameters: This function is only accessed if the guess variable makes it
Pre-Conditions: All of the inputs must be of the correct type and again, the matrix must be able to be manipulated
Post-Conditions: The area the user entered to be flagged now has a carrot in it
*/

void flag_a_cell(string** &matrix, int &guess, int &rows, int &columns, int &bombs_found, int &flagged_row, int &flagged_column, string &num_to_display, int &guessed_row, int &guessed_column, int &bombs_around, string** &blank_matrix) {
bool try_again = true;

    if (guess == 2) {
        do {
            cout << "Enter the row and column you would like to flag:" << endl;
            cin >> flagged_row;
            cin >> flagged_column;
            if ((flagged_row > rows || flagged_row < 0) || (flagged_column > columns || flagged_row < 0)) {
                cout << "The entered row or column was not on the board, try again." << endl;
                try_again = false;
            }
            else {
                if (blank_matrix[flagged_row][flagged_column] == "*") {
                    bombs_found++;
                }
            blank_matrix[flagged_row][flagged_column] = "^";
            print_matrix(rows, columns, matrix, guessed_row, guessed_column, bombs_around, num_to_display, blank_matrix);
            try_again = true;
            }
        } while (try_again == false);
    }
}

/*
Function: delete_matrix
Description: deletes the dynamically allocated array after the program is done using it
Parameters: The matrix is taken in
Pre-Conditions: The matrix must be dynamically allocated for this function to work
Post-Conditions: The matrix is deleted from the heap
*/

void delete_matrix(string** &matrix, string** &blank_matrix, int &rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    for (int j = 0; j < rows; j++) {
        delete[] blank_matrix[j];
    }
    delete[] blank_matrix;
}



void play_game(string** &matrix, int &guess, int &bombs_found, int &guessed_row, int &guessed_column, int &rows, int &columns, int &bombs_around, int &bombs, string &num_to_display, int &flagged_row, int &flagged_column, string** &blank_matrix, bool &game_not_over) {
    create_matrix(rows, columns, bombs, matrix);
    create_blank_matrix(rows, columns, blank_matrix);
    do {
    open_or_flag(guess);
    open_cell(matrix, rows, columns, guess, guessed_column, guessed_row, bombs_found, bombs_around, bombs, num_to_display, blank_matrix, game_not_over);
    flag_a_cell(matrix, guess, rows, columns, bombs_found, flagged_row, flagged_column, num_to_display, guessed_row, guessed_column, bombs_around, blank_matrix);
    } while (game_not_over == true);
}

int main(int count, char* args[]) {
    //variables
    int rows;
    int columns;
    int bombs;
    int bombs_around = 0;
    int bombs_found = 0;
    string** matrix;
    string** blank_matrix;
    int guess;
    int guessed_row;
    int guessed_column;
    srand(time(NULL));
    string num_to_display;
    int flagged_row;
    int flagged_column;
    bool play_again = true;
    int choice;
    bool game_not_over = true;
    int game_counter = 0;

        welcome();
        command_lines_args(count, args, rows, columns, bombs);
    do {
        if (game_counter > 0) {
            game_not_over = true;
            cout << "Enter your new rows, columns, and, bombs wanted: " << endl;
            cin >> rows;
            cin >> columns;
            cin >> bombs;
        }
        play_game(matrix, guess, bombs_found, guessed_row, guessed_column, rows, columns, bombs_around, bombs, num_to_display, flagged_row, flagged_column, blank_matrix, game_not_over);
        delete_matrix(matrix, blank_matrix, rows);
        cout << "Do you want to play again? Enter 1 if yes and 2 if no. " << endl;
        cin >> choice;
        if (choice == 1) {
            game_counter++;
            play_again = true;
        }
        else if (choice == 2) {
            play_again = false;
        }
    } while (play_again == true);

}
