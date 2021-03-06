# **Chapter01 - 프로그램 만들기**
## C 언어의 탄생
- 1972년 데니스 리치가 UNIX 시스템에 사용하기 위해 켄 톰슨이 만든 B 언어를 발전시켜 만들었다
- 초기 유닉스는 어셈블리어로 작성되어 이식성이 낮았다

## C 언어의 장점
- 시스템 프로그래밍이 가능하다 - 운영체제를 개발할 목적로 만든 언어 - 하드웨어 제어 시스템 프로그래밍 가능
- 이식성을 갖춘다. - 표준이 정의되어있다.
- 함수를 사용하여 개별 프로그래밍할 수 있다 - 기능별로 프로그래밍 가능 - 개발 과정에서 에러 수정 용이 - 유지보수 용이, 함수의 재활용 가능

-----
이 책은 1999년에 제정된 C 언어의 국제 표준인 ISO/IEC 9899:1999(줄여서 C99)를 바탕으로 범용적으로 사용할 수 있는 코드를 설명함



# 컴파일과 컴파일러 사용법
- 컴파일: 소스 파일을 컴퓨터가 이해하는 언어인 기계어로 바꾸는 과정
- Visual Studio 모두 저장 단축키: Ctrl + Shift + S
- 솔루션 빌드 단축키: Ctrl + Shift + B
- 실행 파일 실행 단축키: Ctrl + F5
- 프로젝트 폴더/Debug 폴더의 exe 파일을 실행하여 프로그램을 실행하는게 기본적인 실행 방법이다.

## 컴파일 과정 3단계
1 단계: 전처리
- 전처리 지시자에 따라 소스 파일을 가공하는 과정. 
- #include가 전처리 지시자에 해당. - 외부 함수를 불러들이는 역할
- 파일 형태에는 변화가 없다. 자세한 설명은 19장에서

2 단계: 컴파일
- 전처리가 끝난 파일을 compile 시 개체 파일(object file)이 된다. 이는 CPU가 해석할 수 있는 명령어들로 이루어진 기계어 파일이다. 프로그램은 OS에 의해 실행되니 바로 실행은 불가능하다 - 운영체제가 인식할 수 있는 형태로 바꿔야 한다.

3 단계: 링크
- 개체 파일에 startup code를 결합하여 실행파일을 만드는 과정
- startup code: 프로그램을 실행하기 전 준비작업을 수행하는 역할, main 함수 호출
