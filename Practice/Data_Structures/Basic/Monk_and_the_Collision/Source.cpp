#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
    	//cout << "Test : " << t << endl;
    	int N;
    	cin >> N;
    	//cout << "N : " << N<< endl;
    	vector<int> tabHash(10,0);
    	for(int i = 0; i< N; i++)
    	{
    		unsigned long long int X;
    		cin >> X;
    		tabHash[X%10]++;
    		//cout << "Read : " << X << " " << X%10<< endl;
    	}
    	int nbCollision(0);
    	for(int i = 0; i <=9; i++)
    	{
    		if(tabHash[i] > 1)
    			nbCollision += tabHash[i] - 1;
    	}
    	cout << nbCollision << endl;
    }
    return 0;
}
