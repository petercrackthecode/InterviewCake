class GraphNode {
private:
	std::string label_;
	std::unordered_set<GraphNode*> neighbors_;
	std::string color_;
public:
	GraphNode(const std::string &label) : label_(label), neighbors_(), color_() {}

	const std::string& getLabel() const {
		return label_;
	}

	const std::unordered_set<GraphNode *> getNeightbors() const {
		return neighbors_;
	}

	void addNeighbor(GraphNode &neighbor)	{
		neighbors_.insert(&neighbor);
	}

	bool hasColor() const {
		return !color_.empty();
	}

	const std::string &getColor() const {
		if (hasColor()) {
			return color_;
		}
		else {
			throw logic_error("GraphNode is not marked with color");
		}
	}

	void setColor(const std::string &color) {
		color_ = color;
	}
};

GraphNode a("a");
GraphNode b("b");
GraphNode c("c");

a.addNeighbor(b);
b.addNeighbor(a);
b.addNeighbor(c);
c.addNeighbor(b);

std::vector<GraphNode *> graph { &a, &b, &c };