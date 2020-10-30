#include <iostream>
#include <unordered_set>
#include <cstddef>
#include <string>
#include <map>

typedef std::unordered_set<std::string> stringSet;
typedef std::map<char, bool> mcb;

unordered_set<string> getPermutations(const std::string& inputString)	{
	std::unordered_set<std::string> permutations;

	// base case
	if (inputString.length() <= 1)	{
		permutations.insert(inputString);
		return permutations;
	}

	std::string allCharsExceptLast = inputString.substr(0, inputString.length() - 1);
	char lastChar = inputString[inputString.length() - 1];
	
	// recursive call: get all possible permutations for all chars except last
	const auto permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

	//	put the last char in all possible positions for each of the above permutations
	for (const string& permutationOfAllCharsExceptLast : permutationsOfAllCharsExceptLast)	{
		for (size_t position = 0; position <= allCharsExceptLast.length(); ++position)	{
			std::string permutation = permutationOfAllCharsExceptLast.substr(0, position)
				+ lastChar + permutationOfAllCharsExceptLast.substr(position);
			permutations.insert(permutation);
		}
	}

	return permutations;
}