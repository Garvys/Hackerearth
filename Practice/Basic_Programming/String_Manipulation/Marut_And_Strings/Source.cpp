#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
#include <climits>

int main()
{
	int T;
	cin >> T; cin.ignore();
	if(T < 1 || T > 10)
	{
		cout << "Invalid Test" << endl;
		return 0;
	}

	for (int t = 0; t < T; ++t)
	{
		string s;
		getline(cin,s);
		if(s.size() == 0 || s.size() > 100)
		{
			cout << "Invalid Input" << endl;
			continue;
		}

		int nbLowerCase = 0;
		int nbUppercase = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			char charCour = s[i];
			if(charCour >= 'a' && charCour <= 'z')
				nbLowerCase++;
			if(charCour >= 'A' && charCour <= 'Z')
				nbUppercase++;
		}
		if(nbUppercase == 0 && nbLowerCase == 0)
		{
			cout << "Invalid Input" << endl;
			continue;			
		}
		cout << min(nbLowerCase,nbUppercase) << endl;

	}
	return 0;
}