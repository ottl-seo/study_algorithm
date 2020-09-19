/* 4. 마름모 출력하기 */

#include <stdio.h>
int main() {
	int n;
	printf("Input n: "); //라인 수로 입력 받기
	scanf_s("%d", &n);

	// 위 삼각형
	for (int i = 0; i < n; i++) { // n줄
		for (int b = 0; b < (n - i); b++) //blank
			putchar(' ');
		for (int s = 0; s < (2 * i - 1); s++) //star
			putchar('*');
		putchar('\n');
	}
	// 아래 삼각형
	for (int i = n; i > 0; i--) {
		for (int b = 0; b < (n - i); b++) //blank
			putchar(' ');
		for (int s = 0; s < (2 * i - 1); s++) //star
			putchar('*');
		putchar('\n');
	}
	return 0;
}

// 함수화는 하지 않음
// 줄 수로 따지는 게 더 편하다
// blank와 star는 전체를 한 번에 제어 X -- 한줄에 찍히는 걸 반복문화 하는 거임(2i-1)
