def is_first_come_first_served(take_out_orders, dine_in_orders, served_orders):

    # Check if we're serving orders first-come, first-served
    """
    1. Have two pointer, one is for the take_out_orders, the other is for
    dine_in_orders: take_out_index, dine_in_index
    2. Traverse through every single element in the served_orders array. Call each of them an "order"
    3. Check the order is a takeout by assessing the take_out_index boundary and seeing if served_order == take_out_orders[take_out_index].
    If no, move to case 4.
    Otherwise, increment the take_out_index by 1.
    4. Check if the order is a dinein by assessing the dine_in_index boundary and seeing if served_order = dine_in_orders[dine_in_index].
    If no, return False immediately.
    Otherwise, increment the dine_in_index by 1.
    4. After having traversed through all the elements in served_orders, check if we have exhausted all elements within
    take_out_orders and dine_in_orders. If yes, return True. Else, return False.

    Edge case 1: len(take_out_orders) + len(dine_in_orders) != len(served_orders) => We have extra or
    missing orders => False
    Edge case 2: one or both of the take_out_orders and dine_in_orders array
    can be empty => Array out of bound in some situation.
    """

    take_out_index, dine_in_index = [0, 0]

    for order in served_orders:
        if take_out_index < len(take_out_orders) and take_out_orders[take_out_index] == order:
            take_out_index += 1
        elif dine_in_index < len(dine_in_orders) and dine_in_orders[dine_in_index] == order:
            dine_in_index += 1
        else:
            return False

    return take_out_index == len(take_out_orders) and dine_in_index == len(dine_in_orders)
