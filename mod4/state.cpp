/********************************************************************************** 

**  Program Filename : state.cpp

**	Author: Woohyuk Yang

**  Date: May. 5th. 2016

** Description: CS162 ModF

** Input : 

** Output :  STD simulation
************************************************************************************/
#include "state.hpp"


/********************************************************************* 
** Function : State Constructor
** Description : A constructor for a state class
** Parameters : info which can refer objects.(int i) 
** Pre-Conditions : int variable letting a user know which object means which situation.
** Post-Conditions : setting number of cars at each lane 10 initially. 
*********************************************************************/
        State::State(int i)
        {
           // direction = d;
            info = i;        
            numOfCarsAt1Light = 10;
            numOfCarsAt2Light = 10;
        
        }
/********************************************************************* 
** Function : SetInfo
** Description : setting a number as a reference to certain state.
** Parameters : int i(info)
** Pre-Conditions : decision on which state is which number.
** Post-Conditions : setting parameter to info variable
*********************************************************************/
        void State::SetInfo(int i)
        {
            info = i;
        }
/********************************************************************* 
** Function : GetInfo
** Description : returning the value of info variable
** Parameters : n/a
** Pre-Conditions : SetInfo function
** Post-Conditions : this function returns a value stored in info variabl
*********************************************************************/      
	    int State::GetInfo()
        {
            return info;
        }
/********************************************************************* 
** Function : SetNext
** Description : setting a pointer variable to class State to "next" poiter variable
** Parameters : State* p
** Pre-Conditions : State Constructor
** Post-Conditions : setting a pointer variable to "next" pointer variable
*********************************************************************/
void State::SetNext(State* p)
        {
            next = p;
        }
/********************************************************************* 
** Function : GetNext
** Description : returning the address of next pointer variable is pointing to
** Parameters : n/a
** Pre-Conditions : SetNext
** Post-Conditions : this function returns value(address) stored in next. 
*********************************************************************/      
State* State::GetNext()
        {
            return next;
        }
/********************************************************************* 
** Function : SetNumOfCarsAt1Light
** Description : calculating the number of cars left on 1 lane 
** Parameters :  none
** Pre-Conditions : GetNumOfArriveAt1Light(),  GetNumOfDepartAt1Light()
** Post-Conditions : setting the number of cars at 1 Light. 
*********************************************************************/
void State::SetNumOfCarsAt1Light()
        {
           int a = GetNumOfArriveAt1Light();
           int d = GetNumOfDepartAt1Light();
           numOfCarsAt1Light += a -d;
        }
/********************************************************************* 
** Function : GetNumOfCarsAt1Light
** Description : returning the number of cars left on 1 lane 
** Parameters :  none
** Pre-Conditions : SetNumOfCarsAt1Light
** Post-Conditions : returning the number of cars left on 1Light. 
*********************************************************************/     
        int State::GetNumOfCarsAt1Light()
        {   
           if(numOfCarsAt1Light <= 0)
            return 0;

            return numOfCarsAt1Light;
        }
/********************************************************************* 
** Function : SetNumOfCarsAt2Light
** Description : calculating the number of cars left on 2 lane 
** Parameters :  none
** Pre-Conditions : GetNumOfArriveAt2Light(),  GetNumOfDepartAt2Light()
** Post-Conditions : setting the number of cars at 2 Light. 
*********************************************************************/
void State::SetNumOfCarsAt2Light()
        {
           int a = GetNumOfArriveAt2Light();
           int d = GetNumOfDepartAt2Light();
           numOfCarsAt2Light += a -d;
        }
/********************************************************************* 
** Function : GetNumOfCarsAt2Light
** Description : returning the number of cars left on 2 lane 
** Parameters :  none
** Pre-Conditions : SetNumOfCarsAt2Light
** Post-Conditions : returning the number of cars left on 2Light. 
*********************************************************************/      
        int State::GetNumOfCarsAt2Light()
        {
           if(numOfCarsAt2Light <= 0)
            return 0;
            
            return numOfCarsAt2Light;
        }
        
/********************************************************************* 
** Function : nrOfArriveAt1Light()
** Description : setting randomly made number to number of cars arriving at 1 light
** Parameters : int n (the number of arrival )
** Pre-Conditions : randomly made number 
** Post-Conditions : setting randomly made arrival number of cars to numOfArriveAt1Light variable
*********************************************************************/        
        int State::nrOfArriveAt1Light()
        { 
          //  unsigned seed;
          //  seed = time(NULL);
         //   srand(seed);
            
            int randNum = rand() % 5 + 4;

            SetNumOfArriveAt1Light(randNum);
        
            return randNum;
        }
/********************************************************************* 
** Function : nrOfDepartAt1Light()
** Description : returning the value of numOfArrriveAt1Light
** Parameters : n/a
** Pre-Conditions : SetNumOfArriveAt1Light
** Post-Conditions : this function returns the value stored in numOfArriveAt1Light 
*********************************************************************/      
        int State::nrOfDepartAt1Light()
        {
         //   unsigned seed;
         //   seed = time(NULL);
         //   srand(seed);
            
            int randNum = rand() % 9;
        
            SetNumOfDepartAt1Light(randNum);
            return randNum;
        }
/********************************************************************* 
** Function : nrOfArriveAt2Light()
** Description : setting randomly made number to number of cars arriving at 2 light
** Parameters : int n (the number of arrival )
** Pre-Conditions : randomly made number 
** Post-Conditions : setting randomly made arrival number of cars to numOfArriveAt2Light variable
*********************************************************************/        
        int State::nrOfArriveAt2Light()
        { 
        //    unsigned seed;
        //    seed = time(NULL);
        //    srand(seed);
            
            int randNum = rand() % 5 + 4;

            SetNumOfArriveAt2Light(randNum);
        
            return randNum;
        }
/********************************************************************* 
** Function : nrOfDepartAt2Light()
** Description : returning the value of numOfArrriveAt2Light
** Parameters : n/a
** Pre-Conditions : SetNumOfArriveAt2Light
** Post-Conditions : this function returns the value stored in numOfArriveAt2Light 
*********************************************************************/      
        int State::nrOfDepartAt2Light()
        {
         //   unsigned seed;
         //   seed = time(NULL);
         //   srand(seed);
            
            int randNum = rand() % 9;
        
            SetNumOfDepartAt2Light(randNum);
            return randNum;
        }
/********************************************************************* 
** Function : SetNumOfArriveAt1Light()
** Description : setting randomly made number to number of cars arriving at 1 light
** Parameters : int n (the number of arrival )
** Pre-Conditions : randomly made number 
** Post-Conditions : setting randomly made arrival number of cars to numOfArriveAt1Light variable
*********************************************************************/        
        void State::SetNumOfArriveAt1Light(int n)
        { 
            numOfArriveAt1Light = n;
        }
/********************************************************************* 
** Function : GetNumOfArriveAt1Light()
** Description : returning the value of numOfArrriveAt1Light
** Parameters : n/a
** Pre-Conditions : SetNumOfArriveAt1Light
** Post-Conditions : this function returns the value stored in numOfArriveAt1Light 
*********************************************************************/      
        int State::GetNumOfArriveAt1Light()
        {
            return numOfArriveAt1Light;
        }
/********************************************************************* 
** Function : SetNumOfArriveAt2Light()
** Description : setting randomly made number to number of cars arriving at 2 light
** Parameters : int n (the number of arrival )
** Pre-Conditions : randomly made number 
** Post-Conditions : setting randomly made arrival number of cars to numOfArriveAtr2Light variable
*********************************************************************/        
void State::SetNumOfArriveAt2Light(int n)
        {
            numOfArriveAt2Light = n;
        }
/********************************************************************* 
** Function : GetNumOfArriveAt2Light()
** Description : returning the value of numOfArrriveAt2Light
** Parameters : n/a
** Pre-Conditions : SetNumOfArriveAt2Light
** Post-Conditions : this function returns the value stored in numOfArriveAt2Light 
*********************************************************************/         
        int State::GetNumOfArriveAt2Light()
        {
            return numOfArriveAt2Light;
        }
        
/********************************************************************* 
** Function : SetNumOfDepartAt1Light()
** Description : setting randomly made number to number of cars departing at 1 light
** Parameters : int n (the number of depart )
** Pre-Conditions : randomly made number 
** Post-Conditions : setting randomly made arrival number of cars to numOfDepartAt1Light variable
*********************************************************************/  
void State::SetNumOfDepartAt1Light(int n)
        {
            numOfDepartAt1Light = n;
        }
/********************************************************************* 
** Function : GetNumOfDepartAt1Light()
** Description : returning the value of numOfDpartAt1Light
** Parameters : n/a
** Pre-Conditions : SetNumOfDepartAt1Light
** Post-Conditions : this function returns the value stored in numOfDepartAt1Light 
*********************************************************************/  
        int State::GetNumOfDepartAt1Light()
        {
            return numOfDepartAt1Light;
        }
        
/********************************************************************* 
** Function : SetNumOfDepartAt2Light()
** Description : setting randomly made number to number of cars departing at 2 light
** Parameters : int n (the number of depart )
** Pre-Conditions : randomly made number 
** Post-Conditions : setting randomly made arrival number of cars to numOfDepartAt2Light variable
*********************************************************************/  
void State::SetNumOfDepartAt2Light(int n)
        {
            
            numOfDepartAt2Light = n;
        }
/********************************************************************* 
** Function : GetNumOfDepartAt2Light()
** Description : returning the value of numOfDpartAt2Light
** Parameters : n/a
** Pre-Conditions : SetNumOfDepartAt2Light
** Post-Conditions : this function returns the value stored in numOfDepartAt2Light 
*********************************************************************/  
        int State::GetNumOfDepartAt2Light()
        {
            return numOfDepartAt2Light;
        }
/********************************************************************* 
** Function : SetEastWaitSum()
** Description : setting waittime for the lane to the variable eastWaitSum
** Parameters : int n 
** Pre-Conditions : randomly made depart number 
** Post-Conditions :setting waittime for the lane to the variable eastWaitSum
*********************************************************************/  
void State::SetEastWaitSum(int n)
        {
            
            eastWaitSum = n;
        }
/********************************************************************* 
** Function : GetEastWaitSum()
** Description : returning the value stored in waittime variable
** Parameters : n/a
** Pre-Conditions : SetEastWaitSum
** Post-Conditions : this function returns the value stored in eastWaitTime. 
*********************************************************************/  
        int State::GetEastWaitSum()
        {
            return eastWaitSum;
        }

/********************************************************************* 
** Function : SetWestWaitSum()
** Description : setting waittime for the lane to the variable westWaitSum
** Parameters : int n 
** Pre-Conditions : randomly made depart number 
** Post-Conditions :setting waittime for the lane to the variable westtWaitSum
*********************************************************************/  
void State::SetWestWaitSum(int n)
        {
            
            westWaitSum = n;
        }
/********************************************************************* 
** Function : GetWestWaitSum()
** Description : returning the value stored in waittime variable
** Parameters : n/a
** Pre-Conditions : SetWestWaitSum
** Post-Conditions : this function returns the value stored in westWaitTime. 
*********************************************************************/  
        int State::GetWestWaitSum()
        {
            return westWaitSum;
        }

/********************************************************************* 
** Function : SetNorthWaitSum()
** Description : setting waittime for the lane to the variable northWaitSum
** Parameters : int n 
** Pre-Conditions : randomly made depart number 
** Post-Conditions :setting waittime for the lane to the variable northWaitSum
*********************************************************************/  
void State::SetNorthWaitSum(int n)
        {
            
            northWaitSum = n;
        }
/********************************************************************* 
** Function : GetNorthWaitSum()
** Description : returning the value stored in waittime variable
** Parameters : n/a
** Pre-Conditions : SetNorthWaitSum
** Post-Conditions : this function returns the value stored in northWaitTime. 
*********************************************************************/  
        int State::GetNorthWaitSum()
        {
            return northWaitSum;
        }
/********************************************************************* 
** Function : SetSouthWaitSum()
** Description : setting waittime for the lane to the variable southWaitSum
** Parameters : int n 
** Pre-Conditions : randomly made depart number 
** Post-Conditions :setting waittime for the lane to the variable southWaitSum
*********************************************************************/  
void State::SetSouthWaitSum(int n)
        {
            
            southWaitSum = n;
        }
/********************************************************************* 
** Function : GetSouthWaitSum()
** Description : returning the value stored in waittime variable
** Parameters : n/a
** Pre-Conditions : SetSouthWaitSum
** Post-Conditions : this function returns the value stored in southWaitTime. 
*********************************************************************/  
        int State::GetSouthWaitSum()
        {
            return southWaitSum;
        }

/********************************************************************* 
** Function : Arrive
** Description : adding cars to the queue.(arrival of cars)
** Parameters : DynCharQueue* , int, int
** Pre-Conditions : queue like structure 
** Post-Conditions : the queue the cars which arrived has beend added.
*********************************************************************/  
void State::Arrive(DynCharQueue* pQueue, int timeStamp, int num)
        {
          for(int i = 0; i < num; i++)
            pQueue->add(timeStamp);
        }
/********************************************************************* 
** Function : Depart
** Description : removing cars from the queue(departure of cars)
** Parameters : DynCharQueue*, int 
** Pre-Conditions : queue like structure
** Post-Conditions : this function removes the number of cars of departure and returns the car 
					which is at the front of the queue. 
*********************************************************************/  
        int State::Depart(DynCharQueue* pQueue, int num)
        {
             cout << endl << "cars departing" << endl;
                int entry = pQueue->GetFront()->GetLetter();
         
            for(int i = 0; i < num; i++)
            {   
                cout <<  pQueue->remove();
                cout << " ";
            }
            cout << endl;
            return entry;
        }
