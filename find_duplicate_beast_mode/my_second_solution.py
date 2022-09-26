# https://www.interviewcake.com/question/python3/find-duplicate-optimize-for-space-beast-mode?course=fc1&section=trees-graphs
def find_duplicate(int_list):

    # Find a number that appears more than once ... in O(n) time
    """
    + Find the length of the cycle.
    + When do we know we're in a cycle.
    + We can use the two pointer approach: one pointer move twice as fast as the other pointer.
    + Then, they will meet each other at a point within the cycle.
    + When we're in the cycle, save that position, then have a node to traverse from that node
    until we meet the same node again. cycle_length = number_of_moves
    + Then, we'll have two pointers to traverse through the list again. One pointer is
    cycle_length + 1 moves away from the other. 
    + Traverse both of them with the same speed. Once the first_pointer.next = second_pointer,
    duplicate_number = first_pointer.value
    """
    list_length = len(int_list)
    one_move_pointer = int_list[list_length - 1]
    two_moves_pointer = int_list[list_length - 1]

    one_move_pointer = int_list[one_move_pointer - 1]
    two_moves_pointer = int_list[two_moves_pointer - 1]
    two_moves_pointer = int_list[two_moves_pointer - 1]

    while one_move_pointer != two_moves_pointer:
        one_move_pointer = int_list[one_move_pointer - 1]
        two_moves_pointer = int_list[two_moves_pointer - 1]
        two_moves_pointer = int_list[two_moves_pointer - 1]
    cycle_length = 1
    temp_pointer = int_list[one_move_pointer - 1]
    while temp_pointer != one_move_pointer:
        temp_pointer = int_list[temp_pointer - 1]
        cycle_length += 1

    ahead_pointer = int_list[list_length - 1]
    behind_pointer = int_list[list_length - 1]
    moves_count = cycle_length
    while moves_count > 0:
        ahead_pointer = int_list[ahead_pointer - 1]
        moves_count -= 1

    while int_list[behind_pointer - 1] != int_list[ahead_pointer - 1]:
        behind_pointer = int_list[behind_pointer - 1]
        ahead_pointer = int_list[ahead_pointer - 1]

    return int_list[behind_pointer-1]
