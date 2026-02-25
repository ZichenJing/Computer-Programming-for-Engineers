//
//  main.cpp
//  term project
//
//  3/20/2022
//

#include <iostream>
#include <cmath>

using namespace std;

// function will present menu and get a valid choice from the user
int mainMenu() {
    
    // variables
    int choice = 0;
    
    // while true loop to make sure user inputs valid choice
    while (true) {
        
        // present options to the user
        cout << "\nWelcome to our Physical Activity Helper! Choose one of the following options:\n" << endl;
        cout << "1. A Quick Workout" << endl;
        cout << "2. Input/Edit Biometric Data" << endl;
        cout << "3. Show My Information" << endl;
        cout << "4. Help" << endl;
        cout << "5. Exit" << endl;
        
        // store their option into variable 'choice'
        cin >> choice;
        
        // if statement to check if choice is valid
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
            break;
        
        else {
            cout << "That is not a valid option please try again\n" << endl;
        }
    }
    // return 'choice' value to main program
    return choice;
}

void biometrics (int &gender, double &age, double &weight, double &height, double &bmi) {
    
    // greet the user and ask them for their information
    cout << " Please enter some of your information down below:" << endl;
    
    // ask user for their information
    while (true) {
        
        cout << "\nEnter 1 for male and 2 for female: ";
        cin >> gender;
        
        if (gender == 1 || gender == 2) {
            break;
        }
    }
    
    cout << "Enter your age in years: ";
    cin >> age;
    
    cout << "Enter your weight in kilograms: ";
    cin >> weight;
    
    cout << "Enter your height in centimeters: ";
    cin >> height;
    
    // calculate BMI
    bmi = weight / pow((height / 100), 2);
}

void burn_calories (int &calories_target) {
    
    // ask user how many calories they would like to burn
    while (true) {
        
        cout << "\nHow many calories do you want to burn today? (Integer): ";
        cin >> calories_target;
        
        // if statement to check user input
        if (calories_target < 100) {
            cout << "\nPlease input a valid value! You are underexercising" << endl;
            
        } else if (calories_target >= 1000) {
            cout << "\nPlease input a valid value! You are overexerciing" << endl;
            
        } else {
            break;
        }
    }
}

void location (int &place) {
    
    // ask user where they are at to decide what workout to give
    while (true) {
        
        cout << "\nWhere are you today? Choose one of the following options.";
        cout << "\n1. Gym \n2.Track \n3.Home" << endl;
        cin >> place;
        
        // if statement to check if input is valid
        if (place == 1 || place == 2 || place == 3) {
            break;
        }
    }
}

int bodyPlan() {
    
    // variables
    int c;
    
    // while loop
    while (true) {
        
        // have user choose a goal
        cout << "\nChoose a goal from the following: " << endl;
        cout << "1. Cut (Calorie Deficit + Cardio" << endl;
        cout << "2. Maintenance" << endl;
        cout << "3. Endurance" << endl;
        cin >> c;
        
        // if statement to check if choice is valid
        if (c == 1 || c == 2 || c == 3)
            break;
        else {
            cout << "That is not a valid option, please try again\n" << endl;
        }
    }
    return c;
}

int cut_plan() {
    
    // variables
    int cut;
    
    // while loop
    while (true) {
        
        // have user choose goal
        cout << "\nChoose one of the following cutting goals:" << endl;
        cout << "1. -1kg per week \n2. -0.75kg per week \n3. -0.50kg per week. \n4. -0.25kg per week" << endl;
        cin >> cut;
        
        // if statement to check if choice is valid
        if (cut == 1 || cut == 2 || cut == 3 || cut == 4) {
            break;
            
        } else {
            cout << "That is not a valid option, please try again\n" << endl;
        }
    }
    return cut;
}

int main() {
    
    // create variables and arrays
    string plans [4] = {"No plan has been selected yet, please enter your information using one of the other options", "Cut (Calorie Deficit + Cardio", "Maintenance", "Endurance"};
    int choice = 0, calories = 0, plan = 0, c_plan, gender = 0, calories_target = 0, place = 0;
    double age = 0, weight = 0, height = 0, bmi = 0;
    bool biometric = false;
    
    // greet the user
    cout << "Welcome to our Physical Activity Helper!";
    
    // while loop until user decides to exit
    while (true) {
        
        // if there are no biometrics, skip the menu and have the user input their biometrics like option 2
        if (biometric == false) {
            choice = 2;
            
        } else {
            // if 'biometric' is true, present the normal menu and get input
            choice = mainMenu();
        }
        
        // series of if statements based off the user's choice
        if (choice == 1) {
            
            // call burn_calories function to know what the user's calorie goal is
            burn_calories(calories_target);
            
            // get location of the user
            location(place);
            
            // if statements based on where the user is
            if (place == 1) {
                
                cout << "Gym exercises" << endl;
                
            } else if (place == 2) {
                
                cout << "Track Exercises" << endl;
                
            } else if (place == 3) {
                
                cout << "Home" << endl;
            }
            
        } else if (choice == 2) {
            
            // get biometrics and body plan from user
            biometrics(gender, age, weight, height, bmi);
            plan = bodyPlan();
            
            // update boolean biometric variable
            biometric = true;
            
            // if statements based on their body plan
            if (plan == 1) {
                
                // ask how many calories they are eating in a day
                cout << "\nHow many calories are you currently eating in a day? ";
                cin >> calories;
                
                // get the users cut goal
                c_plan = cut_plan();
                
                // if statements based on cut goal
                if (c_plan == 1) {
                    calories -= 500;
                } else if (c_plan == 2) {
                    calories -= 375;
                } else if (c_plan == 3) {
                    calories -= 250;
                } else if (c_plan == 4) {
                    calories -= 125;
                }
                
            } else if (plan == 2) {
                
                // calculate calories based on user gender
                if (gender == 1) {
                    calories = 66.5 + (13.8 * weight) + (5 * height) - (6.8 * age);
                    
                } else if (gender == 2){
                    
                    calories = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
                }
                
            } else if (plan == 3) {
                
                // ask how many calories they currently eat, they need more calories for endurance training
                cout << "\nHow many calories are you currently eating in a day? ";
                cin >> calories;
                
                // have a bit over the amount of calories needed
                calories += 300;
            }
            
            // display BMI information, recommended calorie intake, and tell user their informtation is saved
            cout << "\nYour BMI: " << bmi << endl;
            cout << "Your recommended calorie intake: " << calories << endl;
            cout << "Your information has been saved!" << endl;
        }
        
        else if (choice == 3) {
            
            // user information will be shown when this option is chosen
            cout << "Your current goal is: " << plans[plan] << endl;
            cout << "Your current weight is: " << weight << endl;
            cout << "Your BMI is: " << bmi << endl;
            cout << "Your recommended calorie intake is: " << calories << endl;
        }
        
        else if (choice == 4) {
            
            cout << "\nThis program is meant to assist with physical activity" << endl;
        }
        
        else if (choice == 5) {
            
            cout << "\nThank you for using our physical activity helper! Goodbye!" << endl;
            break;
        }
    }
}
