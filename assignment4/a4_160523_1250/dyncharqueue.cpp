/********************************************************************************** 

**  Program Filename : dyncharqueue.cpp

**	Author: Woohyuk Yang

**  Date: May. 15th. 2016

** Description: CS162 assignment4

** Input : 

** Output :  making a queue like structure
******************************************************************************/


#include "dyncharqueue.hpp"
#include <iostream>


using namespace std;


/********************************************************************* 
** Function : Constructor
** Description : A constructor for a DynCharQueue class
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : setting pointer variable front and rear to NULL.
*********************************************************************/
DynCharQueue::DynCharQueue()
{
    front = NULL;
    rear = NULL;
}

/********************************************************************* 
** Function : add
** Description : adding a character to the queue like structure.
** Parameters : char 
** Pre-Conditions : DynCharQueue constructor
** Post-Conditions : adding new character to the queue like structure.
*********************************************************************/
void DynCharQueue::add(int n)
{
    if(front == NULL)
    {
        front = new QueueNode(n);
        rear = front;

       if( front->ID == 1)
       {
         front->pFighters = new Medusa;
       }
       else if( front->ID == 2)
       {
         front->pFighters = new Barbarian;
       
       }
       else if( front->ID == 3)
       {
         front->pFighters = new Baba_Yaga;
       
       }
       else if( front->ID == 4)
       {
         front->pFighters = new Blue_men;
       
       }
       else if( front->ID == 5)
       {
         front->pFighters = new Harry_Potter;
       
       }
    }
    else
    {
        QueueNode * pNode = new QueueNode(n);
        
       if( pNode->ID == 1)
       {
         pNode->pFighters = new Medusa;
       }
       else if( pNode->ID == 2)
       {
         pNode->pFighters = new Barbarian;
       
       }
       else if( pNode->ID == 3)
       {
         pNode->pFighters = new Baba_Yaga;
       
       }
       else if( pNode->ID == 4)
       {
         pNode->pFighters = new Blue_men;
       
       }
       else if( pNode->ID == 5)
       {
         pNode->pFighters = new Harry_Potter;
       
       }
        
        
        pNode->prev = rear;
        rear->next = pNode;
        rear = pNode;
		rear->next = NULL;
		front->prev = NULL;
    }

}


/********************************************************************* 
** Function : remove
** Description : removing a character from already exisiting queue like structure.
** Parameters : none
** Pre-Conditions : queue -like structure.
** Post-Conditions : removing a chracter on the top of the queue like structure and return the character being removed.
*********************************************************************/
int DynCharQueue::remove()
{  
    QueueNode *temp;
    if(front == NULL)
    {
        cout << "the queue is empty" << endl;
        return 0;
    }
    else
    {
       temp = front;
       front = front->next;
       delete temp;
       return 1;
    }

}
/********************************************************************* 
** Function : BackToQueue
** Description : The winner goes to the back of the queue.
** Parameters : none
** Pre-Conditions : queue -like structure.
** Post-Conditions : sending the character located at front to the rear(back) of the quqeueue when the chracter wins.
*********************************************************************/
int DynCharQueue::BackToQueue()
{  
    QueueNode *temp = front;
    if(front == NULL)
    {
        cout << "the queue is empty" << endl;
        return 0;
    }
    else
    {

       if(front->next != NULL)
       {
        rear->next = temp;
        rear = rear->next;
        front = temp->next;

        rear->next = NULL;
        front->prev = NULL;
       }
        int num = rear->ID;
       return num;

    
    }

}
/********************************************************************* 
** Function : DeleteQueue
** Description : the function which deletes the queue.
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : deleting the exisiting queue.
*********************************************************************/
void DynCharQueue::DeleteQueue()
{
#if 1
while(front != NULL)
    {
        QueueNode *temp = front;
        
        front = front->next;
        delete temp;
    }
#endif

}
/********************************************************************* 
** Function : PrintQueue()
** Description : A function which prints the creatures stored in the queue.
** Parameters : none
** Pre-Conditions : none
** Post-Conditions : printing out the queue.
*********************************************************************/
void DynCharQueue::PrintQueue()
{

    if(front == NULL)
    cout << "this queue is empty" << endl;

     QueueNode * temp = NULL;
     temp = this->front;
    while(temp != NULL)
    {
 


       cout << "Characters = " << temp->GetCreature()->GetName() << " : strength = " << temp->GetCreature()->GetStrength() << endl; 
        temp = temp->next;

    }

}
/********************************************************************* 
** Function : CountQueue()
** Description : A function to count the number of creatures in the queue
** Parameters : none
** Pre-Conditions : queue constructor
** Post-Conditions : return the number of creatures stored in the queue.
*********************************************************************/
int DynCharQueue::CountQueue()
{
    int num = 0;

    if(front == NULL)
    {
        cout << "this queue is empty" << endl;
        return 0;
    }
     QueueNode * temp = NULL;
     temp = this->front;
    while(temp != NULL)
    {
        temp = temp->next;
        num++;
    }
        return num;
}
/********************************************************************* 
** Function :SortQueue()
** Description : A function to put creatures to an array and sort it to get the finishers
** Parameters : none
** Pre-Conditions : queue constructor
** Post-Conditions : sort the queue and place the creatures in another array. .
*********************************************************************/
void DynCharQueue::SortQueue()
{

/*making a pointer array of Creature*/ 
        int num = CountQueue();
        pCreature = new Creature*[num];
        for(int i = 0; i < num; i++)
        pCreature[i] = NULL;

        QueueNode *temp = front;

/*locating creatures to the array made*/
        while(temp != NULL)
        {
            for(int i = 0; i < num; i++)
            {
                 pCreature[i] = temp->GetCreature();
                temp = temp->next; 
            }
        
        
        }
            Creature *pTemp;

//sorting the array // the criteria is strenth points.
            for(int i = 0; i <num; i++)
            {
                for(int j = 0; j < num; j++)
                {
                     if(pCreature[i] == NULL)
                     {
                         return;
                     }
                    if( (pCreature[i]->GetStrength()) > (pCreature[j]->GetStrength()))
                    {
                        pTemp = pCreature[i];
                        pCreature[i] = pCreature[j];
                        pCreature[j] = pTemp;
                    
                    
                    }
                
                
                }
            
            }



           //   cout << endl << "after sorting " << endl;
            for(int i = 0; i < 3; i++)
            {
                if(pCreature[i] == NULL)
                {
                    return;
                }
              cout << "# " << i+1 << "rank is " << pCreature[i]->GetName() << " : strength power : " << pCreature[i]->GetStrength() << endl;
              
            }






}
