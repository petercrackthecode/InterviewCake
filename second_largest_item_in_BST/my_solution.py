from typing import Optional


class BinaryTreeNode(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert_left(self, value):
        self.left = BinaryTreeNode(value)
        return self.left

    def insert_right(self, value):
        self.right = BinaryTreeNode(value)
        return self.right


def is_empty_node(node: Optional[BinaryTreeNode]) -> bool:
    return node == None


def is_leaf_node(node: Optional[BinaryTreeNode]) -> bool:
    return not is_empty_node(node) and (not node.left and not node.right)


def find_second_largest(root_node) -> int:
    # Find the second largest item in the binary search tree
    """
    * Brute force solution:
    + If the root has less than two node: raise an exception.
    + Otherwise, using inorder traversal, save all the nodes from the tree to an array, then return arr[-2],
    + which is the second largest element in the BST that we're looking for.
    Time Complexity: O(N). Space complexity: O(N).

    => Since we're having a binary search tree, we can do better to make it O(logN)

    The largest item in a binary search tree is the right-most item on the tree.
    The right-most item on the tree can be a leaf node or a node with a leaf left child.
    So, our algorithm could be like this: From the root node, have one node called largest and another one called
    second largest.
    (1) Traverse to the right of the tree as much as we can until: not largest.right 
    Traversal algorithm:
        while largest.right:
            second_largest = largest
            largest = largest_right
    (2) Then, see if largest.left is an empty node or not. If largest.left is non-empty,
    second_largest = largest.left. Then keep assigning second_largest to its right child as long as
    second_largest.right is non-empty.

    * Edge case: our tree doesn't have any right child: we skip step (1)
    """
    if is_empty_node(root_node) or is_leaf_node(root_node):
        raise Exception("The tree must have at least 2 nodes")

    largest: Optional[BinaryTreeNode] = root_node
    second_largest: Optional[BinaryTreeNode] = None

    while largest.right:
        second_largest = largest
        largest = largest.right

    if not is_empty_node(largest.left):
        second_largest = largest.left
        while not is_empty_node(second_largest.right):
            second_largest = second_largest.right

    if not second_largest:
        raise Exception("Unknown error: invalid binary search tree")

    return second_largest.value
