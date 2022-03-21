
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

/* 
Program name: assignment3_messing_around_2.cpp
Author: Kevin Pfeil
Date: April 30 2019
Description: Makes sure that the user does not enter a number to take from
the piles that is larger than 3
Input: A number to take from a pile
Output: A number that is less than or equal to 3
*/
int check_int () {
        int tile_number;
        bool check = false;
        do {
                cout << "How many tiles do you want to take from this pile?" << endl; // this prompts the user to take piles from a tile
                cin >> tile_number;
                if (tile_number > 3) {
                        do {
                        cout << "You cannot take more than 3 tiles from the piles, try again." << endl;
                        cin >> tile_number;
                        }
                        while (tile_number > 3);                      
                }
        } while (check);
        return tile_number;
}

/*
Funtion: Main
Description: This is main! This is where all the magic happens. It takes inputs and makes sure that
all the piles are not less than or equal to 0 and ends the game when that is true
Parameters: All piles cannot be equal to 0 for the duntion to continue running
Pre-Condition: All piles have a certain number of tiles that they start with
Post-Condition: All tiles will equal 0 and the winner will be printed out
*/

int main () {
string player_1; // these are all of the variables I need to define
string player_2;
int pile_1 = 4;
int pile_2 = 6;
int pile_3 = 5;
int pile_choice = 0;
int tile_choice = 0;
int tile_number = 0;
bool go_beavs;

cout << "\nWelcome to Nim!\nPlayer 1, enter your name: \n" << endl;
cin >> player_1;
cout << "\n";
cout << "Player 2, enter your name: \n" << endl;
cin >> player_2;
cout << "\n";

cout << "Pile 1 has " << pile_1 << " tiles in it." << endl; // this little block gets printed a lot because it lets the user know how many tiles are in each pile
cout << "Pile 2 has " << pile_2 << " tiles in it." << endl;
cout << "Pile 3 has " << pile_3 << " tiles in it." << endl;
        
        /* this while loop makes sure that the piles do not go below 0 */
        while ((pile_1 >= 0) && (pile_2 >= 0) && (pile_3 >= 0)){ 


                bool try_again = false;
                do{ // do while loops allow the code to break and re-prompt the user in different areas
                        cout << player_1 << ", choose either pile 1, 2, or 3: \n" << endl;
                        cin >> pile_choice;
                        
                        if (pile_choice == 1) {
                                if (pile_1 == 0) {
                                        cout << "The pile is empty! Choose another pile." << endl;
                                        try_again = true;
                                        }
                                go_beavs = true;
                                while (go_beavs) {
                                        go_beavs = false;
                                        tile_number = check_int();
                                        if (pile_1 - tile_number < 0) {
                                               
                                                cout << "There would be less than 0 tiles in the pile if you did that, please try again!" << endl;
                                                go_beavs = true;

                                        }
                                        else {
                                        pile_1 -= tile_number;
                                        cout << "Pile 1: " << pile_1 << " tiles remaining" << endl;
                                        cout << "Pile 2: " << pile_2 << " tiles remaining" << endl;
                                        cout << "Pile 3: " << pile_3 << " tiles remaining" << endl;
                                        }
                                        
                                }
                        }
                        else if (pile_choice == 2) {
                                if (pile_2 == 0) {
                                        cout << "The pile is empty! Choose another pile." << endl;
                                        break;
                                        }
                                go_beavs = true;
                                while (go_beavs) {

                                        go_beavs = false;
                                        tile_number = check_int();
                                        pile_2 -= tile_number;
                                        if (pile_2 < 0) {
                                                
                                                cout << "There would be less than 0 tiles in the pile if you did that, please try again!" << endl;
                                                go_beavs = true;
                                                pile_2 += tile_number;
                                                
                                        }
                                        else {
                                        cout << "Pile 1: " << pile_1 << " tiles remaining" << endl;
                                        cout << "Pile 2: " << pile_2 << " tiles remaining" << endl;
                                        cout << "Pile 3: " << pile_3 << " tiles remaining" << endl;
                                        }
                                }
                        }
                        else if( pile_choice == 3) {
                                if (pile_3 == 0) {
                                        cout << "The pile is empty! Choose another pile." << endl;
                                        break;
                                        }
                                go_beavs = true;
                                while (go_beavs) {

                                        go_beavs = false;
                                        tile_number = check_int();
                                        pile_3 -= tile_number;
                                        if (pile_3 < 0) {
                                                cout << "There would be less than 0 tiles in the pile if you did that, please try again!" << endl;
                                                go_beavs = true;
                                                pile_3 += tile_number;
                                                
                                        }
                                        else {
                                        cout << "Pile 1: " << pile_1 << " tiles remaining" << endl;
                                        cout << "Pile 2: " << pile_2 << " tiles remaining" << endl;
                                        cout << "Pile 3: " << pile_3 << " tiles remaining" << endl;
                                        }
                                        
                                }
                        }
                        else {
                        cout << "Please enter either 1, 2, or 3 to choose a pile" << endl;
                        try_again = true;
                        }
                        if (pile_1 == 0 && pile_2 == 0 && pile_3 == 0) {
                                cout << player_1 << " ,you lose! " << player_2 << " is the winner!" << endl;
                                exit(0);
                        }

                }while(try_again);

                        cout << player_2 << ", choose either pile 1, 2, or 3: \n" << endl; // beginning of player 2's turn
                do {
                        cin >> pile_choice;
                        if (pile_choice == 1) {
                                if (pile_1 == 0) {
                                        cout << "The pile is empty! Choose another pile." << endl;
                                        break;
                                }
                                go_beavs = true;
                                while(go_beavs){
                                        
                                        go_beavs = false;
                                        tile_number = check_int();
                                        pile_1 -= tile_number;
                                        if (pile_1 < 0) {
                                                        cout << "There would be less than 0 tiles in the pile if you did that, please try again!" << endl;
                                                        go_beavs = true;
                                                        pile_1 += tile_number;
                                                        
                                        }                                               
                                        
                                        else {
                                                cout << "Pile 1: " << pile_1 << " tiles remaining" << endl;
                                                cout << "Pile 2: " << pile_2 << " tiles remaining" << endl;
                                                cout << "Pile 3: " << pile_3 << " tiles remaining" << endl;
                                                
                                        }
                                        
                                }
                        }
                        else if (pile_choice == 2) {
                                if (pile_2 == 0) {
                                        cout << "The pile is empty! Choose another pile." << endl;
                                        break;
                                }
                                go_beavs = true;
                                while(go_beavs) {

                                        go_beavs = false;
                                        tile_number = check_int();
                                        pile_2 -= tile_number;
                                        if (pile_2 < 0) {
                                                cout << "There would be less than 0 tiles in the pile if you did that, please try again!" << endl;
                                                go_beavs = true;
                                                pile_2 += tile_number;
                                                
                                        }
                                        else {
                                                cout << "Pile 1: " << pile_1 << " tiles remaining" << endl;
                                                cout << "Pile 2: " << pile_2 << " tiles remaining" << endl;
                                                cout << "Pile 3: " << pile_3 << " tiles remaining" << endl;

                                        }
                                        
                                }
                        }
                        else if (pile_choice == 3) {
                                if (pile_3 == 0) {
                                                cout << "The pile is empty! Choose another pile." << endl;
                                                break;
                                }
                                go_beavs = true;
                                while(go_beavs) {
                                        go_beavs = false;
                                        tile_number = check_int();
                                        pile_3 -= tile_number;
                                        if (pile_3 < 0) {
                                                
                                                cout << "There would be less than 0 tiles in the pile if you did that, please try again!" << endl;
                                                go_beavs = true;
                                                pile_3 += tile_number;
                                                
                                                
                                        }
                                        else {
                                                cout << "Pile 1: " << pile_1 << " tiles remaining" << endl;
                                                cout << "Pile 2: " << pile_2 << " tiles remaining" << endl;
                                                cout << "Pile 3: " << pile_3 << " tiles remaining" << endl;
                                                
                                        }
                                        
                                }      
                        }
                        else {
                        cout << "Please enter either 1, 2, or 3 to choose a pile" << endl;
                        try_again = true;
                        }       
                        if (pile_1 == 0 && pile_2 == 0 && pile_3 == 0) { // this is where the winner is made for player 2. Its the opposite player
                                cout << player_2 << " ,you lose! " << player_1 << " is the winner!" << endl;
                                exit(0);
                        }    
                }while (try_again);
        }        
}

    
