//Beakjoon Online Judge #2346
#include <iostream>
#include <deque>
#include <vector>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    deque<pair<int, int>> balloon;
    vector<int> res;
    for(int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        balloon.push_back({i, tmp});
    }
    
    int index = 0;
    while (balloon.size()!=0)
    {
        res.push_back(balloon[index].first+1);
        int flag = balloon[index].second;
        deque<pair<int, int>>::iterator it = balloon.begin();
        it+=index;
        balloon.erase(it);
        int s = balloon.size();
        if(s==0) break;
        if(flag>0)
        {
            index = (index-1+flag+s)%s;
        }else
        {   
            while (flag<0)
            {
                flag+=s;
            }
            
            index = (index+flag)%s;
        }
    }
    
    
    for(int i = 0 ; i<n; i++)
        cout << res[i] << ' ';
    
    return 0;
    
}
