
/********************************************************************************** 

**  Program Filename : main.cpp

**	Author: Woohyuk Yang

**  Date: May. 5th. 2016

** Description: CS162 ModE

** Input : 

** Output :  STD simulation 
************************************************************************************/

#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "state.hpp"
#include "dyncharqueue.hpp"


using namespace std;

class DynCharQueue;

int main()
{
    unsigned seed;
    seed = time(NULL);
    srand(seed);


    int rotation;

    cout << "how many times do you want STD rotates" << endl;
    cin >> rotation;

#if 1
    State s1(1);
    State s2(2);
    State s3(3);
    State s4(4);

//test
        #endif

#if 1
    
    
    

    s1.SetNext(&s2);
    s2.SetNext(&s3);
    s3.SetNext(&s4);
    s4.SetNext(&s1);
    

    
    State* pCur = &s1;

    DynCharQueue *pEastLane = new DynCharQueue;
    DynCharQueue *pWestLane = new DynCharQueue;
    DynCharQueue *pNorthLane = new DynCharQueue;
    DynCharQueue *pSouthLane = new DynCharQueue;
  
  
    // s3.SetNumOfArriveAt1Light();
    // s3.SetNumOfDepartAt1Light();
    // s3.SetNumOfArriveAt2Light();
    // s3.SetNumOfDepartAt2Light();
    
    for(int i = 1 ; i <= 4*rotation; i++)
    {
        int timeStamp = (i / 4) + 1;

        int a = pCur->GetInfo();

        if(a == 1) // EW G, NS R; cars on E, W lanes can move.
        {
        #if 0
            unsigned seed;
            seed = time(NULL);
            srand(seed);
            
            int randNum[4];
            
            for(int i = 0; i < 4; i++)
               randNum[i] = rand() % 5 + 4;
           
           
            
            s1.SetNumOfArriveAt1Light(randNum[0]);
            s1.SetNumOfDepartAt1Light(randNum[1]);
            s1.SetNumOfArriveAt2Light(randNum[2]);
            s1.SetNumOfDepartAt2Light(randNum[3]);
            
            s1.SetNumOfCarsAt1Light();
            s1.SetNumOfCarsAt2Light();

    #endif
            /*moving control part*/
          #if 1 // after making it into a module.
           
           int eastArrive = s1.nrOfArriveAt1Light();
           int eastDepart = s1.nrOfDepartAt1Light();
           int westArrive = s1.nrOfArriveAt2Light();
           int westDepart = s1.nrOfDepartAt2Light();
           #if 0
          cout << "test 2" << endl;
           cout <<  s1.nrOfArrive() << endl;
           cout <<  s1.nrOfDepart() << endl;
           cout <<  s1.nrOfArrive() << endl;
           cout <<  s1.nrOfDepart() << endl;
           cout <<  s1.nrOfArrive() << endl;
           cout <<  s1.nrOfDepart() << endl;
           cout << "test end " << endl;
          #endif
                  s1.SetNumOfCarsAt1Light();
                  s1.SetNumOfCarsAt2Light();
      
          #endif
      
              /*queue control part*/
      
          s1.Arrive(pEastLane, timeStamp, eastArrive);
          s1.Depart(pEastLane, eastDepart);
          s1.Arrive(pWestLane, timeStamp, westArrive);
          s1.Depart(pWestLane, westDepart);


            /*display part*/


            cout << "EW G" << endl;
            cout << "NS R" << endl << endl;
            cout << "Number of cars arriving at E light : "  << s1.GetNumOfArriveAt1Light() << endl;
            cout << "Number of cars departing at E light : " << s1.GetNumOfDepartAt1Light()<< endl;
            cout << "Number of cars arriving at W light : "  << s1.GetNumOfArriveAt2Light()<< endl;
            cout << "Number of cars departing at W light : " << s1.GetNumOfDepartAt2Light() << endl << endl;

            cout << "Number of cars at E light : " << s1.GetNumOfCarsAt1Light() << endl;
            cout << "Number of cars at W light : " << s1.GetNumOfCarsAt2Light()<< endl;
            cout << "Number of cars at N light : " << s3.GetNumOfCarsAt1Light() << endl;
            cout << "Number of cars at S light : " << s3.GetNumOfCarsAt2Light()<< endl << endl;
           

            /*queue print*/

             cout << "queue print" << endl << endl;
             cout << "east lane" <<endl;
             pEastLane->Print(); 
         
             cout << endl << "west lane" <<endl;
             pWestLane->Print(); 
             cout << endl << "north lane" <<endl;
             pNorthLane->Print(); 
             cout << endl <<  "south lane" <<endl;
             pSouthLane->Print();
             cout << endl;
        
        
        }
        else if(a == 2)// EW Y, NS R; cars on every lane can not move.  
        {
            
            /*display part */
            cout << "EW Y" << endl;
            cout << "NS R" << endl << endl;
            cout << "Number of cars at E light : " << s1.GetNumOfCarsAt1Light() << endl;
            cout << "Number of cars at W light : " << s1.GetNumOfCarsAt2Light() << endl; 

            cout << "Number of cars at N light : " << s3.GetNumOfCarsAt1Light() << endl;
            cout << "Number of cars at S light : " << s3.GetNumOfCarsAt2Light() << endl << endl;
   


            /*queue display*/

            cout << "queue print" << endl << endl;
            cout << "east lane" <<endl;
            pEastLane->Print();
        
            cout << endl << "west lane" <<endl;
            pWestLane->Print();
            cout << endl << "north lane" <<endl;
            pNorthLane->Print(); 
            cout << endl <<  "south lane" <<endl;
            pSouthLane->Print();
            cout << endl; 


        
        
        }
        else if(a == 3)//EW R, NS G; cars on N, S lanes can move.
        {
        #if 0
            unsigned seed;
            seed = time(NULL);
            srand(seed);
           
           int randNum[4];
            
            for(int i = 0; i < 4; i++)
            randNum[i] = rand() % 5 + 4;
            
            
            
            s3.SetNumOfArriveAt1Light(randNum[0]);
            s3.SetNumOfDepartAt1Light(randNum[1]);
            s3.SetNumOfArriveAt2Light(randNum[2]);
            s3.SetNumOfDepartAt2Light(randNum[3]);
            
            s3.SetNumOfCarsAt1Light();
            s3.SetNumOfCarsAt2Light();
        #endif
        #if 1
        /*moving control part*/
        
             int NorthArrive = s3.nrOfArriveAt1Light();
             int NorthDepart = s3.nrOfDepartAt1Light();
             int SouthArrive = s3.nrOfArriveAt2Light();
             int SouthDepart = s3.nrOfDepartAt2Light();
        #if 0
            cout << "test 2" << endl;
             cout <<  s3.nrOfArrive() << endl;
             cout <<  s3.nrOfDepart() << endl;
             cout <<  s3.nrOfArrive() << endl;
             cout <<  s3.nrOfDepart() << endl;
             cout <<  s3.nrOfArrive() << endl;
             cout <<  s3.nrOfDepart() << endl;
             cout << "test end " << endl;
        
        #endif
                            s3.SetNumOfCarsAt1Light();
                            s3.SetNumOfCarsAt2Light();
        /*queue control part*/
        
            s3.Arrive(pNorthLane, timeStamp, NorthArrive);
            s3.Depart(pNorthLane, NorthDepart);
            s3.Arrive(pSouthLane, timeStamp, SouthArrive);
            s3.Depart(pSouthLane, SouthDepart);
        
        
                #endif

            /*display part*/
            
            cout << "EW R" << endl;
            cout << "NS G" << endl << endl;
            cout << "Number of cars arriving at N light : "  <<  s3.GetNumOfArriveAt1Light()   << endl;
            cout << "Number of cars departing at N light : " <<  s3.GetNumOfDepartAt1Light()   << endl;
            cout << "Number of cars arriving at S light : "  <<  s3.GetNumOfArriveAt2Light()   << endl;
            cout << "Number of cars departing at S light : " <<  s3.GetNumOfDepartAt2Light()   << endl << endl;
            
            cout << "Number of cars at E light : " << s1.GetNumOfCarsAt1Light()<< endl;
            cout << "Number of cars at W light : " << s1.GetNumOfCarsAt2Light()<< endl;
            cout << "Number of cars at N light : " << s3.GetNumOfCarsAt1Light() << endl;
            cout << "Number of cars at S light : " << s3.GetNumOfCarsAt2Light() << endl << endl;
        
            /*queue display*/    
            cout << "queue print" << endl << endl;
            cout << "east lane" <<endl;
            pEastLane->Print(); 
        
            cout << endl << "west lane" <<endl;
            pWestLane->Print(); 
            cout << endl << "north lane" <<endl;
            pNorthLane->Print(); 
            cout << endl <<  "south lane" <<endl;
            pSouthLane->Print();
            cout << endl; 
        
        }
        else if(a == 4)//EW R, NS Y; cars on every lane can not move.
        {
            /*display part*/
            cout << "EW R" << endl;
            cout << "NS Y" << endl << endl;
            cout << "Number of cars at E light : " << s1.GetNumOfCarsAt1Light()<< endl;
            cout << "Number of cars at W light : " << s1.GetNumOfCarsAt2Light()<< endl; 
                                                                               
            cout << "Number of cars at N light : " << s3.GetNumOfCarsAt1Light()<< endl;
            cout << "Number of cars at S light : " << s3.GetNumOfCarsAt2Light()<< endl << endl;
  
            /*queue display*/
             cout << "queue print" << endl << endl;
             cout << "east lane" <<endl;
             pEastLane->Print(); 
         
             cout << endl << "west lane" <<endl;
             pWestLane->Print(); 
             cout << endl << "north lane" <<endl;
             pNorthLane->Print(); 
             cout << endl <<  "south lane" <<endl;
             pSouthLane->Print();
             cout << endl; 



      
        
        }
        sleep(1); 
        pCur = pCur->GetNext(); // moving to next node
    }





 
#endif
    return 0;
}