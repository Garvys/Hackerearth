#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
    	string s;
    	cin >> s;
    	int size = (int)s.size();
    	for(int i = size - 1; i >= 0; i--)
    		cout << s[i];
    	cout << endl;
    }
    
    return 0;
}
