// link: https://www.interviewcake.com/question/cpp/second-largest-item-in-bst?course=fc1&section=trees-graphs
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

int findSecondLargest(const BinaryTreeNode* rootNode)
{
    // find the second largest item in the binary search tree
    int ans{0};

    if ((!rootNode->left_ && !rootNode->right_) || !rootNode)
    	return rootNode;

    if (rootNode->right_)	{
    	const BinaryTreeNode* parent = rootNode,
    						  child = rootNode->right_;

    	while (child->right_)	{
    		parent = child;
    		child = child->right_;
    	}

    	ans = parent->value_;
    }
    else	{
    	const BinaryTreeNode * secondLargest = root->left_;

    	while (secondLargest->right_)	{
    		secondLargest = secondLargest->right_;
    	}
    	ans = secondLargest->value_;
    }

    return ans;
}

