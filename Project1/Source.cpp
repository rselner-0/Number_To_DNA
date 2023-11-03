//Project1.cpp
//This project converts large numbers to sequences of DNA nucleotides based off of T=0, C=1, A=2 and G=3.
//Codons are displayed as grouped together between vertical lines (eg. | A T G | T A A | A G A |...).
#include <iostream>
#include <cmath>

using namespace std;

struct values
{
	bool negative = false;
	bool flag = true;
	unsigned long long number = 0;
}n;

void get_number(values* n);
void turn_to_DNA(values* n);

int main()
{
	while (n.flag == true)
	{
		get_number(&n);
		if (n.number != 0)
		{
			turn_to_DNA(&n);
		}
		else
		{
			cout << "~Ok Bye!~\n";
		}
	}
	return 0;
}

void get_number(values* n)
{
	cout << "\tEnter 0 to quit or\nEnter a number less than 18,446,744,073,709,551,616.\n" << endl;
	cin >> n->number;
	cout << "\n";
	if (n->number == 0)
	{
		n->flag = false;
	}
}

void turn_to_DNA(values* n)
{
	double array[50] = {};
	int size = floor(log(n->number) / log(64));
	int counter = 0;
	while (n->number > 63)
	{
		array[size - counter] = n->number % 64;
		n->number -= n->number % 64;
		n->number /= 64;
		counter++;
	}
	array[0] = n->number;

	for (int i = 0; i < counter + 1; i++)
	{
		cout << " | ";
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
		array[i] /= 16;
		array[i] -= floor(array[i]);
		if (array[i] * 4 >= 3)
		{
			cout << "G ";
		}
		else if (array[i] * 4 >= 2)
		{
			cout << "A ";
		}
		else if (array[i] *4 >= 1)
		{
			cout << "C ";
		}
		else if (array[i] *4 >= 0)
		{
			cout << "T ";
		}
		array[i] *= 4;
		array[i] -= floor(array[i]);
		if (array[i] * 4 == 3)
		{
			cout << "G";
		}
		else if (array[i] * 4 == 2)
		{
			cout << "A";
		}
		else if (array[i] * 4== 1)
		{
			cout << "C";
		}
		else if (array[i] *4 == 0)
		{
			cout << "T";
		}
	}
	cout << " |\n" << endl;
}