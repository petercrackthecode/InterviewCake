from typing import List


def get_permutations_helper(char_list) -> List[List[str]]:
    ans = []
    for i, char in enumerate(char_list):
        first_char_of_new_strings = char
        remaining_chars = char_list[:i] + char_list[i+1:]
        substring_permutations = get_permutations_helper(remaining_chars)
        if len(substring_permutations) <= 0:
            ans.append([first_char_of_new_strings])
        else:
            for substr in substring_permutations:
                ans.append([first_char_of_new_strings] + substr)

    return ans


def get_permutations(string):

    # Generate all permutations of the input string
    """
    + Convert the string to a char_list.
    + Iterate through every position from 0 to len(char_list) - 1:
        - Every time you are at a position, take the character from that position, get a
        new sub array of char_list without that position, then:
            - Pass that subarray to a function called get_permutation_helper(char_list) -> 
            [char_list]. That array will return a list of character_lists (which represent
            strings).
            - for every element in that returned array, prepend the taken character to 
            each char_list, then add it to the final ans.
            - At the end of the helper function, return ans.
    """
    if len(string) <= 1:
        return set([string])

    ans = []
    char_list = [x for x in string]

    for i, char in enumerate(char_list):
        first_char_of_new_strings = char
        remaining_chars = char_list[:i] + char_list[i+1:]
        substring_permutations = get_permutations_helper(remaining_chars)
        if len(substring_permutations) <= 0:
            ans.append(first_char_of_new_strings)
        else:
            for substr in substring_permutations:
                ans.append(first_char_of_new_strings + ''.join(substr))

    return set(ans)
