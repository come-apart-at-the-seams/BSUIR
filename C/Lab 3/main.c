

#include <stdio.h>
#include <stdlib.h>

void fill(int chessboard[8][8]);
void print(int chessboard[8][8]);
void paint(int chessbroard[8][8],int a, int b);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int ans= 0;
    int chessboard[8][8];
    fill(chessboard);
    while (!ans){
        for(int n=0;n<8;){
            int check=0;
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(chessboard[i][j]==0) check++;
                }
            }
            if(check==0){
                fill(chessboard);
                n=0;
            }
            int a=rand() % 8, b=rand() % 8;
            if(chessboard[a][b]==0){
                paint(chessboard, a, b);
                n++;
            }
            if(n==7) ans=1;
            print(chessboard);
        }
    }
    print(chessboard);
    printf("True\n");
    return 0;
}

void print(int chessboard[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d  ", chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void fill(int chessboard[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            chessboard[i][j]=0;
        }
    }
}
void paint(int chessboard[8][8], int a, int b){
    
    int ii=0,jj=0;
    if (a<=b){
        for(int j=b-a;j<8;j++){
            chessboard[ii][j]=3;
            ii++;
        }
    }
    if (a>b){
        for(int i=a-b;i<8;i++){
            chessboard[i][jj]=3;
            jj++;
        }
    }
    ii=0;
    jj=7;
    if (a<=7-b){
        for(int j=b+a;j>=0;j--){
            chessboard[ii][j]=3;
            ii++;
        }
    }
    if (a>7-b){
        for(int i=a+b-7;i<8;i++){
            chessboard[i][jj]=3;
            jj--;
        }
    }
    for(int i=0;i<8;i++){
        chessboard[i][b]=3;
    }
    for(int j=0;j<8;j++){
        chessboard[a][j]=3;
    }
        
    chessboard[a][b]=1;
}
