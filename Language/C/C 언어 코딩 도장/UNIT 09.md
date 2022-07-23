## char
문자에 해당하는 정수를 저장. char a = 'A', char a = 97;

## 아스키코드
어떤 정수값을 어떤 문자에 대응시킬지를 표준화함(0~127)

## 작은따옴표
로는 문자 하나만 묶을 수 있지만 2바이트 정수값을 할당할 때 2문자를 묶을 수 있다.
```
unsigned short magic = 'BA';
```

## 제어문자
ASCII 코드는 아래의 제어 문자도 포함한다

\n(LF): line feed, new line
\r(CR): 캐리지 리턴 - 줄의 시작 위치로
\t(TAB): 수평 탭


CR과 LF는 타자기의 두 동작으로 부터 유래.
운영체제별로 파일에서의 줄바꿈을 규정하는 아스키 코드가 다른데 아래와 같다.
Windows: CR LF
Linux, UNIX, OS X: LF
Mac: CR
보통 C 언어에서 printf로 값을 출력 시 OS와 상관 없이 LF만 써도 무방하다.

