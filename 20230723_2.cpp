//Beakjoon Online Judge #1181
#include <iostream>
using namespace std;

int main(){
    string tmp = "";
    while (true)
    {
        int num, mid, flag=0;
        cin >> tmp;
        if(!tmp.compare("0")){
            break;
        }
        num = tmp.size();
        mid = num/2;
        if((num%2)==0){
            for(int i = mid; i<num; i++){
                if(tmp[i]==tmp[num-i-1]){
                    flag++;
                }
            }
            
        }else{
            for(int i = mid+1; i<num; i++){
                if(tmp[i]==tmp[num-i-1]){
                    flag++;
                }
            }
        }
        if(flag==mid){
            cout << "yes" << '\n';
        }else{
            cout << "no" << '\n';
        }
    }
    return 0;
    
}