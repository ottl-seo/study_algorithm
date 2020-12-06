/* 이진탐색트리 -search/insert/delete 복습 */
#include <stdio.h>
#include <stdlib.h>

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
TreeNode* delete_node(TreeNode* root, int key) { //key값을 갖는 노드 삭제
	if (root == NULL) return NULL; // 0. empty 처리
	else if (key < root->key) root->left = delete_node(root->left, key); 
	else if (key > root->key) root->right = delete_node(root->right, key); // 1. key대소 여부 비교해서, delete 왼/오 재귀 호출
	else { 
		/* CASE 1,2: 말단노드이거나 child 1개일 경우 */
		if (root->left == NULL) { //left가 NULL일 경우--> right를 temp로- root free- return temp
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		/* CASE 3. child 2개일 경우 */
		TreeNode* temp = min_value_node(root->right); // 3-1. right child에서 가장 가까운 key값 갖는 노드 찾기
		root->key = temp->key; // 3-2. 가장 가까운 key값을 삭제할 위치(root)에 복사-
		root->right = delete_node(root->right, temp->key); // 3-3. root->right에 delete_node(root->right)...(복사된 값을 갖고있던 노드 삭제)
	}
	return root; //새로운 root 반환
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

	root = insert_node(root, 55);
	printf("55 INSERT 결과\n");
	inorder(root);
	printf("\n\n");

	root = delete_node(root, 50);
	printf("50 DELETE 결과\n");
	inorder(root);
	printf("\n\n");

	if (search(root, 30) != NULL) { printf("30 발견\n"); }
	else { printf("30 발견 실패\n"); }

	return 0;
}
