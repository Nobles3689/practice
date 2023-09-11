//Beakjoon Online Judge #7662
#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int t_case;
    cin >> t_case;
    for(int z = 0; z<t_case; z++){
        multiset<int> ms;
        int cal;
        cin >> cal;
        for (int i = 0; i<cal; i++)
        {
            char flag;
            int num;
            cin >> flag >> num;
            if(flag == 'I'){
                ms.insert(num);
            }
            if(flag == 'D'){
                if(!ms.empty()){
                    if(num == 1){
                        ms.erase(--ms.end());
                    }else if(num = -1){
                        ms.erase(ms.begin());
                    }
                }
            }
        }
        if(ms.empty()){
            cout << "EMPTY\n";
        }else{
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
}