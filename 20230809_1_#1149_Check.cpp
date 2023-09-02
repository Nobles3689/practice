//Beakjoon Online Judge #1149
#include <iostream>
#include <vector>
using namespace std;
int list[1001][3];
int DP[1001][3];
enum rgb { R, G, B };


int dis(rgb color, int max, int index){
    int sum = 0;
    if(index>=max) return 0;//범위 지정(outofbound 방지)
    if(DP[index][color]!=0) return DP[index][color];//이미 수행한 경우 생략(없을 경우 시간초과)
    switch (color)//입력받은 역순으로 계산(재귀 사용)
    {
    case R:
        sum += min(dis(G, max, index+1), dis(B, max, index+1));
        break;
    case G:
        sum += min(dis(R, max, index+1), dis(B, max, index+1));
        break;
    case B:
        sum += min(dis(R, max, index+1), dis(G, max, index+1));
        break;
    }

    return DP[index][color] = sum + list[index][color];//수행 여부와 결과 저장용, 결과 출력
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    list[0][R] = 0;
    list[0][G] = 0;
    list[0][B] = 0;
    for(int i = 1; i<num+1; i++){
        cin >> list[i][R] >> list[i][G] >> list[i][B];//초기화
    }
    int red = dis(R, num+1, 1);
    int green = dis(G, num+1, 1);
    int blue = dis(B, num+1, 1);

    cout << min(min(red, green), blue);
    
    return 0;
}