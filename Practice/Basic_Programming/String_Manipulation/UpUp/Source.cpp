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
	string line;
	getline(cin,line);
	for(int i = 0; i < (line.size()-1); i++)
	{
		if(i == 0 && line[0] >= 'a' && line[0] <= 'z')
		{
			line[0] = toupper(line[0]);
			continue;
		}
		if (line[i] == ' ' && line[i+1] >= 'a' && line[i+1] <= 'z')
		{
			line[i+1] = toupper(line[i+1]);
		}
	}
	cout << line;
	return 0;
}