def fib(n):

    # Compute the nth Fibonacci number
    if n < 0:
        raise ValueError("n cannot be negative")
    elif 0 <= n <= 1:
        return n

    first_num = 0
    second_num = 1

    iterator = 1

    while iterator < n:
        first_num, second_num = second_num, first_num + second_num
        iterator += 1

    return second_num
# a = 1
# b = 2
# a, b = b, a+b


# print(f"a = {a}\nb={b}")
