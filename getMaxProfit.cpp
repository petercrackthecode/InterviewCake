// link: https://www.interviewcake.com/question/cpp/stock-price?course=fc1&section=greedy
int getMaxProfit(const vector<int>& stockPrices)
{
    // calculate the max profit
    if (stockPrices.size() <= 1) {
        throw new std::exception();
    }
    
    int maxProfit{stockPrices[1] - stockPrices[0]};
    
    for (int purchaseIndex= 0; purchaseIndex < stockPrices.size() - 1; ++purchaseIndex) {
        if (stockPrices[purchaseIndex] > 0) {
            int purchasePrice= stockPrices[purchaseIndex];
            for (int sellIndex= purchaseIndex + 1; sellIndex < stockPrices.size(); ++sellIndex) {
                int sellPrice= stockPrices[sellIndex];
                if (sellPrice - purchasePrice > maxProfit) {
                    maxProfit= sellPrice - purchasePrice;
                }
            }
        }
    }

    return maxProfit;
}