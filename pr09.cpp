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

/* 
	switch문의 case에 빠져있는 값이 있으면 안 됨
	즉 100-90-80 이렇게 전달이 안 되고, 100-99-98-... 이렇게 모든 수를 case로 지정해줘야 함.
	그렇지 않으면 case로 지정해주지 않은 값은 default case가 됨-> "Wrong Input"

	case 10:
	case 9: //이렇게 하면 같은 케이스인 것도 기억.

*/