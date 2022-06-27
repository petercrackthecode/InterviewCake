def reverse_character_list_in_range(char_list, _start, _end):
    start = _start
    end = _end
    while start < end:
        # Swap two characters with each other
        char_list[start], char_list[end] = char_list[end], char_list[start]
        start += 1
        end -= 1


def reverse_words(message):

    # Decode the message by reversing the words in-place
    """
    1. Reverse the whole string.
    2. Traverse through the string. For each new words we've detected 
    (delimited by the space or if our pointer hits the end of the string), reverse that word.
    """
    reverse_character_list_in_range(message, 0, len(message) - 1)

    word_start = 0
    word_end = 0

    for i in range(len(message)):
        # new word end detected
        if i >= len(message) - 1 or message[i+1] == ' ':
            word_end = i
            reverse_character_list_in_range(message, word_start, word_end)
        # new word start detected
        elif message[i] == ' ':
            word_start = word_end = i+1

    return


words = [char for char in "cake steal"]
reverse_words(words)
print(words)
