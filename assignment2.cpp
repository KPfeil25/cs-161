// Program: assignment2.cpp
// Author: Kevin Pfeil
// Date: 4/14/19
// Description: Text based game that takes single digit input from the user and lets them decide between options in an effort to defeat a boss
// Input: Single digit inputs from the user
// Output: Either you win and defeat the boss or you lose and the boss defeats you


#include<iostream>
#include<ctime> // need this library for the random parts of this code
#include<cstdlib> // for the if/ else functions

using namespace std;

int main ()  { // creates the main function
    cout << "Welcome to Boss Fight!" << "\n" << "You approach a sign that points uphill or downhill. Enter 1 for uphill or 2 for downhill: \n";  
    int choice_1; // of the variables I need are listed here, they cannot be between the if/ else blocks
    int choice_2;
    int choice_3;
    int choice_4;
    int rand_var1;
    int rand_var2;
    srand(time(NULL)); // uses the time in my computer to keep numbers random
    rand_var1 = rand() % 9 + 1;
    rand_var2 = rand () % 9 + 1;
    cin >> choice_1;
    if (choice_1 == 1) {
        cout << "You went uphill and encounter a boss that can fly! At this point, you could either use the bow and arrow you have or try using a spell from Harry Potter on it! Enter 1 to use the bow and arrow or enter 2 to try using the spell: \n" << endl;
        cin >> choice_2;
        if (choice_2 == 1 && rand_var1 <= 6) {
           cout << "You shot the flying boss with your arrow and it worked! You win! \n" << endl;
        }
        else if (choice_2 == 1 && rand_var1 > 6) { // first random part of the code
            cout << "You shot the arrow at the boss but it dodged it! You can now either accept death by entering 1 or try again and fight back by entering 2" << endl;
            cin >> choice_3;
            
            if (choice_3 == 1) {
                cout << "The flying boyo fell off the edge after you decided to acccept defeat! You win!" << endl;
            }
            else if (choice_3 == 2) {
                cout << "The flying boyo caught your arrow and killed you with it. Maybe next time!" << endl;
            }
            else {
                
                cout << "You made the wrong decision and died! Oops" << endl;   
            }  
        }
        else if (choice_2 == 2 && rand_var2 <= 3) { // second random part of the code
            cout << "You chose to use the spell and it worked! You can either laugh at the boss as he is in pain by entering 1 or shoot another spell at him to finish him by entering 2 \n" << endl;
            cin >> choice_4;
            if (choice_4 == 1) {
                cout << "You dummy. You laughed at the boss and now you're dead!" << endl;
            }
            else if (choice_4 == 2) {
                cout << "Good decision! You killed the boss. Well done." << endl; 
            }
        }
        else if (choice_2 == 2 && rand_var2 >= 3) {
            cout << "Your spell did not work! Flying boyo killed you." << endl;
        }
        else {
                
            cout << "You entered something that did not make sense and so that means you probably would have died one way or another." << endl;
        }  
            
    }   
  
    else if (choice_1 == 2) {
        cout << "You chose to go downhill and encountered a boss that can roll around and throw rocks at you! You can either spray at the boss with your water gun by entering 1 or you could use your blastoise to try and beat him by entering 2! " << endl;
        int choice_5;
        cin >> choice_5;
        if (choice_5 == 1){
            cout << "You sprayed the boss with water! You can now either make fun of the boss by entering 1 or you could spray him again for good measure by entering 2" << endl;
            int choice_6;
            cin >> choice_6;
            if (choice_6 == 1) {
                cout << "You made fun of him and now he mad. He killed you. Oops!" << endl;
            }
            else if (choice_6 == 2) {
                cout << "You sprayed him again and killed him. Well done." << endl;
            }
        }
        else if (choice_5 == 2) {
            cout << "You threw Blastoise at the rock boss! Good choice homeboi. You can either use Surf by entering 1 or use Earthquake by entering 2: \n" << endl;
            int choice_7;
            cin >> choice_7;
            if (choice_7 == 1) {
                cout << "That was the right move! Someone played their Pokemon as a child. You win!" << endl;
            }
            else if (choice_7 == 2) {
                cout << "That was the wrong move. You clearly did not play Pokemon. The rock boss killed you." << endl;
            }
        }
    }
        
                        
    return 0;
}
