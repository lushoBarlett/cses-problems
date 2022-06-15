#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 2e5;

struct AVL {

	struct Node {
		int value;
		int height = 0;
		int left_elements = 0;
		int right_elements = 0;
		Node* left = NULL;
		Node* right = NULL;

		Node(int v) : value(v) {}
		~Node() {
			delete left;
			delete right;
		}
	};

	int size = 0;
	Node* tree = NULL;

	int height(Node* node) {
		return node ? node->height : -1;
	}

	int left_elements(Node* node) {
		return node ? node->left_elements : -1;
	}

	int right_elements(Node* node) {
		return node ? node->left_elements : -1;
	}

	int elements(Node* node) {
		return node ? node->left_elements + node->right_elements : -1;
	}

	void recompute(Node* node) {
		if (!node)
			return;

		node->height = 1 + max(height(node->right), height(node->left));
		assert(node->height >= 0);
		node->left_elements = 1 + elements(node->left);
		assert(node->left_elements >= 0);
		node->right_elements = 1 + elements(node->right);
		assert(node->left_elements >= 0);
	}

	int balance_factor(Node* node) {
		return height(node->right) - height(node->left);
	}

	Node* rotate_right(Node* node) {
		Node* l = node->left;
		node->left = l->right;
		l->right = node;
		recompute(node);
		recompute(l);
		return l;
	}

	Node* rotate_left(Node* node) {
		Node* r = node->right;
		node->right = r->left;
		r->left = node;
		recompute(node);
		recompute(r);
		return r;
	}

	Node* _insert(Node* node, int value) {
		if (!node)
			return new Node(value);

		if (node->value < value)
			node->right = _insert(node->right, value);
		else
			node->left = _insert(node->left, value);

		recompute(node);

		int bf = balance_factor(node);

		if (bf == -2) {
			if (value > node->left->value)
				node->left = rotate_left(node->left);
			return rotate_right(node);
		}
		
		if (bf == 2) {
			if (value < node->right->value)
				node->right = rotate_right(node->right);
			return rotate_left(node);
		}

		recompute(node);

		return node;
	}

	void insert(int value) {
		tree = _insert(tree, value);
		size++;
	}

	Node* _push_down(Node* node) {
		if (!node->left && !node->right) {
			delete node;
			return NULL;
		}

		if (balance_factor(node) < 0) {
			node = rotate_right(node);
			node->right = _push_down(node->right);
		} else {
			node = rotate_left(node);
			node->left = _push_down(node->left);
		}

		recompute(node);
		
		return node;
	}

	Node* _remove(Node* node, int index) {
		if (node->left_elements == index) {
			cout << node->value << endl;
			return _push_down(node);
		}

		if (index < node->left_elements)
			node->left = _remove(node->left, index);
		else
			node->right = _remove(node->right, index - node->left_elements - 1);

		recompute(node);
		
		return node;
	}

	void remove(int index) {
		tree = _remove(tree, index);
		size--;
	}

	~AVL() {
		delete tree;
	}
};

int main() {
	AVL tree;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		tree.insert(i);
	
	int index = 0;
	while (tree.size) {
		index += K;
		index %= tree.size;

		tree.remove(index);
	}
}
