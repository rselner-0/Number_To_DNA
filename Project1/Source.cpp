//Project1.cpp
//This project can convert large numbers to sequences of DNA nucleotides based off of T=0, C=1, A=2 and G=3.
//Codons are displayed as being grouped together between vertical lines (eg. | A T G | T A A | A G A |...).
#include <iostream>
#include <cmath>

using namespace std;

struct values //We want to hold our number, as well as a boolean variable which ends repetition, in this struct.
{
	bool flag = true;
	unsigned long long number = 0; //We want to use the largest data type possible.
}n;

void get_number(values* n); //This function gets the value from the user,
void turn_to_DNA(values* n);//and this function converts it into the string of nucleotide bases grouped into codons.

int main() //Our main function just repeats asking for a number and spitting out the sequence until the user enters a 0.
{
	while (n.flag == true) //Our boolean value determines whether or not we will repeat the program.
	{
		get_number(&n);
		if (n.number != 0) //The condition for the sequence to be displayed is that the number is not zero.
		{
			turn_to_DNA(&n);
		}
		else //If the user enters a 0, this parting message is displayed.
		{
			cout << "~Ok Bye!~\n";
		}
	}
	return 0;
}

void get_number(values* n) //We define our function for acquiring a number from the user here.
{
	cout << "\tEnter 0 to quit or\nEnter a number less than 18,446,744,073,709,551,616.\n" << endl;
	cin >> n->number;
	cout << "\n";
	if (n->number == 0) //Here is where the condition for repetition to end is stated.
	{
		n->flag = false;
	}
}

void turn_to_DNA(values* n) //We define our function for converting the number to a sequence of nucleotide triplets.
{
	double array[11] = {}; //Only 11 elements are required to be initialized for the array.
	int size = floor(log(n->number) / log(64)); //How large the array is will be determined by this definition.
	int counter = 0; //A tally variable is initialized to zero here.
	while (n->number > 63) //The number is converted to a base-64 number in this while loop.
	{
		array[size - counter] = n->number % 64; //The number modulus 64 is placed in the array in a descending-index manner,
		n->number -= n->number % 64; //The number has this value subtracted from it and the resulting difference replaces the number,
		n->number /= 64; //The new number is then divided by the base (64 in this case),
		counter++; //and finally the tally variable is incremented. This process repeats until the number is less than 64.
	}
	array[0] = n->number; //Once we have the number whittled down to the last base-64 digit, it is placed in the 0-index for the array.

	for (int i = 0; i < counter + 1; i++) //Here, we determine the codon sequence associated with the base-64 digits in the array
	{
		cout << " | "; //Beginning with a vertical separatng line, followed by the first nucleotide in the codon,
		if (array[i] / 16 >= 3)
		{
			cout << "G ";
		}
		else if (array[i] / 16 >= 2)
		{
			cout << "A ";
		}
		else if (array[i] / 16 >= 1)
		{
			cout << "C ";
		}
		else if (array[i] / 16 >= 0)
		{
			cout << "T ";
		}
		array[i] /= 16; //Then the digit is divided by 16, 
		array[i] -= floor(array[i]); //and the whole-number value that determined the first nucleotide is removed.
		array[i] *= 4; //Next, the second nucleotide is determined by multiplying the remainder by 4,
		if (array[i] >= 3)
		{
			cout << "G ";
		}
		else if (array[i] >= 2)
		{
			cout << "A ";
		}
		else if (array[i] >= 1)
		{
			cout << "C ";
		}
		else if (array[i] >= 0)
		{
			cout << "T ";
		}
		array[i] -= floor(array[i]); //And then that whole-number value is subtracted from what is left.
		array[i] *= 4; //Finally, the last base is found by multiplying the remainder by 4.
		if (array[i] == 3)
		{
			cout << "G";
		}
		else if (array[i] == 2)
		{
			cout << "A";
		}
		else if (array[i] == 1)
		{
			cout << "C";
		}
		else if (array[i] == 0)
		{
			cout << "T";
		}
	}
	cout << " |\n" << endl; //Once the sequence is finished, the last vertical separator line caps off the last codon.
}