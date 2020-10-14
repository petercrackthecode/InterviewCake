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
    
}