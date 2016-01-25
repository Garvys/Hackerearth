#include <iostream>
#include <string>
//#include <regex>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
#include <climits>

//Algorithm Trailing Zero cf Wikipedia

int main()
{
	int N(0);
	cin >> N;

	int res = 0;
	int puissance5 = 1;

	int k = 0;
	while(1)
	{
		puissance5 *= 5;
		if(puissance5 > N)
			break;
		k++;
	}

	puissance5 = 1;
	for (int i = 1; i <= k; ++i)
	{
		puissance5 *= 5;
		res += (n/ puissance5);
	}
	cout << res << endl;

}