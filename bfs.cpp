class Node {
public:
	std::string name;
	std::vector<Node *> children;

	Node(std::string str) {
		name = str;
	}

	Node *addChild(std::string name) {
		Node *child = new Node(name);
		children.push_back(child);
		return this;
	}

	std::vector<std::string> breadthFirstSearch(std::vector<std::string> * array)	{
		std::queue<Node *> nodes;
		nodes.push(this);

		Node * current = nullptr;

		while (!nodes.empty()) {
			current = nodes.front();
			array->push_back(current->name);
			nodes.pop();

			for (auto child : current->children) {
				nodes.push(child);
			}
		}

		return * array;
	}
}