def fib(n):
    # Edge cases:
    if n < 0:
        raise ValueError(
            "Index was negative. No such thing as a negative index in a series.")
    elif n in [0, 1]:
        return n

    # We're building the fibonacci series from the bottom up
    # so we'll need to track the previous 2 numbers at each step
    prev_prev = 0  # 0th fibonacci
    prev = 1  # 1st fibonacci

    for _ in range(n-1):
        # Iteration 1: current = 2nd fibonacci
        # Iteration 2: current = 3rd fibonacci
        # Iteration 3: current = 4th fibonacci
        # To get nth fibonacci ... do n-1 iterations.
        current = prev + prev_prev
        prev_prev = prev
        prev = current

    return current
