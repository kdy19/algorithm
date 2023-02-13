#include <cstdio>

class BinaryNode
{
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) : data(val), left(l), right(r) {}
	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }
	bool isleaf() { return left == NULL && right == NULL; }
};

class BinaryTree
{
	BinaryNode* root;
public:
	BinaryTree(): root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf("[%C] ", node->getData());
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}

	void inorder(BinaryNode* node) {
		if (node != NULL) {
			inorder(node->getLeft());
			printf("[%C] ", node->getData());
			inorder(node->getRight());
		}
	}

	void postorder(BinaryNode* node) {
		if (node != NULL) {
			postorder(node->getLeft());
			postorder(node->getRight());
			printf("[%C] ", node->getData());
		}
	}

	int getCount() { return isEmpty() ? 0 : getCount(root); }
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) return 0;
		if (node->isleaf()) return 1;
		return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	int getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
};


int main(int argc, char** argv) {
	BinaryTree tree;
	BinaryNode* d = new BinaryNode('D', NULL, NULL);
	BinaryNode* e = new BinaryNode('E', NULL, NULL);
	BinaryNode* b = new BinaryNode('B', d, e);
	BinaryNode* f = new BinaryNode('F', NULL, NULL);
	BinaryNode* c = new BinaryNode('C', f, NULL);
	BinaryNode* a = new BinaryNode('A', b, c);

	tree.setRoot(a);
	tree.preorder(a);
	printf("\n");
	tree.inorder(a);
	printf("\n");
	tree.postorder(a);
	printf("\n");
	printf("node count : %d\n", tree.getCount());
	printf("leaf node count : %d\n", tree.getLeafCount());
	printf("tree height : %d\n", tree.getHeight());

	return 0;
}
