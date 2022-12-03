#include <stdio.h>

/**
Selection Sort(선택 정렬)
 
{1,4,3,2,5,7,6,9,8,10}를 오름차순으로 정렬하라 
-> 한 인덱스 씩 차례대로 그 다음 인덱스들의 값들을 비교해서 최소값을 넣음 
*/
int main(void) {
	int array[10] = {1,4,3,2,5,7,6,9,8,10};
	
	int i;
	int j;
	
	for(i = 0; i<10; i++) {
		int min = array[i];
		int index = i;
		for(j = i+1; j< 10; j++) {
			if(array[j] < min) {
				min = array[j];
				index = j;
			}		
		}
		// swapping
		int copied = array[i];
		array[i] = array[index];
		array[index] = copied;
	}
	
	for(i = 0; i<10; i++) {
		printf("%d ", array[i]);
	}
}

/*
 result: 1 2 3 4 5 6 7 8 9 10
 
 연산 과정:
 	1. 10번 비교 
 	2. 9 번 비교
	3. 8번 비교
	. . .
	10. 1번 비교
	
총 비교 횟수: 등차가 1인 등차수열의 S10
 Sn = (1/2)*N^2 + (1/2)N = (N/2)*(N+1)
 
 일반적으로 알고리즘에서 N은 매우 큰 값으로 가정 -> 나누고 곱하고 더하는 연산은  생략 -> BigO 표기로 하면: (N)*(N) = N^2 
 선택정렬의 시간 복잡도: O(N^2)
 
*/
