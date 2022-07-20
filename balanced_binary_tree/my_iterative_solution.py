# https://www.interviewcake.com/question/python3/balanced-binary-tree?course=fc1&section=trees-graphs
from collections import deque

MAX_NODE_DEPTH = 0
MIN_NODE_DEPTH = float('inf')


def isLeafNode(node):
    if not node:
        return False

    return (not node.left and not node.right)


def is_balanced(tree_root):
    """
    * We can use breadth-first search with two queues to juggle back and forth the node at each level.
    * Have a counter to keep track of the depth. When we go to a new level, depth += 1
    * When we pop a node from one of our queues and that's node is a leaf node (not node.left and not node.right),
      compare MAX_NODE_DEPTH and MIN_NODE_DEPTH with the current depth:
        MAX_NODE_DEPTH = max(MAX_NODE_DEPTH, depth)
        MIN_NODE_DEPTH = min(MIN_NODE_DEPTH, depth)
    * Have a helper function isLeafNode(popped_node): return True if the poppedNode is a leaf node, otherwise return
    False.
    * We have two queues: q1 and q2. Here's our loop algorithm to pass the nodes' and their children between 
    q1 and q2 to do bfs:
      while len(q1) > 0 or len(q2) > 0:
        if len(q1) > 0:
          while len(q1) > 0:
            popped_node = q1.pop()
            if isLeafNode(popped_node):
              MAX_NODE_DEPTH = max(MAX_NODE_DEPTH, depth)
              MIN_NODE_DEPTH = min(MIN_NODE_DEPTH, depth)
            else:
              if popped_node.left:
                q2.append(popped_node.left)
              if popped_node.right:
                q2.append(popped_node.right)
        elif len(q2) > 0:
          while len(q2) > 0:
            popped_node = q2.pop()
            if isLeafNode(popped_node):
              MAX_NODE_DEPTH = max(MAX_NODE_DEPTH, depth)
              MIN_NODE_DEPTH = min(MIN_NODE_DEPTH, depth)
            else:
              if popped_node.left:
                q1.append(popped_node.left)
              if popped_node.right:
                q1.append(popped_node.right)

        depth += 1

    * In the end: return MAX_NODE_DEPTH - MIN_NODE_DEPTH <= 1
    """
    if not tree_root or isLeafNode(tree_root):
        return True

    q1, q2 = deque([tree_root]), deque()

    global MAX_NODE_DEPTH
    global MIN_NODE_DEPTH
    MAX_NODE_DEPTH = 0
    MIN_NODE_DEPTH = float('inf')
    depth = 0

    while len(q1) > 0 or len(q2) > 0:
        if len(q1) > 0:
            while len(q1) > 0:
                popped_node = q1.pop()
                if isLeafNode(popped_node):
                    MAX_NODE_DEPTH = max(MAX_NODE_DEPTH, depth)
                    MIN_NODE_DEPTH = min(MIN_NODE_DEPTH, depth)
                else:
                    if popped_node.left:
                        q2.append(popped_node.left)
                    if popped_node.right:
                        q2.append(popped_node.right)
        elif len(q2) > 0:
            while len(q2) > 0:
                popped_node = q2.pop()
                if isLeafNode(popped_node):
                    MAX_NODE_DEPTH = max(MAX_NODE_DEPTH, depth)
                    MIN_NODE_DEPTH = min(MIN_NODE_DEPTH, depth)
                else:
                    if popped_node.left:
                        q1.append(popped_node.left)
                    if popped_node.right:
                        q1.append(popped_node.right)
        depth += 1

    return MAX_NODE_DEPTH - MIN_NODE_DEPTH <= 1
