# https://www.interviewcake.com/question/python3/find-duplicate-optimize-for-space?course=fc1&section=sorting-searching-logarithms
def count(numbers, left_bound, right_bound):
    ans = 0
    for num in numbers:
        if left_bound <= num <= right_bound:
            ans += 1

    return ans


def find_repeat(numbers):
    """
    * Edge cases: len(numbers) < 2: raise an exception
    * n = len(numbers) - 1 since the integers are in the range 1..n and the list has a length of n+1
    * left = 1, right = n
    * Use modified binary search to divide [left, right] into two range [left, mid] and [mid+1, right] where:
    * mid = (right-left) // 2 + left
    * Iterate through the array to calculate the count of elements fall within those two ranges
    count(num, left, mid) = ___
    count(num, mid+1, right) = ___
    We'll have a helper function called count
    Selection factor: if count(num, left, mid) < count(num, mid+1, right) => move right: left = mid + 1
    otherwise, move left: right = mid - 1
    Base case: we don't move if left == mid or mid + 1 == right because we've already hit the last possible
    shiftment, so if count(num, left, mid) > count(num, mid+1, right) and left == mid: return mid
    Likewise for the othercase: count(num, left, mid) < count(num, mid+1, right) and mid+1 == right: return mid

    * Wrap the operation above inside a while loop: while left < right:
    """
    if len(numbers) > 2:
        n = len(numbers) - 1
        left = 1
        right = n
        while left < right:
            mid = (right - left) // 2 + left
            numbers_appear_in_left_range_count = count(numbers, left, mid)
            numbers_appear_in_right_range_count = count(numbers, mid+1, right)

            if numbers_appear_in_left_range_count > numbers_appear_in_right_range_count:
                if left == mid:
                    return mid
                right = mid
            else:
                if right == mid + 1:
                    return mid + 1
                left = mid + 1

    raise Exception("no duplicate!")


numbers = [4, 1, 4, 8, 3, 2, 7, 6, 5]
repeated_number = find_repeat(numbers)
print(repeated_number)
