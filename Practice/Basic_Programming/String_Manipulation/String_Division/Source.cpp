#include <iostream>
#include <string>
#include <map>
using namespace std;

int getNbOfDifferentChars(string s)
{
	map<char,int> myMap;
	for (char c : s)
	{
		myMap[c] = 1;
	}
	return (int)myMap.size();
}

bool bruteforce(string s)
{
	int N = (int)s.size();
	//Contient la position de fin de la chaine i
	int posEndPartition[3];
	for (posEndPartition[0] = 0; posEndPartition[0] <= (N - 4); posEndPartition[0]++)
	{
		for (posEndPartition[1] = posEndPartition[0]+1; posEndPartition[1] <= (N - 3); posEndPartition[1]++)
		{
			for (posEndPartition[2] = posEndPartition[1]+1; posEndPartition[2] <= (N - 2); posEndPartition[2]++)
			{
				string s1 = s.substr(0, posEndPartition[0] - 0 + 1);
				string s2 = s.substr(posEndPartition[0] + 1, posEndPartition[1] - (posEndPartition[0] + 1) + 1);
				string s3 = s.substr(posEndPartition[1] + 1, posEndPartition[2] - (posEndPartition[1] + 1) + 1);
				string s4 = s.substr(posEndPartition[2] + 1, N-1 - (posEndPartition[2] + 1) + 1);

				bool A = (s1 != s2);
				bool B = (s1 != s3);
				bool C = (s1 != s4);
				bool D = (s2 != s3);
				bool E = (s2 != s4);
				bool F = (s3 != s4);

				if (A && B && C && D && E && F)
					return true;

			}
		}
	}
	return false;
}

bool isFourPartionable(string s)
{
	//Pas assez de caractères pour avoir le nombre min de partition 
	if ((int)s.size() < 4)
		return false;

	int nbCharDifferent = getNbOfDifferentChars(s);
	
	//Si il n'y a qu'un caractere alors il faut des partitons de taille 1,2,3,4 => au moins 10
	if (nbCharDifferent == 1)
		return (int)s.size() >= 10;
	//Cas non trivial
	if (nbCharDifferent == 2 || nbCharDifferent == 3)
		return bruteforce(s);
	//4 caractère différents garantis d'avoir 4 partitions différentes
	if (nbCharDifferent >= 4)
		return true;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		if (isFourPartionable(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}
