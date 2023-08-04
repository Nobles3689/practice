//Beakjoon Online Judge #2630
#include <iostream>
using namespace std;
int paper[128][128];
int a[2] = {0, 1};
int result1 = 0;
int result2 = 0;

int div(int n, pair<int, int> start){
    int flag = 0;
    int w = n*n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            flag+=paper[start.first+i][start.second+j];
        }
    }
    if(flag==0){
        result1++;
        return 1;
    }else if(flag==w){
        result2++;
        return 1;
    }else{
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                div(n/2, make_pair(start.first+(a[i]*n/2), start.second+(a[j]*n/2)));
            }
            
        }
        return 0;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num, tmp;
    cin >> num;
    for(int i = 0; i<num; i++){
        for(int j=0; j<num; j++){
            cin >> tmp;
            paper[i][j] = tmp;
        }
    }
    div(num, make_pair(0, 0));
    cout << result1 << '\n' << result2;
    return 0;
}