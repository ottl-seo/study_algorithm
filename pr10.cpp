/* 10. 배열 - 삽입, 수정, 삭제 연습 */

#include <stdio.h>

int main() {
	int location, value;
	int size = 5; //배열의 크기
	int arr[100] = { 1,2,3,4,5 };
	// *arr = { 1,2,3,4,5 }; //이렇게 안 됨???

	// 1. 삽입
	printf("arr = { 1,2,3,4,5 }\n");
	printf("삽입할 위치: ");
	scanf_s("%d", &location);
	location -= 1; //인덱스는 0부터 시작하므로 1을 빼준다

	printf("삽입할 값: ");
	scanf_s("%d", &value);

	for (int i = size; i >= location; i--)
		arr[i + 1] = arr[i]; //한 칸씩 밀기
	arr[location] = value; //반복문 끝나고 위치에 값 넣어준다
	size += 1;

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//예전에 과제할 때 인덱스 때문에 헷갈렸던 부분. 왜 location에 2를 빼줬어야했는지 헷갈렸는데 이제 알았당. 차근차근하기~!
// 동적 배열이 아니므로, 실제 값이 들어있는 만큼을 입력받거나 변수 지정해줘야 함 //sizeof(arr)하면 100 나옴

/* 배열에 대해서...
	배열 초기화는 선언할 때 하거나, 인덱스 하나하나 접근해서 해줘야 함.
	
	>> int arr[100] = {1,2,3,4,5}; ( O )
	>> arr[0] = 1; ( O )
	>> arr = {1,2,3,4,5}; ( X ) //이미 선언된 후에 이렇게는 X 
*/
