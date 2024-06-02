#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2024"       // �w�q���T���K�X
#define MAX_STUDENTS 10       // �̤j�ǥͼƶq
#define MIN_STUDENTS 5        // �̤p�ǥͼƶq

// �w�q���c�H�s�x�ǥͫH��
typedef struct {
    char name[50];           // �ǥͩm�W
    int student_id;          // �ǥ;Ǹ�
    int math;                // �ƾǦ��Z
    int physics;             // ���z���Z
    int english;             // �^�妨�Z
    float average;           // �������Z
} Student;

// ��ƲM���̹��A�̥��x���P
void clear_screen() {
    #ifdef _WIN32
        system("cls");       // Windows �M�̩R�O
    #else
        system("clear");     // Unix �M�̩R�O
    #endif
}

// �������w��e�������ұK�X
void welcome_screen() {
    int attempts = 0;       // ��l�ƹ��զ���
    char input[5];          // �Ω�s�x�Τ��J���Ʋ�
    
    for(int i=0;i<=20;i++)
 	{
 		printf("���w�A���i�o�Q�F\n");
	}
	system("PAUSE");
	fflush (stdin);
    // �`�����\�̦h3���K�X����
    while (attempts < 3) {
        clear_screen();
        printf("------------------------------------\n");
        printf(" ���\�i�J�ǥͦ��Z�޲z�t�� \n");
        printf("++++++++++++++++++++++++++++++++++++\n");
        printf("�п�J4��Ʀr�K�X: ");
        scanf("%4s", input); // Ū���Τ��J

        // �ˬd��J���K�X�O�_���T
        if (strcmp(input, PASSWORD) == 0) {
            printf("�K�X���T\n");
            getchar(); // �M����J�w�İ�
            return;
        } else {
            printf("���~�C�Э���\n");
            attempts++; // �W�[���զ���
        }
    }

    // �p�G���զ��ƹL�h�A�h�X�{��
    printf("���զ��ƹL�h�C�{�ǱN�h�X�C\n");
    exit(1);
}

// �����ܥD���
void display_menu() {
    printf("------------[���Z�޲z�t��]----------\n");
    printf("|  a. ��J�ǥͦ��Z         |\n");
    printf("|  b. ��ܾǥͦ��Z         |\n");
    printf("|  c. �j���ǥͦ��Z         |\n");
    printf("|  d. ���Z�ƦW             |\n");
    printf("|  e. �h�X�t��             |\n");
    printf("------------------------------------\n");
}

// ��ƿ�J�ǥͦ��Z
void enter_student_grades(Student students[], int *student_count) {
    int n;

    clear_screen();
    printf("��J�ǥͼƶq (5-10): ");
    
    // ���Ҿǥͼƶq
    while (scanf("%d", &n) != 1 || n < MIN_STUDENTS || n > MAX_STUDENTS) {
        printf("��J�L�ġC�п�J5��10�������Ʀr: ");
        while (getchar() != '\n'); // �M����J�w�İ�
    }

    // �`����J�C�Ӿǥͪ��ԲӫH��
    for (int i = 0; i < n; i++) {
        printf("��J�� %d �Ӿǥͩm�W: ", i + 1);
        scanf("%s", students[i].name);

        printf("��J�� %d �Ӿǥ;Ǹ� (6��Ʀr): ", i + 1);
        // ���Ҿǥ;Ǹ�
        while (scanf("%d", &students[i].student_id) != 1 || students[i].student_id < 100000 || students[i].student_id > 999999) {
            printf("�Ǹ��L�ġC�п�J6��Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        printf("��J�ƾǦ��Z (0-100): ");
        // ���ҼƾǦ��Z
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100) {
            printf("���Z�L�ġC�п�J0��100�������Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        printf("��J���z���Z (0-100): ");
        // ���Ҫ��z���Z
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100) {
            printf("���Z�L�ġC�п�J0��100�������Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        printf("��J�^�妨�Z (0-100): ");
        // ���ҭ^�妨�Z
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100) {
            printf("���Z�L�ġC�п�J0��100�������Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        // �p�⥭�����Z
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    *student_count = n; // ��s�ǥͼƶq
}

// �����ܩҦ��ǥͦ��Z
void display_student_grades(Student students[], int student_count) {
    clear_screen();
    // �`����ܨC�Ӿǥͪ��ԲӫH��
    for (int i = 0; i < student_count; i++) {
        printf("�m�W: %s, �Ǹ�: %d, �ƾ�: %d, ���z: %d, �^��: %d, ����: %.1f\n",
            students[i].name, students[i].student_id, students[i].math,
            students[i].physics, students[i].english, students[i].average);
    }
    printf("�����N���^�D���...");
    getchar(); // ���ݥΤ��J
    getchar(); // �M����J�w�İ�
}

// ��ƫ��m�W�j���ǥͦ��Z
void search_student_grades(Student students[], int student_count) {
    char name[50];
    int found = 0;

    clear_screen();
    printf("��J�n�j�����m�W: ");
    scanf("%s", name);

    // �`�����m�W�d��ǥ�
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("�m�W: %s, �Ǹ�: %d, �ƾ�: %d, ���z: %d, �^��: %d, ����: %.1f\n",
                students[i].name, students[i].student_id, students[i].math,
                students[i].physics, students[i].english, students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("�����Ӿǥ͡C\n");
    }

    printf("�����N���^�D���...");
    getchar(); // ���ݥΤ��J
    getchar(); // �M����J�w�İ�
}

// ��ƫ��������Z�ƦW�ǥ�
void grade_ranking(Student students[], int student_count) {
    clear_screen();
    // �ϥΫ_�w�Ƨǫ��������Z�ƦW�ǥ�
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // ��ܱƦW�᪺�ǥ�
    for (int i = 0; i < student_count; i++) {
        printf("�m�W: %s, �Ǹ�: %d, ����: %.1f\n",
            students[i].name, students[i].student_id, students[i].average);
    }

    printf("�����N���^�D���...");
    getchar(); // ���ݥΤ��J
    getchar(); // �M����J�w�İ�
}

// ��ƽT�{�h�X�t��
void exit_system() {
    char choice;
    printf("�T�w�n�h�X�ܡH (y/n): ");
    while (1) {
        choice = getchar();
        if (choice == 'y' || choice == 'Y') {
            exit(0); // �h�X�{��
        } else if (choice == 'n' || choice == 'N') {
            break; // ��^�D���
        } else {
            printf("��J�L�ġC�п�J 'y' �� 'n': ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }
    }
}

int main() {
    Student students[MAX_STUDENTS]; // �Ω�s�x�ǥͼƾڪ��Ʋ�
    int student_count = 0;          // ��l�ƾǥͭp��
    char choice;                   
// �Ω�s�x�Τ����ܪ��ܶq

    welcome_screen(); // ����w��e�������ұK�X

    // �D�`���A��ܵ��óB�z�Τ���
    while (1) {
        clear_screen();
        display_menu(); // ��ܥD���
        choice = getchar();
        while (getchar() != '\n');  // �M����J�w�İ�

        // �B�z�Τ���
        switch (choice) {
            case 'a':
                enter_student_grades(students, &student_count); // ��J�ǥͦ��Z
                break;
            case 'b':
                display_student_grades(students, student_count); // ��ܾǥͦ��Z
                break;
            case 'c':
                search_student_grades(students, student_count); // �j���ǥͦ��Z
                break;
            case 'd':
                grade_ranking(students, student_count); // ��ܦ��Z�ƦW
                break;
            case 'e':
                exit_system(); // �T�{�ðh�X�t��
                break;
            default:
                printf("��ܵL�ġC�Э��աC\n");
                printf("�����N���^�D���...");
                getchar(); // ���ݥΤ��J
        }
    }

    return 0;
}

