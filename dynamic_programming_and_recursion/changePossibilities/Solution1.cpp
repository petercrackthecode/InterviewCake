#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>

using namespace std;

typedef std::vector<int> vi;

void changePosssibilitiesRecursion(int index, const int &amount, const vi &coins, int &waysToReturn) {
    if (amount - coins[index] == 0)	{
    	++waysToReturn;
    }
    else if (amount - coins[index] < 0)	{
    	// Do nothing because cannot change more money than the input money;
    }
    else { // amount - coins[index] > 0
    	for (int jumpSteps = 1; index + jumpSteps < coins.size(); ++jumpSteps)  {
    		changePosssibilitiesRecursion(index + jumpSteps, amount - coins[index], coins, waysToReturn);
    	}

    	changePosssibilitiesRecursion(index, amount - coins[index], coins, waysToReturn);
    }
}

std::size_t changePossibilities(int amount, const vi &denominations)
{
    // calculate the number of ways to make change
    int waysToReturn{0};

    vi coins;
    
    if (denominations.size() <= 0 || amount < 0)  {
        return 0;
    }
    else if (amount == 0)   {
        return 1;
    }

    for (auto denomination : denominations)	{
    	coins.push_back(denomination);
    }

    std::sort(coins.begin(), coins.end());
    
    if (coins[0] > amount) {
        return 0;
    }

    std::size_t biggerThanAmountIndex = 0;

    while (biggerThanAmountIndex < denominations.size() && coins[biggerThanAmountIndex] <= amount)	{
    	++biggerThanAmountIndex;
    }

    coins.erase(coins.begin() + biggerThanAmountIndex, coins.end());

    for (std::size_t startIndex = 0; startIndex < coins.size(); ++startIndex)   {
        if (amount - coins[startIndex] == 0)	{
        	++waysToReturn;
        }
        else if (amount - coins[startIndex] < 0)	{
        	// Do nothing because cannot change more money than the input money;
        }
        else { // amount - coins[startIndex] > 0
            for (int jumpSteps = 1; startIndex + jumpSteps < coins.size(); ++jumpSteps)  {
        		changePosssibilitiesRecursion(startIndex + jumpSteps, amount - coins[startIndex], coins, waysToReturn);
        	}
    
        	changePosssibilitiesRecursion(startIndex, amount - coins[startIndex], coins, waysToReturn);
        }
    }

    return waysToReturn;
}