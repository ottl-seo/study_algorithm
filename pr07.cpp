/* 7. 실수 10개 입력받아 합계, 평균 구하기 */

#include <stdio.h>
int main() {

	double input; //입력받을 실수
	double sum = 0;

	for(int i=0;i<10;i++){
		printf("%d번째 수: ", i + 1);
		scanf_s("%f", &input);
		sum += (double)input;
	}
	printf("\n합계: %f", sum);
	printf("\n평균: %f", (double)sum / (double)10);

	return 0;
}

// 오버플로우 해결 how ?