// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

const int n = 10;
const int riba = 100;

void skaitymas(int skaiciai[]);
void skaiciavimas(int skaiciai[], int& atsakymas);
void isvedimas(int atsakymas);

int main()
{
	int skaiciai[riba];
	int atsakymas;
		skaitymas(skaiciai);
		skaiciavimas(skaiciai, atsakymas);
		isvedimas(atsakymas);
}
void skaitymas(int skaiciai[])
{
	ifstream fd("duom.txt");
	for (int i = 1; i <= n; i++)
	{
		fd >> skaiciai[i];
	}
}
void skaiciavimas(int skaiciai[], int& atsakymas)
{
	int suma[riba];
	for (int i = 1; i <= n; i++)
	{
		suma[i] = 0;
		for (int j = 1; j <= n; j++)
		{
			suma[i] += skaiciai[j];
		}
		suma[i] = suma[i] - skaiciai[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j && suma[i] == skaiciai[j])
				atsakymas = suma[i];
		}
	}
}
void isvedimas(int atsakymas)
{
	ofstream out("rez.txt");
	out << atsakymas << endl;
}

