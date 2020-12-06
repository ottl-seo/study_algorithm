/* 과제로 했던 delete 응용- left_max, right_min 비교 */
#include <stdio.h>
#include <stdlib.h>
//#define 
typedef struct TreeNode {
	int key;
	TreeNode* left, * right;
}TreeNode;

TreeNode* new_node(int item) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = item;
	node->left = node->right = NULL; //child노드를 널로 초기화
	return node;
}
TreeNode* insert_node(TreeNode* node, int key) { /* 적절한 위치 찾아서 key값 노드를 삽입 */
	if (node == NULL) return new_node(key); // 1. empty 처리
	if (key < node->key) node->left = insert_node(node->left, key); // 2.left subtree를 root로 재귀호출
	else if (key > node->key) node->right = insert_node(node->right, key); // 3.right subtree를 root로 재귀호출
	return node; // 4.변경된 root 포인터 반환
}
// insert_node 에서 node->left = insert_node(node->left, key) 이렇게 재귀해서 대입하는 거 잊지말기!!!!!!!

void inorder(TreeNode* root) { //LVR
	if (root == NULL) return; /* 0. empty tree일 경우 처리 잊지말기 */
	else {
		inorder(root->left);		// L
		printf(" [%d]", root->key);	// V
		inorder(root->right);		// R
	}
}
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL; // empty tree일 경우 처리
	if (key == node->key) return node;						  // 1.일치
	else if (key < node->key) return search(node->left, key); // 2.왼쪽
	else return search(node->right, key);					  // 3.오른쪽 -- search 끝
}
TreeNode* min_value_node(TreeNode* node) { // min_value_node(root->right)--> 가장 root값에 가까운 노드 찾기
	TreeNode* current = node; //루트 노드를 current
	while (current->left) current = current->left; //left가 있을 경우에 계속 
	return current;
}
TreeNode* max_value_node(TreeNode* node) { // max_value_node(root->left)에 사용
	TreeNode* current = node; //루트 노드를 current
	while (current->right) current = current->right; //right가 있을 경우에 계속 
	return current;
}
TreeNode* new_delete_node(TreeNode* root, int key) { //key값을 갖는 노드 삭제
	if (root == NULL) return NULL; // 0. empty 경우
	else if (key < root->key) root->left = new_delete_node(root->left, key);
	else if (key > root->key) root->right = new_delete_node(root->right, key);
	else {
		/* CASE 1,2 */
		if (root->left == NULL) { //left가 NULL일 경우
			TreeNode* temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) { // right가 NULL일 경우
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		/* CASE 3 -- 여기에서 left max와 right min 비교하기!!! */ 
		TreeNode* right_min = min_value_node(root->right);
		TreeNode* left_max = max_value_node(root->left);
		printf("-- right_min = %d\n-- left_max = %d\n", right_min->key, left_max->key);
		printf("* original value = %d | ", key);

		if (abs(right_min->key - key) <= abs(left_max->key - key)) { //right가 더 작을 경우
			printf("new value = %d\n", right_min->key);
			root->key = right_min->key;
			root->right = delete_node(root->right, right_min->key); //복사해둔 값을 갖는 노드 삭제
		}
		else {
			printf("new value = %d\n", left_max->key);
			root->key = left_max->key;
			root->left = delete_node(root->left, left_max->key); //복사해둔 값을 갖는 노드 삭제
		}
	}
	return root;
}
int main() {
	TreeNode* root = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과\n");
	inorder(root);
	printf("\n\n");

	printf("- 55 INSERT 결과 -\n");
	root = insert_node(root, 55);
	inorder(root);
	printf("\n\n");
	
	printf("- 49 INSERT 결과 -\n");
	root = insert_node(root, 49);
	inorder(root);
	printf("\n\n");

	printf("- 50 DELETE 결과 -\n");
	root = new_delete_node(root, 50);
	inorder(root);
	printf("\n\n");

	return 0;
}
