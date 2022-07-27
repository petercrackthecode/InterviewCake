# https://www.interviewcake.com/question/python3/second-largest-item-in-bst?course=fc1&section=trees-graphs

def find_largest(root_node):
    current = root_node
    while current:
        if not current.right:
            return current.value
        current = current.right


def find_second_largest(root_node):
    if (root_node is None or (root_node.left is None and root_node.right is None)):
        raise ValueError('Tree must have at least 2 nodes')

    current = root_node
    while current:
        # Case: current is largest and has a left subtree
        # 2nd largest is the largest in that subtree
        if current.left and not current.right:
            return find_largest(current.left)

        # Case: current is parent of largest, and largest has no children, so current is 2nd largest
        if (current.right and
            not current.right.left and
                not current.right.right):
            return current.value

        current = current.right
