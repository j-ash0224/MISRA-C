#define _CRT_SECURE_NO_WARNINGS /*rule 22.01*/
#define STRINGIFY(text, text2) # text##text2  /*rule 20.10: # 연산자가 사용됨, rule 20.11: 전처리 연산자 #의  피연산자 바로 뒤에 ##을 사용함 */ 
#define texta 실패
#define textb 하셨습니다.
#define textMerge STRINGIFY(texta, textb)
#define MY_NULL_1 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void printgrade(grade) {
    printf("rule 05.01 오류: grade값은 %d입니다. \n", grade);
}

void printCountdown1(int arr[/*static*/ 10]);/*rule 17.06 gcc 컴파일 시 검출 가능*/
void printCountdown(int arr[5]) {
    {
#if 10 /*rule 20.08: #if 제어 표현식이 0또는 1로 평가되지 않음*/
#endif
        //int printCountdown1[/*error*/ ]; /*rule 18.08*/
        int arr1[3] = { 1,2,3, }; /*rule 17.05: 배열의 선언크기와 사용한 배열 크기가 다름*/
        int arr2[4] = { 0,1,2,3 };
        printCountdown(arr1);
    }
}

void startGame(bool helloNo) { /*rule 17.08: 함수 매개변수를 변경함*/

    if (helloNo = true) {
        switch (helloNo) {/*rule 16.07: switch문의 조건식에 Boolean 타입을 사용하면 안됨*/
            int bad1601; /*rule 16.01: switch문 안에 case, default이외의 절이 존재하면 안됨*/
        case true: {
            printf("%s\n", STRINGIFY(사칙연산게임을, " 시작합니다."));
        case false: { /*rule 16.02: switch label을 포함하는 가장 가까운 문장이 switch문이 아님*/
            switch (0) { /*rule 16.06: switch문이 두 개 이상의 절을 가지지 않음*/
                //default: { /*rule 16.04: switch문에 default절이 없음*/
            }
            printf("%s", "레벨을 선택하세요. ");
        }
                  break;
        }

        }
    }
}

#define AA 0xffff
#define BB( x ) ( x ) + wow ## x /*rule 20.12: 추가적인 매크로 치환이 필요한 인자가 #또는 ##의 피연산자로 사용되었음*/


void fwowAA(void)
{
    int wowAA = 200000;
    wowAA = BB(AA);
    printf("깡통함수라도 오류에 검출되고 싶은 정도: %d\n", wowAA);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int bsearchError(void) {
    int array[] = { 1, 2, 3, 4, 5 };
    int key = 3;
    int* item;

    item = (int*)bsearch(&key, array, 5, sizeof(int), compare); /*rule 21.09: bsearch는 사용이 금지된 함수임*/
    if (item != NULL) {
        printf("Found: %d\n", *item);
    }
    else {
        printf("Not Found\n");
    }
    return 0;
}

int main_e() {

    return 0;
}