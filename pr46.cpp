/* week3 다항식 배열 문제 #2 
	다항식에서 0이 아닌 항만을 배열에 저장 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 101

struct {
	float coef; //계수
	int expon; //차수
}terms[MAX] = { {4,7},{8,6},{7,5},{1,1},{10,3},{-7,1},{1,0} };
 //이렇게 태그 네임 없이 정의할 시, 한번 정의하면 끝임
// 두고두고 쓰려면 typedef 하고 태그네임 써주기

int avail = 7; //현재 비어있는 위치의 인덱스 (항 몇개인지. C가 오기 위해)

void add(float coef, int expon) { //항 추가
	if (avail > MAX) {
		printf("저장 불가\n");
		exit(1);
	}
	terms[avail].coef = coef; //배열의 다음 위치에 새로운 계수,차수 넣는다
	terms[avail].expon = expon;
	avail++; //비어있는 위치 인덱스 증가
}
void print_poly(int start, int end) {
	for (int i = start; i < end; i++) {
		printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%.1fx^%d\n", terms[end].coef, terms[end].expon);
}
void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) { //포인터로 보내는 이유? 리턴값 2개일수 없으므로 저장하려고..
	*Cs = avail; //결과 다항식의 시작 위치
	while (As <= Ae && Bs <= Be) {
		if (terms[As].expon > terms[Bs].expon) { //A다항식의 차수가 더 큰 경우.
			add(terms[As].coef, terms[As].expon);
			As++; //다음 항으로 이동
		}
		else if (terms[As].expon == terms[Bs].expon) { //같은 차수일 경우
			if (terms[As].coef + terms[Bs].coef != 0) { //더해서 0인경우 추가 x
				add(terms[As].coef + terms[Bs].coef, terms[As].expon);
			}
			As++; Bs++;
		}
		else { //B항이 더 큰 경우
			add(terms[Bs].coef, terms[Bs].expon);
			Bs++;
		}
	} //end of while
	for (; As <= Ae; As++) { //As가 아직 남은 경우.
		add(terms[As].coef, terms[As].expon);
	}
	for (; Bs <= Be; Bs++) { //Bs가 아직 남은 경우.
		add(terms[Bs].coef, terms[Bs].expon);
	}
	*Ce = avail - 1; //항 추가 후 avail이 자동으로 증가 되었ㅇ므ㅡ로 종료 위치는 avail-1
}

int main() {
	int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;
	poly_add(As, Ae, Bs, Be, &Cs, &Ce); //반환값이 두개일 수 없으므로 call by reference
	
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("------------------------------------------\n");
	print_poly(Cs, Ce);

	return 0;
}