/********************************************************************************** 

**  Program Filename : stadium.cpp

**	Author: Woohyuk Yang

**  Date: May.8th. 2016

** Description: CS162 Assignment3

** Input : creature kinds and names

** Output : a simulation program letting two creatures fight till the result comes up. 
************************************************************************************/
#include "stadium.hpp"

/********************************************************************* 
** Function : Stadium Constructor
** Description : A constructor for a Stadium class
** Parameters : none
** Pre-Conditions : double pointer to creature and roundNumber variable
** Post-Conditions : making a list composed of 2 pointer variables pointing to creature objects
					 setting round number to 1.
*********************************************************************/
Stadium::Stadium()
{
/*fight waiting list*/
   pQueue = new DynCharQueue[2];
 
/*fighting ground */
    pFighters = new Creature*[2];
    for(int i = 0; i < 2; i++)
    pFighters[i] = NULL;

    SetRoundNumber(1);

/*loser pile*/
    pStack = new DynCharStack;
}
/********************************************************************* 
** Function : SetRoundNumber
** Description : setting the round number of the fight to roundNumber variable
** Parameters : int roundNumber(round of the fight)
** Pre-Conditions : Stadium constructor, ShowMenu()
** Post-Conditions : setting the round number of fight to roundNumber variable
*********************************************************************/
void Stadium::SetRoundNumber(int r)
{
    roundNumber = r;
}
/********************************************************************* 
** Function : GetRoundNumber
** Description : returning the roundNumber of the fight
** Parameters : n/a
** Pre-Conditions : List constructor
** Post-Conditions : this function returns the value of roundNumber variable.
*********************************************************************/
int Stadium::GetRoundNumber() 
{
    return roundNumber;
}
/********************************************************************* 
** Function : SetNumOfCharacters
** Description : setting the number of characters to fight
** Parameters : int (number of characters)
** Pre-Conditions : Stadium constructor, ShowMenu()
** Post-Conditions : setting the number of the characters to fight to numOfCharacters variable
*********************************************************************/
void Stadium::SetNumOfCharacters(int n)
{
    numOfCharacters = n;
}
/********************************************************************* 
** Function : GetNumOfCharacters
** Description : returning the number of the fighters
** Parameters : n/a
** Pre-Conditions : List constructor
** Post-Conditions : this function returns the value of numOfCharacter variable.
*********************************************************************/
int Stadium::GetNumOfCharacters() 
{
    return numOfCharacters;
}
/********************************************************************* 
** Function : ShowMenu()
** Description : prompting user to choose the action
** Parameters : none
** Pre-Conditions : Stadium constructor
** Post-Conditions : FighterChoose(), Fight(), FightResult(), qutting the program
*********************************************************************/
void Stadium::ShowMenu()
{
  while(1)
  {
    int choose;
    cout << "chose the menu" << endl;
    cout << "1. Fight Start" << endl;
    cout << "2. Program End" << endl;

    cin >> choose;

    while(cin.fail() || ((choose != 1) && (choose != 2)))     //validating process
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << endl << "invalid! input proper number" << endl << endl;
        cin >> choose;
        
    }

#if 1
    if(choose == 1)
   {
        cin.get();
        FighterChoose();
        Fight();
        
    }
    else if(choose == 2 )
    {
        cout << "program end" << endl;
        break;
    } 
#endif  
  }

}

/********************************************************************* 
** Function : FighterChoose()
** Description : prompting user to choose the two fighters
** Parameters : none
** Pre-Conditions : Stadium constructor
** Post-Conditions : Fight(), FightResult()
*********************************************************************/
void Stadium::FighterChoose()
{
#if 0
    cout << "now time to choose the chracters" << endl;
    int choose;

  for(int i = 0; i <2; i++)
  {
    cout << "chose the creatrues to fight" << endl;
    cout << "1. Medusa" << endl;
    cout << "2. Barbarian" << endl;
    cout << "3. Baba Yaga" << endl;
    cout << "4. Blue men" << endl;
    cout << "5. Harry Potter" << endl;

    cin >> choose;
  

    while(cin.fail() || ((choose != 1) && (choose != 2) && (choose != 3) &&(choose !=4) && (choose !=5)))    //validation process
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << endl << "invalid! input proper number" << endl << endl;
        cin >> choose;
        
    }

     
    if(choose == 1)
    {
        cout << "chose Medusa" << endl;
        //medusa object created
            pFighters[i] = new Medusa;
        
        
        cout <<  "medusa created  and";
        cout << "registered as a fighter" << endl;
    }
    else if(choose == 2)
    {
        //barbarian object created
            pFighters[i] = new Barbarian;
        
        
        
        cout << "Barbarian created and";
        cout << "registered as a fighter" << endl;
     
    
    }
    else if(choose == 3)
    {
        //baba yaga object created
            pFighters[i] = new Baba_Yaga;
       
        
        
        cout << "Baba yaga created and";
        cout << "registered as a fighter" << endl;
    
    }
    else if(choose ==4 )
    {
        //blue men object created
            pFighters[i] = new Blue_men;
        
        
        
        cout << "Blue men created" << endl;
        cout << "registered as a fighter" << endl;
    }
    else if(choose == 5 )
    {
        //harry potter object created
          pFighters[i] = new Harry_Potter;
        
        
        
        cout << "Harry potter created" << endl;
        cout << "registered as a fighter" << endl;
    }
#endif
#if 1

//    DynCharQueue team[2];
    int a = 0;

    cout << "now enter the number of fighters" << endl;
    
    int numOfCharacters;

    cin >> numOfCharacters;

    while(cin.fail() || (numOfCharacters <= 0)  )    //validation process
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << endl << "invalid! input proper number" << endl << endl;
        cin >> numOfCharacters;
        
    }

    SetNumOfCharacters(numOfCharacters);

    int num_char = GetNumOfCharacters();

    
for(int i = 0; i < 2; i++)
 {

    int choose;
 #if 1

    cout << "NUm of character:" << numOfCharacters;
  for(int i = 0; i < num_char; i++)
  {
    cout << "chose the creatrues to fight" << endl;
    cout << "1. Medusa" << endl;
    cout << "2. Barbarian" << endl;
    cout << "3. Baba Yaga" << endl;
    cout << "4. Blue men" << endl;
    cout << "5. Harry Potter" << endl;

    cin >> choose;
  

    while(cin.fail() || ((choose != 1) && (choose != 2) && (choose != 3) &&(choose !=4) && (choose !=5)))    //validation process
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << endl << "invalid! input proper number" << endl << endl;
        cin >> choose;
        
    }

     
    if(choose == 1)
    {
        cout << "chose Medusa" << endl;
        pQueue[a].add(1);
        cout << "a" << a << endl; 
        //cout << "ak" << pQueue[a].remove()<< endl;
    }
    else if(choose == 2)
    {
        cout << "chose Medusa" << endl;
        pQueue[a].add(2);
        cout << "a" << a << endl; 
     
    
    }
    else if(choose == 3)
    {
        cout << "chose Medusa" << endl;
        pQueue[a].add(3);
        cout << "a" << a << endl; 
    
    }
    else if(choose ==4 )
    {
        cout << "chose Medusa" << endl;
        pQueue[a].add(4);
        cout << "a" << a << endl; 
    }
    else if(choose == 5 )
    {
        cout << "chose Medusa" << endl;
        pQueue[a].add(5);
        cout << "a" << a << endl; 
        
        
    }


    }
#endif


    a++;

  }
printf("%s:%d\n",__FILE__,__LINE__);
#endif
printf("%s:%d\n",__FILE__,__LINE__);
printf("%s:%d\n",__FILE__,__LINE__);
printf("%s:%d\n",__FILE__,__LINE__);



}


/********************************************************************* 
** Function : Fight()
** Description : Fight happens here in this function
** Parameters : none
** Pre-Conditions : Stadium constructor
** Post-Conditions : FightResult()
*********************************************************************/
void Stadium::Fight()
{
 //bringing the characters in the list to the array.
  // cout << "team A player" <<pQueue[0].GetCreature()->GetName() << endl;
printf("%s:%d\n",__FILE__,__LINE__);
 //  string a = pQueue[1].GetFront()->GetCreature()->GetName();
printf("%s:%d\n",__FILE__,__LINE__);
 //   cout << a << endl; 
 
#if 1 
 
 
 int a = this->GetRoundNumber();

while(1)
    {

       string f1 = pQueue[0].GetFront()->GetCreature()->GetName();
       string f2 = pQueue[1].GetFront()->GetCreature()->GetName();
       
 

        cout << endl << endl << endl << "Round " << a << " Start" << endl << endl;    //new round starts here
        cout << endl << "stregnth points before round " << a << endl;

        int fighter1_sp = pQueue[0].GetFront()->GetCreature()->GetStrength();
        cout << f1 << " has " << fighter1_sp << " strength points left" << endl;
        int fighter2_sp = pQueue[1].GetFront()->GetCreature()->GetStrength();
        cout << f2 << " has " << fighter2_sp  <<" strength points left" << endl << endl;
       
       /*fighter1 attacks and fighter2 defense*/
       sleep(1);
        int fighter1_attack = pQueue[0].GetFront()->GetCreature()->attack();
      //  int fighter1_attack = pFighters[0]->attack();
       sleep(1);
      
        pQueue[1].GetFront()->GetCreature()->defense(fighter1_attack);
       //pFighters[1]->defense(fighter1_attack);
       sleep(1);

       cout << endl;
       /*fighter2 attacks and fighter1 defense*/
        int fighter2_attack = pQueue[1].GetFront()->GetCreature()->attack();
       // int fighter2_attack = pFighters[1]->attack();
       sleep(1);
       // pFighters[0]->defense(fighter2_attack);
        pQueue[0].GetFront()->GetCreature()->defense(fighter2_attack);
       sleep(1);
        
        /*figuring out the result*/
      #if 1
        int result = FightResult(); 
        if(result == 1)
        break;
      #endif
       
        a++;
        this->SetRoundNumber(a);
    }
 
#endif
}
/********************************************************************* 
** Function : FightResult()
** Description : figuring out who won and who lost
** Parameters : none
** Pre-Conditions : Stadium constructor
** Post-Conditions : the result of the fight
*********************************************************************/ 
int Stadium::FightResult()
{
       string f1 = pQueue[0].GetFront()->GetCreature()->GetName();
       string f2 = pQueue[1].GetFront()->GetCreature()->GetName();
     
        int a = this->GetRoundNumber();
     
        int fighter1_sp = pQueue[0].GetFront()->GetCreature()->GetStrength();
        int fighter2_sp = pQueue[1].GetFront()->GetCreature()->GetStrength();

     


   
    if(fighter1_sp <= 0)
    {/*both creatures die*/
        if(fighter2_sp <= 0)
        {
             cout << endl << "The match result!!" << endl << endl;
            cout << f1<< " and "<< f2 << " died." << endl;                 
            this->SetRoundNumber(1);
            //when one is lost then it should be sent to the loser pile and the winner should  go to the back of the queue. 
           







            
            
            
            return 1; 
           
        }
        else if(fighter2_sp > 0)
        {/*fighter1 dies and loose*/
            cout << endl << "The match result!!" << endl << endl;
            cout << f1 << " lost" << endl;        
            this->SetRoundNumber(1);
              return 1;
        }
    }
    else if(fighter1_sp > 0)
    {
        if(fighter2_sp <= 0)
        {/*fighter2 dies and loose*/
            cout << endl << "The match result!!" << endl << endl;
            cout << f2 << " lost" << endl;        
            this->SetRoundNumber(1);
                return 1;
        }   
        if(fighter1_sp >= 100)                                   //if both character's strength points go up over 100 then the game is tie. 
        {
            if(fighter2_sp >= 100)
            {
                cout << endl << "The match result!!" << endl << endl;
                cout <<  " DRAW, both fought well" << endl;        
                this->SetRoundNumber(1);
                return 1;
            }
        }   
    }
    else if( a >= 100)                                          //if round number goes up over 100 then the game is tie. 
    {
        cout << endl << "The match result!!" << endl << endl;
        cout << "DRAW, both fought well." << endl;
        this->SetRoundNumber(1);
        return 1;
    }
    
    return 0;
}






