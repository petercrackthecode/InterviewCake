https://www.interviewcake.com/question/cpp/linked-list-cycles?course=fc1&section=linked-lists
#include <iostream>
#include <vector>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class LinkedListNode {
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

bool containsCycle(const LinkedListNode* firstNode)
{
    // check if the linked list contains a cycle
    LinkedListNode * normalSpeed = new LinkedListNode(firstNode->intValue_),
                   * doubleSpeed = new LinkedListNode(firstNode->intValue_);
    
    normalSpeed->next_ = doubleSpeed->next_ = firstNode->next_;
    
    
    while (doubleSpeed && normalSpeed) {
        // move 2 steps
        doubleSpeed = doubleSpeed->next_;
        if (!doubleSpeed)
            return false;
        else if (doubleSpeed == normalSpeed)
            return true;
        doubleSpeed = doubleSpeed->next_;
        if (!doubleSpeed)
            return false;
        else if (doubleSpeed == normalSpeed)
            return true;   
        
        normalSpeed = normalSpeed->next_;
        if (normalSpeed == doubleSpeed)
            return true;
        if (!normalSpeed)
            return false;
    }

    return true;
}


















// tests

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values);
void freeLinkedListNodes(vector<LinkedListNode*>& nodes);

const lest::test tests[] = {
    {CASE("linked list with no cycle") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        EXPECT(containsCycle(nodes[0]) == false);
        freeLinkedListNodes(nodes);
    }},
    {CASE("cycle loops to beginning") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4});
        nodes[3]->next_ = nodes[0];
        EXPECT(containsCycle(nodes[0]) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("cycle loops to middle") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4, 5});
        nodes[4]->next_ = nodes[2];
        EXPECT(containsCycle(nodes[0]) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("two node cycle at end") {
        auto nodes = valuesToLinkedListNodes(vector<int> {1, 2, 3, 4, 5});
        nodes[4]->next_ = nodes[3];
        EXPECT(containsCycle(nodes[0]) == true);
        freeLinkedListNodes(nodes);
    }},
    {CASE("empty list") {
        EXPECT(containsCycle(nullptr) == false);
    }},
    {CASE("one element linked list no cycle") {
        auto node = new LinkedListNode(1);
        EXPECT(containsCycle(node) == false);
        delete node;
    }},
    {CASE("one element linked list cycle") {
        auto node = new LinkedListNode(1);
        node->next_ = node;
        EXPECT(containsCycle(node) == true);
        delete node;
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}

vector<LinkedListNode*> valuesToLinkedListNodes(const vector<int>& values)
{
    vector<LinkedListNode*> nodes;
    for (int value: values) {
        auto node = new LinkedListNode(value);
        if (!nodes.empty()) {
            nodes.back()->next_ = node;
        }
        nodes.push_back(node);
    }
    return nodes;
}

void freeLinkedListNodes(vector<LinkedListNode*>& nodes)
{
    for (auto node: nodes) {
        delete node;
    }
    nodes.clear();
}