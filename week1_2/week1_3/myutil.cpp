#include "mymenu.hpp"


void Input()
{
    int row_size;
    cout << "enter integer for rows of the grid" << endl;
    cin >> row_size;
    
    while((cin.fail()) || row_size == 0)
    {
       // cout << "invalid! enter integer for rows of the grid" << endl;
        cin.clear();
        cin.ignore(100000,'\n');
        cout << "invalid! enter integer for rows of the grid" << endl;
        cin >> row_size;
    }
    while( row_size > ROW_MAX )
    {
         cout << "too big value, make it at most " << ROW_MAX  << endl;
         cin >> row_size;
    }

    int column_size;
    cout << "enter integer for rows of the grid" << endl;
    cin >> column_size;
    
    while((cin.fail()) || column_size == 0)
    {
       // cout << "invalid! enter integer for rows of the grid" << endl;
        cin.clear();
        cin.ignore(100000,'\n');
        cout << "invalid! enter integer for rows of the grid" << endl;
        cin >> column_size;
    }
    while( column_size > COLUMN_MAX )
    {
         cout << "too big value, make it at most " << COLUMN_MAX  << endl;
         cin >> column_size;
    }
}
