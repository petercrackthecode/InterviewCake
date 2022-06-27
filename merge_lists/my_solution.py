def merge_lists(my_list, alices_list):
    # Combine the sorted lists into one large sorted list
    my_list_pos, alices_list_pos = [0, 0]
    merged_list = []

    while my_list_pos < len(my_list) and alices_list_pos < len(alices_list):
        if my_list[my_list_pos] <= alices_list[alices_list_pos]:
            merged_list.append(my_list[my_list_pos])
            my_list_pos += 1
        else:
            merged_list.append(alices_list[alices_list_pos])
            alices_list_pos += 1

    while my_list_pos < len(my_list):
        merged_list.append(my_list[my_list_pos])
        my_list_pos += 1

    while alices_list_pos < len(alices_list):
        merged_list.append(alices_list[alices_list_pos])
        alices_list_pos += 1

    return merged_list
