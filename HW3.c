#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h>
#define ROWS 9
#define COLS 9

void clearScreen() {
    system("cls");
    printf("按任意鍵繼續...\n");
    getch(); /*等待使用者按下任意鍵*/
}
void displayMenu() { /*主選單*/ 
    printf("____________________________\n");
    printf("|     [Booking System]    |\n");
    printf("|    a.Available seats    |\n");
    printf("|    b.Arrange for you    |\n");
    printf("|    c.Choose by yourself |\n");   
    printf("|    d.Exit               |\n");
    printf("____________________________\n");
}
void initializeSeats(char seats[ROWS][COLS]) { /*初始化座位表格，隨機選擇十個座位並標記為已預訂*/
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
void displaySeats(char seats[ROWS][COLS]) {  /*顯示座位表格的內容和狀態*/
    printf(" \\123456789\n");
    for(int i = ROWS-1; i >= 0; i--) {
        printf("%d", i+1);
        for(int j = 0; j < COLS; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
    printf("按任一鍵返回主選單...\n");
    getch();
}

void arrangeSeatsForUser(char seats[ROWS][COLS], int numSeats) {  /*為使用者安排指定數量的座位*/
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
    displaySeats(seats); /*顯示座位表格*/ 
    char response; /*回應字元*/ 
    printf("您對安排滿意嗎？(y/n):");
    scanf(" %c", &response);
    if(response == 'y') { /*判斷是否滿意*/ 
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
void chooseSeatsByUser(char seats[ROWS][COLS]) { /*由使用者選擇座位*/
    int row, col;
    char dummy;
    printf("輸入座位位置（例如 1-2、2-9）。 輸入“q”停止\n");
    while(1) {
        printf("輸入座位位置（行列）： ");
        if(scanf("%d-%d", &row, &col) != 2) break;
        if(row < 1 || row > ROWS || col < 1 || col > COLS || seats[row-1][col-1] != '-') {
            printf("座位無效或已預約，再試一次\n");
            while((dummy = getchar()) != '\n' && dummy != EOF);  /*清除輸入緩衝區中的所有字符*/
            continue;
        }
        seats[row-1][col-1] = '@';
    }
    displaySeats(seats);  /*顯示座位表格的內容*/
    printf("按任一鍵確認您的選擇...\n");
    getch();
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(seats[i][j] == '@') {
                seats[i][j] = '*';
            }
        }
    }
}
/*個人風格*/ 
int main(){
     printf("吳誌軒的個人風格之簡約風\n");
    for(int i=1;i<=20;i++){
        for(int j=0;j<i;j++){
            printf("%d\n",i);
    }}
    system("PAUSE");
    system("CLS");

    /*要求使用者輸入4個數字的密碼*/
    int a,b,c,d;
    int e=0; /*e為計變數*/
    printf("輸入密碼\n");
    while(e<3){ /*用while迴圈，直到用戶輸入正確密碼或連續三次輸入錯誤才會結束*/
        scanf("%d",&a);
        if(a==2024){ /*判斷數字密碼是否2024*/
            printf("密碼正確\n");
            break;
        }else{
            printf("密碼錯誤\n");
            e++; /*如果輸入不是2024，計變數+1*/
        }
    }
    if(e==3){ /*計變數加到3為止*/
        printf("密碼錯誤，結束程式\n");
        return 0;
    }

    /*座位表*/
    char seats[ROWS][COLS];
    initializeSeats(seats);

    /*主選單*/
    char choice;
    do {
        clearScreen();
        displayMenu();
        printf("輸入選擇:");
        scanf(" %c", &choice);
        switch(choice) {
            case 'a':
                clearScreen();
                displaySeats(seats);
                break;
            case 'b': {
                clearScreen();
                int numSeats;
                printf("需要幾個座位(1-4)? ");
                scanf("%d", &numSeats);
                if(numSeats < 1 || numSeats > 4) {
                    printf("座位數無效\n");
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
                    printf("正在退出...\n");
                    return 0;
                }
                break;
            }
            default:
                printf("無效選擇，再試一次\n");
                break;
        }
    } while(choice != 'd');
    return 0;
}
//對於這次作業我依然是矇矇懂懂，雖然勉強做出來了，但整體來還算ok? 
