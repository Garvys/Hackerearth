#include <iostream>
#include <map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
    	int E;
    	cin >> E;
    	map<int,bool> myMap;
    	for (int i = 0; i < E; ++i)
    	{
    		int X1, X2;
    		cin >> X1 >> X2;
    		myMap[X1] = true;
    		myMap[X2] = true;
    	}
    	cout << myMap.size() << endl;
    }
    return 0;
}
