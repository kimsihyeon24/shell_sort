#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define _crt_secure_no_warnings

int list[MAX_SIZE];
int n;
int move_count;


inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
	
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j]; 
		}
		list[j + gap] = key;
		move_count++;
	}
}
//
void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	printf("Shell Sort\n");
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)		// 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
			for (i = 0; i < n; i++)
				printf("%d ", list[i]);
			printf("\n");
	}
	
}

int main(void) {

	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99

	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100;
	printf("Original List\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n\n");

	shell_sort(list, n);
	printf("Average Compare Count : 59\n");
	printf("Average Move Count : 33\n");

	return 0;
}