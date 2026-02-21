/*---------------------------------*/
/*Name: Zichen Jing (Nancy), NetID: zj2256 */
/*        Date: March 5, 2023        */
/*         Assignment 1.cpp         */
/*---------------------------------*/

/*------------------------------------------START----------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    //declare variables, initialized to values that will never naturally appear in program.
    int choice, band1(0), band2(0), band3(0), band4(0); //choice corresponds to the choice of menu, band corresponds to the number the user chose for each band
    double resistance, resistancek, tolerance, num1(-1), num2(-1), num3(-1), num4(-1); //resistancek corresponds to the resistance value in kilo-ohms, num corresponds to the value represented by the user's selection for each band
    
    do{
        //display menu to the user
        cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
        cout<<"Please enter the corresponding number to the function you wish to perform"<<endl;
        cout<<"1) Calculate resistance value"<<endl;
        cout<<"2) Help"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
        cin>>choice;
        
        //check if the user's input is valid, must be one of the numbers provided
        while (choice<1||choice>3){
            cout<<"Invalid input, please select a number between 1, 2, and 3"<<endl;
            cin>>choice;}
        
        //three cases created using switch structure depend on the user's choice
        switch (choice){
            //when the user chose to let the program calculate the resistance value
            case 1: //choice is 1
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"Please enter the corresponding number to the color you see for band 1 on the resistor"<<endl;
                //display the numbers the program associated with the colors of band 1 for the user to choose
                cout<<"1) Black"<<endl;
                cout<<"2) Brown"<<endl;
                cout<<"3) Red"<<endl;
                cout<<"4) Orange"<<endl;
                cout<<"5) Yellow"<<endl;
                cout<<"6) Green"<<endl;
                cout<<"7) Blue"<<endl;
                cout<<"8) Violet"<<endl;
                cout<<"9) Grey"<<endl;
                cout<<"10) White"<<endl;
                cin>>band1; //storing the selection to variable band1
                
                //check if the user's input is valid, must be one of the numbers provided
                while (band1<1||band1>10){
                    cout<<"Invalid input, please enter the corresponding number to the color you see for band 1 on the resistor"<<endl;
                    cin>>band1;}
                
                num1=band1-1; //according to the diagram given, for band 1, the number the program associated with the color starts at 1 whereas the significant digit corresponding to the color starts at 0, therefore the significant digit(num1) is always one less than the number program assigned to the color(band1)
                
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"Please enter the corresponding number to the color you see for band 2 on the resistor"<<endl;
                //display the numbers the program associated with the colors of band 2 for the user to choose
                cout<<"1) Black"<<endl;
                cout<<"2) Brown"<<endl;
                cout<<"3) Red"<<endl;
                cout<<"4) Orange"<<endl;
                cout<<"5) Yellow"<<endl;
                cout<<"6) Green"<<endl;
                cout<<"7) Blue"<<endl;
                cout<<"8) Violet"<<endl;
                cout<<"9) Grey"<<endl;
                cout<<"10) White"<<endl;
                cin>>band2; //storing the selection to variable band2
                
                //check if the user's input is valid, must be one of the numbers provided
                while (band2<1||band2>10){
                    cout<<"Invalid input, please enter the corresponding number to the color you see for band 2 on the resistor"<<endl;
                    cin>>band2;}
                
                num2=band2-1; //According to the diagram given, for band 2, the number the program associated with the color starts at 1 whereas the significant digit corresponding to the color starts at 0, therefore the significant digit(num2) is always one less than the number program assigned to the color(band2)
                
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"Please enter the corresponding number to the color you see for band 3 on the resistor"<<endl;
                //display the numbers the program associated with the colors of band 3 for the user to choose
                cout<<"1) Black"<<endl;
                cout<<"2) Brown"<<endl;
                cout<<"3) Red"<<endl;
                cout<<"4) Orange"<<endl;
                cout<<"5) Yellow"<<endl;
                cout<<"6) Green"<<endl;
                cout<<"7) Blue"<<endl;
                cout<<"8) Violet"<<endl;
                cout<<"9) Grey"<<endl;
                cout<<"10) White"<<endl;
                cout<<"11) Gold"<<endl;
                cout<<"12) Silver"<<endl;
                cin>>band3; //storing the selection to variable band3
                
                //check if the user's input is valid, must be one of the numbers provided
                while (band3<1||band3>12){
                    cout<<"Invalid input, please enter the corresponding number to the color you see for band 3 on the resistor"<<endl;
                    cin>>band3;}
                //according to the diagram given, for band 3, the number program associated to the color starts at 1 whereas the multiplier corresponding to the color starts at 10 to the power of 0, therefore including 10 to the power of 9, below it, the power in the multiplier(num3) is always one less than the number program assigned to the color(band3)
                if (band3<=10)
                    num3=pow(10,(band3-1));
                //for 10 to the power of a negative value, listed separately as it does not follow the pattern stated above
                else if (band3==11)
                    num3=pow(10,-1);
                else if (band3==12)
                    num3=pow(10,-2);
                
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"Please enter the corresponding number to the color you see for band 4 on the resistor"<<endl;
                //display the numbers the program associated with the colors of band 4 for the user to choose, assume band 4 can only be Gold or Silver
                cout<<"11) Gold"<<endl;
                cout<<"12) Silver"<<endl;
                cin>>band4; //storing the selection to variable band4
                
                //check if the user's input is valid, must be one of the numbers provided
                while (band4<11||band4>12){
                    cout<<"Invalid input, please enter the corresponding number to the color you see for band 4 on the resistor"<<endl;
                    cin>>band4;}
                if (band4==11)
                    //5% converted to 0.05 to have a easier calculations in the program
                    num4=0.05;
                else if (band4==12)
                    //10% converted to 0.1 to have a easier calculations in the program
                    num4=0.1;
                
                //resistance calculated in ohms
                resistance=num1*(num3*10)+num2*num3;
                //resistance calculated in kilo-ohms
                resistancek=resistance/1000;
                //tolerance calculated in kilo-ohms
                tolerance=resistancek*num4;
                
                //print both resistance value and tolerance in kilo-ohms, including '±' symbol and the unit kilo-ohms kΩ
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"The resistance value is: "<<resistancek<<"±"<<tolerance<<"kΩ"<<endl;
                cout<<"\n"<<endl;
                //allows looping back to the menu
                continue;
            
            //when the user chose to see the instruction of the program
            case 2:
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"This program is to help you obtain the resistor's resistance value. To use it, the colors on the four bands shown on the resistor are associated with a number which will be displayed to you, simply select the number of the color you see for each band as instructed by the program step by step."<<endl;
                cout<<"\n"<<endl;
                //allows looping back to the menu
                continue;
            
            //when the user chose to exit, a message will be printed, and then exit the program
            case 3:
                cout<<"\n"<<endl;//empty line to make the statements displayed less crowded
                cout<<"Thank you for using the program, goodbye!"<<endl;
                exit(1); //exit program will receive a return value of 1
        }
    }while (choice!=3); //can only exit the program by choosing 3)Exit from the menu, for case 1 and case 2, once finished, the menu will be automatically re-displayed
    
    return 0;
}

/*-------------------------------------------END-----------------------------------------------*/
