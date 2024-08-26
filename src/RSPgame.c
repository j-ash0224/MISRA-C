#include "gameHeader.h" 

#define POINTUP(x) x+1 

extern int playerLimitAge = 10;
extern int playerAge; // 8-3 : playerAge의 타입이 BASEBALLgmae.c 파일에서 이전에 선언된 타입과 호환되지 않음

extern int point = 0;  // 5-8 : 시스템에서 외부 연결을 가지는 point 변수의 식별자가 유일하지 않음

static char winner[10]; //8-9 : process함수에서만 사용하는 winner변수가 해당 함수 영역에 정의되지 않음

void rock_Scissors_Paper() { // 15-5
    if (playerAge < playerLimitAge) {
        printf("사용 가능 연령이 아닙니다.");
        exit(0);
    }
    printf("\nRock_Scissors_Paper Game\n");
    printf("=============================\n");
    char again = ' ';

    while ((again != 'N') && (again != 'n')) {
        int computer_choice = C_choice();
        int user_choice;

        printf("선택하세요\n");

        // 9-4  : 객체의 요소 [2]가 2번 초기화 됨
        // 9-5 : 지정 초기화가 사용되었지만 배열의 크기가 명시되지 않음
        char* rsp[] = {
                        "1.가위 ",
                        "2.바위 ",
                        [2] = "3.보 ",
                        [2] = "3. 보"
                        };

        //13-6 : sizeof의 피 연산자에 side effect 발생 가능성 존재
        if ((sizeof(playerLimitAge++)) == 4) {
            for (double i = 0.0; i < 3.0; i += 1.0) { // 14-1 : 반복문에 사용된 변수가 실수형임
                int k = i; //10-3 : 실수형 타입이 정수형 타입에 할당 됨
                printf("%s", rsp[k]);
            }
        }
        printf("\n");
        int forInfinity = 1;
        while (forInfinity) { // 14-4 : 반복문에 제어식은 bool 타입만 사용 가능
            if (scanf("%d", &user_choice) != 1) {
                printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
                while (getchar() != '\n'); // 10-4 : 일반산술변환의 두 피연산자가 같은 essential type이 아님 (int / char)
            }
            else if (user_choice < 1 || user_choice > 3) { // 12-1 : 수식 내부의 연산자의 우선순위를 명시하지 않음
                printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
                while (getchar() != '\n'); 
                printf("1.가위  2.바위  3.보\n");
                scanf("%d", &user_choice);
            }
            else {
                break; 

                return 0; // 2-1 : break문 이후에 return문에 도달할 수 없음
            }
        }

        process(computer_choice, user_choice);

        printf("한번 더 플레이 하시겠습니까? (y/n)\n>> ");
        scanf(" %c", &again);
    }
    main();
}

int C_choice() {
    int result = (rand() % 3) + 1;
    return result;
}

void choiceToString(int choice, char* result) {
    
    enum choice { s = 1, dummy1, dummy2, r=2, p=3}; // 8-12 : 열거자 리스트 내에 암시적 상수가 유일한 값을 가지는지 확인이 안됨
                                                    // 5-3 : choice는 상위 영역(파라미터)에 존재하는 동일한 식별자를 가림

    (enum choice)4; // 10-5 : signed 타입을 enum타입으로 명시적 형변환 하면 안됨

    switch (choice) {
    case s:
        strcpy(result, "가위");
        break;
    case r:
        strcpy(result, "바위");
        break;
    case p:
        strcpy(result, "보");
        break;
    default:
        strcpy(result, "알 수 없음");
        break;
    }
}

int process(int computer_choice, int user_choice) {
    char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_computer[10]; // 5-1 : 해당 변수가 시스템 내에서 식별 불가능
    char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_user[10];     

    static char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_02_computer[10]; 
    char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_02_user[10];     // 5-2 : 같은 함수 영역 안에서 선언했는데 검출되지 않음

    choiceToString(computer_choice, var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_computer);
    choiceToString(user_choice, var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_user);

    printf("Computer's choice: %s\n", var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_computer);
    printf("Your choice: %s\n", var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_user);

    if (computer_choice == user_choice) {
        printf("비겼습니다!\n");
        return 0;
    }

    if (computer_choice == 1 && user_choice == 3) {
        strcpy(winner, "컴퓨터");
        printf("%s가 이겼습니다\n", winner);
        return 0;
    }

    if (computer_choice == 1 && user_choice == 2) {
        strcpy(winner, "사용자");
        printf("%s가 이겼습니다\n", winner);
        point = POINTUP(2, 3); // 1-3 : POINTUP 매크로 사용시 파라미터와 인자의 개수가 불일치
        return 0;
    }

    if ((computer_choice == 2 && user_choice == 1) || (computer_choice == 3 && user_choice == 2)) {
        strcpy(winner, "컴퓨터");
        printf("%s가 이겼습니다\n", winner);
        return 0;
    }

    if ((computer_choice == 2 && user_choice == 3) || (computer_choice == 3 && user_choice == 1)) {
        strcpy(winner, "사용자");
        printf("%s가 이겼습니다\n", winner);
        point = POINTUP(2, 3);
        return 0;
    }
}/*rule 17.04*/