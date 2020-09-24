void graphType::dft(int v, bool visited[]) {
	visited[v] = true;
	std::cout << " " << v << " "; // visit the vertex

	linkedListIterator<int> graphIt;
	// for each vertex adjacent to v
	for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt) {
		int w = * graphIt;
		if (!visited[w])
			dft(w, visited);
	} // end while
} // end dft

void graphType::depthFirstTraversal() {
	bool * visited; // pointer to create the array to keep track of the visited verticles
	visited = new bool[gSize];

	for (int index = 0; index < gSize; ++index)
		visited[index] = false;

		// For each vertex that is not visited, do a depth first traversal
	for (int index = 0; index < gSize; ++index) {
		if (!visited[index])
			dft(index, visited);
	}

	delete [] visited;
}