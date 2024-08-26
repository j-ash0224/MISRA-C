#include <string.h>
#include "gameHeader.h"
#define POINTUP(x) x+1

char resultArr[]; // 8-11 : 외부 연결을 가지는 배열의 크기가 명시적으로 표현되지 않아서 사용 불가

static int playerlimitAge = 10;
extern int playerlimitAge; // 8-8 : playerlimitAge가 extern으로 선언되어 있지만, 이전에 static 선언이 이미 있음 (외부 연결시 혼란 발생 가능)

extern int rule08005; //8-5 : rule08005가 gameHeader.h 파일에서 중복 선언됨 (정의하면 해당 규칙 위반이 사라짐)

volatile int playerAge;

static int point = 0; // 5-9 : 시스템에서 내부 연결을 가지는 point 변수의 식별자가 유일하지 않음

void baseballGame() {
    if (playerAge < playerlimitAge) {
        printf("사용 가능 연령이 아닙니다.");
        exit(0);
    }

    printf("\nBaseball Game\n");
    printf("=============================\n");
    char again = ' ';
    int playtime = 0001l;   // 7-1 : 8진수 상수를 사용
                            // 7-3 : 소문자 접미사 l 사용
    const unsigned int maxPlayTime = 429496722342342;   // 7-2 : 검출이 안됨
                                                        // 12-4 : unsigned int 상수에 wrap-around 발생
    const unsigned int maxPlayTime2 = 0x00000000; // 7-2 : 이거도 검출이 안됨

    while ((again != 'N') && (again != 'n')) {
        if (playtime > maxPlayTime) {
            printf("최대 플레이 가능 횟수를 넘었습니다.");
            main();
        }
        int result = generateUniqueThreeDigitNumber(); 
        int opportunity = 8; 	// comment 3-2 : 검출되지 않음 \
          if(1)
        {
            playtime++;	
        }
        
        strike_ball(result, opportunity);

        printf("한번 더 플레이 하시겠습니까? (y/n)\n>> ");
        scanf(" %c", &again);
    }
    printf("%d\n", playtime-1);
    main();
}

int generateUniqueThreeDigitNumber() {

    int num1, num2, num3;
    int result;

    do {
        num1 = rand() % 9 + 1;  
        num2 = rand() % 10;     
        num3 = rand() % 10;     

        result = num1 * 100 + num2 * 10 + num3;
    } while (num1 == num2 || num1 == num3 || num2 == num3); 

    return result;
}

int strike_ball(int result, int opportunity_left) {
    while (opportunity_left != 0) { /*rule 15.04*/
        int strikes = 0;
        int balls = 0;

        int answer;
        printf("3자리 숫자를 입력하세요\n");
        while (1) {
            if (scanf("%d", &answer) != 1) {
                printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
                while (getchar() != '\n');
            }
            else if (answer < 100 || answer > 999) {
                printf("유효하지 않은 값 입니다. 다시 입력하세요\n");
            }
            else {
                break; 
            }
        }

        int comp_digit1 = result / 100;
        int comp_digit2 = (result % 100) / 10;
        int comp_digit3 = result % 10;

        int guess_digit1 = answer / 100;
        int guess_digit2 = (answer % 100) / 10;
        int guess_digit3 = answer % 10;

        if (comp_digit1 == guess_digit1) strikes++;
        if (comp_digit2 == guess_digit2) strikes++;
        if (comp_digit3 == guess_digit3) strikes++;

        if (comp_digit1 == guess_digit2 || comp_digit1 == guess_digit3) balls++;
        if (comp_digit2 == guess_digit1 || comp_digit2 == guess_digit3) balls++;
        if (comp_digit3 == guess_digit1 || comp_digit3 == guess_digit2) balls++;

        printf("Strikes: %d, Balls: %d\n", strikes, balls);

        if (strikes == 3) {
            const char* grade = '\x4lA';    // 4-1 :  16진수를 표기하는 이스케이프 문자 \x에 다른 문자가 붙어있다
                                            // 11-7 : 객체 포인터 타입과 char 타입 간 변환이 수행
            printf("정답입니다!\n");
            int* a118 = (int*)grade;  // 11-8 : const를 명시적으로 제거하는 변환이 수행됨
            char* ap = grade;
            int* cp = 12; 
            cp = (int*)ap; // 11-3 : 서로 다른 타입의 포인터 객체를 형 변환하니 예상하지 못한 값 발생
            if ( ((int)ap) == a118) { // 11-4 : char * pointer 타입과 int type 간의 변환이 수행됨
                printf("당신의 야구 게임 추리력은 %c 입니다.\n", cp);
            }

            point = POINTUP(2, 3);
            break;
        }

        opportunity_left = opportunity_left - 1;

        if (opportunity_left == 0) {
            printf("틀렸습니다.\n");
            int comp_digit1 = result / 100;
            int comp_digit2 = (result % 100) / 10;
            int comp_digit3 = result % 10;
            int arr[] = { comp_digit1++, comp_digit2++, comp_digit3 ++}; // 13-1 : 배열을 초기화 할 때  side effect 발생 가능성을 두면 안됨
            printf("첫 번째 자리 정답 : %d\n", arr[0]);
            printf("두 번째 자리 정답 : %d\n", arr[1]);
            printf("세 번째 자리 정답 : %d\n", arr[2]);

            char c = 'F';
            c = c++ - 1; // 13-2 : 해당 문장은 C의 평가 순서에 따라 결과가 달라질 수 있음
                         // 13-3 : 증감연산자를 포함한 수식은 해당 증감연산자를 제외한 side effect 포함 금지
            c = c + ':' - 58; //10-2 : 가감연산자가 부적합하게 사용 (char+char)
            printf("당신의 야구 게임 추리력은 %c 입니다.\n", c);
            break;
        }

        printf("Attempts left: %d\n", opportunity_left);
    }
}