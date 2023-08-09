//Beakjoon Online Judge #1149
#include <iostream>
#include <vector>
using namespace std;
int list[1001][3];
int DP[1001][3];
enum rgb { R, G, B };


int dis(rgb color, int max, int index){
    int sum = 0;
    if(index>=max) return 0;
    if(DP[index][color]!=0) return DP[index][color];
    switch (color)
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

    return DP[index][color] = sum + list[index][color];
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
        cin >> list[i][R] >> list[i][G] >> list[i][B];
    }
    int red = dis(R, num+1, 1);
    int green = dis(G, num+1, 1);
    int blue = dis(B, num+1, 1);

    cout << min(min(red, green), blue);
    
    return 0;
}