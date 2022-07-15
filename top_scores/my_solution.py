# https://www.interviewcake.com/question/python3/top-scores?course=fc1&section=sorting-searching-logarithms
def sort_scores(unsorted_scores, highest_possible_score):

    # Sort the scores in O(n) time
    ans = [0] * len(unsorted_scores)
    nums_count = [0] * (highest_possible_score + 1)

    for score in unsorted_scores:
        nums_count[score] += 1

    reversed_ans_index = len(ans) - 1
    for index, count in enumerate(nums_count):
        while count > 0 and reversed_ans_index >= 0:
            ans[reversed_ans_index] = index
            reversed_ans_index -= 1
            count -= 1

    return ans
