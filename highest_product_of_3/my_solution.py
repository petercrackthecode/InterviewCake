# https://www.interviewcake.com/question/python3/highest-product-of-3
def highest_product_of_2_indices(list_of_ints):
    greatest_num = list_of_ints[0]
    greatest_num_index = 0
    smallest_num = list_of_ints[0]
    smallest_num_index = 0

    # Save the greatest_num and its index:
    for index, num in enumerate(list_of_ints):
        if num > greatest_num:
            greatest_num_index = index
            greatest_num = num

    # Save the smallest_num and its index:
    for index, num in enumerate(list_of_ints):
        if num < smallest_num:
            smallest_num_index = index
            smallest_num = num

    ans = (0, 1)
    highest_product_of_2 = list_of_ints[0] * list_of_ints[1]

    # get the indices of the highest product of 2
    for index, num in enumerate(list_of_ints):
        if index != greatest_num_index and index != smallest_num_index:
            if num > 0 and num * greatest_num > highest_product_of_2:
                ans = (index, greatest_num_index)
                highest_product_of_2 = num * greatest_num
            elif num < 0 and num * smallest_num > highest_product_of_2:
                ans = (index, smallest_num_index)
                highest_product_of_2 = num * smallest_num

    return ans


def smallest_product_of_2_indices(list_of_ints):
    greatest_num = list_of_ints[0]
    greatest_num_index = 0
    smallest_num = list_of_ints[0]
    smallest_num_index = 0

    # Save the greatest_num and its index:
    for index, num in enumerate(list_of_ints):
        if num > greatest_num:
            greatest_num_index = index
            greatest_num = num

    # Save the smallest_num and its index:
    for index, num in enumerate(list_of_ints):
        if num < smallest_num:
            smallest_num_index = index
            smallest_num = num

    ans = (0, 1)
    smallest_product_of_2 = list_of_ints[0] * list_of_ints[1]

    # get the indices of the highest product of 2
    for index, num in enumerate(list_of_ints):
        if index != greatest_num_index and index != smallest_num_index:
            if num < 0 and num * greatest_num < smallest_product_of_2:
                ans = (index, greatest_num_index)
                smallest_product_of_2 = num * greatest_num
            elif num > 0 and num * smallest_num < smallest_product_of_2:
                ans = (index, smallest_num_index)
                smallest_product_of_2 = num * smallest_num

    return ans


def highest_product_of_3(list_of_ints):
    """
    Edge cases: when len(list_of_ints) < 3, raise an exception

    We can find & save 4 results:
    - The indices (e,f) of the pair whose product makes the highest product of 2.
    - The indices (m,n) of the pair whose product makes the lowest product of 2.
        Note: (e,f) can be possibly the same as (m,n) 
        or e==f and m==n
    Iterate through the array again:
    for every element at position i:
        if i != e and i != f:
            ans = max(ans, arr[i] * highest_product_of_2)
        if i != m and i != n:
            ans = max(ans, arr[i] * lowest_product_of_2)
    Return ans by the end of the iteration.

    Meta questions: 
    - How do we find the highest_product_of_2?
      Get the biggest number and the smallest number in the array, 
        save their indices.
      Iterate through the array again, if arr[i] > 0:
        max_product_of_2_with_current_num = arr[i] * biggest_number
        else:
            max_product_of_2_with_current_num = arr[i] * smallest_number
        highest_product_of_2 = max(highest_product_of_2, max_product_of_2_with_current_num)
        Remember to save the pair of max_product_of_2_with_current_num instead of the result.
    - How do we find the lowest_product_of_2?
        Likewise with the way we find the highest_product_of_2, 
        but use min() instead of max()
    """
    # Handle the edge case: Throw an exception if len(list_of_ints) < 3
    if len(list_of_ints) < 3:
        raise Exception("The input list must have at least 3 elements")

    # Find the highest product of 2 indices:
    high_1, high_2 = highest_product_of_2_indices(list_of_ints)
    small_1, small_2 = smallest_product_of_2_indices(list_of_ints)

    highest_product_of_3 = list_of_ints[0] * list_of_ints[1] * list_of_ints[2]

    for index, num in enumerate(list_of_ints):
        if num > 0 and index != high_1 and index != high_2:
            highest_product_of_3 = max(
                highest_product_of_3, num * list_of_ints[high_1] * list_of_ints[high_2])
        elif index != small_1 and index != small_2:
            highest_product_of_3 = max(
                highest_product_of_3, num * list_of_ints[small_1] * list_of_ints[small_2])

    return highest_product_of_3
