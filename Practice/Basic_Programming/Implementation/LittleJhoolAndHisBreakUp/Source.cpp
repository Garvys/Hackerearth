#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define SUCCEEDED "I love you, too!"
#define FAILURE "Let us breakup!"

int main()
{
	string input;
	cin >> input;
	int res = -1;
	res = input.find('l');
	if (res == string::npos)
	{
		cout << FAILURE << endl;
		return 0;
	}
	res = input.find('o',res);
	if (res == string::npos)
	{
		cout << FAILURE << endl;
		return 0;
	}
	res = input.find('v',res);
	if (res == string::npos)
	{
		cout << FAILURE << endl;
		return 0;
	}
	res = input.find('e',res);
	if (res == string::npos)
	{
		cout << FAILURE << endl;
		return 0;
	}
	cout << SUCCEEDED << endl;

	return 0;
}
