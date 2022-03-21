/*
Program: Assignment4.cpp
Author: Kevin Pfeil
Date: 5/13/2019
Description: This is hangman, the game where you must guess the word that is coded
Input: Guesses about the word that are characters
Output: Shows you the missed letters you have entered, the correct letters, and what turn you are on
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

/* this function will make sure that the user enters a value that is an integer. That will be done by
using the ASCII values and checking if the inputs ASCII value is between the values for integers*/

char prompt_user(char s) {
    bool sko_beavs = true;
    do {
    cout << "What's your guess? " << endl;
    cin >> s;
        if (!(s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {
            cout << "The character you inputted was not a letter! The entered guess needs to be a letter." << endl;
            sko_beavs = false;
        }
        else {
            sko_beavs = true; // makes sure that the function does not go into an infinite loop
        }
    } while (sko_beavs == false); // allows the user to be reprompted
    return s;
}
// this function checks to see if the user won the game or not
bool is_game_over(string answer, char guessed_word[]) {
    
    if(strcmp(answer.c_str(), guessed_word) == 0) { // strcomp compares two strings and sees if they are the same
        cout << "You win the game!" << endl; 
        return true;
    }
    else {

        return false;
    }
    
    
}

int main () {
    bool game_over;
    int counter = 0;
    int n = 0;
    int attempts = 1;
    char guess;
    char list_of_wrong_letters;
    char correct_letter;
    string answer = "Federer";
    
    int length_of_word;
    length_of_word = answer.length();
    char correct_word[7];
    for (int i = 0; i < answer.length(); i++) {
        correct_word[i] = '_';
    }

    char misses[7];
    for (int i = 0; i < answer.length(); i++) {
        misses[i] = ' ';
    }


    cout << "Welcome to hangman! You will have 1 more attempt than the length of the word to guess the correct word" << endl;
    cout << "Enter letters to see if you can guess the correct word!" << endl;

    while (attempts <= length_of_word && game_over != true) { //make sure that the user has not gone over the max amount of turns they get
        cout << endl;
        cout << "Attempt " << attempts << "/" << length_of_word + 1 << endl;
        cout << "Word: "; 
        for (int i = 0; i < answer.length(); i++) {
        cout << correct_word[i] << " ";
        }
            cout << endl;
            correct_letter = prompt_user(guess);
            switch (correct_letter) { // switch statement check the users input and sees if it is in the correct word
                case 'f': correct_word[0] = 'F';
                                    break;
                case 'F': correct_word[0] = 'F';
                                    break;
                case 'e': correct_word[1] = 'e';
                                    correct_word[3] = 'e';
                                    correct_word[5] = 'e';
                                    break;
                case 'E': correct_word[1] = 'e';
                                    correct_word[3] = 'e';
                                    correct_word[5] = 'e';
                                    break;

                case 'd': correct_word[2] = 'd';
                                    break;
                case 'D': correct_word[2] = 'd';
                                    break;
                case 'r': correct_word[4] = 'r';
                                    correct_word[6] = 'r';
                                    break;
                case 'R': correct_word[4] = 'r';
                                    correct_word[6] = 'r';
                                    break;
                default:   
                    misses[n] = correct_letter; // this part of the code adds the letter to the "misses" array and keeps track of it
                    n++;
                    cout << "Misses: " << misses;
            }

    attempts++;
    game_over = is_game_over(answer, correct_word); // calls the function to see if the user has won the game
    }

}