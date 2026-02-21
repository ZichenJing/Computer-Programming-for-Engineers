/*---------------------------------*/
/*Name: Zichen Jing (Nancy), NetID: zj2256 */
/*        Date: April 4, 2023        */
/*         Assignment 2.cpp         */
/*---------------------------------*/

/*-----------------------------------------START---------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

//function prototypes:

int print_Menu();

int rand_int();

void run_Test(int x[], int y[], int answers[], int operation, int size);

int print_Summary(int x[], int y[], int answers[], int operation, int size);


//function to display the menu for the user to choose
int print_Menu(){
    int choice;
    cout<<"Please choose the calculation you want to practice"<<endl;
    cout<<"1) Multiplication"<<endl;
    cout<<"2) Division (quotient)"<<endl;
    cout<<"3) Exit"<<endl;
    cout<<"Please make a selection: "<<endl;
    cin>>choice;
    //check the validity of the user's input, must be one of the numbers provided
    while (choice<1||choice>3){
        cout<<"The number you entered is invalid, please try again"<<endl;
        cout<<"Please make a selection: "<<endl;
        cin>>choice;}
    
    return choice;
}

//function to generate a random number which will be used in building the equations
int rand_int(){
    return rand()%9+1;
}

//function to display 10 multiplication or 10 division equations based on the user's choice
void run_Test(int x[], int y[], int answers[], int operation, int size){
    cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
    cout<<"Please give the answers to the following multiplication questions in the form of integers"<<endl;
    //if the user chooses to do multiplications
    if (operation==1){
        for (int i=0; i<size; i++){
            //set the seed of the random number generator
            srand((unsigned)time(NULL));
            //store into x array and y array
            x[i]=rand_int(); //call the random integer generating function
            y[i]=rand_int(); //call the random integer generating function
            //output the generated numbers into an equation form
            cout<<x[i]<<"*"<<y[i]<<"=";
            //store into answer array
            cin>>answers[i];
        }
    }
    //if the user chooses to do divisions
    if (operation==2){
        for (int i=0; i<size; i++){
            //set the seed of the random number generator
            srand((unsigned)time(NULL));
            //store into x array and y array
            x[i]=rand_int(); //call the random integer generating function
            y[i]=rand_int(); //call the random integer generating function
            //output the generated numbers into an equation form
            cout<<x[i]<<"/"<<y[i]<<"=";
            //store into answer array
            cin>>answers[i];
        }
    }
}

//function to display the summary of the user's answers, including the correct rate and if needed, correction to wrong answers
int print_Summary(int x[], int y[], int answers[], int operation, int size){
    int ctr(0); //the number of correct answers
    //if the user chooses to do multiplications
    if (operation==1){
        cout<<"Exam Summary:"<<endl;
        //print the equations and the user's answers
        for(int i=0; i<size; i++){
            cout<<x[i]<<"*"<<y[i]<<"="<<answers[i];
            //if the user answered correctly
            if(x[i]*y[i]==answers[i]){
                cout<<" "<<"- correct answer"<<endl;
                ctr++; //increase the number of correct answers
            }
            //correction to wrong answers
            else
                cout<<" "<<"- incorrect answer - the answer is "<<x[i]*y[i]<<endl;
        }
    }
    //if the user chooses to do divisions
    if (operation==2){
        cout<<"Exam Summary:"<<endl;
        //print the equations and the user's answers
        for(int i=0; i<size; i++){
            cout<<x[i]<<"/"<<y[i]<<"="<<answers[i];
            //if the user answered correctly
            if(x[i]/y[i]==answers[i]){
                cout<<" "<<"- correct answer"<<endl;
                ctr++; //increase the number of correct answers
            }
            //correction to wrong answers
            else
                cout<<" "<<"- incorrect answer - the answer is "<<x[i]/y[i]<<endl;
        }
    }
    
    //answering correctly for more than 7 questions
    if (ctr>7)
        cout<<"Congratulations! You scored "<<ctr<<"/10"<<endl;
    //answering correctly for less than 7 questions
    else
        cout<<"You scored "<<ctr<<"/10. Please ask your teacher for help!"<<endl;
    
    return ctr;
}
        

int main() {
    
#define size 10 //declare "size" as 10
    
    //declare variables, initialized to values that will never naturally appear in the program
    int operation(0), x[size], y[size], answers[size], choice(0);
    
    do{
        choice=print_Menu(); //call the function to display the menu
        
        switch(choice){
            //when the user chooses to do multiplication
            case 1:
                operation=choice; //assign the user's choice of the menu to operation so that the function can respond correctly
                run_Test(x, y, answers, operation, size); //call the function to generate equations based on the user's choice
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                print_Summary(x, y, answers, operation, size); //call the function to display the summary of the user's progress
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                break;
            
            //when the user chooses to do division
            case 2:
                operation=choice; //assign the user's choice of the menu to operation so that the function can respond correctly
                run_Test(x, y, answers, operation, size); //call the function to generate equations based on the user's choice
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                print_Summary(x, y, answers, operation, size); //call the function to display the summary of the user's progress
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                break;
             
            //when the user chooses to exit the program
            case 3:
                cout<<"Thank you for using the program, goodbye!"<<endl;
                exit(1);
        }
    }while (choice!=3); //only way to terminate the program is by choosing option 3
    
    
    return 0;
}
