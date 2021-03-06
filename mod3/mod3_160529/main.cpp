
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
#include <deque>


using namespace std;

class DynCharQueue;

int main()
{
    unsigned seed;
    seed = time(0);
    srand(1);


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
#if 0
    DynCharQueue *pEastLane = new DynCharQueue;
    DynCharQueue *pWestLane = new DynCharQueue;
    DynCharQueue *pNorthLane = new DynCharQueue;
    DynCharQueue *pSouthLane = new DynCharQueue;
#endif

#if 1 //after adoptng dequeu STL container
    deque<int> eastLane;
    deque<int> westLane;
    deque<int> northLane;
    deque<int> southLane;

    //filling each queues, each lanes have 10 cars at first 
    for(int i = 0; i < 10; i++)
    {
        eastLane.push_back(0);
        westLane.push_back(0);
        northLane.push_back(0);
        southLane.push_back(0);
    }

    cout << "test" <<endl;
    for(int i = 0; i < 10; i++)
    {
        cout << eastLane[i] << " "; 
    }
        cout << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << westLane[i] << " "; 
    }
        cout << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << northLane[i] << " "; 
    }
        cout << endl;
    
    for(int i = 0; i < 10; i++)
    {   
        cout << southLane[i] << " "; 
    } 
    cout << "test endl" << endl;
#endif
  
            int eastWaitSum = 0;
            int westWaitSum = 0;
            int northWaitSum = 0;
            int southWaitSum = 0;
  
    
    for(int i = 1 ; i <= 4*rotation; i++)
    {
        int timeStamp = (i / 4) + 1;

        int a = pCur->GetInfo();

        if(a == 1) // EW G, NS R; cars on E, W lanes can move.
        {
            /*moving control part*/
          #if 1 // after making it into a module.
           
           int eastArrive = s1.nrOfArriveAt1Light();
           int eastDepart = s1.nrOfDepartAt1Light();
           int westArrive = s1.nrOfArriveAt2Light();
           int westDepart = s1.nrOfDepartAt2Light();
                  s1.SetNumOfCarsAt1Light();
                  s1.SetNumOfCarsAt2Light();


          #endif
      
              /*queue control part*/
     #if 0 
          s1.Arrive(pEastLane, timeStamp, eastArrive);
          eastWaitSum += timeStamp - (s1.Depart(pEastLane, eastDepart) + 1);
          s1.SetEastWaitSum(eastWaitSum);
          s1.Arrive(pWestLane, timeStamp, westArrive);
           westWaitSum += timeStamp - (s1.Depart(pWestLane, westDepart) + 1);
          s1.SetWestWaitSum(westWaitSum);
            cout << "east wait " << eastWaitSum  << "west wait " << westWaitSum << endl;
    #endif
    #if 1
    printf("%s : %d\n",__FILE__,__LINE__);
        /*queue add*/
        for(int i = 0; i < eastArrive; i++)  
          eastLane.push_back(timeStamp);
        
        int eastEntry;

        /*getting wait sum to get average wait time later*/
        eastWaitSum += timeStamp - (eastLane.front() + 1);
          s1.SetEastWaitSum(eastWaitSum);

    printf("%s : %d\n",__FILE__,__LINE__);
       
       /*queue remove and display*/

        for(int i = 0; i < eastDepart; i++)
        {
            cout << eastLane.front() << " ";
            eastLane.pop_front();
        }

    printf("%s : %d\n",__FILE__,__LINE__);
        
        /*queue add*/
        for(int i = 0; i < westArrive; i++)  
           westLane.push_back(timeStamp);   
       
        /*getting wait sum to get average wait time later*/
       westWaitSum += timeStamp - (westLane.front() + 1);
          s1.SetWestWaitSum(westWaitSum);

        
       /*queue remove and display*/
        for(int i = 0; i < westDepart; i++)
        {
            cout << westLane.front() << " ";
            westLane.pop_front();
        }


            cout << "east wait " << eastWaitSum  << "west wait " << westWaitSum << endl;

    #endif
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
            #if 0
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
            #endif
        
        }
        else if(a == 2)// EW Y, NS R; cars on every lane can not move.  
        {
            
            /*display part */
            cout << endl;
            cout << "EW Y" << endl;
            cout << "NS R" << endl << endl;
            cout << "Number of cars at E light : " << s1.GetNumOfCarsAt1Light() << endl;
            cout << "Number of cars at W light : " << s1.GetNumOfCarsAt2Light() << endl; 

            cout << "Number of cars at N light : " << s3.GetNumOfCarsAt1Light() << endl;
            cout << "Number of cars at S light : " << s3.GetNumOfCarsAt2Light() << endl << endl;
   


            /*queue display*/
           #if 0
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
            #endif

        
        
        }
        else if(a == 3)//EW R, NS G; cars on N, S lanes can move.
        {
        #if 1
        /*moving control part*/
        
             int NorthArrive = s3.nrOfArriveAt1Light();
             int NorthDepart = s3.nrOfDepartAt1Light();
             int SouthArrive = s3.nrOfArriveAt2Light();
             int SouthDepart = s3.nrOfDepartAt2Light();
                            s3.SetNumOfCarsAt1Light();
                            s3.SetNumOfCarsAt2Light();
        /*queue control part*/

        #if 0
        
            s3.Arrive(pNorthLane, timeStamp, NorthArrive);
           northWaitSum += timeStamp - (s3.Depart(pNorthLane, NorthDepart) + 1);
           s3.SetNorthWaitSum(northWaitSum);
           s3.Arrive(pSouthLane, timeStamp, SouthArrive);
            southWaitSum += timeStamp - (s3.Depart(pSouthLane, SouthDepart) + 1);
            
           s3.SetSouthWaitSum(southWaitSum);


            cout << "north wait " << northWaitSum  << "south wait " << southWaitSum << endl;
        #endif
    #if 1
        /*queue add*/
        for(int i = 0; i < NorthArrive; i++)  
          northLane.push_back(timeStamp);
        
        /*getting wait sum to get average wait time later*/
        northWaitSum += timeStamp - (northLane.front() + 1);
          s3.SetNorthWaitSum(northWaitSum);

       
       /*queue remove and display*/
        for(int i = 0; i < NorthDepart; i++)
        {
            cout << northLane.front() << " ";
            northLane.pop_front();
        }

        
        /*queue add*/
        for(int i = 0; i < SouthArrive; i++)  
           southLane.push_back(timeStamp);   
       
        /*getting wait sum to get average wait time later*/
       southWaitSum += timeStamp - (southLane.front() + 1);
          s3.SetSouthWaitSum(southWaitSum);

        
       /*queue remove and display*/
        for(int i = 0; i < SouthDepart; i++)
        {
            cout << southLane.front() << " ";
            southLane.pop_front();
        }


            cout << "north wait " << northWaitSum  << "south wait " << southWaitSum << endl;

    #endif

                #endif

            /*display part*/
            
            cout << endl;
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
            #if 0
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
            #endif
        }
        else if(a == 4)//EW R, NS Y; cars on every lane can not move.
        {
            /*display part*/
            cout << endl;
            cout << "EW R" << endl;
            cout << "NS Y" << endl << endl;
            cout << "Number of cars at E light : " << s1.GetNumOfCarsAt1Light()<< endl;
            cout << "Number of cars at W light : " << s1.GetNumOfCarsAt2Light()<< endl; 
                                                                               
            cout << "Number of cars at N light : " << s3.GetNumOfCarsAt1Light()<< endl;
            cout << "Number of cars at S light : " << s3.GetNumOfCarsAt2Light()<< endl << endl;
  
            /*queue display*/
             #if 0
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
            #endif

        /* getting average wait time for a time unit*/
        // dividing the total waiting time by the number of cars

        
        int nrOfEast = s1.GetNumOfCarsAt1Light();
        int nrOfWest = s1.GetNumOfCarsAt2Light();
        int nrOfNorth = s3.GetNumOfCarsAt1Light();
        int nrOfSouth = s3.GetNumOfCarsAt2Light();

        cout << "nrOfEast " << nrOfEast << endl;
        cout << "nrOfwest " << nrOfWest << endl;
        cout << "nrOfnorth " << nrOfNorth << endl;
        cout << "nrOfsouth " << nrOfSouth << endl;


        int eastWaitSum = s1.GetEastWaitSum(); 
        int westWaitSum = s1.GetWestWaitSum();
        int northWaitSum = s3.GetNorthWaitSum();
        int southWaitSum = s3.GetSouthWaitSum();
        
        cout << "eastWaitt " << eastWaitSum << endl;
        cout << "westWait "  << westWaitSum << endl;
        cout << "northWait " << northWaitSum << endl;
        cout << "southWait " << southWaitSum << endl;
        
        int eastAverage = 4 * eastWaitSum / nrOfEast;
        int westAverage = 4 * westWaitSum / nrOfWest;
        int northAverage =4 * northWaitSum / nrOfNorth;
        int southAverage =4 * southWaitSum / nrOfSouth;



        cout << "Average wait time for East lane is " << eastAverage << " minutes" <<endl; 
        cout << "Average wait time for West lane is " << westAverage << " minutes" <<endl;
        cout << "Average wait time for North lane is " << northAverage << " minutes" <<endl;
        cout << "Average wait time for South lane is " << southAverage << " minutes" <<endl;

      
        
        }
        //sleep(1); 
        
        
        pCur = pCur->GetNext(); // moving to next node
    }





 
#endif
    return 0;
}
