#include "Test.h"
#include <iostream>
#include <vector>
using namespace std;

int findClosestMatch(vector<int> sorted_coins, int value, int start, int end)
{
	int half = (start + end) / 2;
	int current = sorted_coins[half];
	int next = (half+1 < sorted_coins.size()) ? sorted_coins[half+1] : 10000000;

	if (current == value)
		return current;
	else if (current < value && next > value)
		return current;
	else if (current < value && next < value)
		return findClosestMatch (sorted_coins, value, half+1, sorted_coins.size()-1);
	else
		return findClosestMatch (sorted_coins, value, 0, half-1);
}

int findClosestMatch(vector<int> sorted_coins, int value)
{
	return findClosestMatch(sorted_coins, value, 0, sorted_coins.size()-1);
}

int maxTimes(int Amount, int x)
{
	int val = ( Amount / x );
	return val*x;
}


vector<int> makeChange(vector<int> sorted_coins, int amount)
{
	int currentChange = 0;
	int changeRemaining = amount;
	vector<int>answer;

	while(changeRemaining != 0)
	{
	currentChange = maxTimes(changeRemaining, findClosestMatch(sorted_coins, changeRemaining));
	answer.push_back(currentChange);
	changeRemaining -= currentChange;
	}

    return answer;
}

int main ()
{

    test();
    return 0;
}
