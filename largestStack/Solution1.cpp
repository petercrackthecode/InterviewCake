class MaxStack {
private:
	stack<int> stack_;
	stack<int> maxesStack_;

public:
	// Add a new item to the top of our stack. If the item is greater than
	// or equal to the last item in maxesStack_, it's the new max! So we'll add it
	// to maxesStack_
	void push(int item) {
		stack_.push(item);
		if (maxesStack_.empty() || item >= maxesStack_.top()) {
			maxesStack_.push(item);
		}
	}

	// Remove and return the top item from our stack. If it equals
	// the top item in maxesStack_, they must have been pushed in together.
	// So we'll pop it out of maxesStack_ too.
	int pop() {
		int item = stack_.top();
		stack_.pop();
		if (item == maxesStack_.top()) {
			maxesStack_.pop();
		}

		return item;
	}

	// The last item in maxesStack is the max item in our stack.
	int getMax() const {
		return maxesStack_.top();
	}
};