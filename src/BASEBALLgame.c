#include <string.h>
#include "gameHeader.h"
#define POINTUP(x) x+1

char resultArr[]; // 8-11 : �ܺ� ������ ������ �迭�� ũ�Ⱑ ��������� ǥ������ �ʾƼ� ��� �Ұ�

static int playerlimitAge = 10;
extern int playerlimitAge; // 8-8 : playerlimitAge�� extern���� ����Ǿ� ������, ������ static ������ �̹� ���� (�ܺ� ����� ȥ�� �߻� ����)

extern int rule08005; //8-5 : rule08005�� gameHeader.h ���Ͽ��� �ߺ� ����� (�����ϸ� �ش� ��Ģ ������ �����)

volatile int playerAge;

static int point = 0; // 5-9 : �ý��ۿ��� ���� ������ ������ point ������ �ĺ��ڰ� �������� ����

void baseballGame() {
    if (playerAge < playerlimitAge) {
        printf("��� ���� ������ �ƴմϴ�.");
        exit(0);
    }

    printf("\nBaseball Game\n");
    printf("=============================\n");
    char again = ' ';
    int playtime = 0001l;   // 7-1 : 8���� ����� ���
                            // 7-3 : �ҹ��� ���̻� l ���
    const unsigned int maxPlayTime = 429496722342342;   // 7-2 : ������ �ȵ�
                                                        // 12-4 : unsigned int ����� wrap-around �߻�
    const unsigned int maxPlayTime2 = 0x00000000; // 7-2 : �̰ŵ� ������ �ȵ�

    while ((again != 'N') && (again != 'n')) {
        if (playtime > maxPlayTime) {
            printf("�ִ� �÷��� ���� Ƚ���� �Ѿ����ϴ�.");
            main();
        }
        int result = generateUniqueThreeDigitNumber(); 
        int opportunity = 8; 	// comment 3-2 : ������� ���� \
          if(1)
        {
            playtime++;	
        }
        
        strike_ball(result, opportunity);

        printf("�ѹ� �� �÷��� �Ͻðڽ��ϱ�? (y/n)\n>> ");
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
        printf("3�ڸ� ���ڸ� �Է��ϼ���\n");
        while (1) {
            if (scanf("%d", &answer) != 1) {
                printf("��ȿ���� ���� �� �Դϴ�. �ٽ� �Է��ϼ���\n");
                while (getchar() != '\n');
            }
            else if (answer < 100 || answer > 999) {
                printf("��ȿ���� ���� �� �Դϴ�. �ٽ� �Է��ϼ���\n");
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
            const char* grade = '\x4lA';    // 4-1 :  16������ ǥ���ϴ� �̽������� ���� \x�� �ٸ� ���ڰ� �پ��ִ�
                                            // 11-7 : ��ü ������ Ÿ�԰� char Ÿ�� �� ��ȯ�� ����
            printf("�����Դϴ�!\n");
            int* a118 = (int*)grade;  // 11-8 : const�� ��������� �����ϴ� ��ȯ�� �����
            char* ap = grade;
            int* cp = 12; 
            cp = (int*)ap; // 11-3 : ���� �ٸ� Ÿ���� ������ ��ü�� �� ��ȯ�ϴ� �������� ���� �� �߻�
            if ( ((int)ap) == a118) { // 11-4 : char * pointer Ÿ�԰� int type ���� ��ȯ�� �����
                printf("����� �߱� ���� �߸����� %c �Դϴ�.\n", cp);
            }

            point = POINTUP(2, 3);
            break;
        }

        opportunity_left = opportunity_left - 1;

        if (opportunity_left == 0) {
            printf("Ʋ�Ƚ��ϴ�.\n");
            int comp_digit1 = result / 100;
            int comp_digit2 = (result % 100) / 10;
            int comp_digit3 = result % 10;
            int arr[] = { comp_digit1++, comp_digit2++, comp_digit3 ++}; // 13-1 : �迭�� �ʱ�ȭ �� ��  side effect �߻� ���ɼ��� �θ� �ȵ�
            printf("ù ��° �ڸ� ���� : %d\n", arr[0]);
            printf("�� ��° �ڸ� ���� : %d\n", arr[1]);
            printf("�� ��° �ڸ� ���� : %d\n", arr[2]);

            char c = 'F';
            c = c++ - 1; // 13-2 : �ش� ������ C�� �� ������ ���� ����� �޶��� �� ����
                         // 13-3 : ���������ڸ� ������ ������ �ش� ���������ڸ� ������ side effect ���� ����
            c = c + ':' - 58; //10-2 : ���������ڰ� �������ϰ� ��� (char+char)
            printf("����� �߱� ���� �߸����� %c �Դϴ�.\n", c);
            break;
        }

        printf("Attempts left: %d\n", opportunity_left);
    }
}