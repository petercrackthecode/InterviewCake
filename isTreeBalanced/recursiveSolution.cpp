class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

bool checkHeight(const BinaryTreeNode * node, int &minHeight, int &maxHeight, int currentHeight)    {
    if (!node) {
        return true;
    }
    
    if (!node->left_ && !node->right_)    {
        if (minHeight == 1 && currentHeight > 1)
            minHeight = currentHeight;
        else minHeight = std::min(minHeight, currentHeight);
        maxHeight = std::max(maxHeight, currentHeight);
        
        return (maxHeight - minHeight > 1) ? false : true;
    }
    else {
        return checkHeight(node->left_, minHeight, maxHeight, currentHeight + 1) && 
               checkHeight(node->right_, minHeight, maxHeight, currentHeight + 1);
    }
}

bool isBalanced(const BinaryTreeNode* treeRoot)
{
    // determine if the tree is superbalanced
    int minHeight = 1,
        maxHeight = 1,
        currentHeight = 1;
    
    return checkHeight(treeRoot, minHeight, maxHeight, currentHeight);
}
