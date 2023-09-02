//Baekjoon Online Judge #1018
#include <iostream>
using namespace std;

int replace(int flag, char chess[][50], int i, int j){
    int replace = 0;
    //int flag = 0;
    for(int k =0; k<8;k++){
        for(int l = 0; l<8; l++){
            if(flag == 0){
                if(chess[i+k][j+l]!='B'){
                    replace++;
                    //chess[i+k][j+l] = 'B';
                }
                flag = 1;
            }
            else if(flag == 1){
                if(chess[i+k][j+l]!='W'){
                    replace++;
                    //chess[i+k][j+l] = 'W';
                }
                flag = 0;
            }
        }
        if(flag==0){
            flag = 1;
        }else{
            flag = 0;
        }
    }
    
    return replace;
}

int main(){
    int row, col;
    char chessboard[50][50];
    int result = 64;
    int tmp0 = 64;
    int tmp1 = 64;
    cin >> row >> col;
    for(int i = 0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> chessboard[i][j];
        }
    }
    for(int i = 0; i<row-7; i++){
        for(int j = 0; j<col-7; j++){
            tmp0 = replace(0, chessboard, i, j);
            tmp1 = replace(1, chessboard, i, j);
            if (tmp0 < tmp1)
            {
                if(tmp0 < result){
                    result = tmp0;
                }
            }
            if(tmp1 < result){
                    result = tmp1;
                }
        }
    }
    cout << result;
    return 0;
}