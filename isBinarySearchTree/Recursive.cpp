// link: https://www.interviewcake.com/question/cpp/bst-checker?course=fc1&section=trees-graphs
using namespace std;

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

void isBinarySearchTreeHelper(const BinaryTreeNode *node, std::vector<int> &values)    {
    if (!node)
        return; // Do nothing if the node is empty
    else {
        isBinarySearchTreeHelper(node->left_, values);
        values.push_back(node->value_);
        isBinarySearchTreeHelper(node->right_, values);
    }
}

bool areValuesIncreasing(const std::vector<int> values)   {
    if (values.size() == 0) return true;
    else {
        int temp = values[0];
        for (int index = 1; index < values.size(); ++index) {
            if (values[index] <= temp)
                return false;
            
            temp = values[index];
        }
    }
    
    return true;
}

bool isBinarySearchTree(const BinaryTreeNode *root) {
	// determine if the tree is a valid binary search tree
	std::vector<int> values;
	isBinarySearchTreeHelper(root, values);
	
	return areValuesIncreasing(values);
}