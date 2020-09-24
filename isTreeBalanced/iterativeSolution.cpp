class BinaryTreeNode {
public:
    int value_;
    BinaryTreeNode *left_;
    BinaryTreeNode *right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr) {
    }

    ~BinaryTreeNode() {
        delete left_;
        delete right_;
    }

    BinaryTreeNode *insertLeft(int value) {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode *insertRight(int value) {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

bool isBalanced(const BinaryTreeNode *treeRoot) {
    // a tree with no nodes is superbalanced, since there are no leaves!
    std::stack<const BinaryTreeNode*> nodesStack;
    std::map<BinaryTreeNode *, bool> visited;
    BinaryTreeNode * node = new BinaryTreeNode(treeRoot->value_);
    node->left_  = treeRoot->left_;
    node->right_ = treeRoot->right_;

    int minHeight = 1, maxHeight = 1;

    bool balanced = true;

    while (node || !nodesStack.empty()) {
        // take all the nodes on the left
        while (node) {
            nodesStack.push(node);
            visited[node] = true;
            node = node->left_;
        }
        
        if (!nodesStack.top()->left_ && !nodesStack.top()->right_) {
            int currentHeight = nodesStack.size();
            
            if (minHeight == 1) 
                minHeight = currentHeight;
            else minHeight = std::min(minHeight, currentHeight);
            maxHeight = std::max(maxHeight, currentHeight);

            if (maxHeight - minHeight > 1) {
                balanced = false;
                break;
            }
        }
        
        if (!visited[nodesStack.top()->right_] && nodesStack.top()->right_)  {
            node = nodesStack.top()->right_;
        }
        else {
            nodesStack.pop();
        }
    }

    return balanced;
}
