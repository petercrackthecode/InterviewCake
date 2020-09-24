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
    std::map<const BinaryTreeNode *, bool> visited;
    const BinaryTreeNode * node = treeRoot;

    int minHeight = 1, maxHeight = 1;

    bool balanced = true;

    while (!node || !nodesStack.empty()) {
    	
    }

    return balanced;
}
