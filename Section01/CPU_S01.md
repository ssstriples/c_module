# C Power Upgrade
# Part1. 기본실력 점검 및 향상
## Section1. 콘솔 입출력
---
### 1. 기본적인 입력 및 출력에 대한 점검 
```
<문제>
키보드로부터 데이터를 입력 받고, 입력 받은 데이터를 입력 순서 그대로 출력하는 프로그램을 작성하자. 단, 반드시 다음 순서와 포맷으로 입력을 받아야 한다(콤마를 포함하여).
                [문자, 정수, 실수, 문자열]
```
```
<세부 요구사항>
- scanf 함수를 이용해서 데이터를 입력 받고, printf 함수를 이용해서 데이터를 출력한다.
- 각각의 입력 데이터 사이에 콤마(,)가 존재함에 주목하자. 데이터의 구분을 위해서 반드시 콤마를 입력 받는 형태로 프로그램을 구현해야 한다. 이 문제는 이 부분을 처리할 줄 아는지 확인하기 위한 것이다.
```
```
<실행의 예>
[문자, 정수, 실수, 문자열]의 포맷으로 입력: c, 7, 3.14, Good
입력된 데이터 출력: c, 7, 3.14, Good
```
```
#include <stdio.h>

int main(void)
{
    char ch;
    int iNum;
    double dNum;
    char str[100];

    printf("[문자, 정수, 실수, 문자열]의 포맷으로 입력: ");
    scanf("%c, %d, %lf, %s", &ch, &iNum, &dNum, str);
    
    printf("입력된 데이터 출력: %c, %d, %.2lf, %s \n", ch, iNum, dNum, str);
    return 0;
}
```
---
### 2. 문자열을 입력 받는 두 가지 방법의 차이점
```
<문제>
이름을 입력 받아서 출력하는 프로그램을 작성하자. 단, 다음과 같은 형태의 입력을 모두 허용해야 한다.
- "홍빛나"
- "홍 빛 나"
- "빛나는 홍"
```
```
<실행의 예>
문자열 입력 : 빛나는 홍!
입력된 문자열 : 빛나는 홍!
```
```
#include <stdio.h>
#define STR_LEN 50

int main(void)
{
    char name[STR_LEN];

    fputs("문자열 입력 : ", stdout);
    gets(name);

    fputs("입력된 문자열 : ", stdout);
    puts(name);

    return 0;
}
```
---
### 3. 숫자를 읽어 들이려는데 16진수로 읽고 싶다면?
```
<문제>
두 개의 정수를 16진수로 입력 받자. 그리고 이렇게 입력된 두 수의 합의 결과를 8진수, 10진수, 16진수로 각각 출력하는 프로그램을 작성하여라.
```
```
<첫번째 실행의 예>
두 수를 16진수로 입력 : 10 4
연산 결과 8진수 : 24
연산 결과 10진수 : 20
연산 결과 16진수 : 14
```
```
<두번째 실행의 예>
두 수를 16진수로 입력 : abc def
연산 결과 8진수 : 14253
연산 결과 10진수 : 6315
연산 결과 16진수 : 18ab
```
```
#include <stdio.h>

int main(void)
{
    int n1, n2;
    int add;

    fputs("두 수를 16진수로 입력 : ", stdout);
    scanf("%x %x", &n1, &n2);
    add = n1 + n2;

    printf("연산 결과 8진수 : %o\n", add);
    printf("연산 결과 10진수 : %d\n", add);
    printf("연산 결과 16진수 : %x\n", add);
    
    return 0;
}
```
---
### 4. 파일의 끝을 의미하는 EOF가 콘솔에서는 어떠한 의미를?
```
<문제4-1>
키보드로부터 EOF가 입력될 때까지 문자를 입력 받아서, 입력된 문자의 총 개수를 출력하는 프로그램을 작성하자. 그저 입력된 문자의 개수만 출력하면 된다. 입력 받은 문자들을 저장해 둘 필요가 없다는 뜻이다.

<문제4-2>
키보드로부터 EOF가 입력될 때까지 숫자를 입력 받아서, 입력된 숫자의 총 합을 출력하는 프로그램을 작성하자.
```
```
<세부 요구사항>
- 문제 4-1은 getchar함수를 활용해서 해결한다.
- 문제 4-2는 여러분이 원하는 함수를 선택해서 해결한다. 그러나 숫자를 입력 받기 위해서는 scanf함수의 선택이 불가피할 것이다. 물론 다른 방법을 고민해 볼 수는 있겠으나 scanf함수를 활용하는 것만큼 쉽지 않다.
```
```
<문제4-1 실행의 예>
Data input(Ctrl+Z to exit) : a
Data input(Ctrl+Z to exit) : b
Data input(Ctrl+Z to exit) : c
Data input(Ctrl+Z to exit) : d
Data input(Ctrl+Z to exit) : e
Data input(Ctrl+Z to exit) : ^Z
입력된 문자의 수 : 5
```
```
<문제4-2 실행의 예>
Data input(Ctrl+Z to exit) : 10
Data input(Ctrl+Z to exit) : 20
Data input(Ctrl+Z to exit) : ^Z
총 합 : 30
```
```
<문제4-1>
#include <stdio.h>

int main(void)
{
    int total = 0;
    char input;

    while(1)
    {
        fputs("Data input(Ctrl+Z to exit) : ", stdout);
        input = getchar();
        if (input == EOF){
            break;
        }
        fflush(stdin);
        total++;
    }
    printf("입력된 문자의 수 : %d \n", total);
    return 0;
}
```
```
<문제4-2>
#include <stdio.h>

int main(void)
{
    int total = 0;
    int input;

    while(1)
    {
        fputs("Data input(Ctrl+Z to exit) : ", stdout);

        if (scanf("%d", &input) == EOF){
            break;
        }
        total += input;
    }
    printf("총 합 : %d \n", total);
    return 0;
}
```