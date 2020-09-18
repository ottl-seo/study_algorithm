/* 6. 달팽이 우물 탈출하기 
	- 달팽이가 7m를 이동한 후, 3m씩 밑으로 미끄러질 때, 몇 회만에 탈출하는가?
*/
#include <stdio.h>

int main() {
	int tall = 0; //달팽이가 이동한 높이
	int count = 0; //몇 회인지 카운트
	while (1) { //무한반복, tall이 100 이상이 되면 break
		count++;
		tall += 7; //7m 이동
		if (tall >= 100){
			printf(" [%2d] 달팽이: %3dm\n", count, tall); //출력하고 break
			break;
		}
		else
			tall -= 3; //3m 미끄러짐
		printf(" [%2d] 달팽이: %3dm\n", count, tall);
	}
	printf("불쌍한 달팽이는 %2d회 만에 우물을 탈출했답니다.\n", count);
	return 0;
}