//Beakjoon Online Judge #18111
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, b;
    cin >> n >> m >> b;
    int g[500][500];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> g[i][j];
        }
    }

    int time = 0x7fffffff;
    int max_g = 0;
    for(int i = 0; i<257; i++){
        int diff = 0;
        int inven = b;
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                int tmp;
                tmp = i - g[j][k];
                if(tmp>0){
                    diff += tmp;
                    inven -= tmp;
                }else{
                    diff -= (tmp*2);
                    inven -= tmp;
                }
            }
        }
        if(inven>=0){
            if(time>=diff){
                time = diff;
                max_g = i;
            }
        }

    }

    cout << time << ' ' << max_g;
    return 0;

}
