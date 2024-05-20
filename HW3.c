#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
#define ROWS 9
#define COLS 9

void clearScreen() {
    system("cls");
    printf("�����N���~��...\n");
    getch(); /*���ݨϥΪ̫��U���N��*/
}
void displayMenu() { /*�D���*/ 
    printf("____________________________\n");
    printf("|     [Booking System]    |\n");
    printf("|    a.Available seats    |\n");
    printf("|    b.Arrange for you    |\n");
    printf("|    c.Choose by yourself |\n");   
    printf("|    d.Exit               |\n");
    printf("____________________________\n");
}
void initializeSeats(char seats[ROWS][COLS]) { /*��l�Ʈy����A�H����ܤQ�Ӯy��üаO���w�w�q*/
    srand(time(0));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            seats[i][j] = '-';
        }
    }
    for(int k = 0; k < 10; k++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(seats[row][col] == '-') {
            seats[row][col] = '*';
        } else {
            k--; 
        }
    }
}
void displaySeats(char seats[ROWS][COLS]) {  /*��ܮy���檺���e�M���A*/
    printf(" \\123456789\n");
    for(int i = ROWS-1; i >= 0; i--) {
        printf("%d", i+1);
        for(int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
    printf("�����@���^�D���...\n");
    getch();
}

void arrangeSeatsForUser(char seats[ROWS][COLS], int numSeats) {  /*���ϥΪ̦w�ƫ��w�ƶq���y��*/
    int found = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(seats[i][j] == '-' && j + numSeats <= COLS) {
                int available = 1;
                for(int k = 0; k < numSeats; k++) {
                    if(seats[i][j + k] != '-') {
                        available = 0;
                        break;
                    }
                }
                if(available) {
                    for(int k = 0; k < numSeats; k++) {
                        seats[i][j + k] = '@';
                    }
                    found = 1;
                    break;
                }
            }
        }
        if(found) break;
    }
    if(!found && numSeats == 4) {
        for(int i = 0; i < ROWS - 1; i++) {
            for(int j = 0; j < COLS; j++) {
                if(seats[i][j] == '-' && seats[i+1][j] == '-') {
                    seats[i][j] = '@';
                    seats[i+1][j] = '@';
                    if(j+1 < COLS && seats[i][j+1] == '-' && seats[i+1][j+1] == '-') {
                        seats[i][j+1] = '@';
                        seats[i+1][j+1] = '@';
                        found = 1;
                        break;
                    } else {
                        seats[i][j] = '-';
                        seats[i+1][j] = '-';
                    }
                }
            }
            if(found) break;
        }
    }
    displaySeats(seats); /*��ܮy����*/ 
    char response; /*�^���r��*/ 
    printf("�z��w�ƺ��N�ܡH(y/n):");
    scanf(" %c", &response);
    if(response == 'y') { /*�P�_�O�_���N*/ 
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(seats[i][j] == '@') {
                    seats[i][j] = '*';
                }
            }
        }
    } else {
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(seats[i][j] == '@') {
                    seats[i][j] = '-';
                }
            }
        }
    }
}
void chooseSeatsByUser(char seats[ROWS][COLS]) { /*�ѨϥΪ̿�ܮy��*/
    int row, col;
    char dummy;
    printf("��J�y���m�]�Ҧp 1-2�B2-9�^�C ��J��q������\n");
    while(1) {
        printf("��J�y���m�]��C�^�G ");
        if(scanf("%d-%d", &row, &col) != 2) break;
        if(row < 1 || row > ROWS || col < 1 || col > COLS || seats[row-1][col-1] != '-') {
            printf("�y��L�ĩΤw�w���A�A�դ@��\n");
            while((dummy = getchar()) != '\n' && dummy != EOF);  /*�M����J�w�İϤ����Ҧ��r��*/
            continue;
        }
        seats[row-1][col-1] = '@';
    }
    displaySeats(seats);  /*��ܮy���檺���e*/
    printf("�����@��T�{�z�����...\n");
    getch();
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(seats[i][j] == '@') {
                seats[i][j] = '*';
            }
        }
    }
}
/*�ӤH����*/ 
int main(){
     printf("�d�x�a���ӤH���椧²����\n");
    for(int i=1;i<=20;i++){
        for(int j=0;j<i;j++){
            printf("%d\n",i);
    }}
    system("PAUSE");
    system("CLS");

    /*�n�D�ϥΪ̿�J4�ӼƦr���K�X*/
    int a,b,c,d;
    int e=0; /*e���p�ܼ�*/
    printf("��J�K�X\n");
    while(e<3){ /*��while�j��A����Τ��J���T�K�X�γs��T����J���~�~�|����*/
        scanf("%d",&a);
        if(a==2024){ /*�P�_�Ʀr�K�X�O�_2024*/
            printf("�K�X���T\n");
            break;
        }else{
            printf("�K�X���~\n");
            e++; /*�p�G��J���O2024�A�p�ܼ�+1*/
        }
    }
    if(e==3){ /*�p�ܼƥ[��3����*/
        printf("�K�X���~�A�����{��\n");
        return 0;
    }

    /*�y���*/
    char seats[ROWS][COLS];
    initializeSeats(seats);

    /*�D���*/
    char choice;
    do {
        clearScreen();
        displayMenu();
        printf("��J���:");
        scanf(" %c", &choice);
        switch(choice) {
            case 'a':
                clearScreen();
                displaySeats(seats);
                break;
            case 'b': {
                clearScreen();
                int numSeats;
                printf("�ݭn�X�Ӯy��(1-4)? ");
                scanf("%d", &numSeats);
                if(numSeats < 1 || numSeats > 4) {
                    printf("�y��ƵL��\n");
                } else {
                    arrangeSeatsForUser(seats, numSeats);
                }
                break;
            }
            case 'c':
                clearScreen();
                chooseSeatsByUser(seats);
                break;
            case 'd': {
                char confirm;
                printf("Continue? (y/n): ");
                scanf(" %c", &confirm);
                if(confirm == 'n') {
                    printf("���b�h�X...\n");
                    return 0;
                }
                break;
            }
            default:
                printf("�L�Ŀ�ܡA�A�դ@��\n");
                break;
        }
    } while(choice != 'd');
    return 0;
}
//���o���@�~�ڨ̵M�Oéé�����A���M�j�j���X�ӤF�A��������ٺ�ok? 
