# UNIT 23. 비트 연산자 사용하기
## AND OR XOR NOT
|연산|기호|
|---|---|
|AND|&|
|OR|||
|XOR|^|
|NOT|~|

### ex
101을 NOT 연산 -> 010

101과 100을 XOR 연산 -> 001

``` c
#include <stdio.h>

int main(void) {
    char c = 5; // 101(2진수)
	printf("%d\n", ~c); // -6(10진수)
	
	unsigned char cu = 5; // 00000101(2진수)
	printf("%u\n", cu); // 5(10진수)
	cu = ~cu;
	printf("%u\n", cu); // 250(10진수), 11111010(2진수)
}
```

UNIT 36에서 10진수를 2진수로 배열을 이용해서 변환하는 방법을 다룬다.

'비트 연산과 부호 비트에 대해서는 'Unit 24 비트 연산자 응용하기'에서 설명하겠습니다.'

## SHIFT
a << b: a 값의 비트들을 b칸 만큼 왼쪽으로 이동  
>>는 오른쪽으로 이동

``` c
#include <stdio.h>

int main(void) {
	int a = 13;
	printf("%d", a<<2); //52
	printf("%d", a); //13
}
```

## 연산 후 할당
``` C
num1 <<= 2;
num1 >>= 2;
num1 &= 2;
num1 |= 2;
num1 ^= 2;
```
