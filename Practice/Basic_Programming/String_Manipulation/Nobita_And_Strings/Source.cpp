#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#include <climits>

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	for (int t = 0; t < T; ++t)
	{
		string s;
		getline(cin,s);

	  	istringstream iss(s);
	  	vector<string> v;
	    do
	    {
	        string sub;
	        iss >> sub;
	        v.push_back(sub);

	    } while (iss);

		for (int i = v.size()-1; i >= 0; i--)
		{
			if(v[i].size() > 0)
				cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}