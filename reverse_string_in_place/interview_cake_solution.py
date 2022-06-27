def reverse(list_of_chars):
    left_index = 0
    right_index = len(list_of_chars) - 1

    while left_index < right_index:
        # Swap characters
        list_of_chars[left_index], list_of_chars[right_index] = list_of_chars[right_index], list_of_chars[left_index]
        # Move towards middle
        left_index += 1
        right_index -= 1


list_of_chars = [char for char in "absolute"]
print("Before swap: |{}|".format(''.join(list_of_chars)))
reverse(list_of_chars)
print("After swap: |{}|".format(''.join(list_of_chars)))
