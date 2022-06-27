# https://www.interviewcake.com/question/python3/reverse-string-in-place?course=fc1&section=array-and-string-manipulation
def reverse(list_of_chars):
    # Reverse the input list of chars in place
    """
    1. Find the mid point of the list of chars
    2. Have two pointers: one starts from the beginning of the list, and one traces back from the end of the list.
    3. While start_pointer < end_pointer, swap the elements between them.
       After each swap:
       - Move the start_pointer to the right by: start_pointer += 1
       - Move the end_pointer to the left by: end_pointer -= 1
    """
    start, end = (0, len(list_of_chars) - 1)
    temp_character = ''
    while start < end:
        temp_character = list_of_chars[start]
        list_of_chars[start] = list_of_chars[end]
        list_of_chars[end] = temp_character
        start += 1
        end -= 1

    return


list_of_chars = ['a', 'b', 'c']
print("Before swap: |{}|".format(''.join(list_of_chars)))
reverse(list_of_chars)
print("After swap: |{}|".format(''.join(list_of_chars)))
