#define _CRT_SECURE_NO_WARNINGS /*rule 22.01*/
#define STRINGIFY(text, text2) # text##text2  /*rule 20.10: # �����ڰ� ����, rule 20.11: ��ó�� ������ #��  �ǿ����� �ٷ� �ڿ� ##�� ����� */ 
#define texta ����
#define textb �ϼ̽��ϴ�.
#define textMerge STRINGIFY(texta, textb)
#define MY_NULL_1 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void printgrade(grade) {
    printf("rule 05.01 ����: grade���� %d�Դϴ�. \n", grade);
}

void printCountdown1(int arr[/*static*/ 10]);/*rule 17.06 gcc ������ �� ���� ����*/
void printCountdown(int arr[5]) {
    {
#if 10 /*rule 20.08: #if ���� ǥ������ 0�Ǵ� 1�� �򰡵��� ����*/
#endif
        //int printCountdown1[/*error*/ ]; /*rule 18.08*/
        int arr1[3] = { 1,2,3, }; /*rule 17.05: �迭�� ����ũ��� ����� �迭 ũ�Ⱑ �ٸ�*/
        int arr2[4] = { 0,1,2,3 };
        printCountdown(arr1);
    }
}

void startGame(bool helloNo) { /*rule 17.08: �Լ� �Ű������� ������*/

    if (helloNo = true) {
        switch (helloNo) {/*rule 16.07: switch���� ���ǽĿ� Boolean Ÿ���� ����ϸ� �ȵ�*/
            int bad1601; /*rule 16.01: switch�� �ȿ� case, default�̿��� ���� �����ϸ� �ȵ�*/
        case true: {
            printf("%s\n", STRINGIFY(��Ģ���������, " �����մϴ�."));
        case false: { /*rule 16.02: switch label�� �����ϴ� ���� ����� ������ switch���� �ƴ�*/
            switch (0) { /*rule 16.06: switch���� �� �� �̻��� ���� ������ ����*/
                //default: { /*rule 16.04: switch���� default���� ����*/
            }
            printf("%s", "������ �����ϼ���. ");
        }
                  break;
        }

        }
    }
}

#define AA 0xffff
#define BB( x ) ( x ) + wow ## x /*rule 20.12: �߰����� ��ũ�� ġȯ�� �ʿ��� ���ڰ� #�Ǵ� ##�� �ǿ����ڷ� ���Ǿ���*/


void fwowAA(void)
{
    int wowAA = 200000;
    wowAA = BB(AA);
    printf("�����Լ��� ������ ����ǰ� ���� ����: %d\n", wowAA);
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int bsearchError(void) {
    int array[] = { 1, 2, 3, 4, 5 };
    int key = 3;
    int* item;

    item = (int*)bsearch(&key, array, 5, sizeof(int), compare); /*rule 21.09: bsearch�� ����� ������ �Լ���*/
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