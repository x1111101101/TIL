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

## 심사 문제
표준 입력으로 두 정수(unsigned int)가 입력됩니다. 입력된 두 정수의 비트 연산 결과를 각 줄에 출력하는 프로그램을 만드세요(scanf 함수 호출 전에 문자열을 출력하면 안 됩니다).

num1과 num2을 비트 XOR 연산
num1과 num2을 비트 OR 연산
num1과 num2를 비트 AND 연산
num1을 비트 NOT 연산
출력 결과는 서식 지정자 %u를 사용하세요.

정답에는 C 언어 컴파일러에서 정상적으로 컴파일되는 전체 코드를 입력해야 합니다.

### 내 답안
``` c
#include <stdio.h>

int main(void) {
    unsigned int a,b;
    scanf("%u %u", &a, &b);
    printf("%u\n%u\n%u\n%u\n", a^b, a|b, a&b, ~a);
}
```
-----
표준 입력으로 정수가 입력됩니다. 입력된 정수를 왼쪽으로 20번, 오른쪽으로 4번 시프트 연산하여 결과를 출력하는 프로그램을 만드세요(scanf 함수 호출 전에 문자열을 출력하면 안 됩니다). 단, 정수형 변수는 unsigned long long으로 선언하고 출력 결과는 서식 지정자 %llu를 사용하세요.

정답에는 C 언어 컴파일러에서 정상적으로 컴파일되는 전체 코드를 입력해야 합니다

### 내 답안:
``` c
#include <stdio.h>

int main(void) {
    unsigned long long a;
    scanf("%llu", &a);
    printf("%llu", a << 20 >> 4);
}
```
