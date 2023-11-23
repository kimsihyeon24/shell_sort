#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int n;
int move_count = 0;
int compare_count = 0;


// gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last
inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j];
			move_count++; // 이동 횟수 추가
		}
		list[j + gap] = key;
		compare_count++; // 비교 횟수 추가
	}
}

void shell_sort(int list[], int n, int a)   // n = size
{
	int i, gap;
	
		for (i = 0; i < n; i++) {    	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		}
		for (i = 0; i < n; i++) {    	// 난수 생성 및 출력 
			list[i] = rand() % 100;
		}
		for (gap = n / 2; gap > 0; gap = gap / 2) {
			if ((gap % 2) == 0) gap++;
			for (i = 0; i < gap; i++)		// 부분 리스트의 개수는 gap
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
		for (i = 0; i < n; i++) {    	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
		}
		for (i = 0; i < n; i++) {    	// 난수 생성 및 출력 
			list[i] = rand() % 100;
		}
		if (a == 0) { // 전체 한번만 출력
			printf("Original List\n");
			for (i = 0; i < n; i++) {
				printf("%d ", list[i]);
			}
			printf("\n\n");
		}
	
		shell_sort(list, n, a);
	 
	}

	printf("Average Compare Count : %d\n", compare_count/20 ); // 비교횟수 출력
	printf("Average Move Count : %d\n", move_count/20 ); // 이동횟수 출력
}
