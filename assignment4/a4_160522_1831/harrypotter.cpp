/********************************************************************************** 

**  Program Filename : harrypotter.cpp

**	Author: Woohyuk Yang

**  Date: May.8th. 2016

** Description: CS162 Assignment3

** Input : creature names and features.

** Output : a simulation program letting two creatures fight till the result comes up. 
************************************************************************************/
#include "harrypotter.hpp"

/********************************************************************* 
** Function : Harry_Potter Constructor
** Description : A constructor for a medusa class
** Parameters : none
** Pre-Conditions : creature name, strength points, armor valule, some functions for randomly rolling dice
** Post-Conditions : setting some values to medusa object. 
*********************************************************************/
Harry_Potter::Harry_Potter()
{// setting each creatures own features in its constructor
    SetStrength(10);
    SetName("Harry Potter");
    SetArmor(0);
    
    lifeChance = 1; //harry has "Hogwarts" skill. when this variable is 1, he has another chance to fight again. when he revives this variable is set to be 0 and that's harry's last chacne.
 
 //gyetting ready to roll dices randomly
    unsigned seed;
    seed = time(NULL);
    srand(seed);



    cout << "Harry_Potter made" << endl;
}

/********************************************************************* 
** Function : attack
** Description : fighter's attack function
** Parameters : none
** Pre-Conditions : creature's constructor
** Post-Conditions : returns attack points 
*********************************************************************/
#if 1
int Harry_Potter::attack()
{  
    int att = 0;

    for(int i = 0; i < 2; i++)
      att += rand() % 6 + 1;
    
    cout << endl <<" harry potter attack" << " " << att << endl;
    
    return att;

}
#endif

/********************************************************************* 
** Function : defense
** Description : fighter's defense function
** Parameters : none
** Pre-Conditions : creature's constructor
** Post-Conditions : creature defenses and cocerning the damage calculate the strength points newly  
*********************************************************************/
#if 1
void Harry_Potter::defense(int a)
{
    int def = 0;
    int tempSt = strength;
    cout << "Harry Potter defense ";
     def += rand() % 10 + 1;
   
    cout << def << endl;
    tempSt -= a - def - armor;
    
    if(tempSt >= strength)
    {
        cout << this->GetName() << " damage is 0" << endl;
        strength = strength;
    }
    else if(tempSt < strength)
    {
        cout << this->GetName() << " damage is " << a-def-armor<< endl;
        strength = tempSt;
    }

/*harry has "Hogwarts" skill. when this variable is 1, he has another chance to fight again. when he revives this variable is set to be 0 and that's harry's last chacne.
 
 *below logic deals with that */
 
    if(strength <= 0)
    {
        if(lifeChance == 1)
        {
            cout << "harry's second chance" << endl;
            strength = 20;
            lifeChance = 0;
        }
        else if(lifeChance == 0)
        {
            cout << "this was harry's last chance" << endl;
        }

        
    }

    
}
#endif

/********************************************************************* 
** Function : SetLifeChacne
** Description : setting number to harry's life chance
** Parameters : integer n
** Pre-Conditions : harry object 
** Post-Conditions : harry's life chance gets changed.
*********************************************************************/
void Harry_Potter::SetLifeChance(int n)
{
    lifeChance = n;
}

/********************************************************************* 
** Function : GetLifeChance
** Description : return harry's life chance
** Parameters : none
** Pre-Conditions : harry's object
** Post-Conditions : return the value stored in variable(LifeChance)
*********************************************************************/
int Harry_Potter::GetLifeChance()
{
    return lifeChance;
}
