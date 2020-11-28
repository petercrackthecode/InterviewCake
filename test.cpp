class Change {
private:
	unordered_map<string, size_t> memo_;

public:
	size_t changePossibilitiesTopDown(int amountLeft, 
									  const vector<int> &denominations, 
									  size_t currentIndex = 0) {
		// check our memo and short-circuit if we've already solved this one.
		ostringstream oss;
		oss << amountLeft << ", " << currentIndex;
		string memoKey = oss.str();

		auto it = memo_.find(memoKey);
		if (it != memo_.end()) {
			std::cout << "grabbing memo[" << amountLeft << ", "
					  << currentIndex << "]\n";
			return it->second;
		}

		// base cases:
		// we hit the amount spot on. yes!
		if (amountLeft == 0)
			return 1;

		// we overshot the amount left (used too many coins)
		if (amountLeft < 0)
			return 0;

		// we're out of denominations
		if (currentIndex == denominations.size())
			return 0;

		cout << "checking ways to make " << amountLeft << " with [";

		for (size_t i = currentIndex; i < denominations.size(); ++i) {
			if (i > currentIndex) {
				std::cout << ", ";
			}
			cout << denominations[i];
		}
		cout << "]\n";

		// choose a current coin
		int currentCoin = denominations[currentIndex];

		// see how many possibilities we can get
		// for each number of times to use currentCoin
		size_t numPossibilities = 0;
		while (amountLeft >= 0) {
			numPossibilities += changePossibilitiesTopDown(amountLeft, denominations, currentIndex + 1);
			amountLeft -= currentCoin;
		}

		// save the answer in our memo so we don't compute it again
		memo_.insert(make_pair(memoKey, numPossibilities));
		return numPossibilities;
	}
}