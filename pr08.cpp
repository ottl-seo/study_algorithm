/* 8. 난수 발생
	- 범위 내 20개 출력 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int start, end;
	int x, num; // 범위 정할 때 사용할 x, 난수 num
	printf("시작값을 입력하세요: ");
	scanf_s("%d", &start);
	printf("종료값을 입력하세요: ");
	scanf_s("%d", &end);
	
	x = end - start + 1; // 종료값-시작값 +1
	for (int i = 0; i < 20; i++) {
		num = rand() % x + start; //start값을 더해 범위를 맞춰준다.
		printf("\n%d", num);
	}
	return 0;
}

/* 난수 발생 방법: <stdlib.h>의 rand() 함수
	 rand() % 10 // 0~9까지의 난수 발생
	 rand() % 50 // 0~49
	 rand() % 50 + 10 // 10~49
*/