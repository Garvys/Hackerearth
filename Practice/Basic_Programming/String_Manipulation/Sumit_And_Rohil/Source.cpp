#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
using namespace std;

#define endl '\n'
class FluxIO
{
public:
	FluxIO(string name_in, string name_out)
	{
		this->name_in = name_in;
		this->name_out = name_out;
		this->useStandardIn = false;
		this->useStandardOut = false;
		this->inputFileOpened = false;
		this->outputFileOpened = false;
	}
	~FluxIO()
	{
		//Fermeture des fichiers
		if (inputFileOpened)
			fichier_in.close();
		if (outputFileOpened)
			fichier_out.close();
	}
	void checkInputFileOpened()
	{
		if (!useStandardIn && !inputFileOpened)
		{
			fichier_in.open(name_in, ios::in);
			if (!fichier_in)
				cerr << "Impossible d'ouvrir le fichier d'entrée" << endl;
			else
				this->inputFileOpened = true;
		}
	}
	void checkOutputFileOpened()
	{
		if (!useStandardOut && !outputFileOpened)
		{
			fichier_out.open(name_out, ios::out | ios::trunc);
			if (!fichier_out)
				cerr << "Impossible d'ouvrir le fichier de sortie" << endl;
			else
				outputFileOpened = true;
		}
	}
	template<class Type>
	ostream& operator<<(Type X)
	{
		checkOutputFileOpened();
		useStandardOut ? cout << X : fichier_out << X;
		return useStandardOut ? cout : fichier_out;
	}
	template<class Type>
	istream& operator>>(Type& X)
	{
		checkInputFileOpened();
		useStandardIn ? cin >> X : fichier_in >> X;
		return useStandardIn ? cin : fichier_in;
	}
	template<class Type>
	ostream& operator<<(vector<Type> X)
	{
		checkOutputFileOpened();
		for (int i = 0; i < (int)X.size(); i++)
			useStandardOut ? cout << X[i] << " " : fichier_out << X[i] << " ";
		return useStandardOut ? cout : fichier_out;
	}
	template<class Type>
	istream& operator>>(vector<Type>& X)
	{
		checkInputFileOpened();
		for (int i = 0; i < (int)X.size(); i++)
			useStandardIn ? cin >> X[i] : fichier_in >> X[i];
		return useStandardIn ? cin : fichier_in;
	}
	void useStandardInput(bool b)
	{
		useStandardIn = b;
	}
	void useStandardOutput(bool b)
	{
		useStandardOut = b;
	}
private:
	string name_in;
	string name_out;
	ifstream fichier_in;
	ofstream fichier_out;
	bool useStandardOut;
	bool useStandardIn;
	bool inputFileOpened;
	bool outputFileOpened;
};

class Anagram
{
public:
	Anagram(){}
	Anagram(string s)
	{
		map<char, int>::iterator it;
		for (int i = 0; i < (int)s.size(); i++)
		{
			 it = myMap.find(s[i]);
			 if (it != myMap.end())
				 it->second++;
			 else
				 myMap[s[i]] = 1;
		}
	}
	map<char, int> getMap()
	{
		return myMap;
	}
private:
	map<char,int> myMap;
};

class Partition
{
public:
	Partition(string s)
	{
		this->names.push_back(s);
		this->firstChar = s[0];
		this->lastChar = s[s.length() - 1];
		this->anagram = Anagram(s);
	}
	void add(string s)
	{
		names.push_back(s);
	}
	bool verifyCondition(char first, char last, Anagram anagram)
	{
		return ((first == this->firstChar)
			&& (last == this->lastChar)
			&& (this->anagram.getMap() == anagram.getMap()));
	}
private:
	vector<string> names;
	char firstChar;
	char lastChar;
	Anagram anagram;

};

int getNbPartition(vector<string>& names)
{
	int N = (int)names.size();
	vector<Partition> v_partition;
	for (int i = 0; i < (int)names.size(); i++)
	{
		bool added = false;
		Anagram aCour(names[i]);
		for (int j = 0; j < (int)v_partition.size(); j++)
		{
			if (v_partition[j].verifyCondition(names[i].front(), names[i].back(), aCour))
			{
				added = true;
				v_partition[j].add(names[i]);
				break;
			}
		}
		if (!added)
		{
			v_partition.push_back(Partition(names[i]));
		}
	}
	return v_partition.size();
}

int main()
{
	FluxIO flux("in.txt", "out.txt");
	flux.useStandardInput(false);
	flux.useStandardOutput(false);

	int N(0);
	flux >> N;
	vector<string> names;

	for (int i = 0; i < N; i++)
	{
		string name;
		flux >> name;
		names.push_back(name);
	}

	flux << getNbPartition(names);

	return 0;
}

