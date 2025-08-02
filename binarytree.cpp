#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
// input
void pre(Node* node){
    if(node == NULL){
        return;
    }
    cout << node->data << " ";
    pre(node->left);
    pre(node->right);
}
void inorder(Node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
void post(Node* node){
    if(node == NULL){
        return;
    }
    post(node->left);
    post(node->right);
    cout << node->data << " ";
}
int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    pre(root);
    cout << endl;
    inorder(root);
    cout << endl;
    post(root);
    cout << endl;
    return 0;

}
