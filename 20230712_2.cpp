//Beakjoon Online Judge #2750
#include <iostream>
using namespace std;

void Merge(int* arr, int* tmparr, int left, int right){
    for(int i=left; i<=right; i++){
        tmparr[i] = arr[i];
    }

    int mid = (left+right)/2;
    int tmpleft = left;
    int tmpright = mid+1;
    int index = left;
    

    while (tmpleft<=mid&&tmpright<=right)
    {
        if(tmparr[tmpleft]<=tmparr[tmpright]){
            arr[index] = tmparr[tmpleft];
            index++;
            tmpleft++;
        }else{
            arr[index] = tmparr[tmpright];
            index++;
            tmpright++;
        }
    }
    if(tmpleft>mid){
        int remain = right - tmpright;
        for(int i = 0; i<=remain; i++){
            arr[index+i] = tmparr[tmpright+i];
        }
    }
    else{
        int remain = mid - tmpleft;
        for(int i = 0; i<=remain; i++){
            arr[index+i] = tmparr[tmpleft+i];
        }
    }
    
}

void Part(int*arr, int*tmparr, int left, int right){
    if(left<right){
        int mid = (left+right) / 2;
        Part(arr, tmparr, left, mid);
        Part(arr, tmparr, mid+1, right);
        Merge(arr, tmparr, left, right);
    }
}

int main(){
    int arr[1000];
    int num;
    int tmparr[1000];
    cin >> num;
    for(int i=0; i<num; i++){
        cin >> arr[i];
    }
    Part(arr, tmparr, 0, num-1);
    for(int i = 0; i<num; i++){
        cout << arr[i];
        if(i!=(num-1)){
            cout << '\n';
        }
    }
    return 0;
}