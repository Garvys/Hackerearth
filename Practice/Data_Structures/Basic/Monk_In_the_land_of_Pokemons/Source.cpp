#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
    	int N;
    	cin >> N;
    	vector<int> foodPossesed(1000001,0);
    	int res(0);
    	for (int i = 0; i < N; ++i)
    	{
    		int A, B;
    		cin >> A >> B;
    		foodPossesed[A]++;
    		if(foodPossesed[B] == 0)
    			res++;
    		else
    			foodPossesed[B]--;
    	}
    	cout << res << endl;
    }
    return 0;
}
