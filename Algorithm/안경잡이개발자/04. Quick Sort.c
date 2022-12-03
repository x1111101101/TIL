#include <stdio.h>

/**
Quick Sort: 대표적인 분할 정복 알고리즘 
평균 속도: O(N * logN)

log2(1000000)은 20도 되지 않는다. 거의 상수나 마찬가지 -> 이 말은 거의 O(N)과 마찬가지라는 뜻이다. 


Quick Sort는 특정한 pivot값을 지정해서 pviot 값을 기준으로 원소를 두 집합으로 나눈다.
 
3 7 8 1 5 9 6 10 2 4
1. 일반적으로 퀵 정렬에서 pivot값은 가장 앞의 숫자로 지정한다. (위 배열에서 pivot값은 3) 
(3) 7 8 1 5 9 6 10 2 4
2. 왼쪽에서 오른쪽으로 이동하며 pivot 보다 큰 값을 선택한다 -> 7
3. 오른쪽에서 왼쪽으로 이동하며 pivot 보다 작은 값을 선택한다 -> 2
4. 두 값이 엇갈리지 않는다면(즉, 작은 값의 인덱스가 큰 값의 인덱스보다 크다면) 둘의 자리를 바꾼다. ->
(3) 2 8 1 5 9 6 10 7 4
5. 엇갈리는 값이 나올 때 까지 반복한다.
-> (3) 2 1 8 5 9 6 10 7 4

6. 큰값: 8, 작은 값: 1 -> 엇갈린다 
7. 작은 값과 pivot을 swap
-> 1 2 (3) 8 5 9 6 10 7 4 -> 이때 pivot은 정렬이 이루어 졌다. 즉 3의 자리는 확정됨(3의 왼쪽 값들은 모두 3보다 작고 오른쪽 값들은 모두 3보다 큼) 
-> 집합이 두개로 나뉨(3의 왼쪽, 3의 오른쪽)
8. 나뉜 두 집합에서 위와 동일한 연산을 수행
왼쪽 집합:(1) 2 
오른쪽 집합: (8) 5 9 6 10 7 4
(8) 5 4 6 10 7 9 
(8) 5 4 6 7 10 9
7 5 4 6 (8) 10 9 -> 8의 자리 확정

또 나뉜다
(7) 5 4 6, (10) 9
6 5 4 (7), 9 (10)

또 나뉘었다
(6) 5 4
4 5 (6)

또 나뉜다
(4) 5

-> 모든 요소의 자리가 확정되었다. -> 정렬 끝 
 

분할 시 시간복잡도의 변화(분할 정복의 원리):
	시간복잡도가 N^2일 때 
	1 2 3 4 5 6 7 8 9 10의 데이터를 처리할때 소요시간: 10^2 = 100
	{1 2 3 4 5}, {6 7 8 9 10} 각각의 소요시간의 합: 5^2 + 5^2 = 25 + 25 = 50
	{1 2}, {3 4 5}, {6 7 8}, {9 10} 각각의 소요시간의 합: = 4 + 9 + 9 + 4 = 26 

*/
int data3[10] = {3, 7, 8, 1, 5, 9, 6, 10, 2, 4};
int data2[10] = {1,3,2,4,5,6,7,8,9,10};
int data[10] = {10,9,8,7,6,5,4,3,2,1};
int main(void) {
	printData();
	quickSort(data, 0, 9);
	int i;
	printData();
}

void printData() {
	int i;
	for(i = 0; i<10; i++) printf("%d ", data[i]);
	printf("\n");
}

void quickSort(int data[], int begin, int end) {
	printf("%d ~ %d\n", begin, end);
	if(begin >= end) return;
	int pivot = data[begin];
	int left = begin+1, right = end;
	while(left <= end && left < right) {
		// find big
		while(left <= end && data[left] < pivot) left++;
		printf("left: %d\n", left);
		// find small
		while(right>=begin && data[right] > pivot) {
			right--;
		}
		
		printf("right: %d\n", right);
		if(left < right) {
			// con1. 교차X
			swap(data, left, right); printData();
			continue;
		} else if (right==begin) {
			// con2. R-X
			quickSort(data, begin+1, end);
			quickSort(data, begin, left-1);
		} else if (left==end+1){
			// con3. L-X
			swap(data, begin, end); printData();
			
			quickSort(data, begin, end-1);
		} else {
			// con4. 교차
			swap(data, right, begin); printData();
			quickSort(data, begin, left-1);
			quickSort(data, left+1, end);
		}
		return;
	}
	
	
	
}

void swap(int arr[], int index1, int index2) {
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}
