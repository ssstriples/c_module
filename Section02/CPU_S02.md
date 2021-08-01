# C Power Upgrade
# Part1. 기본실력 점검 및 향상
## Section2. 연산자
---
### 5. 기본 사칙 연산자 활용
```
<문제5-1>
실수(정수가 아닌 실수이다) 두 개를 입력 받아서, 두 실수의 사칙연산 결과를 출력하는 프로그램을 작성하여라.

<문제5-2>
원의 반지름 정보를 입력 받아서, 원의 넓이를 계산해서 출력하는 프로그램을 작성하여라. 단 원의 넓이를 계산하는 공식은 다음과 같다.
        원의 넓이 공식 : 반지름 X 반지름 X 3.14

```
```
<문제5-1 실행의 예>
두 개의 실수 입력 : 3.7 2.5
덧셈 결과 : 6.200000
뺄셈 결과 : 1.200000
곱셈 결과 : 9.250000
나눗셈 결과 : 1.480000
```
```
<문제5-2 실행의 예>
반지름 입력 : 2.5
원의 넓이 : 19.625000
```
```
<문제5-1>
#include <stdio.h>

int main(void)
{
    double n1;
    double n2;

    fputs("두 개의 실수 입력 : ", stdout);
    scanf("%lf %lf", &n1, &n2);

    printf("덧셈 결과 : %f \n", n1 + n2);
    printf("뺄셈 결과 : %f \n", n1 - n2);
    printf("곱셈 결과 : %f \n", n1 * n2);
    printf("나눗셈 결과 : %f \n", n1 / n2);
    return 0;
}
```
```
<문제5-2>
#include <stdio.h>
#define PI 3.14

int main(void)
{
    double rad;

    fputs("반지름 입력 : ", stdout);
    scanf("%lf", &rad);

    printf("원의 넓이 : %f \n", rad*rad*PI);
    return 0;
}
```
---
### 6. 명시적 형 변환, 묵시적인 형 변환
```
<문제>
7개의 숫자를 정수 형태로(반드시 정수 형태로 입력 받는다) 입력 받아서 입력 받은 수들의 최대값, 최소값, 전체 합, 그리고 평균을 구하는 프로그램을 작성한다. 단 평균은 정확히 계산하여 소수점 이하까지 출력한다.
```
```
<세부 요구사항>
- 키보드로부터 입력되는 7개의 정수를 저장하지 않기로 하자. 7개의 변수를 선언하거나, 배열을 선언해서 입력되는 모든 값을 저장한 이후에 최대값, 최소값, 전체 합 그리고 평균을 구하지 말자는 뜻이다. 이 요구사항은 문제의 난이도를 높이기 위해서 제시한 것이니 반드시 지키기 바란다. 가급적이면 최소한의 변수를 선언해서 문제를 해결하도록 노력하자.
- 7개의 데이터를 입력 받기 위해서 for문을 활용한다.
```
```
<실행의 예>
정수형 데이터 입력 : 3
정수형 데이터 입력 : 4
정수형 데이터 입력 : 2
정수형 데이터 입력 : 3
정수형 데이터 입력 : 5
정수형 데이터 입력 : 7
정수형 데이터 입력 : -12
최대값 : 7
최소값 : -12
전체합 : 12
평 균 : 1.714286
```
```
#include <stdio.h>
#define DATA_CNT 7

int main(void)
{
    int num;
    int total = 0;
    int max = 0, min = 0;

    /** 초기 입력 **/
    fputs("정수형 데이터 입력 : ", stdout);
    scanf("%d", &num);
    min = num;
    max = num;
    total += num;

    /** 두 번째 이후 입력 **/
    for(int i = 0; i < DATA_CNT - 1; i++)
    {
        fputs("정수형 데이터 입력 : ", stdout);
        scanf("%d", &num);
        
        if(num > max)
            max = num;

        if(num < min)
            min = num;

        total += num;
    }
    printf("최대값 : %d \n", max);
    printf("최소값 : %d \n", min);
    printf("전체합 : %d \n", total);
    printf("평 균 : %f \n", (double)total/DATA_CNT);

    return 0;
}
```
---
### 7. 조건 연산자(삼 항 연산자) 활용
```
<문제7-1>
두 개의 숫자를 입력 받아서 그 중 큰 수를 출력하는 프로그램을 구현하여라. 단, if 관련 문장을 사용해야 한다면 이를 대신해서 조건 연산자를 사용하기로 하자.

<문제7-2>
세 개의 숫자를 입력 받아서 그 중 가장 큰 수를 출력하는 프로그램을 구현하여라. 이번에도 마찬가지로 if 관련 문장을 대신하여 조건 연산자를 사용해야 한다.
```
```
<세부 요구사항>
- if 관련 문장을 사용하지 않고 조건 연산자(삼 항 연산자)를 사용해서 위 두 문제를 해결해야한다.
- 특히 문제7-2의 경우는 조건 연산자를 중첩시켜서 해결하자. 조건 연산자를 중첩시킨다는 의미는 조건 연산자 안에 다시 조건 연산자가 존재하는 상황을 의미한다. 중첩시킨 예제를 찾으려 하지 말자. 문제 7-1을 통해서 조건 연산자의 기본 원리를 이해했다면, 조건 연산자를 어떻게 중첩시킬지 여러분이 고민해서 결론 내리기 바란다.
```
```
<문제7-1 실행의 예>
두 개의 숫자를 입력하세요 : 7 12
큰 수는 12
```
```
<문제7-2 실행의 예>
세 개의 숫자를 입력하세요 : 3 7 12
큰 수는 12
```
```
<문제7-1>
#include <stdio.h>

int main(void)
{
    int num1, num2;
    int bigNumber;

    fputs("두 개의 숫자를 입력하세요 : ", stdout);
    scanf("%d %d", &num1, &num2);

    bigNumber = (num1 > num2) ? num1 : num2;
    printf("큰 수는 %d\n", bigNumber);
    return 0;
}
```
```
<문제7-2>
#include <stdio.h>

int main(void)
{
    int num1, num2, num3;
    int bigNumber;

    fputs("세 개의 숫자를 입력하세요 : ", stdout);
    scanf("%d %d %d", &num1, &num2, &num3);

    bigNumber = (num1 > num2) ? 
                ((num1 > num3) ? num1 : num3) : 
                ((num2 > num3) ? num2 : num3);
    printf("큰 수는 %d\n", bigNumber);
    return 0;
}
```
---
### 8. 나머지 연산자
```
<문제>
정수형 데이터를 10진수로 입력 받아서 해당 데이터의 2진수 표현을 출력하는 프로그램을 구현하자.
```
```
<실행의 예>
10진수 정수 입력 : 12
12를 2진수로 변환하면 : 1100
```
```
#include <stdio.h>
#define ARR_LEN 20

int main(void)
{
    int num;
    int binaryArr[ARR_LEN];
    int binaryCnt = 0;

    fputs("10진수 정수 입력 : ", stdout);
    scanf("%d", &num);

    printf("%d를 2진수로 변환하면 : ", num);
    /* 2진수로 변환하기 위한 나머지 연산 */
    while(num > 0)
    {
        binaryArr[binaryCnt++] = num % 2;
        num /= 2;
    }

    /* 나머지를 거꾸로 출력하여 2진수를 보임 */
    while(binaryCnt > 0)
    {
        printf("%d", binaryArr[binaryCnt - 1]);
        binaryCnt -= 1;
    }
    puts("");
    return 0;
}
```