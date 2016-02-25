#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	std::vector<int> input;
	for (int t = 0; t < T; ++t)
	{
		int N;
		cin >> N;
		input.push_back(N);
	}

	int maxInput = *max_element(input.begin(), input.end());

	int exposantMax = 0;
	while (exposantMax*exposantMax*exposantMax <= maxInput)
		exposantMax++;

	std::vector<int> goodNums;

	for (int i = 1; i <= exposantMax; ++i)
	{
		for (int j = 1; j <= exposantMax; ++j)
		{
			if (i != j)
				goodNums.push_back(i*i*i + j*j*j);
		}
	}

	sort(goodNums.begin(), goodNums.end());

	for (int i = 0; i < input.size(); ++i)
	{
		int N = input[i];
		int good = -1;
		for (int j = 0; j < goodNums.size(); ++j)
		{
			if (goodNums[j] <= N && count(goodNums.begin(), goodNums.end(), goodNums[j]) > 2)
			{
				good = goodNums[j];
			}
			if (goodNums[j] > N)
				break;
		}
		cout << good << endl;
	}

	return 0;
}
