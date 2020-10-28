/* ����Ž��Ʈ��- search, insert, delete */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(int item) { //�� ��� ����
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = item;
	node->left = node->right = NULL; //child ��带 �η� �ʱ�ȭ
	return node;
}
TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) { return new_node(key); }
	
	/* insert�� ���� ũ�⿡ ���� subtree�� root�� insert ���ȣ�� */
	if (key < node->key) { node->left = insert_node(node->left, key); }
	else if (key > node->key) { node->right = insert_node(node->right, key); }
	
	return node; //����� root ������ ��ȯ
}
void inorder(TreeNode* root) {
	if (root == NULL) return;
	else {
		inorder(root->left);
		printf(" [%d]", root->key);
		inorder(root->right);
	}
}
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL)return NULL;
	if (node->key == key)return node;
	else if (node->key < key)return search(node->left, key);
	else return search(node->right, key);
}
TreeNode* min_value_node(TreeNode* node) { //�ּڰ� ã��-- left ��ȸ �ϸ� ��
	TreeNode* current = node;
	while (current->left != NULL) { current = current->left; } //���� ������ ���϶����� �ݺ�
	return current;
}
TreeNode* max_value_node(TreeNode* node) { //�ִ� ã��-- right ��ȸ �ϸ� ��
	TreeNode* current = node;
	while (current->right != NULL) { current = current->right; } //���� �������� ���϶����� �ݺ�
	return current;
}
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL)return root; // CASE 1.
	else if (root->key > key) { root->left = delete_node(root->left, key); }
	else if (root->key < key) { root->right = delete_node(root->right, key); }
	else {
		if (root->left == NULL) { //CASE 2. �ܸ� ���ų�, child�� �ϳ� ���� ����� ��� (1)
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) { //CASE 2-(2)
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		/* CASE 3. child�� �� �� �ִ� ���
			- ���� ����� key �� ���� ��� ã��(������) */
		TreeNode* temp1 = min_value_node(root->right); // right subtree���� �ּҰ� ã��
		TreeNode* temp2 = max_value_node(root->left); // left subtree���� �ִ밪 ã��
		printf("left subtree�� min: %d\n", temp2->key);
		printf("right subtree�� max: %d\n", temp1->key);
		if (abs(root->key - temp1->key) < abs(root->key - temp2->key)) { //root������ ���̰� temp1�� �� ���� ���
			printf("original value: %d | new value: %d\n", root->key, temp1->key);
			root->key = temp1->key;
			root->right = delete_node(root->right, temp1->key); //����� ���� ���� �ִ� ������� ����
		}
		else {
			printf("original value: %d | new value: %d\n", root->key, temp2->key);
			root->key = temp2->key;
			root->left = delete_node(root->left, temp2->key); //����� ���� ���� �ִ� ������� ����
		}
	}
	return root; //���ο� root ��ȯ
}
int main() {
	TreeNode* root = NULL;
	char input; // I/D/X �߿� ����� ����
	int value; //insert/delete �ÿ� �Է¹��� ��

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 45);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	inorder(root);
	printf("\n\n");

	do {
		printf("* operation ����: Insert(I) / Delete(D) / Exit(X): ");
		scanf_s("\n%c", &input);

		switch (input) {
		case'I': case'i':
			printf("Insert�� ����? ");
			scanf_s("%d", &value);
			root = insert_node(root, value); //value�� insert
			inorder(root); //Ʈ�� ���
			printf("\n\n");
			break;
		case'D':case'd':
			printf("Delete�� ����? ");
			scanf_s("%d", &value);
			root = delete_node(root, value); //value�� delete
			inorder(root); //Ʈ�� ���
			printf("\n\n");
			break;
		case 'X':
			break;
		default:
			printf("Wrong Input\n");
			break;
		}
	} while (input != 'X'); //�Է��� X�̸� �ݺ��� ����
	printf("���α׷� ����");

	return 0;
}