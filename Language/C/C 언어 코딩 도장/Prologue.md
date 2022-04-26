
## 온라인 C 컴파일러
http://www.tutorialspoint.com/compile_c_online.php

## 프로젝트와 솔루션
프로젝트: 헤더파일, 소스파일의 모음  
솔루션: 프로젝트의 모음

## include
헤더 파일을 포함시키는 문법. 여러 함수 등을 사용하기 위해 헤더 파일을 포함시켜야 한다.

## 서식 지정자
%s: 문자열 변수 등을 출력할 때 유용하게 사용 가능

## 코딩 심사
https://dojang.io/
코딩 도장 책의 코딩 문자들에 대한 시험

## C, C++ 빌드 모드
Debug Mode: 지역 변수 등 디버깅 정보를 포함  
Release Mode: 디버깅 정보를 포함하지 않음. 속도화 용량 최적화

## 컴퓨테이셔널 씽킹
1. 분해: 복잡한 문제를 작은 문제로 나눈다
2. 패턴 인식: 문제 안에서 유사성을 발견한다
3. 추상화: 문제의 핵심에만 집중하고 부차적인건 제외
4. 알고리즘: 이렇게 정의한 문제를 해결하는 절차

## 자료형
int, short, long, char: 정수  
float, double: 실수  
void: 형태가 없는 자료형(포인터를 사용할 때, 함수의 반환값을 표현할 때 등 다양하게 사용됨)

## 한번에 여러개 변수 선언, 할당
```
int num1=30, num2=30;
```
## 중단점(break point)
을 활용해서 디버깅을 손쉽게 할 수 있다

## long
자바의 long와 c의 long에는 차이가 꽤 있다. C에서 long은 아키텍쳐나 운영체제에 따라서 최적으로 사용할 수 있는 크기의 비트수를 가진다.

The size of a "long" integer varies between architectures and operating systems.  
https://www.intel.com/content/www/us/en/developer/articles/technical/size-of-long-integer-type-on-different-architecture-and-os.html

long long 자료형은 8byte 크기 고정

## 서식 지정자
%ld: long decimal  
%lld: long long deciaml  
%d: decimal  
%u: unsigned decimal  
%lu: long unsigned decimal  
%llu: long long unsigned decimal  

unsigned char, unsigned short는 %d로 충분히 출력되나, unsigned int는 %u를 사용해야하고, unsigned long 은 %lu, unsigned long long은 %llu를 써야한다.

## 오버플로우와 언더플로우
정수형 자료형에서 표현할 수 있는 범위를 넘어서는 수를 저장하게되면 오버/언더플로우가 발생해 최소/최댓값 부터 다시 시작한다

## sizeof
byte 단위로 자료형의 크기를 구할 수 있다.

sizeof 표현식 / sizeof(표현식): 변수, 배열 등  
sizeof(자료형)

```
sizeof(int)
sizeof(num1)
sizeof num1
```
