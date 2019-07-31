/*
    Kitiara See
    EH8

Problem reads:
    Create an array of size N of random integer, 1 ≤ N ≤ 45. Use any sorting 
    technique other than the linear sort to sort the array. Also search the
    array for the values 0, 23, 45. You must do this for arrays of sizes 4, 
    25, 46, 200.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function that sorts the array using selection sort
void sort(int a[], int b) 
{
        //initializers for the function
	int i;
	int mini;
	int minv;
    
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

//Function that searches using binary search
int search(int c[], int d, int n)  
{
        //initializers for the function
	int f = 0;          //first item in the array
	int l = d - 1;      //last item in the array, set to size minus one
	int mid;
	int p = -1;        //set to -1 to show that it doesn't exist in the array
	bool e = false;
	


	while (!e && f <= l)   
	{
		mid = (f + l) / 2;
		
		if (c[mid] == n)        //checks for the value if true, it sets the
		{                       //position to the midpoint
			e = true;
			p = mid;
		}

		else if (c[mid] > n)
		{
			l = mid - 1;        //this is the new starting point in
		}                           //the lower end of the sorted array

		else
		{
			f = mid + 1;        //this is the new starting point in 
		}                           //the upper end of the sorted array
	}

	return p; //returns the first position the value is in
}

void show(const int f[], int g)     //Functions that shows the array
{
	for (int i = 0; i < g; i++)
	{
		cout << f[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int main()
{
        //initializing arrays
	int arr1[4];
	int arr2[25];
	int arr3[46];
	int arr4[200];

        //want to get different random numbers per array
	unsigned seed = time(0);
	srand(seed);
    
        /* The following for loops fill the arrays to the specified size with 
        random numbers */
	for (int i = 0; i < 4; i++)
	{
		arr1[i] = 1 + rand() % 45;
	}

	for (int i = 0; i < 25; i++)
	{
		arr2[i] = 1 + rand() % 45;
	}

	for (int i = 0; i < 46; i++)
	{
		arr3[i] = 1 + rand() % 45;
	}

	for (int i = 0; i < 200; i++)
	{
		arr4[i] = 1 + rand() % 45;
	}

	cout << "The arrays sorted are : " << endl;
	cout << endl;
    
        //calls the sort function to sort the arrays
	sort(arr1, 4);
	sort(arr2, 25);
	sort(arr3, 46);
	sort(arr4, 200);

        //shows the sorted arrays
	show(arr1, 4);
	show(arr2, 25);
	show(arr3, 46);
	show(arr4, 200);

	cout << endl;
	
	/*This group of functions search each of the arrays for 0, 23, and 45 
	respectively */
	cout << search (arr1, 4, 0) << ", ";
	cout << search (arr1, 4, 23) << ", ";
	cout << search (arr1, 4, 45) << endl;
	
	cout << search (arr2, 25, 0) << ", ";
	cout << search (arr2, 25, 23) << ", ";
	cout << search (arr2, 25, 45) << endl;

	cout << search (arr3, 46, 0) << ", ";
	cout << search (arr3, 46, 23) << ", ";
	cout << search (arr3, 46, 45) << endl;

	cout << search (arr4, 200, 0) << ", ";
	cout << search (arr4, 200, 23) << ", ";
	cout << search (arr4, 200, 45) << endl;

	system("pause > nil");
	return 0;
}



/* The output looks like this:

The arrays sorted are :

15 23 29 43

3 3 4 7 8 13 14 15 18 18 20 21 21 22 23 26 26 29 31 32 35 36 36 36 38

1 3 5 5 6 6 6 7 7 7 7 9 10 11 12 13 14 14 15 16 17 17 19 21 21 23 25 27 28 29 
29 30 30 34 36 37 39 40 41 41 42 42 43 43 44 44

1 1 1 1 1 1 1 2 2 2 3 3 3 3 4 4 4 4 5 5 5 6 6 6 6 7 7 7 7 8 8 8 9 9 9 9 10 10 
10 10 10 10 10 11 11 11 11 11 11 11 11 12 12 12 12 12 13 14 14 14 14 15 15 15 
15 15 15 15 15 16 17 17 17 17 17 17 17 18 18 18 19 19 19 19 19 20 20 20 20 21 
21 21 21 21 21 22 22 22 22 22 22 23 23 23 23 24 24 24 24 24 24 25 25 25 25 26 
26 26 26 26 26 27 27 27 27 27 27 28 28 28 28 29 29 30 30 30 31 31 31 31 31 31 
31 31 31 31 32 32 32 32 33 33 33 33 34 34 34 34 34 35 35 35 36 36 36 36 36 37 
37 38 38 38 38 39 39 39 39 40 40 40 40 40 40 40 40 40 41 41 41 42 42 43 44 44 
44 44 44 44 45 45

-1, 1, -1
-1, 14, -1
-1, 25, -1
-1, 102, 198
