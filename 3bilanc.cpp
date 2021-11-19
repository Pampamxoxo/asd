#include<bits/stdc++.h>
using namespace std;
#define pippo 4
struct Node{
  int key;
  Node* p;
  Node* left;
  Node* right;
  Node(int k, Node* padre, Node* sx = nullptr, Node* dx = nullptr)
    : key{k}, p{padre}, left{sx}, right{dx} {}
};

typedef Node* PNode;
bool t3Bil(PNode u);

int main(){

    PNode root=new Node(0,nullptr);
    root->left = new Node(0,root);
    root->left->left= new Node (0,root->left);
    root->right=new Node(0,root);

    cout<<t3Bil(root);
}

#define isterm(x) (x->left==nullptr||x->right==nullptr)

int f(PNode u, bool& ris){
    if(u==nullptr||ris==false) return 0;
    int maxsotto=max(f(u->right, ris),f(u->left, ris));
    if(isterm(u) && (maxsotto+1)>=3)
        ris=false;
    return maxsotto+1;
}

bool t3Bil(PNode u){
    bool ris = true;
    f(u,ris);
    return ris;
}

