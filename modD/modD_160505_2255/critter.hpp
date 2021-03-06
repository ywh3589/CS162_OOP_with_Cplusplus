/********************************************************************************** 

**  Program Filename : critter.hpp

**	Author: Woohyuk Yang

**  Date: April. 16th. 2016

** Description: CS162 ModC

** Input : grid size(rows, columns), the number of critters, the number of steps for critters to take

** Output :   A simulating program in which a critter moves on the grid making another critter after moving 3 times
************************************************************************************/
#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <iostream>

using namespace std;

class Critter
{
    private:

    protected:
        int oldX;
        int oldY;
        int x_pos;
        int y_pos;
        int count;
        int starveCount;
    public:
       Critter(); 
       void SetOldX(int x);
       int GetOldX();
       void SetXpos(int x);
       int GetXpos();
       void SetOldY(int y);
       int GetOldY();
       void SetYpos(int y);
       int GetYpos();
       virtual void SetCount(int x)=0;
       virtual int GetCount()=0;
      // virtual void SetStarveCount(int x)=0;
      // virtual int GetStarveCount()=0;
       int CritterMove(int n);
       virtual Critter* Breed()=0;
       virtual Critter* Eat()=0;

};

#endif
