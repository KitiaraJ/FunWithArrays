#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	//variables
	string in("");
	int asci[128] = {0};
	int i = 0;

	//prompt the user for a string
	cout << "Please input a string and I will count the frequency of the characters within: ";
	getline(cin, in);

	//counts the ascii characters 
	while (i < in.length()) {
		
		int a = (int)in[i];
		asci[a] = (asci[a]) + 1;  //Increase count by one
		i++;
	}

    //for loop to print out the results
	for (i = 0; i < 128; i++)
	{
		if (asci[i] != 0) //prints only the non-zero values of the array
		{
			cout << (char)i << ": " << asci[i] << endl;
		}
	}

	system("pause>nil");
	return 0;
}