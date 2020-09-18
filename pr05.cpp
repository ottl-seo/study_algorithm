/* 5. 19단 출력하기.
- 한 단이 출력될 때마다 엔터로 넘기게 하기 */

#include <stdio.h>

int main() {
	for (int dan = 1; dan <= 19; dan++) {
		printf("[ %d단 출력 ]\n",dan);
		for (int i = 1; i <= 19; i++)
			printf("%2d * %2d = %3d\n", dan, i, dan * i);
		printf("Enter 키를 누르세요.");

		// 엔터로 어떻게 넘김??? --getchar() 이용
		getchar(); //문자 하나 받고 넘어가게
	}
	return 0;
}