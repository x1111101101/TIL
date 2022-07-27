## 2의 거듭제곱
어떤 수에 2^x를 곱할 때 왼쪽 시프트를 이용하면 빠르다.
```c
#include <stdio.h>

int main(void) {
	int a = 6;
	printf("%d\n", a<<3); // 48
	printf("%d\n", a*2*2*2);  // 48
}
```

## 범위 초과
1바이트 짜리 값 0100 0000을 오른쪽으로 2칸 Shift -> 0000 00000

0000 1010을 왼쪽으로 2칸 Shift -> 0000 0010

## MSB, LSB
- Most Significant Bit: 가장 왼쪽 비트(부호 비트)
- Least Significant Bit: 가장 오른쪽 비트


## signed 자료형에 시프트 연산 하기
부호가 있는 signed 자료형에 시프트 연산 시 부호비트 자리에 의해 양수가 음수가 되거나 음수가 양수로 바뀌는 일이 일어날 수 있으니 유의하자.

``` C
#include <stdio.h>
 
int main()
{
    char num1 = -125;            // -125: 1000 0011
    
    char num2 = num1 >> 5; // 1000 0011 -> 1100 0001 ->  1110 0000 -> 1111 0000 -> 1111 1000 -> 1111 1100
    // 오른쪽 시프트 시 시프트되면서 비게되는맨 첫째 자리는 부호 비트로 채워진다. 위 예에서는 양수->음수가 됨
    
    printf("%d", num2);


    return 0;
}
```
``` C
#include <stdio.h>
 
int main()
{
    char num1 = -125;            // -125: 1000 0011 -> 0110 0000
    
    char num2 = num1 << 5; // 1000 0011 -> 0110 0000
    // 왼쪽 시프트는 부호 비트 값과 상관 없이 최우측이 0으로 채워지면서 비트들이 이동한다.
    
    
    printf("%d\n", num2);

    char num3 = 9;
    printf("%d\n", num3 << 3); // 0000 1001 ->  0100 1000(72)
    return 0;
}
```
``` C
#include <stdio.h>
 
int main()
{
    char num1 = 113;    //  113: 0111 0001
    char num2 = -15;    //  -15: 1111 0001 (0000 1110 -> 1111 0001 (bit flip))
    char num3, num4, num5, num6;
 
    num3 = num1 << 2;    // num1의 비트 값을 왼쪽으로 2번 이동 -> 1100 0100 - 부호 비트를 덮어쓰게 되므로 양수에서 음수가 됨
    num4 = num2 << 2;    // num2의 비트 값을 왼쪽으로 2번 이동 -> 1100 0100: 이미 음수인 수는 계속 음수가 됨
    printf("%d\n", num3);
    printf("%d\n", num4);
    
    num5 = num1 << 4;    // num1의 비트 값을 왼쪽으로 4번 이동
    num6 = num2 << 4;    // num1의 비트 값을 왼쪽으로 4번 이동
    printf("%d\n", num5);    // 16: 0001 0000 (양수)
    printf("%d\n", num6);    // 16: 0001 0000 (양수)
 
    return 0;
}
```



