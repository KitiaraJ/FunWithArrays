/* 
    Kitiara See
    EH9
    
Problem Reads:
    Create a structure Mouse that has data members Name and height.
    In your code create 8 different mice in a loop. Use 8 different mouse 
    names and 8 random heights. (We have the ^ operator for exponentiation.)
    Find and display the mouse with the smallest size and the mouse 
    with the largest size.
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Mouse
{
	char Name;   //name
	int height;  //height
};

void sort(int a[], int b) 
{
        //initializers for the function
	int i;
	int mini;
	int minv;
    
        //Selection sort method
	for (i = 0; i < (b - 1); i++)
	{
		mini = i;
		minv = a[i];

		for (int j = i + 1; j < b; j++)
		{
			if (a[j] < minv)
			{
				minv = a[j];
				mini = j;
			}
		}
		a[mini] = a[i];
		a[i] = minv;
	}
}




int main()
{
        //Initializing arrays
	Mouse m[8];
	int x[8];

        //Fills the structure with mice
	for (int i = 0; i < 8; i++)
	{
		m[i].Name = 'a' + i ;
		m[i].height = rand() % 13;
	}

        //Displays the mice
	for (int i = 0; i < 8; i++)
	{
		cout << "My name is: " << m[i].Name;
		cout << " and I am " << m[i].height << " inches tall!" << endl;
	}
	
	//Puts the heights into alternative array for sorting
	for (int j = 0; j < 8; j++)
	{
		x[j] = m[j].height;
	}
    
        //Sorts the mice heights for easy search
	sort(x, 8);
    
        //displays smallest and largest mouse
	cout << "The smallest mouse height is: " << x[0] << " inches" << endl;
	cout << "The biggest mouse height is: " << x[7] << " inches" << endl;

	system("pause>nil");
	return 0;
}

/*
The output looks like this:

    My name is: a and I am 2 inches tall!
    My name is: b and I am 7 inches tall!
    My name is: c and I am 3 inches tall!
    My name is: d and I am 6 inches tall!
    My name is: e and I am 7 inches tall!
    My name is: f and I am 7 inches tall!
    My name is: g and I am 12 inches tall!
    My name is: h and I am 4 inches tall!
    The smallest mouse height is: 2 inches
    The biggest mouse height is: 12 inches
*/