#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

// 3-1 : 주석 안에서 /* 사용
#define a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_05_04 49 // 5-4 : 해당 매크로가 다른 매크로와 구별 되지 않음
                                                                                    // 5-5 : 해당 매크로가 다른 식별자와 구별 되지 않음

#define a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_05 (char id, char pw) return 0;  // 2-5 : 매크로를 선언하고 사용하지 않음

int a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_04 = 0; // 8-4 : 해당 변수의 정의 이전에 선언이 존재하지 않음

int playerAge;

typedef int point;  // 2-3 : point 타입을 선언하고 사용하지 않음
                    // 5-6 : typedef로 선언한 타입의 이름이 유일하지 않음

struct User
{
    char id[20];
    char pw[20];
    int age;
}; // 5-7 : 구조체의 이름이 유일하지 않음

struct Userinfo
{
    int addressp : 4; // 6-1 : 비트필드의 base 타입은 signed int 혹은 unsigned int 여야 함
    signed int point : 1; // 6-2 : Signed int bit 필드의 size 는 2보다 작음
}; // 2-4 : Userinfo 구조체를 선언하고 사용하지 않음

struct User users[a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_05_04]; // 8-7

// 8-2 : 함수의 파라미터가 없지만 명시적인 void 타입의 파라미터를 설정하지 않음
signUp() {
    if (a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_04 == a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_05_04) {
        printf("더 이상 회원 가입이 불가능합니다. 최대 회원 수를 초과했습니다.\n");
        return;
    }
    
    struct s;
    struct s* sp;
    char *x = 0; // 11-9 : 0 대신 NULL을 씀으로써 null 포인터 상수(유효한 오브젝트나 함수를 가리키지 않음을 표시하는 값)가 사용되었음을 더 명확히 해야함
    x = "회원 가입 페이지"; // 7-4 : char * 타입 변수 x에 문자열을 할당함
    if (1 > 2) { // 14-3 : 항상 거짓의 결과를 수행하는 조건문
        // 14-2 : 두 번째 절에서 표현식은 side effect 가능성이 없어야 함
        for (float i = 0.0; i++ > 10.0f; ++i) {
            printf("잘못 짜여져 반복을 수행하지 않음");
        }
        printf("% c", sp); // 9-1 : 변수 sp 가 할당 되기 전에 읽힘
        label1:	printf("정보를 입력해주세요\n");  // 2-6 : 레이블을 선언하고 사용하지 않음
    }
    sp = (struct s*)x;// 11-2 : 불완전 포인터 타입 s와 포인터 타입간 형 변환
    
    struct User newUser;

    printf("ID: ");
    scanf("%s", newUser.id);

    printf("PassWord: ");
    scanf("%s", newUser.pw);

    printf("Age: ");
    scanf("%d", &newUser.age);

    users[a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_04++] = newUser;

    login(1);
}

struct User* findUserByID(char id[20], char pw[20]) {

    for (int i = 0; i < a0000000000_example_identifier_for_rule_number_aaaaaaaaaaaaaaaa05_05_04; ++i) {
        if ((strcmp(users[i].id, id) == 0) && (strcmp(users[i].pw, pw) == 0)) {
            playerAge = users[i].age;
            return &users[i];
        }
    }
    return NULL; 
}

//8-1 : 함수의 타입을 명시적으로 지정하지 않음
signIn() {
    //관리자 정보를 담는 배열을 선언 (배열 초기화 형식에 어긋나는 예시 - 사용 불가)
    struct User ManagerInfo[5] = { "1111", "1111", 25 }; // 9-2 : ManagerInfo 의 초기화가 {}로 둘러 쌓여있지 않으므로 사용 불가
                                                                 // 9-3 : 배열의 길이는 5 인데 일부분만 초기화 됨

    char id[20], pw[20];

    printf("ID : ");
    scanf("%s", id);

    printf("PW : ");
    scanf("%s", pw);

    struct User* user = findUserByID(id, pw); // 8-13 : 포인터 타입의 변수 user가 const로 선언되지 않음

    if (user != NULL) {
        printf("사용자 로그인 성공\n");
        return;
    }
    else if (strcmp(id, "1111") == 0 && strcmp(pw, "1111") == 0) {
        printf("관리자 로그인 성공\n");
        playerAge = 25;
        return;
    }
    else {
        printf("해당 ID를 가진 회원을 찾을 수 없습니다.\n");
        login(1);
    }
}

int login(int* restrict p1) {   // 2-7 : 파라미터 p1이 함수 안에서 사용되지 않음
                                // 8-14 : 파라미터 p1에 restrict 한정자를 사용

    int choice;
    printf("메뉴를 선택해주세요.\n\n");
    printf("1. 로그인\n");
    printf("2. 회원 가입\n");

    scanf_s("%d", &choice);

    while (1) {
        if (choice < 1 || choice > 2) {
            printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
            scanf_s("%d", &choice);
        }
        else {
            break;
        }
    }

    if (choice == 1) {
        signIn();
    }
    else if (choice == 2) {
        signUp();
    }

    return 0;
}


