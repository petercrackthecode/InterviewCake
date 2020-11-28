bool binarySearch(int target, const vector<int> &nums) {
	// see if target appears in nums
	// we think of floorIndex as leftmost edge of the possible positions
	// of our target and ceilingIndex as "wall" on the right of it
	size_t floorIndex = 0;
	size_t ceilingIndex = nums.size();

	// If there isn't at least 1 index between floor and ceiling,
	// we've run out of guesses and the number must not be present
	while (floorIndex <= ceilingIndex) {
		// find the index ~halfway between the floor and ceiling
		// we use integer division, so we'll never get a "half index"
		size_t distance = ceilingIndex - floorIndex;
		size_t halfDistanc = distance / 2;
		size_t guessIndex= floorIndex + halfDistance;

		int guessValue= nums[guessIndex];

		if (guessValue == target) {
			return true;
		}
		else if (guessValue > target) {
			// target is to the left, so move ceiling to the left
			ceilingIndex= guessIndex;
		}
		else {
			// target is to the right, so move floor to the right
			floorIndex= guessIndex + 1;
		}
	}

	return false;
}