/*---------------------------------*/
/*Name: Zichen Jing (Nancy), NetID: zj2256 */
/*        Date: April 24, 2023        */
/*         Assignment 3.cpp         */
/*---------------------------------*/

/*-----------------------------------------START---------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PoliceStation;

class PoliceCar
{
private:
    int ID; //police car ID
    double xcoordinate; //x position of the police car
    double ycoordinate; //y position of the police car
    PoliceStation *policestation; //reference to the class police station
    int mul; //minimum urgent level
    static int numOfCars; //static number of police cars, cannot be changed by the program or the user
    
public:
    //default constructor
    PoliceCar(PoliceStation* policestation){
        xcoordinate=0;
        ycoordinate=0;
        mul=0;
        numOfCars++; //start with 0, increment to 1 when the first police car is created
        ID=numOfCars; //start with 1
        this->policestation=policestation; //reference to the class police station
    }
    
    //non-default constructor
    PoliceCar(double xcoordinate, double ycoordinate, int mul, PoliceStation* policestation){
        this->xcoordinate=xcoordinate; //user decide
        this->ycoordinate=ycoordinate; //user decide
        this->mul=mul; //user decide
        numOfCars++; //decide internally by the program
        ID=numOfCars; //decide internally by the program
        this->policestation=policestation; //reference to the class police station
    }
    
    //getters of the data members
    int getID(){return ID;}
    double getPosx(){return xcoordinate;}
    double getPosy(){return ycoordinate;}
    int getLevel(){return mul;}
    int getNumOfCars(){return numOfCars;}
    
    //setters of the data members
    void setPosx(double xcoordinate){this->xcoordinate=xcoordinate;}
    void setPosy(double ycoordinate){this->ycoordinate=ycoordinate;}
    void setLevel(int mul){this->mul=mul;}
    
    //move the police car to a randomly new location within (-100,100)x(-100,100), change the urgent level of the police car randomly to a number between 1, 2, and 3
    void move(){
        xcoordinate=rand_pos();
        ycoordinate=rand_pos();
        mul=rand_mul();
    }
    
    // generate a random number from 0 to 200
    double rand_pos(){
        return double(rand()%201-100);
    }
    
    //generate a random number from 1 to 3
    double rand_mul(){
        return double(rand()%3+1);
    }
    
    //display the information (ID, minimum urgent level, 2D position) about the police car
    void print(){
        cout<<left<<setw(10)<<ID<<left<<setw(13)<<mul<<left<<"("<<left<<xcoordinate<<left<<","<<left<<ycoordinate<<left<<setw(10)<<")"<<endl;
    }
};
int PoliceCar::numOfCars=0; //initialize the number of police cars to 0

class Call
{
private:
    int CID; //ID of the call
    double xcoordinate; //x position of the call
    double ycoordinate; //y position of the call
    int ul; //urgent level
    static int numOfCalls; //static number of calls, cannot be changed by the program or the user
    
public:
    //default constructor
    Call(){
        xcoordinate=0;
        ycoordinate=0;
        ul=0;
        numOfCalls++; //start with 0, increment to 1 when the first accident calls
        CID=numOfCalls; //start with 1
    }
    
    //non-default constructor
    Call(double xcoordinate, double ycoordinate, int ul){
        this->xcoordinate=xcoordinate; //user decide
        this->ycoordinate=ycoordinate; //user decide
        this->ul=ul; //user decide
        numOfCalls++; //decide internally by the program
        CID=numOfCalls; //decide internally by the program
    }
    
    //getters of the data members
    int getCID(){return CID;}
    double getPosx(){return xcoordinate;}
    double getPosy(){return ycoordinate;}
    int getUlevel(){return ul;}
    int getNumOfCalls(){return numOfCalls;}
    
    //setters of the data members
    void setPosx(double xcoordinate){this->xcoordinate=xcoordinate;}
    void setPosY(double ycoordinate){this->ycoordinate=ycoordinate;}
    void setUlevel(int ul){this->ul=ul;}
    
    //display the information (ID, urgent level, 2D position) about the call
    void print(){
        cout<<left<<setw(10)<<CID<<left<<setw(13)<<ul<<left<<"("<<left<<xcoordinate<<left<<","<<left<<ycoordinate<<left<<setw(10)<<")"<<endl;
    }
};
int Call::numOfCalls=0; //initialize the number of calls to 0

class PoliceStation
{
private:
    int ID; //police station ID
    PoliceCar ** policecars; //reference to the array of PoliceCar
    int numOfCars; //the number of police cars
    Call ** calls; //reference to the array of Call
    int numOfCalls; //the number of calls
    double xcoordinate; //x position of the police station
    double ycoordinate; //y position of the police station
    static int numOfStations; //static number of police stations, cannot be changed by the program or the user
    
public:
    //default constructor, all values set internally by the program
    PoliceStation(){
        //number of police cars and calls are both set to zero, location of the police station is set to (0,0)
        numOfCars=0;
        numOfCalls=0;
        xcoordinate=0;
        ycoordinate=0;
        numOfStations++; //start with 0, increment to 1 when the first police station is created
        ID=numOfStations; //start with 1
    }
    
    //non-default constructor
    PoliceStation(double xcoordinate, double ycoordinate){
        //number of police cars and calls are both set to zero, location of the police station is determined by the user
        numOfCars=0;
        numOfCalls=0;
        this->xcoordinate=xcoordinate; //user decide
        this->ycoordinate=ycoordinate; //user decide
        numOfStations++;
        ID=numOfStations;
    }
    
    //getters of the data members
    int getID(){return ID;}
    double getPosx(){return xcoordinate;}
    double getPosy(){return ycoordinate;}
    int getNumOfCars(){return numOfCars;}
    int getNumOfCalls(){return numOfCalls;}
    int getNumOfStations(){return numOfStations;}
    
    //setters of the data members
    void setPosx(double xcoordinate){this->xcoordinate=xcoordinate;}
    void setPosy(double ycoordinate){this->ycoordinate=ycoordinate;}
    
    //calculate the distance from the accident to all police cars
    double * Calcdist(Call * C1){
        double * distance=new double [numOfCars]; //create an array "distance" with the size of the number of cars
        //go through all police cars and store the distance into the array
        for (int i=0; i<numOfCars; i++){
            double x1=policecars[i]->getPosx(); //x position of the police car
            double y1=policecars[i]->getPosy(); //y position of the police car
            double x2=C1->getPosx(); //x position of the accident
            double y2=C1->getPosy(); //y position of the accident
            distance[i]=sqrt((pow(x1-x2,2))+(pow(y1-y2,2))); //calculate distance between the police car and the accident
        }
        return distance;
    }
    
    //update the position and the minimum urgent level of each police car randomly
    void update(){
        //go through all police cars
        for(int i=0; i<numOfCars; i++){
            policecars[i]->move(); //call the move function
        }
    }
    
    //assign the police car based on the status (distance, urgent level) to the accident
    void assign(Call * C1){
        double * dist=Calcdist(C1); //create an array "dist" which stores the distance from each police car to the call
        int min(0), ctr(0);
        int * urglev=new int[numOfCars]; //create an array "urglev" with the size of the number of cars
        //check available police cars according to urgent level
        for (int i=0; i<numOfCars; i++){
            //the minimum urgent level of the police car must be smaller or equal to the urgent level of the accident
            if (policecars[i]->getLevel()<=C1->getUlevel()){
                urglev[ctr]=i; //urglev stores the index of police cars in the array "policecars" with suitable minimum urgent level
                ctr++; //counter to keep track of how many police cars are available according to the urgent level
            }
        }
        //if there is no police car available due to non-matching of the urgent level
        if (ctr==0){
            cout<<"Sorry, there is no police car available for this call, please dial later!"<<endl;
            return; //exit the function here, no execution of the rest
        }
        //among police cars with matching urgent levels, find the police car with the nearest distance
        for (int i=0; i<ctr; i++){
            int index=urglev[i]; //get the index of police cars in the array "policecars" with suitable minimum urgent level
            min=urglev[0]; //start with the first one
            if (dist[index]<dist[min])
                min=index; //min is the index of the police cars with the nearest distance to the call
        }
        //display the information about the call and the assigned police car
        cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
        cout<<"Accident Information:"<<endl;
        //information about the call
        cout<<"The accident with ID "<<C1->getCID()<<" occurred at "<<"("<<C1->getPosx()<<","<<C1->getPosy()<<"), with an urgent level of "<<C1->getUlevel()<<"."<<endl;
        //information about the assigned car
        cout<<"The police car assigned to this accident has an ID "<<policecars[min]->getID()<<", with a minimum urgent level of "<<policecars[min]->getLevel()<<"."<<endl;
        cout<<"The distance between the accident and the assigned police car is "<<dist[min]<<endl;
        //the assigned police car is moved to the location of the call
        policecars[min]->setPosx(C1->getPosx());
        policecars[min]->setPosy(C1->getPosy());
        DeleteCar(min); //the assigned police car is no longer available for other calls therefore deleted
        delete[]urglev; //deallocate memory
        delete[]dist; //deallocate memory
    }
    
    //display the information of available police cars (not assigned) and all calls of the specified police station
    void print(){
        cout<<"For the police station with the ID "<<getID()<<":"<<endl;
        cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
        cout<<"Available Police Car Information:"<<endl;
        cout<<"Number of available police cars:"<<numOfCars<<endl; //number of available police cars
        cout<<left<<setw(10)<<"ID"<<left<<setw(13)<<"Urg Level"<<left<<setw(10)<<"Location"<<endl; //header of table
        //display the information of each police car
        for(int i=0; i<numOfCars; i++){
            policecars[i]->print();
        }
        cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
        cout<<"Call Information:"<<endl;
        cout<<"Number of calls:"<<numOfCalls<<endl;
        cout<<left<<setw(10)<<"ID"<<left<<setw(13)<<"Urg Level"<<left<<setw(10)<<"Location"<<endl; //header of table
        //display the information of each call
        for(int i=0; i<numOfCalls; i++){
            calls[i]->print();
        }
        cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
    }
    
    //add a police car
    void AddPolicecar(PoliceCar * policecar){
        PoliceCar ** newpolicecars=new PoliceCar * [numOfCars+1]; //the size of the array becomes original number+1
        //copy original policecars to the new array
        for(int i=0; i<numOfCars; i++){
            newpolicecars[i]=policecars[i];
        }
        //add the additional police car
        newpolicecars[numOfCars]=policecar;
        //copy the new array back to the original
        policecars=newpolicecars;
        numOfCars++; //increment the number of police cars
        update(); //update the position and the minimum urgent level of all police cars including the newly added one
    }
    
    //add a call
    void AddCall(Call * call){
        Call ** newcalls=new Call * [numOfCalls+1]; //the size of the array becomes original number+1
        //copy original calls to the new array
        for(int i=0; i<numOfCalls; i++){
            newcalls[i]=calls[i];
        }
        //add the additional call
        newcalls[numOfCalls]=call;
        //copy the new array back to the original
        calls=newcalls;
        numOfCalls++; //increment the number of calls
        update(); //update the position and the minimum urgent level of all police cars
        assign(call); //find the most suitable police car for the call according to urgent level and distance
    }
    
    //delete the police car that has been assigned to calls since it is no longer available
    void DeleteCar(int index){
        PoliceCar ** newpolicecars=new PoliceCar * [numOfCars-1]; //the size of the array becomes original number-1
        //copy the original policecars to the new array, skip the assigned police car which is located at array[index]
        for(int i=0; i<index; i++){
            newpolicecars[i]=policecars[i];
        }
        for(int i=index; i<numOfCars-1; i++){
            newpolicecars[i]=policecars[i+1];
        }
        //copy the new array back to the original
        policecars=newpolicecars;
        numOfCars--; //decrement the number of police cars
    }
    
    //destructor of dynamically allocated memory
    ~PoliceStation(){
        for (int i=0; i<numOfCars; i++){
            delete policecars[i];
        }
        delete[]policecars;
        for (int i=0; i<numOfCalls; i++){
            delete calls[i];
        }
        delete[]calls;
    }
};
int PoliceStation::numOfStations=0;


int main(){
    int numOfCars, ul, choice(0);
    double xcoordinate, ycoordinate;
    PoliceStation *PS=new PoliceStation; //create a pointer "PS" to an object in PoliceStation
    
    cout<<"Please enter the number of police cars you want to add"<<endl;
    cin>>numOfCars;
    //print the header of the information of the created police cars
    cout<<left<<setw(10)<<"ID"<<left<<setw(13)<<"Urg Level"<<left<<setw(10)<<"Location"<<endl;
    srand((unsigned)time(NULL)); //set the seed for the random number generator
    //add police cars according to the user's input
    for(int i=0; i<numOfCars; i++){
        PoliceCar *P1=new PoliceCar(PS); //create a pointer "P1" to an object in PoliceCar, the created police car belongs to PoliceStation
        PS->AddPolicecar(P1);
        P1->print(); //print the information of the police car
    }
    
    cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
    cout<<"Thank you for dialing 999, please provide the location of the accident with the form 'x y', and its urgent level"<<endl;
    cin>>xcoordinate>>ycoordinate>>ul;
    //check if the user's inputs about the position and urgent level are valid
    while (xcoordinate>100||xcoordinate<-100||ycoordinate>100||ycoordinate<-100||ul<1||ul>3){
        cout<<"Invalid inputs, please provide again the location and the urgent level of the accident"<<endl;
        cin>>xcoordinate>>ycoordinate>>ul;
    }
    Call*C1=new Call(xcoordinate, ycoordinate, ul); //create a pointer "C1" to an object in Call
    PS->AddCall(C1); //add the call to assign an available police car
    cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
    PS->print(); //print the information of remaining police cars and the call
    
    do{
        //ask the user about their next step
        cout<<"Please choose what you want to do next:"<<endl;
        cout<<"1. Add police car(s)"<<endl;
        cout<<"2. Add a call"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;
        //check if the user's input is valid, must be one of the numbers provided
        while (choice<1||choice>3){
            cout<<"Invalid input, please re-enter a number between 1, 2, and 3"<<endl;
            cin>>choice;
        }
        
        switch (choice){
                
            //if the user chose to add more police cars
            case 1:
            {
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"Please enter the number of police cars you want to add"<<endl;
                cin>>numOfCars;
                //print the header of the information of the created police cars
                cout<<left<<setw(10)<<"ID"<<left<<setw(13)<<"Urg Level"<<left<<setw(10)<<"Location"<<endl;
                srand((unsigned)time(NULL)); //set the seed for the random number generator
                //add police cars according to the user's input
                for(int i=0; i<numOfCars; i++){
                    PoliceCar *P1=new PoliceCar(PS); //create a pointer "P1" to an object in PoliceCar, the created police car belongs to PoliceStation
                    PS->AddPolicecar(P1);
                }
                PS->print(); //print the information of the updated police cars with the information of calls till now
                continue;
            }
                
            //if the user chose to add a call
            case 2:
            {
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"Thank you for dialing 999, please provide the location of the accident with the form 'x y', and its urgent level"<<endl;
                cin>>xcoordinate>>ycoordinate>>ul;
                //check if the user's inputs about the position and urgent level are valid
                while (xcoordinate>100||xcoordinate<-100||ycoordinate>100||ycoordinate<-100||ul<1||ul>3){
                    cout<<"Invalid inputs, please provide again the location and the urgent level of the accident"<<endl;
                    cin>>xcoordinate>>ycoordinate>>ul;
                }
                Call*C1=new Call(xcoordinate, ycoordinate, ul); //create a pointer "C1" to an object in Call
                PS->AddCall(C1); //add the call to assign an available police car
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                PS->print(); //print the information of remaining police cars and all the previous calls
                continue;
            }
                
            //if the user chose to exit the program
            case 3:
            {
                cout<<"\n"<<endl; //empty line to make the statements displayed less crowded
                cout<<"Thank you for using the program, goodbye!"<<endl;
                exit(1); //exit program will receive a return value of 1
            }
        }
        
    }while (choice!=3);//can only exit the do/while loop by choosing 3)Exit
    
    return 0;
}
