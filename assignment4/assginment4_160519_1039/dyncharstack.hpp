/********************************************************************************** 

**  Program Filename : dyncharstack.hpp

**	Author: Woohyuk Yang

**  Date: May. 15th. 2016

** Description: CS162 Mod2

** Input : 

** Output :  testing stack like structures
******************************************************************************/

#ifndef DYNCHARSTACK_HPP
#define DYNCHARSTACK_HPP
#include <cstdlib>
class DynCharStack
{
    private:
        class StackNode
        {
            friend class DynCharStack;
            int value;
            StackNode *next;
            //constructor
            StackNode(int value1, StackNode *next1 = NULL)
            {
                value = value1;
                next = next1;
            }
        
        };
        StackNode *top;
    public:
        DynCharStack();
        void add(int);
        int remove();

};

#endif
