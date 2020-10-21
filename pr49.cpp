/* 재귀함수로 거듭제곱 구현하기 (시간복잡도)
	2020-2 데이터구조 시험문제 */

#include <stdio.h>
#include <stdlib.h>

int midterm(int a, int n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) return midterm(a * a, n / 2);
	else return a*midterm(a * a, (n - 1) / 2);
}

int main() {
	int a, n;
	printf("Input a: ");
	scanf_s("%d", &a);

	printf("Input n: ");
	scanf_s("%d", &n);

	int result = midterm(a, n);
	printf("a^n = %d\n", result);

	return 0;
}
