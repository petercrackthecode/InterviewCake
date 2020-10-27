#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class GraphNode	{
private:
    std::string label_;
    std::unordered_set<GraphNode *> neighbors_;
    std::string color_;
public:
    GraphNode(const std::string &label) : label_(label), neighbors_(), color_()	{

    }

    const std::string &getLabel() const	{
        return label_;
    }

    const std::unordered_set<GraphNode *> getNeighbors() const	{
        return neighbors_;
    }

    void addNeighbor(GraphNode &neighbor)	{
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const	{
        return !color_.empty();
    }

    const std::string &getColor() const	{
        if (hasColor())	{
            return color_;
        } else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const std::string &color)	{
        color_ = color;
    }
};

void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    for (auto node : graph) {
        const auto& neighbors = node->getNeighbors();

        if (neighbors.find(node) != neighbors.end())    {
            ostringstream errorMessage;
            errorMessage << "Legal coloring impossible for node with loop: " << node->getLabel();
            throw invalid_argument(errorMessage.str());
        }

        // get the node's neighbors' colors, as a set
        // so we can check if a color is illegal in constant time.
        std::unordered_set<std::string> illegalColors;
        for (const auto neighbor : neighbors) {
            if (neighbor->hasColor()) {
                illegalColors.insert(neighbor->getColor());
            }
        }

        // assign the first legal color
        for (const auto& color : colors)    {
            if (illegalColors.find(color) == illegalColors.cend()) {
                node->setColor(color);
                break;
            }
        }
    }
}

/*
GraphNode a("a");
GraphNode b("b");
GraphNode c("c");

a.addNeighbor(b);
b.addNeighbor(c);
b.addNeighbor(c);
c.addNeighbor(b);

std::vector<GraphNode *> graph {&a, &b, &c};
*/

