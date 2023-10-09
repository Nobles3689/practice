//Beakjoon Online Judge #1806
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int length, goal;
    cin >> length >> goal;
    vector<int> v(length);
    
    for(int i = 0; i<length; i++){
        cin >> v[i];
    }
    int ans = 100001;
    int tmp = v[0];
    int left = 0, right = 0;
    while (right<length)
    {
        if(tmp>=goal){
            if(left==right){
                ans = 1;
                break;
            }else{
                ans = min(ans, (right+1)-left);
                tmp-=v[left];
                left++;
                
            }
        }else{
            right++;
            tmp+=v[right];
        }
    }
    
    if(ans==100001) ans = 0;
    cout << ans;
    return 0;

}