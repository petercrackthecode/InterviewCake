std::size_t changePossibilitiesTopDown(int amountLeft, const vector<int> &denominations, std::size_t currentIndex = 0) {
	// base cases:
	// we hit the amount spot on. yes!
	if (amountLeft == 0) {
		return 1;
	}

	// we overshot the amount left (used too many coins)
	if (amountLeft < 0) {
		return 0;
	}

	// we're out of denominations
	if (currentIndex == denominations.size()) {
		return 0;
	}

	std::cout << "checking ways to make " << amountLeft << " with [";
	for (std::size_t i = currentIndex; i < denominations.size(); ++i) {
		if (i > currentIndex) {
			std::cout << ", ";
		}
		std::cout << denominations[i];
	}
	cout << "]" << endl;

	// choose a current coin
	int currentCoin = denominations[currentIndex];

	// see how many possibilities we can get
	// for each number of times to use currentCoin
	std::size_t numPossibilities = 0;

	while (amountLeft >= 0) {
		numPossibilities += changePossibilitiesTopDown(amountLeft, denominations, currentIndex + 1);
		amountLeft -= currentCoin;
	}

	return numPossibilities;
}