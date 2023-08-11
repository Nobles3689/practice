//Beakjoon Online Judge #1991
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Node
{
    char data;
    Node* l_node;
    Node* r_node;
};

Node* NewNode(char a){
    Node* newnode = new Node;
    newnode->data = a;
    newnode->l_node = newnode->r_node = NULL;
    return newnode;
}

Node* InitNode(Node* node, char a, char b){
    if(a!='.')
        node->l_node = NewNode(a);
    if(b!='.')
        node->r_node = NewNode(b);
    return node;
}

Node* InsertNode(Node* root, Node* node){
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* tmp = q.front();
		q.pop();

        if(tmp->data==node->data){
            tmp->l_node = node->l_node;
            tmp->r_node = node->r_node;
            break;
        }
        if (tmp->l_node != NULL)
			q.push(tmp->l_node);
		
		if (tmp->r_node != NULL)
			q.push(tmp->r_node);
		
    }
    return root;
    
}

void preorder(Node* node){
    if(node!=NULL){
        cout << node->data;
        preorder(node->l_node);
        preorder(node->r_node);
    }

}

void inorder(Node* node){
    if(node!=NULL){
        inorder(node->l_node);
        cout << node->data;
        inorder(node->r_node);
    }
}

void postorder(Node* node){
    if(node!=NULL){
        postorder(node->l_node);
        postorder(node->r_node);
        cout << node->data;
    }
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    char tmp1, tmp2, tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    Node* root = NewNode(tmp1);
    InitNode(root, tmp2, tmp3);
    for(int i = 0; i<num-1; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        Node* node1 = NewNode(tmp1);
        InitNode(node1, tmp2, tmp3);
        InsertNode(root, node1);
    }

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    return 0;
}
