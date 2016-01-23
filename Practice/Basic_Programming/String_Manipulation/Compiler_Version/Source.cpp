#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
#include <climits>
//Ici on va effectuer le boulot en deux temps:
//-Une premiere passe qui détecter les commentaires
//-Une seconde qui va remplacer le code voulus

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
	void getline(string &s)
	{
		checkInputFileOpened();
		string temp;
		std::getline(fichier_in, temp);
		s.append(temp);
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

void transformLineNoRegex(string &s)
{
	int pos_comment = INT_MAX;
	std::size_t found_comment = s.find("//");
	if (found_comment != std::string::npos)
		pos_comment = found_comment;
	while (1)
	{
		std::size_t found = s.find("->");
		if (found == std::string::npos || found > pos_comment)
			break;
		s.replace(found, 2, ".");
	}
}

void transformLine(string &s)
{
	smatch m_comment;
	regex e_comment("(//)(.*)");
	regex_search(s, m_comment, e_comment);
	int pos_comment = INT_MAX;
	if (m_comment.size()>0)
		pos_comment = m_comment.position(0);
	smatch m;
	regex e("(->)");
	string s_copy(s);
	while (regex_search(s_copy, m, e))
	{
		int pos = m.position(0);
		if (pos < pos_comment)
			s.replace(s.begin() + pos, s.begin() + pos + 2, ".");
		s_copy.replace(s_copy.begin() + pos, s_copy.begin() + pos + 2, ".");
	}
}

int main()
{
	FluxIO flux("in.txt","out.txt");
	flux.useStandardInput(false);
	flux.useStandardOutput(false);

	string line;
	flux.getline(line);
    do
    {
		transformLineNoRegex(line);
    	
    	flux << line << endl;
    	line.clear();
    	flux.getline(line);
    }while(!line.empty());
    return 0;
}
