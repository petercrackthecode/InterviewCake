# https://www.interviewcake.com/question/python3/permutation-palindrome?course=fc1&section=hashing-and-hash-tables
def has_palindrome_permutation(the_string):
    # Track characters we've seen an odd number of times
    unpaired_characters = set()

    for char in the_string:
        if char in unpaired_characters:
            unpaired_characters.remove(char)
        else:
            unpaired_characters.add(char)

    # The string has a palindrome permutation if it has
    # one or zero characters without a pair
    return len(unpaired_characters) <= 1
