## 2의 거듭제곱
어떤 수에 2^x를 곱할 때 왼쪽 시프트를 이용하면 빠르다.
```c
#include <stdio.h>

int main(void) {
	int a = 6;
	printf("%d\n", a<<3); // 48
	printf("%d\n", a*8);  // 48
}
```

## 범위 초과
1바이트 짜리 값 0100 0000을 오른쪽으로 2칸 Shift -> 0000 00000

0000 1010을 왼쪽으로 2칸 Shift -> 0000 0010

## MSB, LSB
- Most Significant Bit: 가장 왼쪽 비트
- Least Significant Bit: 가장 오른쪽 비트



