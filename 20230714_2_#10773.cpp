//Beakjoon Online judge #10773
#include <iostream>
using namespace std;

void sPush(int* stack, int num, int& index){
    index++;
    stack[index] = num;
}

void sPop(int* stack, int& index){
    if(index<0){
    }else{
        index--;
    }
}

int main(){
    int cmdNum;
    int stack[100000];
    int result=0;
    int index = -1;
    int num;
    cin >> cmdNum;
    for(int i = 0; i<cmdNum; i++){
        cin >> num;
        if(num == 0){
            sPop(stack, index);
        }else{
            sPush(stack, num, index);
        }
    }
    for(int i = 0; i<index+1; i++){
        result+=stack[i];
    }
    cout << result;
    return 0;
}