#include <iostream>
#include <vector>

using namespace std;

size_t changePossibilities(int amount, const vector<int>& denominations)
{
    // calculate the number of ways to make change
    vector<size_t> waysOfDoingNCents(amount + 1); // vector of zeros from 0..amount
	waysOfDoingNCents[0] = 1;

	for (const int coin : denominations) {
		for (int higherAmount = coin; higherAmount <= amount; ++higherAmount) {
			int higherAmountRemainder = higherAmount - coin;
			waysOfDoingNCents[higherAmount] += waysOfDoingNCents[higherAmountRemainder];
		}
	}    

    return waysOfDoingNCents[amount];
}