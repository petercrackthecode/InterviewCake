def is_binary_search_tree(root):
    # Start at the root, with an arbitrarily low lower bound and an arbitrarily high upper bound
    node_and_bounds_stack = [(root, float('-inf'), float('inf'))]

    # Depth-first traversal
    while len(node_and_bounds_stack) > 0:
        node, lower_bound, upper_bound = node_and_bounds_stack.pop()

        # If this node is invalid, we return false right away
        if (node.value <= lower_bound) or (node.value >= upper_bound):
            return False

        if node.left:
            # This node must be less than the current node
            node_and_bounds_stack.append((node.left, lower_bound, node.value))
        if node.right:
            # This node must be greater than tha current node
            node_and_bounds_stack.append((node.right, node.value, upper_bound))

    # If node of the nodes were invalid, return True
    # (at this point we have checked all nodes)
    return True
