/* Filename: Assignment5.cpp 
Author: Kevin Pfeil
Date: May 28th 2019
Description: Runs a travel report and asks the user about certain things and ouputs stuff
Input: Lots of information about the trip they took, including airfare and info about rental cars and food eaten
Output: The total expenses and the amount that the user is reimbursed and the difference between the two
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

/*
Function: is_float
Description: Checks to see of the inputted string is a float
Parameters: A string is entered
Pre-Conditions: There really is not a pre-condition, this function just checks something
Post-Conditions: A boolean where if it is a float, then it will return true and vice versa
*/

bool is_float(string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (!(str[i] >= '0' && str[i] <= '9')){ // makes sure that the entered character is a number
                if (str[i] == '.'){
                    continue;
                }
                //cout << "This string is not a float" << endl;
                return false;
        }
        for (int i = 0; i < str.length(); i++) {   
            if (str[i] == '.') {
                count += 1;
            }
        }
        if (count > 1){
            //cout << "This string is not a float" << endl; // this means that they entered 2 decimals and that is not a float
            return false;
        }
        if (count == 1){
            //cout << "This string is a float" << endl;
            return true;
        }
    }
    //cout << "This string is a float" << endl;
    return true;
}

/*
Function: is_time
Description: Checks to see of the inputted string is a valid time
Parameters: A string is entered
Pre-Conditions: There really is not a pre-condition, this function just checks something
Post-Conditions: A boolean where if it is a time, then it will return true and vice versa
*/

bool is_time(string input) {
    float time = 0;
    if (is_float(input) == false) return false;
    else if (is_float(input) == true) {
        if (time < 0.00 || time > 23.59) return false;
        return true;
    }
}

/*
Function: get_arrival_time
Description: Gets the users arrival time
Parameters: A float is entered
Pre-Conditions: The user is asked for a time in the format 00.00
Post-Conditions: This value will be stored and can be used later as long as it passes the parameters
*/

float get_arrival_time(float &arrival_time) {
    string arr_time;
    bool go_beavs = true;
    do {
        cout << "What time did you arrive at the location?" << endl;
        cin >> arr_time;
        if (is_time(arr_time) == true) {
            go_beavs = true;
            arrival_time = stof(arr_time);
        }
        else if (is_time(arr_time) == false) {
            cout << "What was entered was not a valid time! Try again." << endl;
            go_beavs = false;
        }
    } while (go_beavs == false);
}

/*
Function: get_departure_time
Description: Gets the users departure time
Parameters: A float is entered
Pre-Conditions: The user is asked for a time in the format 00.00
Post-Conditions: This value will be stored and can be used later as long as it passes the parameters
*/

float get_departure_time(float &departure_time) {
    string dep_time;
    bool go_beavs = true;
    do {
        cout << "Enter the time you departed for the trip: " << endl;
        cin >> dep_time;
        if (is_time(dep_time) == false){
            cout << "Invalid input! Please try again and enter a value that is a time of day." << endl;
            go_beavs = false;
        }
        if (is_time(dep_time) == true) {
            go_beavs = true;
            departure_time = stof(dep_time);
        }
    } while (go_beavs == false);
}

/*
Function: is_money lmao
Description: Checks if a user enters a valid money value
Parameters: A string is entered
Pre-Conditions: Not really a pre-condition
Post-Conditions: The function will be allowed to continue if this function returns a true value
*/

bool is_money(string input) {
    int dot_counter = 0;
    int dot_index = -1;
    for (int i = 0; i <input.length(); i++){
        if (input[i] == '.') {
            dot_counter++;
            dot_index = i;
        }
        else if (input[i] < '0' || input[i] > '9') return false;
    }
    if (dot_counter > 1) return false;
    else if (dot_counter == 1) {
        if (input.length() - dot_index > 2) return false; // this makes sure that the entered cost does not go to more than 2 decimal places
    }
    return true;
}

/*
Function: is_int
Description: Checks if an entered value is an int
Parameters: A string is entered
Pre-Conditions: Not really a pre-condition
Post-Conditions: Allows the function to continue onward if a true value is returned
*/

bool is_int(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] < '0' || str[i] > '9' ) {
                if (i == 0 && str[i] == '-') // allows the number to be negative
                    continue;
            return false;
        }
    return true;
}

/*
Function: get_days
Description: Gets the amount of days of the trip
Parameters: An integer is entered
Pre-Conditions: The user is asked for how many days they spent on the trip
Post-Conditions: The value can be used later in many other functions
*/

int get_days(int &number_of_days) {
    string days;
    bool try_again = true;
    do {
        cout << "How many days did you spend on this trip?" << endl;
        cin >> days;
        if (is_int(days) == false) {
            cout << "Invalid input! Please make sure that the entered value is a number and is at least 1" << endl;
            try_again = false;
        }
        if (is_int(days) == true) {
            if (stoi(days) < 1) {
                cout << "You must spend at least one day on the trip! Please enter again." << endl;
                try_again = false;
            }
            else {
                number_of_days = stoi(days);
                try_again = true;
                return stoi(days);
            }
        }
    } while (try_again == false);
}

/*
Function: airfare_amount
Description: Gets the amount the user spent on airfare
Parameters: The total reimbursement and expenses are given so they can be updated
Pre-Conditions: The user is asked for the amount they spent on airfare
Post-Conditions: The two big variables about keeping track of money spent are being updated in this function
*/

int airfare_amount(float &total_reimbursement, float &total_expenses) {
    string amount;
    bool try_again = true;
    do {
        cout << "How much did you spend on airfare?" << endl;
        cin >> amount;
        if (is_money(amount) == false) {
            cout << "The entered number is not a money. Try again!" << endl;
            try_again = false;
            }
        else if (is_money(amount) == true) {
            if (stof(amount) < 0.00) {
                cout << "You must spend more than no money on the flight! Try again." << endl;
                try_again = false;
            }
            else {
                total_reimbursement += stof(amount);
                total_expenses += stof(amount);
                try_again = true;
            }
        }
    } while (try_again == false);
}

/*
Function: conference_amount
Description: Gets the amount the user spent on a conference
Parameters: The total reimbursement and expenses are given so they can be updated
Pre-Conditions: The user is asked for the amount they spent on conference fees
Post-Conditions: The two big variables about keeping track of money spent are being updated in this function
*/

int conference_amount(float &total_reimbursement, float &total_expenses) {
    string amount;
    bool try_again = true;
    do {
        cout << "How much did you spend on entrance fees to the conference?" << endl;
        cin >> amount;
        if (is_money(amount) == false) {
            cout << "The entered value is not a money. Try again!" << endl;
            try_again = false;
        }
        else if (is_money(amount) == true) {
            if (stof(amount) < 0.00) {
                cout << "You must spend more than no money on the conference. Try again!" << endl;
                try_again = false;
            }
            else {
                total_reimbursement += stof(amount);
                total_expenses += stof(amount);
                try_again = true;
            }
        }
    } while (try_again == false);
}

/*
Function: car_or_taxi
Description: Gets if the user took a rental car or took taxis
Parameters: An int will be used to keep track of 0 or 1
Pre-Conditions: The user is asked what form of car they took
Post-Conditions: The variable about what kind of car is kept and used later in the program
*/

int car_or_taxi(int &num_for_car_or_taxi) {
    bool go_beavs = true;
    int car_type;
    do {
    cout << "Enter 1 if you took taxis during the trip, and 2 if you rented a car" << endl;
    cin >> car_type;
    if (car_type == 1 || car_type == 2) {
        go_beavs = true;
        num_for_car_or_taxi = car_type;
        return num_for_car_or_taxi;
    }
    else {
        cout << "You dd not enter 1 or 2, please try again!" << endl;
        go_beavs = false;
    }
    } while (go_beavs == false);
}

/*
Function: taxi_costs
Description: Gets the amount the user spent on taxis if they took taxis
Parameters: All of the variables that needed to be kept track of in the background are passes and so are number of days and if they took car or taxi
Pre-Conditions: The user is asked for the amount they spent on taxis
Post-Conditions: The two big variables about keeping track of money spent are being updated in this function
*/

float taxi_costs(float &total_reimbursement, float &total_expenses, int &num_for_car_or_taxi, int &number_of_days) {
    float taxi_costs = 0;
    if (num_for_car_or_taxi == 1) {
        for (int i = 1; i <= number_of_days; i++) {
            cout << "Enter your taxi cost for day " << i << ": " << endl;
            cin >> taxi_costs;
            if (taxi_costs > 6) {
                total_reimbursement += 6;
                total_expenses += taxi_costs;
            }
            if (taxi_costs < 6) {
                total_reimbursement += taxi_costs;
                total_expenses += taxi_costs;
            }
        }
    }
}

/*
Function: car_type
Description: Gets the type of car used (1-4)
Parameters: If they took cars or taxis is used 
Pre-Conditions: The user is asked what kind of car they took
Post-Conditions: This variable will be kept and can be used later
*/

int car_type(int &num_for_car_or_taxi, int &type_of_car) {
    int car_type = 0;
    bool boolean = false;
    if (num_for_car_or_taxi == 2) {
        do {
        cout << "Please enter the kind of car you rented:" << endl;
        cout << "1. Sedan" << endl;
        cout << "2. SUV" << endl;
        cout << "3. Van" << endl;
        cout << "4. Convertible" << endl;
        cin >> type_of_car;
        if (type_of_car == 1 || type_of_car == 2 || type_of_car == 3 || type_of_car == 4) {
            boolean = true;
            type_of_car = car_type;
            return type_of_car;
        }
        else {
            cout << "You did not enter 1, 2, 3, or 4. Please try again!" << endl;
            boolean = false;
        }
        } while (boolean == false);
    }
}

float car_costs_for_miles_driven(int &type_of_car,float &total_reimbursement,float &total_expenses, int &num_for_car_or_taxi) {
    float miles_driven;
    if (num_for_car_or_taxi == 2) {
        cout << "How many miles did you drive?" << endl;
        cin >> miles_driven;
        if (type_of_car == 1) {
            total_reimbursement += (miles_driven * .24);
            total_expenses += (miles_driven * .24);
        }
        else if (type_of_car == 2) {
            total_reimbursement += (miles_driven * .27);
            total_expenses += (miles_driven * .27);
        }
        else if (type_of_car == 3) {
            total_reimbursement += (miles_driven * .32);
            total_expenses += (miles_driven * .32);
        }
        else if (type_of_car == 4) {
            total_reimbursement += (miles_driven * .45);
            total_expenses += (miles_driven * .45);
        }
    }
}

int car_rental_costs(int &type_of_car,float &total_reimbursement,float &total_expenses, int &num_for_car_or_taxi, int &number_of_days) {
    if (num_for_car_or_taxi == 2){
        if (type_of_car == 1) {
            total_reimbursement += (20 * number_of_days);
            total_expenses += (20 * number_of_days);
        }
        else if (type_of_car == 2) {
            total_reimbursement += (25 * number_of_days);
            total_expenses += (25 * number_of_days);
        }
        else if (type_of_car == 3) {
            total_reimbursement += (30 * number_of_days);
            total_expenses += (30 * number_of_days);
        }
        if (type_of_car == 4) {
            total_reimbursement += (50 * number_of_days);
            total_expenses += (50 * number_of_days);
        }
    }
}

float parking_fees(int &num_for_car_or_taxi, int &number_of_days,float &total_reimbursement, float &total_expenses) {
    int parking_cost = 0;
    if (num_for_car_or_taxi == 2) {
        for (int i = 0; i < number_of_days; i++) {
            cout << "Enter your parking fees for day " << i << ":" << endl;
            cin >> parking_cost;
            if (parking_cost > 6) {
                total_reimbursement += 6;
                total_expenses += parking_cost;
            }
            else {
                total_reimbursement += parking_cost;
                total_expenses += parking_cost;
            }
        }
    }
}

float hotel_costs(int &number_of_days, float &total_reimbursement, float &total_expenses) {
    int hotel_fees = 0;
    if (number_of_days > 1) {
        for (int i = 1; i <= number_of_days; i++) {
            cout << "Please enter how much you spent on hotels on day " << i << ":" << endl;
            cin >> hotel_fees;
                if (hotel_fees > 90) {
                    total_reimbursement += 90;
                    total_expenses += hotel_fees;
                }
                else {
                    total_reimbursement += hotel_fees;
                    total_expenses += hotel_fees;
                }
        }
    }
}

float food_costs_for_first_day(int &number_of_days, float &departure_time, float &cost_for_breakfast_day1, float &cost_for_lunch_day1, float &cost_for_dinner_day1) {
    for (int i = 0; i < number_of_days; i++) {
        if (i == 1) {
            if (departure_time < 7) {
                cout << "Enter your cost for breakfast: " << endl;
                cin >> cost_for_breakfast_day1;
                cout << "Enter your cost for lunch: " << endl;
                cin >> cost_for_lunch_day1;
                cout << "Enter your cost for dinner: " << endl;
                cin >> cost_for_dinner_day1;
            }
            if (departure_time > 7 && departure_time < 12) {
                cout << "Breakfast is not an allowed expense on day 1. " << endl;
                cout << "Enter your cost for lunch: " << endl;
                cin >> cost_for_lunch_day1;
                cout << "Enter your cost for dinner: " << endl;
                cin >> cost_for_dinner_day1;
            }
            if (departure_time > 12 && departure_time < 18) {
                cout << "Breakast and lunch are not allowed expenses on day 1. " << endl;
                cout << "Enter your cost for dinner: " << endl;
                cin >> cost_for_dinner_day1;
            }
            if (departure_time > 18) {
                cout << "No meals are allowed for day 1." << endl;
            }           
        }
    }
}

float update_total_for_meals_on_day_one(float &cost_for_breakfast_day1, float &cost_for_lunch_day1, float &cost_for_dinner_day1, float &total_reimbursement, float &total_expenses) {
    if (cost_for_breakfast_day1 > 9) {
        total_reimbursement += 9;
        total_expenses += cost_for_breakfast_day1;
    }
    if (cost_for_breakfast_day1 < 9) {
        total_reimbursement += cost_for_breakfast_day1;
        total_expenses += cost_for_breakfast_day1;
    }
    if (cost_for_lunch_day1 > 12) {
        total_reimbursement += 12;
        total_expenses += cost_for_lunch_day1;
    }
    if (cost_for_lunch_day1 < 12) {
        total_reimbursement += cost_for_lunch_day1;
        total_expenses += cost_for_lunch_day1;
    }
    if (cost_for_dinner_day1 > 16) {
        total_reimbursement += 16;
        total_expenses += cost_for_dinner_day1;
    }
    if (cost_for_breakfast_day1 < 16) {
        total_reimbursement += cost_for_dinner_day1;
        total_expenses += cost_for_dinner_day1;
    }
}


float meals_for_middle_days(int &number_of_days, float &cost_for_breakfast_not_day1, float &cost_for_lunch_not_day1, float &cost_for_dinner_not_day1 ) {
    for (int i = 2; i <= number_of_days; i++) {
        if (i != 1 && i <= number_of_days) {
            cout << "Enter your cost for breakfast on day " << i << ":" << endl;
            cin >> cost_for_breakfast_not_day1;
            cout << "Enter your cost for lunch on day " << i << ":" << endl;
            cin >> cost_for_lunch_not_day1;
            cout << "Enter your cost for dinner on day " << i << ":" << endl;
            cin >> cost_for_dinner_not_day1;
        }
    }
}

float update_meals_not_day_one(float &cost_for_breakfast_not_day1, float &cost_for_lunch_not_day1, float &cost_for_dinner_not_day1, float &total_reimbursement, float &total_expenses) {
    if (cost_for_breakfast_not_day1 > 9) {
        total_reimbursement += 9;
        total_expenses += cost_for_breakfast_not_day1;
    }
    if (cost_for_breakfast_not_day1 < 9) {
        total_reimbursement += cost_for_breakfast_not_day1;
        total_expenses += cost_for_breakfast_not_day1;
    }
    if (cost_for_lunch_not_day1 > 12) {
        total_reimbursement += 12;
        total_expenses += cost_for_lunch_not_day1;
    }
    if (cost_for_lunch_not_day1 < 12) {
        total_reimbursement += cost_for_lunch_not_day1;
        total_expenses += cost_for_lunch_not_day1;
    }
    if (cost_for_dinner_not_day1 > 16) {
        total_reimbursement += 16;
        total_expenses += cost_for_dinner_not_day1;
    }
    if (cost_for_breakfast_not_day1 < 16) {
        total_reimbursement += cost_for_dinner_not_day1;
        total_expenses += cost_for_dinner_not_day1;
    }
}


float meals_for_last_day(int &number_of_days, float &arrival_time, float &breakfast_for_last_day, float &lunch_for_last_day, float &dinner_for_last_day) {
    for (int i = 2; i < number_of_days; i++) {
        if (i == number_of_days) {
            if (arrival_time > 8 && arrival_time < 13) {
                cout << "Enter your breakfast costs: " << endl;
                cin >> breakfast_for_last_day;
                cout << "Lunch and dinner are not allowed costs on the last day. " << endl;
            }
            if (arrival_time > 13 && arrival_time < 19) {
                cout << "Enter your breakfast costs: " << endl;
                cin >> breakfast_for_last_day;
                cout << "Enter lunch costs: " << endl;
                cin >> lunch_for_last_day;
                cout << "Dinner is not an all allowed expense on the last day." << endl;
            }
            if (arrival_time > 19) {
                cout << "Enter your breakfast costs: " << endl;
                cin >> breakfast_for_last_day;
                cout << "Enter lunch costs: " << endl;
                cin >> lunch_for_last_day;
                cout << "Enter your dinner costs: " << endl;
                cin >> dinner_for_last_day;
            }
            if (arrival_time < 8) {
                cout << "No meal is an allowed expense on the last day." << endl;
            }
        }
    }
 }

float update_total_for_last_meals(float &total_reimbursement, float &total_expenses, float &breakfast_for_last_day, float &lunch_for_last_day, float &dinner_for_last_day) {
    if (breakfast_for_last_day > 9) {
        total_reimbursement += 9;
        total_expenses += breakfast_for_last_day;
    }
    if (breakfast_for_last_day < 9) {
        total_reimbursement += breakfast_for_last_day;
        total_expenses += breakfast_for_last_day;
    }
    if (lunch_for_last_day > 12) {
        total_reimbursement += 12;
        total_expenses += lunch_for_last_day;
    }
    if (lunch_for_last_day < 12) {
        total_reimbursement += lunch_for_last_day;
        total_expenses += lunch_for_last_day;
    }
    if (breakfast_for_last_day > 9) {
        total_reimbursement += 9;
        total_expenses += breakfast_for_last_day;
    }
    if (breakfast_for_last_day < 9) {
        total_reimbursement += breakfast_for_last_day;
        total_expenses += breakfast_for_last_day;
    }
    if (dinner_for_last_day > 16) {
        total_reimbursement += 16;
        total_expenses += dinner_for_last_day;
    }
    if (breakfast_for_last_day < 16) {
        total_reimbursement += dinner_for_last_day;
        total_expenses += dinner_for_last_day;
    }
}

void car_stuff(float &total_reimbursement, float &total_expenses, int &type_of_car, int &num_for_car_or_taxi, int &number_of_days) {
    car_or_taxi(num_for_car_or_taxi);
    taxi_costs(total_reimbursement, total_expenses, num_for_car_or_taxi, number_of_days);
    car_type(num_for_car_or_taxi, type_of_car);
    car_costs_for_miles_driven(type_of_car, total_reimbursement, total_expenses, num_for_car_or_taxi);
    car_rental_costs(type_of_car, total_reimbursement, total_expenses, num_for_car_or_taxi, number_of_days);
    parking_fees(num_for_car_or_taxi, number_of_days, total_reimbursement, total_expenses);
}

void travel_info(float &total_reimbursement, float &total_expenses, float &arrival_time, int &number_of_days, float &departure_time) {
    get_arrival_time(arrival_time);
    get_departure_time(departure_time);
    airfare_amount(total_reimbursement, total_expenses);
    conference_amount(total_reimbursement, total_expenses);
    hotel_costs(number_of_days, total_reimbursement, total_expenses);
}

void food_info(float &total_reimbursement, float &total_expenses, float &arrival_time, int &number_of_days, float &departure_time, float &cost_for_breakfast_day1, float &cost_for_lunch_day1, float &cost_for_dinner_day1, float &cost_for_breakfast_not_day1, float &cost_for_lunch_not_day1, float &cost_for_dinner_not_day1, float &breakfast_for_last_day, float &lunch_for_last_day, float &dinner_for_last_day) {
    food_costs_for_first_day(number_of_days, departure_time, cost_for_breakfast_day1, cost_for_lunch_day1, cost_for_dinner_day1);
    update_total_for_meals_on_day_one(cost_for_breakfast_day1, cost_for_lunch_day1, cost_for_dinner_day1, total_reimbursement, total_expenses);
    meals_for_middle_days(number_of_days, cost_for_breakfast_not_day1, cost_for_lunch_not_day1, cost_for_dinner_not_day1);
    update_meals_not_day_one(cost_for_breakfast_not_day1, cost_for_lunch_not_day1, cost_for_dinner_not_day1, total_reimbursement, total_expenses);
    meals_for_last_day(number_of_days, arrival_time, breakfast_for_last_day, lunch_for_last_day, dinner_for_last_day);
    update_total_for_last_meals(total_reimbursement, total_expenses, breakfast_for_last_day, lunch_for_last_day, dinner_for_last_day);
}

int main () {
    // variables
    float total_reimbursement = 0;
    float total_expenses = 0;
    float arrival_time = 0;
    int number_of_days = get_days(number_of_days);
    float departure_time = 0;
    int type_of_car = 0;
    int num_for_car_or_taxi = 0;
    float cost_for_breakfast_day1 = 0;
    float cost_for_lunch_day1 = 0;
    float cost_for_dinner_day1 = 0;
    float cost_for_breakfast_not_day1 = 0;
    float cost_for_lunch_not_day1 = 0;
    float cost_for_dinner_not_day1 = 0;
    float breakfast_for_last_day = 0;
    float lunch_for_last_day = 0;
    float dinner_for_last_day = 0;
    int choice = 0;
    bool run_again = true;
    
    do {
    travel_info(total_reimbursement, total_expenses, arrival_time, number_of_days, departure_time);
    car_stuff(total_reimbursement, total_expenses, type_of_car, num_for_car_or_taxi, number_of_days);
    food_info(total_reimbursement, total_expenses, arrival_time, number_of_days, departure_time, cost_for_breakfast_day1, cost_for_lunch_day1, cost_for_dinner_day1, cost_for_breakfast_not_day1, cost_for_lunch_not_day1, cost_for_dinner_not_day1, breakfast_for_last_day, lunch_for_last_day, dinner_for_last_day);
    
    cout << "Your total expenses are: " << total_expenses << endl;
    cout << "The total amount you are reimbursed is: " << total_reimbursement << endl;
    cout << "You owe: " << total_expenses - total_reimbursement << endl;
    cout << "Do you want to run the report again? Enter 0 if no, 1 if yes." << endl;

    cin >> choice;
    if (choice == 1) {
        run_again = true;
    }
    else if (choice == 0) {
        run_again = false;
    }
    } while (run_again == true);
}