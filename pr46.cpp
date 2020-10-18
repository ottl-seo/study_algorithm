/* week3 ���׽� �迭 ���� #2 
	���׽Ŀ��� 0�� �ƴ� �׸��� �迭�� ���� */
#include <stdio.h>
#include <stdlib.h>
#define MAX 101

struct {
	float coef; //���
	int expon; //����
}terms[MAX] = { {4,7},{8,6},{7,5},{1,1},{10,3},{-7,1},{1,0} };
 //�̷��� �±� ���� ���� ������ ��, �ѹ� �����ϸ� ����
// �ΰ�ΰ� ������ typedef �ϰ� �±׳��� ���ֱ�

int avail = 7; //���� ����ִ� ��ġ�� �ε��� (�� �����. C�� ���� ����)

void add(float coef, int expon) { //�� �߰�
	if (avail > MAX) {
		printf("���� �Ұ�\n");
		exit(1);
	}
	terms[avail].coef = coef; //�迭�� ���� ��ġ�� ���ο� ���,���� �ִ´�
	terms[avail].expon = expon;
	avail++; //����ִ� ��ġ �ε��� ����
}
void print_poly(int start, int end) {
	for (int i = start; i < end; i++) {
		printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%.1fx^%d\n", terms[end].coef, terms[end].expon);
}
void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) { //�����ͷ� ������ ����? ���ϰ� 2���ϼ� �����Ƿ� �����Ϸ���..
	*Cs = avail; //��� ���׽��� ���� ��ġ
	while (As <= Ae && Bs <= Be) {
		if (terms[As].expon > terms[Bs].expon) { //A���׽��� ������ �� ū ���.
			add(terms[As].coef, terms[As].expon);
			As++; //���� ������ �̵�
		}
		else if (terms[As].expon == terms[Bs].expon) { //���� ������ ���
			if (terms[As].coef + terms[Bs].coef != 0) { //���ؼ� 0�ΰ�� �߰� x
				add(terms[As].coef + terms[Bs].coef, terms[As].expon);
			}
			As++; Bs++;
		}
		else { //B���� �� ū ���
			add(terms[Bs].coef, terms[Bs].expon);
			Bs++;
		}
	} //end of while
	for (; As <= Ae; As++) { //As�� ���� ���� ���.
		add(terms[As].coef, terms[As].expon);
	}
	for (; Bs <= Be; Bs++) { //Bs�� ���� ���� ���.
		add(terms[Bs].coef, terms[Bs].expon);
	}
	*Ce = avail - 1; //�� �߰� �� avail�� �ڵ����� ���� �Ǿ����Ǥѷ� ���� ��ġ�� avail-1
}

int main() {
	int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;
	poly_add(As, Ae, Bs, Be, &Cs, &Ce); //��ȯ���� �ΰ��� �� �����Ƿ� call by reference
	
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("------------------------------------------\n");
	print_poly(Cs, Ce);

	return 0;
}