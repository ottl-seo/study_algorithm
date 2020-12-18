/* 9. 입력된 값에 따라 학점 출력하기
	- switch문 연습 */
#include <stdio.h>

int main() {
	int input;
	char grade; // A~F

	printf("<< 학점 계산기 >>\n");
	printf("본인의 점수(0~100)를 입력하면 학점을 출력합니다.\n");
	printf("( 종료코드: 111 )\n");
	printf("--------------------\n");
	
	
	while (1) {
		printf("\n점수: ");
		scanf_s("%d", &input);

		if (input == 111) { // 엔터 입력 시 종료
			printf("프로그램을 종료합니다.\n");
			break;
		}
		switch (input / 10)
		{
		case 10:
		case 9:
			printf("A\n");
			break;
		case 8:
			printf("B\n");
			break;
		case 7:
			printf("C\n");
			break;
		case 6:
			printf("D\n");
			break;
		case 5:
		case 4:
		case 3:
		case 2:
		case 1:
		case 0:
			printf("F\n");
			break;
		default:
			printf("Wrong Input\n");
			break;
		}
	}
	return 0;
}
