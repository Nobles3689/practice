//Beakjoon Online Judge #5639
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value;
    Node* LN;
    Node* RN;
};

Node* NewNode(int n){
    Node* newnode = new Node;
    newnode->value = n;
    newnode->LN = newnode->RN = NULL;
    return newnode;
}

Node* insert(Node* root, int n){
    if(n<root->value){
        if(root->LN == NULL){
            Node* tmp = NewNode(n);
            root->LN = tmp;
        }else{
            insert(root->LN, n);
        }
    }else{
        if(root->RN == NULL){
            Node* tmp = NewNode(n);
            root->RN = tmp;
        }else{
            insert(root->RN, n);
        }
    }
    return root;
}

void postorder(Node* node){
    if(node!=NULL){
        postorder(node->LN);
        postorder(node->RN);
        cout << node->value << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int rv;
    cin >> rv;
    Node* root = NewNode(rv);
    int tmp;
    while (cin >> tmp)
    {
        if(cin.fail())
            break;
        insert(root, tmp);
    }
    postorder(root);
    return 0;
    
    
}