# https://www.interviewcake.com/question/python3/permutation-palindrome?course=fc1&section=hashing-and-hash-tables
def has_palindrome_permutation(the_string):

    # Check if any permutation of the input is a palindrome
    characters_frequency = dict()

    for char in the_string:
        if char in characters_frequency:
            characters_frequency[char] += 1
        else:
            characters_frequency[char] = 1

    is_odd_length_string = len(the_string) % 2 == 1
    did_and_odd_frequency_character_exist = False

    for frequency in characters_frequency.values():
        if frequency % 2 == 1:
            if is_odd_length_string and not did_and_odd_frequency_character_exist:
                did_and_odd_frequency_character_exist = True
            else:
                return False

    return True


print(str(has_palindrome_permutation('')))
