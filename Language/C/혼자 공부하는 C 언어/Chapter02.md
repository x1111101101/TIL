# **Chapter 02 - 상수와 데이터 출력**
## main 함수 구조
- 머리는 함수 원형 function prototype라고 하며, 함수의 이름과 필요한 데이터 등을 표시
------
기초적인 문법들은 이미 익숙하므로 최대한 기록하지 않음

## printf
printf: print formatted - 일정한 형식에 따라 출력

## #include <stdio.h>
- stdio.h 파일의 내용을 프로그램 안에 복사한다는 의미. 
- stdio(standard IO): C 언어에서 기본으로 사용하는 입출력 함수 내장.

## 제어 문자
출력 방식에 영향을 주는 문자

### \n
개행(new line): 다음줄로 이동

### \t
커서가 다음 탭 위치로 이동

### \b
백스페이스(backspace): 한칸 왼쪽으로 이동
```C
printf("goot\bd\tchance\n");
/*
[출력 흐름]
goot -> goo -> good -> good chance
*/

```


### \r
캐리지 리턴: 커서가 첫 번째 칸으로 이동, \b와 마찬가지로 문자열을 덮어쓰게 됨

### \a
알럿 경보, alert: 이 문자열이 출력될 순서에 벨소리를 출력함

## 정수와 실수 출력
- %d: decimal - 정수 출력
- %lf: long float - 실수 출력

구글링 해보니 입력 받을 땐 double은 %lf로 구분해줘야 하지만, 출력할 땐 %f, %lf 모두 사용해도 차이가 없다고 한다.
http://gigglehd.com/zbxe/10649472


