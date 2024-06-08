#include <iostream>
using namespace std;

typedef struct BST
{
	int value;
	struct BST* left;
	struct BST* right;
} BST;

BST* create_bst(int i)
{
	BST* element = new BST;
	element->value = i;
	element->right = nullptr;
	element->left = nullptr;
	return element;
}



void insert_into_bst(BST* root, BST* element)
{
	if (element->value < root->value)
	{
		if (root->left == nullptr) {
			root->left = element;
		}
		else {
			insert_into_bst(root->left, element);
		}
	}
	else
	{
		if (root->right == nullptr) {
			root->right = element;
		}
		else {
			insert_into_bst(root->right, element);
		}
	}
}

void print_three(BST* element)
{
	if (element->left != nullptr)
	{
		print_three(element->left);
	}
	cout << element->value << endl;
	if (element->right != nullptr) {
		print_three(element->right);
	}
}

int main() {
	int b[10] = { 11, 143, 1, 154, -99, 654, 1, 1, 1, 1 };
	BST* root = create_bst(45);
	for (int i = 0; i < 10; i++) {
		BST* elem = create_bst(b[i]);
		insert_into_bst(root, elem);
	}
	cout << "THree" << endl;
	print_three(root);
}
