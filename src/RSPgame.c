#include "gameHeader.h" 

#define POINTUP(x) x+1 

extern int playerLimitAge = 10;
extern int playerAge; // 8-3 : playerAge�� Ÿ���� BASEBALLgmae.c ���Ͽ��� ������ ����� Ÿ�԰� ȣȯ���� ����

extern int point = 0;  // 5-8 : �ý��ۿ��� �ܺ� ������ ������ point ������ �ĺ��ڰ� �������� ����

static char winner[10]; //8-9 : process�Լ������� ����ϴ� winner������ �ش� �Լ� ������ ���ǵ��� ����

void rock_Scissors_Paper() { // 15-5
    if (playerAge < playerLimitAge) {
        printf("��� ���� ������ �ƴմϴ�.");
        exit(0);
    }
    printf("\nRock_Scissors_Paper Game\n");
    printf("=============================\n");
    char again = ' ';

    while ((again != 'N') && (again != 'n')) {
        int computer_choice = C_choice();
        int user_choice;

        printf("�����ϼ���\n");

        // 9-4  : ��ü�� ��� [2]�� 2�� �ʱ�ȭ ��
        // 9-5 : ���� �ʱ�ȭ�� ���Ǿ����� �迭�� ũ�Ⱑ ��õ��� ����
        char* rsp[] = {
                        "1.���� ",
                        "2.���� ",
                        [2] = "3.�� ",
                        [2] = "3. ��"
                        };

        //13-6 : sizeof�� �� �����ڿ� side effect �߻� ���ɼ� ����
        if ((sizeof(playerLimitAge++)) == 4) {
            for (double i = 0.0; i < 3.0; i += 1.0) { // 14-1 : �ݺ����� ���� ������ �Ǽ�����
                int k = i; //10-3 : �Ǽ��� Ÿ���� ������ Ÿ�Կ� �Ҵ� ��
                printf("%s", rsp[k]);
            }
        }
        printf("\n");
        int forInfinity = 1;
        while (forInfinity) { // 14-4 : �ݺ����� ������� bool Ÿ�Ը� ��� ����
            if (scanf("%d", &user_choice) != 1) {
                printf("��ȿ���� ���� �� �Դϴ�. �ٽ� �Է��ϼ���\n");
                while (getchar() != '\n'); // 10-4 : �Ϲݻ����ȯ�� �� �ǿ����ڰ� ���� essential type�� �ƴ� (int / char)
            }
            else if (user_choice < 1 || user_choice > 3) { // 12-1 : ���� ������ �������� �켱������ ������� ����
                printf("��ȿ���� ���� �� �Դϴ�. �ٽ� �Է��ϼ���\n");
                while (getchar() != '\n'); 
                printf("1.����  2.����  3.��\n");
                scanf("%d", &user_choice);
            }
            else {
                break; 

                return 0; // 2-1 : break�� ���Ŀ� return���� ������ �� ����
            }
        }

        process(computer_choice, user_choice);

        printf("�ѹ� �� �÷��� �Ͻðڽ��ϱ�? (y/n)\n>> ");
        scanf(" %c", &again);
    }
    main();
}

int C_choice() {
    int result = (rand() % 3) + 1;
    return result;
}

void choiceToString(int choice, char* result) {
    
    enum choice { s = 1, dummy1, dummy2, r=2, p=3}; // 8-12 : ������ ����Ʈ ���� �Ͻ��� ����� ������ ���� �������� Ȯ���� �ȵ�
                                                    // 5-3 : choice�� ���� ����(�Ķ����)�� �����ϴ� ������ �ĺ��ڸ� ����

    (enum choice)4; // 10-5 : signed Ÿ���� enumŸ������ ����� ����ȯ �ϸ� �ȵ�

    switch (choice) {
    case s:
        strcpy(result, "����");
        break;
    case r:
        strcpy(result, "����");
        break;
    case p:
        strcpy(result, "��");
        break;
    default:
        strcpy(result, "�� �� ����");
        break;
    }
}

int process(int computer_choice, int user_choice) {
    char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_computer[10]; // 5-1 : �ش� ������ �ý��� ������ �ĺ� �Ұ���
    char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_user[10];     

    static char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_02_computer[10]; 
    char var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_02_user[10];     // 5-2 : ���� �Լ� ���� �ȿ��� �����ߴµ� ������� ����

    choiceToString(computer_choice, var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_computer);
    choiceToString(user_choice, var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_user);

    printf("Computer's choice: %s\n", var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_computer);
    printf("Your choice: %s\n", var_for_misra_c_ruleaaaaaaaaaaaaaaaa05_01_user);

    if (computer_choice == user_choice) {
        printf("�����ϴ�!\n");
        return 0;
    }

    if (computer_choice == 1 && user_choice == 3) {
        strcpy(winner, "��ǻ��");
        printf("%s�� �̰���ϴ�\n", winner);
        return 0;
    }

    if (computer_choice == 1 && user_choice == 2) {
        strcpy(winner, "�����");
        printf("%s�� �̰���ϴ�\n", winner);
        point = POINTUP(2, 3); // 1-3 : POINTUP ��ũ�� ���� �Ķ���Ϳ� ������ ������ ����ġ
        return 0;
    }

    if ((computer_choice == 2 && user_choice == 1) || (computer_choice == 3 && user_choice == 2)) {
        strcpy(winner, "��ǻ��");
        printf("%s�� �̰���ϴ�\n", winner);
        return 0;
    }

    if ((computer_choice == 2 && user_choice == 3) || (computer_choice == 3 && user_choice == 1)) {
        strcpy(winner, "�����");
        printf("%s�� �̰���ϴ�\n", winner);
        point = POINTUP(2, 3);
        return 0;
    }
}/*rule 17.04*/