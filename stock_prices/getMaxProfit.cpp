// link: https://www.interviewcake.com/question/cpp/stock-price?course=fc1&section=greedy
int getMaxProfit(const vector<int>& stockPrices)	{
    // calculate the max profit
    if (stockPrices.size() <= 1)	{
        throw new std::exception();
    }
    
    int maxProfit{INT_MIN},
        traversalIndex{0},
        localMin{INT_MAX};

    
    while (traversalIndex < stockPrices.size())	{
        if (localMin != INT_MAX && stockPrices[traversalIndex] - localMin > maxProfit)	{
            maxProfit= stockPrices[traversalIndex] - localMin;
        }
        
        if (stockPrices[traversalIndex] < localMin)	{
            localMin= stockPrices[traversalIndex];
        }
        
        ++traversalIndex;
    }
    
    // 10, 9, 6, 5, 4, 1
    // 10, 7, 5, 8, 3

    return maxProfit;
}