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

bool isBinarySearchTree(const BinaryTreeNode *root) {
	// determine if the tree is a valid binary search tree


	return false;
}