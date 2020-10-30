#include <iostream>
#include <unordered_set>
#include <cstddef>
#include <string>
#include <map>

typedef std::unordered_set<std::string> stringSet;
typedef std::map<char, bool> mcb;

void getPermutation(const std::string& inputString, stringSet &permutations, 
					std::string tempString, mcb &isCharacterAdded)	{
	if (tempString.length() == inputString.length())	{
		permutations.insert(tempString);
	}

	else for (auto character : inputString)	{
		// jump to the next iteration if the character already added.
		if (isCharacterAdded[character]) continue;
		else {
			isCharacterAdded[character] = true;
			getPermutation(inputString, permutations, tempString + character, isCharacterAdded);
			isCharacterAdded[character] = false;
		}
	}
}

std::unordered_set<std::string> getPermutations(const std::string& inputString)
{
    // generate all permutations of the input string
    stringSet permutations;
    mcb isCharacterAdded;
    std::string tempString = "";
    
    for (auto character : inputString)  {
        isCharacterAdded[character] = true;
        getPermutation(inputString, permutations, tempString + character, isCharacterAdded);
        isCharacterAdded[character] = false;
    }

    if (permutations.size() == 0)    {
        permutations.insert("");
    }

    return permutations;
}