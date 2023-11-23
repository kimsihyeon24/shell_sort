#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int n;
int move_count = 0;
int compare_count = 0;


// gap ��ŭ ������ ��ҵ��� ���� ����
// ������ ������ first���� last
inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j];
			move_count++; // �̵� Ƚ�� �߰�
		}
		list[j + gap] = key;
		compare_count++; // �� Ƚ�� �߰�
	}
}

void shell_sort(int list[], int n, int a)   // n = size
{
	int i, gap;
	
		for (i = 0; i < n; i++) {    	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		}
		for (i = 0; i < n; i++) {    	// ���� ���� �� ��� 
			list[i] = rand() % 100;
		}
		for (gap = n / 2; gap > 0; gap = gap / 2) {
			if ((gap % 2) == 0) gap++;
			for (i = 0; i < gap; i++)		// �κ� ����Ʈ�� ������ gap
				inc_insertion_sort(list, i, n - 1, gap);
			
			if (a == 0) {
				for (i = 0; i < n; i++) {
					
					printf("%d ", list[i]);
				}
				printf("\n");
			}
		}	

		
}


int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (int a = 0; a < 20; a++) {
		for (i = 0; i < n; i++) {    	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		}
		for (i = 0; i < n; i++) {    	// ���� ���� �� ��� 
			list[i] = rand() % 100;
		}
		if (a == 0) { // ��ü �ѹ��� ���
			printf("Original List\n");
			for (i = 0; i < n; i++) {
				printf("%d ", list[i]);
			}
			printf("\n\n");
		}
	
		shell_sort(list, n, a);
	 
	}

	printf("Average Compare Count : %d\n", compare_count/20 ); // ��Ƚ�� ���
	printf("Average Move Count : %d\n", move_count/20 ); // �̵�Ƚ�� ���
}
