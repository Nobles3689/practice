#include <iostream>
using namespace std;

void Merge(int* xarr, int* yarr, int left, int right){
    int tmpxarr[100000];
    int tmpyarr[100000];
    for(int i=left; i<=right; i++){
        tmpxarr[i] = xarr[i];
        tmpyarr[i] = yarr[i];
    }

    int mid = (left+right)/2;
    int tmpleft = left;
    int tmpright = mid+1;
    int index = left;
    

    while (tmpleft<=mid&&tmpright<=right)
    {
        if(tmpxarr[tmpleft]<tmpxarr[tmpright]){
            xarr[index] = tmpxarr[tmpleft];
            yarr[index] = tmpyarr[tmpleft];
            index++;
            tmpleft++;
        }else if(tmpxarr[tmpleft]>tmpxarr[tmpright]){
            xarr[index] = tmpxarr[tmpright];
            yarr[index] = tmpyarr[tmpright];
            index++;
            tmpright++;
        }else{
            if(tmpyarr[tmpleft]<=tmpyarr[tmpright]){
                xarr[index] = tmpxarr[tmpleft];
                yarr[index] = tmpyarr[tmpleft];
                index++;
                tmpleft++;
            }else{
                xarr[index] = tmpxarr[tmpright];
                yarr[index] = tmpyarr[tmpright];
                index++;
                tmpright++;
            }
        }
    }
    if(tmpleft>mid){
        int remain = right - tmpright;
        for(int i = 0; i<=remain; i++){
            xarr[index+i] = tmpxarr[tmpright+i];
            yarr[index+i] = tmpyarr[tmpright+i];
        }
    }
    else{
        int remain = mid - tmpleft;
        for(int i = 0; i<=remain; i++){
            xarr[index+i] = tmpxarr[tmpleft+i];
            yarr[index+i] = tmpyarr[tmpleft+i];
        }
    }
    
}

void Part(int*arr, int*yarr, int left, int right){
    if(left<right){
        int mid = (left+right) / 2;
        Part(arr, yarr, left, mid);
        Part(arr, yarr, mid+1, right);
        Merge(arr, yarr, left, right);
    }
}

int main(){
    int num;
    int xarr[100000];
    int yarr[100000];
    cin >> num;
    for(int i=0; i<num; i++){
        cin >> xarr[i] >> yarr[i];
    }
    Part(xarr, yarr, 0, num-1);
    for(int i=0; i<num; i++){
        cout << xarr[i] << ' ' << yarr[i];
        if(i<num){
            cout << '\n';
        }
    }
    return 0;
}