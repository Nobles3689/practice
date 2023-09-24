//Beakjoon Online Judge #20529
#include <iostream>
#include <vector>
using namespace std;

int cal(int num){
    if(num > 32){
        string tmp;
        cin.ignore();
        getline(cin, tmp);
        return 0;
    }
    int ans = 12;
    vector<string> v(num);
    for(int i = 0; i<num; i++){
        cin >> v[i];
    }
    for(int i = 0; i<num-2; i++){
        for(int j = i+1; j<num-1; j++){
            for(int k = j+1; k<num; k++){
                int res = 0;
                for(int l = 0; l<4; l++){
                    if(v[i][l] != v[j][l]) res++;
                    if(v[j][l] != v[k][l]) res++;
                    if(v[k][l] != v[i][l]) res++;
                }
                ans = min(res, ans);
            }
        }
    }
    return ans;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for(int i = 0; i<tc; i++){
        int num;
        cin >> num;
        cout << cal(num) << '\n';
    }
    return 0;
}