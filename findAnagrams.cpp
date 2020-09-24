std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> anagramsIndex;
    // sort p
    std::sort(p.begin(), p.end());
    int endIndex= s.length() - p.length();
    std::string substrOfS{""};
        
    for (int startIndex = 0; startIndex <= endIndex; ++startIndex) {
        if (substrOfS == "") {
            substrOfS = s.substr(startIndex, p.length());
        }
        else {
            substrOfS = substrOfS.substr(startIndex, p.length() - 1);
            substrOfS+= s[startIndex + p.length() - 1];
        }
            
        std::sort(substrOfS.begin(), substrOfS.end());
        if (substrOfS == p) {
            anagramsIndex.push_back(startIndex);
        }
    }
        
    return anagramsIndex;
}