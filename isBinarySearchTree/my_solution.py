# https://www.interviewcake.com/question/python3/bst-checker?course=fc1&section=trees-graphs
from collections import deque
from typing import Optional

IS_QUEUE_INCREMENTALLY_SORTED = True
last_element = float('-inf')


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


def check_binary_search_tree(node: Optional[BinaryTreeNode]):
    global IS_QUEUE_INCREMENTALLY_SORTED
    global last_element

    if not node or not IS_QUEUE_INCREMENTALLY_SORTED:
        return

    check_binary_search_tree(node.left)

    if not IS_QUEUE_INCREMENTALLY_SORTED:
        return

    if last_element >= node.value:
        IS_QUEUE_INCREMENTALLY_SORTED = False
    else:
        last_element = node.value

    check_binary_search_tree(node.right)


def is_binary_search_tree(root: Optional[BinaryTreeNode]):

    # Determine if the tree is a valid binary search tree
    if not root or (not root.left and not root.right):
        return True

    q = deque()
    global IS_QUEUE_INCREMENTALLY_SORTED
    IS_QUEUE_INCREMENTALLY_SORTED = True
    global last_element
    last_element = float('-inf')

    check_binary_search_tree(root.left)
    if not IS_QUEUE_INCREMENTALLY_SORTED:
        return False

    if last_element >= root.value:
        return False

    last_element = root.value

    check_binary_search_tree(root.right)

    return IS_QUEUE_INCREMENTALLY_SORTED
