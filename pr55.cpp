/* 백준 1157. 단어 공부 
https://www.acmicpc.net/problem/1157 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct dictionary {
	char ch; // 알파벳
	int num; //해당 알파벳 개수
}dictionary;

char find_max(dictionary dict[], int dict_len);
void add_word(dictionary dict[], int* dict_len, char ch);
char what_word(char* string);

int main() {
	char input[MAX]; //입력받을 문자열
	char fre; //가장 많이 사용된 알파벳

	printf("단어를 입력하세용\n");
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
	// 딕셔너리 끝까지 가도 없으면, 새로운 항으로 추가	
	dict[++*dict_len] = { ch,1 }; return;
}

char what_word(char* string) {
	int len = strlen(string);
	char ch; char freq;
	
	dictionary dict[MAX]; // 딕셔너리 구조체 배열 생성
	dict[0] = { string[0], 1 }; //첫 문자를 구조체에 저장
	int dict_len = 1; //딕셔너리의 길이= 1

	for (int i = 1; i < len; i++) {
		add_word(dict, &dict_len, ch = string[i]);
	}
	freq = find_max(dict, &dict_len);
	return freq;
}