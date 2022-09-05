# https://www.interviewcake.com/question/python3/mesh-message

# will be a list of lists of strings.
valid_paths = []


def get_path_dfs(graph, current_node, target_node, path_so_far, visited_nodes):
    neighbors = graph[current_node]
    for neighbor in neighbors:
        if not neighbor in visited_nodes:
            new_path = path_so_far + [neighbor]
            new_visited_nodes = visited_nodes.union({neighbor})
            if neighbor == target_node:
                global valid_paths
                valid_paths.append(new_path)
            else:
                get_path_dfs(graph, neighbor, target_node,
                             new_path, new_visited_nodes)


def get_path(graph, start_node, end_node):
    if not start_node in graph:
        raise ValueError("Error: " + start_node + " not presented")
    elif not end_node in graph:
        raise ValueError("Error: " + end_node + " not presented")
    elif start_node == end_node:
        return [start_node]
    # Find the shortest route in the network between the two users
    global valid_paths
    valid_paths = []
    path_so_far = [start_node]
    visited_nodes = set(path_so_far)
    get_path_dfs(graph, start_node, end_node, path_so_far, visited_nodes)
    if len(valid_paths) == 0:
        # There's no way to reach the end_node from the start_node
        return None

    shortest_path = valid_paths[0]
    for i in range(1, len(valid_paths)):
        if len(shortest_path) > len(valid_paths[i]):
            shortest_path = valid_paths[i]

    return shortest_path
