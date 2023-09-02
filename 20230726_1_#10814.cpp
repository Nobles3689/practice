//Beakjoon Online Judge #10814
#include <iostream>
#include <vector>
using namespace std;
typedef struct memb{
    int age;
    char name[101];
    int order;
}mem;


int comp(const void* left, const void* right){
    mem* a = (mem*) left;
    mem* b = (mem*) right;

    if(a->age>b->age){
	    return 1;
	}
	else if(a->age<b->age){
	    return -1;
	}
	else if(a->age==b->age){
	    if(a->order>b->order){
	        return 1;
	    }
	    else if(a->order<b->order){
	        return -1;
	    }
	}
    return 0;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int num;
    cin >> num;
    mem m[num];
    for(int i = 0; i<num; i++){
        cin >> m[i].age >> m[i].name;
        m[i].order = i;
    }

    qsort(m, num, sizeof(mem), comp);


    for(int i = 0; i<num; i++){
        cout << m[i].age << ' ' << m[i].name<<'\n';
    }
    return 0;
}