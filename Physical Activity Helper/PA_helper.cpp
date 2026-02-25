#include <M5Core2.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

// create pulseoximeter object 
PulseOximeter HR_detector;

// create global variables
int time_exercise1, time_exercise2, hr, target_hr, max_hr;
String exer1, exer2;

// functions to get the user's age
int get_age () {

  // create variables for the function
  int age = 20;
  bool submit = false;

  // set up the M5 screen and ask the user for their age and provide instructions
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Enter your age: \n\nLeft button to decrease \n\nRight button to increase \n\nMiddle button to submit");

  // display the default age value and have user change it 
  M5.Lcd.setCursor(0, 175);
  M5.Lcd.println("Your age: " + String(age) + " years");

  // while loop to check if user has submitted value
  while (!submit) {

    //update M5 if user has not submitted
    M5.update();
    
    // if statement for right button, if pressed decrease age by 1 and print
    if (M5.BtnA.wasReleased()) {
      age--;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your age: " + String(age)+ " years");
    }

    // if statement for left button, if pressed increase age by 1 and print
    if (M5.BtnC.wasReleased()) {
      age++;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your age: " + String(age) + " years");
    }

    // if statement for middle button, if pressed submit age
    if (M5.BtnB.wasReleased()) {
      submit = true;
    }
  }
  return age;
}



// function to get user weight
int get_weight () {

  // create variables for the function
  int weight = 70;
  bool submit = false;

  // set up the M5 screen and ask the user for their age and provide instructions
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Enter your weight (kg): \n\nLeft button to decrease \n\nRight button to increase \n\nMiddle button to submit");

  // display the default weight value and have user to change it:
  M5.Lcd.setCursor(0, 175);
  M5.Lcd.println("Your weight: " + String(weight) + " kg");

  // while loop to check if user has submitted value
  while (!submit) {

    //update M5 if user has not submitted
    M5.update();
    
    // if statement for right button, if pressed decrease age by 1 and print
    if (M5.BtnA.wasReleased()) {
      weight--;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your weight: " + String(weight)+ " kg");
    }

    // if statement for left button, if pressed increase age by 1 and print
    if (M5.BtnC.wasReleased()) {
      weight++;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your weight: " + String(weight)+ " kg");
    }

    // if statement for middle button, if pressed submit age
    if (M5.BtnB.wasReleased()) {
      submit= true;
    }
  }
  return weight;
}

// function to get user height
int get_height () {

  // create variables for function
  int height = 170;
  bool submit = false;

  // set up the M5 screen and ask the user for their age and provide instructions
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Enter your height (cm): \n\nLeft button to decrease \n\nRight button to increase \n\nMiddle button to submit");

  // display the default height value and have user change it 
  M5.Lcd.setCursor(0, 175);
  M5.Lcd.println("Your height: " + String(height) + " cm");
  
  // while loop to check if user has submitted value
  while (!submit) {

    //update M5 if user has not submitted
    M5.update();
    
    // if statement for right button, if pressed decrease age by 1 and print
    if (M5.BtnA.wasReleased()) {
      height--;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your height: " + String(height)+ " cm");
    }

    // if statement for left button, if pressed increase age by 1 and print
    if (M5.BtnC.wasReleased()) {
      height++;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your height: " + String(height) + " cm");
    }

    // if statement for middle button, if pressed submit age
    if (M5.BtnB.wasReleased()) {
      submit= true;
    }
  }
  return height;
}

// function to get user height
int get_gender () {

  // create variables for function
  int gender = 5;
  bool submit = false;

  // set up the M5 screen and ask the user for their age and provide instructions
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Enter your gender: \n\nEven number for male \n\nOdd number for female \n\nMiddle button to submit");

  // display the default gender value and have user change it
  M5.Lcd.setCursor(0, 175);
  M5.Lcd.println("Your gender: " + String(gender));
  
  // while loop to check if user has submitted value
  while (!submit) {

    //update M5 if user has not submitted
    M5.update();
    
    // if statement for right button, if pressed decrease age by 1 and print
    if (M5.BtnA.wasReleased()) {
      gender--;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your gender: " + String(gender));
    }

    // if statement for left button, if pressed increase age by 1 and print
    if (M5.BtnC.wasReleased()) {
      gender++;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your gender: " + String(gender));
    }

    // if statement for middle button, if pressed submit age
    if (M5.BtnB.wasReleased()) {
      submit= true;
    }
  }
  return gender;
}

// function to get user's desired burned calories
int burn_calories () {

  // create variables 
  int calories = 250;
  bool submit = false;

  // set up the M5 screen and ask the user for desired burned calories and provide instructions
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("How many calories would \n\nyou like to burn today: \n\nLeft button to decrease \nRight button to increase \nMiddle button to submit");
  
  // display the default calories value and have user change it
  M5.Lcd.setCursor(0, 165);
  M5.Lcd.println("Calories to burn: " + String(calories));

  // while loop to check if user has submitted value
  while (!submit) {

    //update M5 if user has not submitted and update calories number
    M5.update();
    
    // if statement for right button, if pressed decrease age by 1 and print
    if (M5.BtnA.wasReleased()) {
      calories -= 10;
      M5.Lcd.setCursor(0, 165);
      M5.Lcd.println("Calories to burn: " + String(calories));
    }

    // if statement for left button, if pressed increase age by 1 and print
    if (M5.BtnC.wasReleased()) {
      calories+= 10;
      M5.Lcd.setCursor(0, 165);
      M5.Lcd.println("Calories to burn: " + String(calories));
    }

    // if statement for middle button, if pressed submit age
    if (M5.BtnB.wasReleased()) {

      // if calories is less than 100, user is underexercising
      if (calories < 150) {
        M5.Lcd.setCursor(0, 190);
        M5.Lcd.println("Please input a valid value\nYou are underexercising!");

      // if calories if more than 900, user is overexercising
      } else if (calories >= 850) {
        M5.Lcd.setCursor(0, 190);
        M5.Lcd.println("Please input a valid value\nYou are overexercising!");
      
      // if calories is between 150 - 850, submit
      } else {
        submit = true;
      }
    }
  }
  return calories;
}

int get_location () {

  // create variables 
  int choice = 5;
  bool submit = false;

  // set up the M5 screen and ask the user for their age and provide instructions
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 15);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Where are you today? \n\nEven number for Gym \n\nOdd number for Track \n\nMiddle button to submit");

  // display default location value and have user change it
  M5.Lcd.setCursor(0, 175);
  M5.Lcd.println("Your location: " + String(choice));

  // while loop to check if user has submitted value
  while (!submit) {

    //update M5 if user has not submitted
    M5.update();
    
    // if statement for right button, if pressed, decrease age by 1 and print
    if (M5.BtnA.wasReleased()) {
      choice--;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your location: " + String(choice));
    }

    // if statement for left button, if pressed, increase age by 1 and print
    if (M5.BtnC.wasReleased()) {
      choice++;
      M5.Lcd.setCursor(0, 175);
      M5.Lcd.println("Your location: " + String(choice));
    }

    // if statement for middle button, if pressed, submit age
    if (M5.BtnB.wasReleased()) {
      submit= true;
    }
  }
  return choice;
}

// function to make sure button b is pressed
void press_middle_button (int target_hr, String exercise1) {

  // create variables
  bool submit = false;

  // reset screen, cursor and text size
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextSize(2);

  // display instructions to user and remind them to stay around their target_hr
  M5.Lcd.println("Press the middle button to\n\nbegin the first exercise:  \n" + exercise1);
  M5.Lcd.println("\nRemember to workout around\n\nyour target HR of:        \n\n" + String (target_hr) + " bpm");

  while (!submit) {

    // update the M5 if submit is false
    M5.update();

    // if statement for middle button, if pressed submit age
    if (M5.BtnB.wasReleased()) {
      submit= true;
    }
  }
}

// function to make sure button b is pressed
void press_middle_button_2 (int target_hr, String exercise2) {

  // create variables
  bool submit = false;

  // reset screen, cursor and text size
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextSize(2);

  // display instructions to user and remind them to stay around their target_hr
  M5.Lcd.println("Press the middle button to\n\nbegin the 2nd exercise:  \n" + exercise2);
  M5.Lcd.println("\nRemember to workout around\n\nyour target HR of:        \n\n" + String (target_hr) + " bpm");

  while (!submit) {

    // update the M5 if submit is false
    M5.update();

    // if statement for middle button, if pressed submit age
    if (M5.BtnB.wasReleased()) {
      submit= true;
    }
  }
}

// create function to detect the heart rate
void detect_hr() {

  // get heart rate and store it in hr variable
  hr = HR_detector.getHeartRate();

  // update the screen accordingly and display the heart rate
  M5.Lcd.setCursor(0, 40);
  M5.Lcd.setTextSize(3);
  M5.Lcd.print("Heart rate:" + String (hr));
}

// this function will display information of what each display color means
void color_info () {

  // reset screen, cursor and text size
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("During the workout there ");
  M5.Lcd.println("will be three different\nscreen colors: ");
  M5.Lcd.println("\nBlue means your heart rate\nis too low");
  M5.Lcd.println("\nGreen means your heart\nrate is just right ");
  M5.Lcd.println("\nRed means your heart rate is too high");
  delay(10000);
}

// this will be executed during the setup
void setup() {

  // set random seed
  srand(time(NULL));

  // create variables and arrays
  int age, weight, height, gender, calories, total_time, location;
  int time_min = 5, time_max, exercise1, exercise2;
  String gym_exer[4] = {"Treadmill" , "Rowing Machine", "Elliptical", "Stationary bike"};
  String track_exer[4] = {"Running", "Hurdles", "Riding a bike", "Jumping jacks"};


  // begin the M5 and appropriate items for heart rate, adjust the text size and cursor
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 15);

  // display intro message to the user
  M5.Lcd.println("Welcome to our Physical\n");
  M5.Lcd.println("Activity Helper, please\n");
  M5.Lcd.println("answer the following\n");
  M5.Lcd.println("questions:");
  delay(5000);

  // call the get_age function and store the value in age, clear the screen and have a short delay
  age = get_age();
  M5.Lcd.clear();
  delay(500);

  // based on age calculate max_hr and target_hr
  max_hr = 220 - age;
  target_hr = max_hr * 0.7;

  // call the get_weight function and store the value in weight, clear the screen and have a short delay
  weight = get_weight();
  M5.Lcd.clear();
  delay(500);

  // call the get_height function and store the value in height, clear the screen and have a short delay
  height = get_height();
  M5.Lcd.clear();
  delay(500);

  // call the get_gender function and store the value in gender, clear the screen and have a short delay
  gender = get_gender();
  M5.Lcd.clear();
  delay(500);

  // call the get_weight function and store the value in weight, clear the screen and have a short delay
  calories = burn_calories();
  M5.Lcd.clear();
  delay(500);

  // calculate the time the user would need to workout to burn calories. based on male or female
  if (gender % 2 == 0) {
    total_time = (calories * 4.184) / (0.6309 * target_hr + 0.1988 * weight + 0.2017 * age - 55.0969);
  } else {
    total_time = (calories * 4.184) / (.4472 * target_hr - 0.1263 * weight + 0.074 * age - 20.4022);
  }

  // reset M5 screen, cursor, and text size 
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 5);
  M5.Lcd.setTextSize(2);

  // display message that user's information will be shown
  M5.Lcd.println("Your information is shown: ");

  // move cursor appropriately to add a space before user information
  M5.Lcd.setCursor(0, 35);
  M5.Lcd.println("Your age: " + String(age) + " years");
  M5.Lcd.println("Your weight: " + String(weight) + " kg");
  M5.Lcd.println("Your height: " + String(height) + " cm");

  // if statement to display gender
  if (gender % 2 == 0) {
    M5.Lcd.println("Your gender: Male");
  } else {
    M5.Lcd.println("Your gender: Female");
  }

  // display the rest of user's info
  M5.Lcd.println("Calories you would like toburn: " + String(calories) + " calories\n");
  M5.Lcd.println("You will need to workout \nfor: " + String(total_time)+ " minutes\n");
  M5.Lcd.println ("You will need to workout \nat target HR of: " + String (target_hr) + " bpm");
  delay(15000);

  // call the get_location function and store the value in location
  location = get_location();

  // clear screen for the following output
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 5);
  M5.Lcd.setTextSize(2);
  delay(500);

  // set max time to 5 less than time
  time_max = total_time - 5;

  // time for exercise 1, get a random int between 5 and total_time - 5, exercises must be at least 5 min
  time_exercise1 = random(time_min, time_max+1);

  // the time for the 2nd exercises will be total time - time_exercise1
  time_exercise2 = total_time - time_exercise1;

  // get two random indexes for the exercises betweem 0-3 inclusive
  exercise1 = random(0, 4);

  // this do while loop will make sure the two exercise indexes are not the same
  do {
    exercise2 = random(0,4);

  } while (exercise1 == exercise2);

  // if statement if location is gym, num is even
  if (location % 2 == 0) {

    // display a random gym workout with 2 exercises with random times, set exercise variables as well
    M5.Lcd.println("Here is your workout plan: \n");
    M5.Lcd.println(gym_exer[exercise1]+ " for: " + String(time_exercise1) + " minutes\n");
    M5.Lcd.println(gym_exer[exercise2]+ " for: " + String(time_exercise2) + " minutes\n");
    exer1 = gym_exer[exercise1];
    exer2 = gym_exer[exercise2];
    M5.Lcd.println("You will need to workout  for: " + String(total_time) + " minutes to burn: \n" + String(calories) + " calories");
    delay(10000);

  } else {

    // display a random track workout with 2 exercises with random times, set exercise variables as well
    M5.Lcd.println("Here is your workout plan: \n");
    M5.Lcd.println(track_exer[exercise1]+ " for: " + String(time_exercise1) + " minutes\n");
    M5.Lcd.println(track_exer[exercise2]+ " for: " + String(time_exercise2) + " minutes\n");
    exer1 = track_exer[exercise1];
    exer2 = track_exer[exercise2];
    M5.Lcd.println("You will need to workout  for: " + String(total_time) + " minutes to burn: \n" + String(calories) + " calories");
    delay(10000);
  }

  // display what each color means
  color_info();

  // call press_middle_button function, so user's workout will begin when middle button is pressed
  press_middle_button (target_hr, exer1);

  // begin equipment for heart rate
  Wire.begin();
  HR_detector.begin();

  // clear the m5 display so the heart rate can display properly
  M5.Lcd.clear();

  // Set onbeatdetectedcallback function to be detect_hr()
  HR_detector.setOnBeatDetectedCallback(detect_hr);  

  // create variables, static so values hold between loops
  long time_exercise1_ms = time_exercise1 * 60 * 1000;
  long time_exercise2_ms = time_exercise2 * 60 * 1000;
  long past_time = millis();
  long current_time = 0;
  long time_passed = 0;

  // EXERCISE1
  // while loop to run as long as time_exercise1_ms has not been reached
  while (time_passed < time_exercise1_ms ) {

    // calculate current time
    current_time = millis();

    // set new time_passed value based on time since loop is ran
    time_passed = current_time - past_time;

    // Set onbeatdetectedcallback function to be detect_hr()
    HR_detector.update();
    delay(100);

    // if hr is under 100, show a blue screen
    if (hr <= max_hr * 0.5) {
      M5.Lcd.fillScreen(TFT_BLUE);
      HR_detector.update();
      delay(100);

    // else if hr is over 180, show a red screen
    } else if (hr >= max_hr * 0.75) {
      M5.Lcd.fillScreen(TFT_RED);
      HR_detector.update();
      delay(100);

    // for anything else that means heart rate is in target and show a green screen
    } else {
      M5.Lcd.fillScreen(TFT_GREEN);
      HR_detector.update();
      delay(100);
    }
  }

  // wait until user pressed middle button to begin following exercise
  press_middle_button_2 (target_hr, exer2);

  // begin equipment for heart rate
  Wire.begin();
  HR_detector.begin();

  // clear the m5 display so the heart rate can display properly
  M5.Lcd.clear();

  // reset time variables
  past_time = millis();
  time_passed = 0;

  // EXERCISE 2
  // while loop to run as long as time_exercise1_ms has not been reached
  while (time_passed < time_exercise2_ms ) {

    // calculate current time
    current_time = millis();

    // set new time_passed value based on time since loop is ran
    time_passed = current_time - past_time;

    // Set onbeatdetectedcallback function to be detect_hr()
    HR_detector.update();
    delay(100);

    // if hr is under 100, show a blue screen
    if (hr <= max_hr * 0.5) {
      M5.Lcd.fillScreen(TFT_BLUE);
      HR_detector.update();
      delay(100);

    // else if hr is over 180, show a red screen
    } else if (hr >= max_hr * 0.75) {
      M5.Lcd.fillScreen(TFT_RED);
      HR_detector.update();
      delay(100);

    // for anything else that means heart rate is in target and show a green screen
    } else {
      M5.Lcd.fillScreen(TFT_GREEN);
      HR_detector.update();
      delay(100);
    }
  }

  // reset display and print all of user info when workout is done
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 5);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Your information is shown: ");

  // move cursor appropriately to add a space before user information
  M5.Lcd.setCursor(0, 35);
  M5.Lcd.println("Your age: " + String(age) + " years");
  M5.Lcd.println("Your weight: " + String(weight) + " kg");
  M5.Lcd.println("Your height: " + String(height) + " cm");

  // if statement to display gender
  if (gender % 2 == 0) {
    M5.Lcd.println("Your gender: Male");
  } else {
    M5.Lcd.println("Your gender: Female");
  }

  // display the rest of user's info
  M5.Lcd.println("Calories you would like toburn: " + String(calories) + " calories\n");
  M5.Lcd.println("You will need to workout \nfor: " + String(total_time)+ " minutes\n");
  M5.Lcd.println ("You will need to workout \nat target HR of: " + String (target_hr) + " bpm");
  delay(15000);

  // reset display and print the workout info
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 5);
  M5.Lcd.setTextSize(2);

  M5.Lcd.println("Here was your workout plan: \n");
  M5.Lcd.println(exer1 + " for: " + String(time_exercise1) + " minutes\n");
  M5.Lcd.println(exer2 + " for: " + String(time_exercise2) + " minutes\n");
  M5.Lcd.println("You worked out for: " + String(total_time) + " minutes to burn: \n" + String(calories) + " calories");
  delay(10000);

  // after workout is complete, thank the user for using the program 
  M5.Lcd.clear();
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.setCursor(0, 5);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("All done, thank you for\n\nusing our Physical \n\nActivity Helper");
  delay(60000);
}

void loop() {

}