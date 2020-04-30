// link: https://www.interviewcake.com/question/cpp/permutation-palindrome?course=fc1&section=hashing-and-hash-tables
bool hasPalindromePermutation(const string& str)
{
    // check if any permutation of the input is a palindrome
    std::vector<int> charactersCount(127, 0);
    
    bool hadAUniqueCharacter{false};
    
    for (char ch : str) {
        ++charactersCount[ch];
    }
    
    for (int aCharacterCount : charactersCount) {
        if (aCharacterCount > 0) {
            if (aCharacterCount % 2 != 0) {
                if (!hadAUniqueCharacter) {
                    hadAUniqueCharacter= true;
                }
                else {
                    return false;
                }
            }
        }
    }
    
    return true;
}