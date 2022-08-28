import unittest


class GraphNode:

    def __init__(self, label):
        self.label = label
        self.neighbors = set()
        self.color = None


def color_graph(graph, colors):
    # Create a valid coloring for the graph
    """
    * Have a map to save the labels and respective colors of nodes. Call it node_color_lookup
        + Key: label (string)
        + Value: color (string)
    * Traverse through the array of nodes (graph):
        + At each time we visit a node, assign the set: available_colors = set(colors)
        + Given a node, say a, we should check if that node and all the neighbor nodes are colored. Have a helper function called
        color_node_and_its_neighbors(node: GraphNode, available_colors: List[str]) to do the task above
            - If the node is already colored (curr_node.label in node_color_lookup), remove that color from the list of available_colors:
                available_colors.remove(curr_node.color) (remember to put a try catch here for the case where available_colors has no color
                left to assign)
            - If not, color it with any available color, and remove it from the list of available colors:
                if len(available_colors) > 0:
                    curr_node = available_colors.pop()
            - If the list of available colors is empty before we complete coloring any node and its neighbors:
                raise ValueError("cannot color all the nodes with the number of available colors")
    """
    for node in graph:
        if not node.color:
            illegal_colors = set()
            for neighbor in node.neighbors:
                if neighbor == node:
                    raise ValueError("Cannot legal color a loop graph")
                if neighbor.color:
                    illegal_colors.add(neighbor.color)
            legal_color = None
            for color in colors:
                if not color in illegal_colors:
                    legal_color = color
                    break
            if not legal_color:
                raise ValueError(
                    f"Unable to color the graph with {len(colors)} colors")
            node.color = legal_color


class Test(unittest.TestCase):

    def setUp(self):
        self.colors = frozenset([
            'red',
            'green',
            'blue',
            'orange',
            'yellow',
            'white',
        ])

    def assertGraphColoring(self, graph, colors):
        self.assertGraphHasColors(graph, colors)
        self.assertGraphColorLimit(graph)
        for node in graph:
            self.assertNodeUniqueColor(node)

    def assertGraphHasColors(self, graph, colors):
        for node in graph:
            msg = 'Node %r color %r not in %r' % (
                node.label, node.color, colors)
            self.assertIn(node.color, colors, msg=msg)

    def assertGraphColorLimit(self, graph):
        max_degree = 0
        colors_found = set()
        for node in graph:
            degree = len(node.neighbors)
            max_degree = max(degree, max_degree)
            colors_found.add(node.color)
        max_colors = max_degree + 1
        used_colors = len(colors_found)
        msg = 'Used %d colors and expected %d at most' % (
            used_colors, max_colors)
        self.assertLessEqual(used_colors, max_colors, msg=msg)

    def assertNodeUniqueColor(self, node):
        for adjacent in node.neighbors:
            msg = 'Adjacent nodes %r and %r have the same color %r' % (
                node.label,
                adjacent.label,
                node.color,
            )
            self.assertNotEqual(node.color, adjacent.color, msg=msg)

    def test_line_graph(self):
        node_a = GraphNode('a')
        node_b = GraphNode('b')
        node_c = GraphNode('c')
        node_d = GraphNode('d')

        node_a.neighbors.add(node_b)
        node_b.neighbors.add(node_a)
        node_b.neighbors.add(node_c)
        node_c.neighbors.add(node_b)
        node_c.neighbors.add(node_d)
        node_d.neighbors.add(node_c)

        graph = [node_a, node_b, node_c, node_d]
        tampered_colors = list(self.colors)
        color_graph(graph, tampered_colors)
        self.assertGraphColoring(graph, self.colors)

    # def test_separate_graph(self):
        node_a = GraphNode('a')
        node_b = GraphNode('b')
        node_c = GraphNode('c')
        node_d = GraphNode('d')

        node_a.neighbors.add(node_b)
        node_b.neighbors.add(node_a)
        node_c.neighbors.add(node_d)
        node_d.neighbors.add(node_c)

        graph = [node_a, node_b, node_c, node_d]
        tampered_colors = list(self.colors)
        color_graph(graph, tampered_colors)
        self.assertGraphColoring(graph, self.colors)

    # def test_triangle_graph(self):
        node_a = GraphNode('a')
        node_b = GraphNode('b')
        node_c = GraphNode('c')

        node_a.neighbors.add(node_b)
        node_a.neighbors.add(node_c)
        node_b.neighbors.add(node_a)
        node_b.neighbors.add(node_c)
        node_c.neighbors.add(node_a)
        node_c.neighbors.add(node_b)

        graph = [node_a, node_b, node_c]
        tampered_colors = list(self.colors)
        color_graph(graph, tampered_colors)
        self.assertGraphColoring(graph, self.colors)

    # def test_envelope_graph(self):
        node_a = GraphNode('a')
        node_b = GraphNode('b')
        node_c = GraphNode('c')
        node_d = GraphNode('d')
        node_e = GraphNode('e')

        node_a.neighbors.add(node_b)
        node_a.neighbors.add(node_c)
        node_b.neighbors.add(node_a)
        node_b.neighbors.add(node_c)
        node_b.neighbors.add(node_d)
        node_b.neighbors.add(node_e)
        node_c.neighbors.add(node_a)
        node_c.neighbors.add(node_b)
        node_c.neighbors.add(node_d)
        node_c.neighbors.add(node_e)
        node_d.neighbors.add(node_b)
        node_d.neighbors.add(node_c)
        node_d.neighbors.add(node_e)
        node_e.neighbors.add(node_b)
        node_e.neighbors.add(node_c)
        node_e.neighbors.add(node_d)

        graph = [node_a, node_b, node_c, node_d, node_e]
        tampered_colors = list(self.colors)
        color_graph(graph, tampered_colors)
        self.assertGraphColoring(graph, self.colors)

    # def test_loop_graph(self):
        node_a = GraphNode('a')

        node_a.neighbors.add(node_a)

        graph = [node_a]
        tampered_colors = list(self.colors)
        with self.assertRaises(Exception):
            color_graph(graph, tampered_colors)


unittest.main(verbosity=2)
