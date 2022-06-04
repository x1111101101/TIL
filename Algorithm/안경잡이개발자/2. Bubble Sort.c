#include <stdio.h>

/**
Bubble Sort(버블 정렬)
 
{1,3,2,5,4}를 오름차순으로 정렬하라

1. 손으로 알고리즘 확인해보기
	1,3,2,5,4
	1,2,3,5,4
	1,2,3,4,5

	한번 모든 인덱스(1~5)를 탐색하면 최댓값이 마지막 인덱스에 항상 위치함
	따라서 마지막 인덱스가 1씩 작아짐 
	
*/

// {1,4,3,2,5,7,6,9,8,10}를 오름차순으로 정렬하라 
int main(void) {
	int arr[] = {1,4,3,2,5,7,6,9,8,10};
	int i, k, temp;
	for(i = 0; i<10; i++) {
		for(k =i+1; k<10-i; k++) {
			if(arr[k] < arr[i]) {
				temp = arr[k];
				arr[k] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	
	for(i = 0; i<10; i++) 
		printf("%d ", arr[i]);
	
}

/**
선택정렬과 마찬가지로 한번 반복할 때 마다 집합 크기가 1씩 줄어듬 -> 비교 횟수: 10, 9, 8, 7, ... ,1
 -> (N/2)*(N+1) -> O(N^2)
 
버블 정렬: 루프 시 매번 swap
선택 정렬: 루프 시 한번 swap
-> 버블 정렬이 선택정렬에 비해 더 비효율적 
*/
