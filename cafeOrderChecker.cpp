// link: https://www.interviewcake.com/question/cpp/cafe-order-checker?course=fc1&section=array-and-string-manipulation
bool isFirstComeFirstServed(const vector<int>& takeOutOrders,
                            const vector<int>& dineInOrders,
                            const vector<int>& servedOrders)
{
    int takeOutOrdersLength= static_cast<int>(takeOutOrders.size()),
    	dineInOrdersLength= static_cast<int>(dineInOrders.size()),
    	servedOrdersLength= static_cast<int>(servedOrders.size()),
    	takeOutOrdersIndex{0},
    	dineInOrdersIndex{0},
    	servedOrdersIndex{0};

    if (takeOutOrdersLength + dineInOrdersLength != servedOrdersLength) {
    	return false;
    }

    while (takeOutOrdersIndex < takeOutOrdersLength && dineInOrdersIndex < dineInOrdersLength) {
    	if (takeOutOrders[takeOutOrdersIndex] <= dineInOrders[dineInOrdersIndex]) {
    		if (takeOutOrders[takeOutOrdersIndex] != servedOrders[servedOrdersIndex]) {
    			return false;
    		}
    		++takeOutOrdersIndex;
    	}
    	else {
    		if (dineInOrders[dineInOrdersIndex] != servedOrders[servedOrdersIndex]) {
    			return false;
    		}
    		++dineInOrdersIndex;
    	}

    	++servedOrdersIndex;
    }

    if (takeOutOrdersIndex < takeOutOrdersLength) {
    	while (takeOutOrdersIndex < takeOutOrdersLength) {
    		if (takeOutOrders[takeOutOrdersIndex] != servedOrders[servedOrdersIndex]) {
    			return false;
    		}
    		++takeOutOrdersIndex;
    		++servedOrdersIndex;
    	}
    }
    else {
    	while (dineInOrdersIndex < dineInOrdersLength) {
    		if (dineInOrders[dineInOrdersIndex] != servedOrders[servedOrdersIndex]) {
    			return false;
    		}
    		++dineInOrdersIndex;
    		++servedOrdersIndex;
    	}
    }

    return true;
}