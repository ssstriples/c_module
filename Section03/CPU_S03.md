# C Power Upgrade
# Part1. 기본실력 점검 및 향상
## Section3. 조건문과 반복문
---
### 9. if~else, while, for, break문에 대한 연습
```
<문제9-1>
정수 n을 입력 받는다. 그리고 1부터 입력 받은 정수 n까지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성하자.
예를 들어서 정수 5를 입력 받으면, 1 + 2 + 3 + 4 + 5 의 연산 결과인 15를 출력해야 한다.

<문제9-2>
정수 n1과 n2를 입력 받는다. 그리고 n1부터 n2까지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성한다.
예를 들어 2와 5가 입력되면 2 + 3 + 4 + 5 의 연산 결과를 출력해야 한다.
```
```
<세부 요구사항>
- 만약에 n이 0보다 작다면 1이상의 값이 일력될 때까지 재 입력을 요구해서 1이상의 값을 받을 수 있도록 예제를 작성하자.
- 5와 2가 입력되어도 동일한 결과를 보여줄 수 있도록 예제를 작성하자. 즉 입력 받을 두 숫자의 순서는 아무 상관이 없도록 예제를 작성해야 한다.
```
```
<문제9-1 실행의 예>
1 이상의 정수 입력 : -10
1 이상의 정수를 입력해야 합니다.
1 이상의 정수 입력 : 10
1부터 10까지의 합은 55.
```
```
<문제9-2 실행의 예>
두 개의 정수 입력 : 12 7
12과 7을 포함하여 그 사이에 있는 정수들의 합 : 57
```
```
<문제9-1>
#include <stdio.h>

int main(void)
{
    int num, i;
    int total = 0;

    while(1)
    {
        fputs("1 이상의 정수 입력 : ", stdout);
        scanf("%d", &num);
        
        if (num > 0)
            break;
        else
            puts("1 이상의 정수를 입력해야 합니다.");
    }
    
    for (i = 1; i <= num; i++)
        total += i;

    printf("1부터 %d까지의 합은 %d. \n", num, total);

    return 0;
}
```
```
<문제9-2>
#include <stdio.h>

int main(void)
{
    int num1, num2, i;
    int total = 0;

    int start, end;

    fputs("두 개의 정수 입력 : ", stdout);
    scanf("%d %d", &num1, &num2);

    if (num1 > num2)
    {
        start = num2;
        end = num1;
    }
    else{
        start = num1;
        end = num2;
    }

    for (i = start; i <= end; i++)
        total += i;

    printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합 :  %d \n",\ 
        num1, num2, total);

    return 0;
}
```
---
### 10. continue문에 대한 연습
```
<문제>
정수 n1과 n2를 입력 받는다. 그리고 n1부터 n2까지의 합을 계산해서 그 결과를 출력하되, 3의 배수이거나 5의 배수이면 총 합에서 제외시키는 프로그램을 작성하자.
```
```
<세부 요구사항>
- continue문을 활용하자.
- 제외된 수들의 정보를 출력하도록 구현하자.
```
```
<실행의 예>
두 개의 정수 입력 : 2 10
3는 합에서 제외.
5는 합에서 제외.
6는 합에서 제외.
9는 합에서 제외.
10는 합에서 제외.
2과 10을 포함하여 그 사이에 있는 정수들의 합 : 21
```
```
#include <stdio.h>

int main(void)
{
    int num1, num2, i;
    int total = 0;

    int start, end;

    fputs("두 개의 정수 입력 : ", stdout);
    scanf("%d %d", &num1, &num2);

    if (num1 > num2)
    {
        start = num2;
        end = num1;
    }
    else{
        start = num1;
        end = num2;
    }

    for (i = start; i <= end; i++)
    {
        if ( !(i % 3) || !(i % 5) )
        {
            printf("%d는 합에서 제외.\n", i);
            continue;
        }
        total += i;
    }
    printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합 : %d \n",\ 
        num1, num2, total);

    return 0;
}
```
---
### 11. 추가 문제들
```
<문제11-1>
입력 받은 정수 n 이하의 자연수 중에서 짝수의 합과, 홀수의 합을 각각 계산하여 출력하는 프로그램을 구현하자.
참고로 자연수라 함은 0보다 큰 정수를 의미한다.

<문제11-2>
정수 n을 입력 받는다(단 n은 2 이상이 입력되어야 한다). 그리고 1부터 시작해서 다음과 같은 형태로 점진적인 덧셈을 진행한다.
1 + 2 + 3 + 4 + 5 + 6 + ......
이 때 얼마를 더하는 순간부터 덧셈의 결과가 n보다 커지기 시작하는지, 그리고 n보다 커지기 전과 n보다 커진 후의 덧셈 결과를 출력하는 프로그램을 구현하자.
```
```
<문제11-1 실행의 예>
자연수 입력 : 12
12 이하 홀수 합 : 36
12 이하 짝수 합 : 42
```
```
<문제11-2 실행의 예>
2 이상 입력 : 20
6를 더할 때 처음 20를 넘기 시작한다.
20를 넘기 이전의 합 : 15
20를 넘은 이후의 합 : 21
```
```
<문제11-1>
#include <stdio.h>

int main(void)
{
    int num, i;
    int oddTotal = 0;
    int evenTotal = 0;

    while(1)
    {    
        fputs("자연수 입력 : ", stdout);
        scanf("%d", &num);
        
        if (num > 0)
            break;
        else
            puts("자연수가 아닙니다. 다시 입력!");
    }

    for (i = 1; i <= num; i++)
    {
        if ( i % 2 == 0 )
            evenTotal += i;
        else
            oddTotal += i;
    }

    printf("%d 이하 홀수 합 : %d \n", num, oddTotal);
    printf("%d 이하 짝수 합 : %d \n", num, evenTotal);

    return 0;
}
```
```
<문제11-2>
#include <stdio.h>

int main(void)
{
    int num, i;
    int total = 0;

    while(1)
    {    
        fputs("2 이상 입력 : ", stdout);
        scanf("%d", &num);
        
        if (num > 1)
            break;
        else
            puts("2 이상이 아닙니다. 다시 입력!");
    }

    i = 1;
    while( num >= (total + i))
    {
        total += i;
        i++;
    }
    
    printf("%d를 더할 때 처음 %d를 넘기 시작한다. \n", i, num);
    printf("%d를 넘기 이전의 합 : %d \n", num, total);
    printf("%d를 넘은 이후의 합 : %d \n", num, total + i);

    return 0;
}
```