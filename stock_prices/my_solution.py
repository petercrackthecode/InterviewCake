# https://www.interviewcake.com/question/javascript/stock-price?course=fc1&section=greedy
def get_max_profit(stock_prices):
    # Calculate the max profit

    if len(stock_prices) < 2:
        raise Exception(
            "There must be at least 2 price points so we can buy and sell the stock")

    max_profit = float('-inf')
    buy_index = 0

    for i in range(1, len(stock_prices)):
        max_profit = max(stock_prices[i] - stock_prices[buy_index], max_profit)
        if stock_prices[i] < stock_prices[buy_index]:
            buy_index = i

    return max_profit
