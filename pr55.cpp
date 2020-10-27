/* ���� 1157. �ܾ� ���� 
https://www.acmicpc.net/problem/1157 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct dictionary {
	char ch; // ���ĺ�
	int num; //�ش� ���ĺ� ����
}dictionary;

char find_max(dictionary dict[], int dict_len);
void add_word(dictionary dict[], int* dict_len, char ch);
char what_word(char* string);

int main() {
	char input[MAX]; //�Է¹��� ���ڿ�
	char fre; //���� ���� ���� ���ĺ�

	printf("�ܾ �Է��ϼ���\n");
	gets_s(input);
	fre = what_word(input);
	
	printf("\n%c\n", fre);
	return 0;
}
char find_max(dictionary dict[],int* dict_len) {
	int max = 1;
	char max_ch = dict[0].ch;

	for (int i = 0; i < *dict_len; i++) {
		if (dict[i].num > max) { max_ch == dict[i].ch; }
		else if (dict[i].num == max) { max_ch = '?'; }
	}
	return max_ch;
}
void add_word(dictionary dict[],int* dict_len, char ch) {
	for (int i = 0; i < *dict_len; i++) {
		if (ch == dict[i].ch) { dict[i].num++; return; }
	}
	// ��ųʸ� ������ ���� ������, ���ο� ������ �߰�	
	dict[++*dict_len] = { ch,1 }; return;
}

char what_word(char* string) {
	int len = strlen(string);
	char ch; char freq;
	
	dictionary dict[MAX]; // ��ųʸ� ����ü �迭 ����
	dict[0] = { string[0], 1 }; //ù ���ڸ� ����ü�� ����
	int dict_len = 1; //��ųʸ��� ����= 1

	for (int i = 1; i < len; i++) {
		add_word(dict, &dict_len, ch = string[i]);
	}
	freq = find_max(dict, &dict_len);
	return freq;
}