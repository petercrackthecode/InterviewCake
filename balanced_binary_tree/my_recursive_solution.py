# https://www.interviewcake.com/question/python3/balanced-binary-tree?course=fc1&section=trees-graphs
import unittest

MAX_NODE_DEPTH = 0
MIN_NODE_DEPTH = float('inf')


def calculateDepth(node, parent_depth) -> None:
    global MAX_NODE_DEPTH
    global MIN_NODE_DEPTH

    if not node:
        return
    if not node.left and not node.right:
        # leaf node! calculate the depth
        node_depth = parent_depth + 1
        MAX_NODE_DEPTH = max(MAX_NODE_DEPTH, node_depth)
        MIN_NODE_DEPTH = min(MIN_NODE_DEPTH, node_depth)
    else:
        calculateDepth(node.left, parent_depth+1)
        calculateDepth(node.right, parent_depth+1)


def is_balanced(tree_root):

    # Determine if the tree is superbalanced
    # A tree is superbalanced if the difference between the depths of any two leaf nodes is no greater than one.
    """
    * Have a variable called max_leaf_node_depth, which saves the greatest depth of any leaf node from the tree.
    * Have a variable called min_leaf_node_depth that saves the smallest depth of any leaf node from the tree.
    * Have a function called calculateDepth(node, parent_depth) to calculate the depth of any node in the tree.
      If the node is a leaf node, its depth = parent_depth + 1. Compare that value to max_leaf_node_depth and
      min_leaf_node_depth as:
        max_leaf_node_depth = max(node_depth, max_leaf_node_depth)
        min_leaf_node_depth = min(node_depth, min_leaf_node_depth)
        - stop the iteration
      Otherwise:
        if node.left:
          calculateDepth(node.left, parent_depth + 1)
        if node.right:
          calculateDepth(node.right, parent_depth + 1)

    * return max_leaf_node_depth - min_leaf_node_depth <= 1

    """
    # Edge case
    if not tree_root or (not tree_root.left and not tree_root.right):
        return True

    global MAX_NODE_DEPTH
    global MIN_NODE_DEPTH
    MAX_NODE_DEPTH = 0
    MIN_NODE_DEPTH = float('inf')

    calculateDepth(tree_root, 0)

    return MAX_NODE_DEPTH - MIN_NODE_DEPTH < 2


class Test(unittest.TestCase):

    class BinaryTreeNode(object):

        def __init__(self, value):
            self.value = value
            self.left = None
            self.right = None

        def insert_left(self, value):
            self.left = Test.BinaryTreeNode(value)
            return self.left

        def insert_right(self, value):
            self.right = Test.BinaryTreeNode(value)
            return self.right

    def test_full_tree(self):
        tree = Test.BinaryTreeNode(5)
        left = tree.insert_left(8)
        right = tree.insert_right(6)
        left.insert_left(1)
        left.insert_right(2)
        right.insert_left(3)
        right.insert_right(4)
        result = is_balanced(tree)
        self.assertTrue(result)

    def test_both_leaves_at_the_same_depth(self):
        tree = Test.BinaryTreeNode(3)
        left = tree.insert_left(4)
        right = tree.insert_right(2)
        left.insert_left(1)
        right.insert_right(9)
        result = is_balanced(tree)
        self.assertTrue(result)

    def test_leaf_heights_differ_by_one(self):
        tree = Test.BinaryTreeNode(6)
        left = tree.insert_left(1)
        right = tree.insert_right(0)
        right.insert_right(7)
        result = is_balanced(tree)
        self.assertTrue(result)

    def test_leaf_heights_differ_by_two(self):
        tree = Test.BinaryTreeNode(6)
        left = tree.insert_left(1)
        right = tree.insert_right(0)
        right_right = right.insert_right(7)
        right_right.insert_right(8)
        result = is_balanced(tree)
        self.assertFalse(result)

    def test_three_leaves_total(self):
        tree = Test.BinaryTreeNode(1)
        left = tree.insert_left(5)
        right = tree.insert_right(9)
        right.insert_left(8)
        right.insert_right(5)
        result = is_balanced(tree)
        self.assertTrue(result)

    def test_both_subtrees_superbalanced(self):
        tree = Test.BinaryTreeNode(1)
        left = tree.insert_left(5)
        right = tree.insert_right(9)
        right_left = right.insert_left(8)
        right.insert_right(5)
        right_left.insert_left(7)
        result = is_balanced(tree)
        self.assertFalse(result)

    def test_both_subtrees_superbalanced_two(self):
        tree = Test.BinaryTreeNode(1)
        left = tree.insert_left(2)
        right = tree.insert_right(4)
        left.insert_left(3)
        left_right = left.insert_right(7)
        left_right.insert_right(8)
        right_right = right.insert_right(5)
        right_right_right = right_right.insert_right(6)
        right_right_right.insert_right(9)
        result = is_balanced(tree)
        self.assertFalse(result)

    def test_three_leaves_at_different_levels(self):
        tree = Test.BinaryTreeNode(1)
        left = tree.insert_left(2)
        left_left = left.insert_left(3)
        left.insert_right(4)
        left_left.insert_left(5)
        left_left.insert_right(6)
        right = tree.insert_right(7)
        right_right = right.insert_right(8)


unittest.main(verbosity=2)
