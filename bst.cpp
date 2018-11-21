#include  <iostream>
// #include <fstream>
// #include <cstdlib>
using namespace std;

class Node {
public:
  Node *left;
  Node *right;
  int key;
friend class Tree;
};

class Tree {
public:
  Node *root;
  Tree(){root=0;}
  Node* maxNode(Node *);
  Node* minNode(Node *);
  Node* insertBST(Node*, int);
  void deleteBST(Node*, int);
};

Node* getNode(){
  Node *temp=new Node();
  temp->left=NULL;
  temp->right=NULL;
  temp->key=0;
  return temp;
}

int height(Node *T){
    if(T->left==NULL && T->right==NULL) return 0;
    else {
        int heightL, heightR;
        if(T->left) heightL=height(T->left);
        if(T->right) heightR=  height(T->right);
        if (heightL>heightR){
          heightL=heightL+1;
          return heightL;
        }
        else{
            heightR=heightR+1;
            return heightR;
        }
    }
}

int noNodes(Node *T){
  int noL=0, noR=0;
  if(T->left!=NULL) noL=noNodes(T->left);
  if(T->right!=NULL) noR=noNodes(T->right);
  return noL+noR+1;
}

Node* Tree::maxNode(Node *T){
  while(T->right!=NULL) T=T->right;
  return T;
}
Node* Tree::minNode(Node *T){
  while(T->left!=NULL) T=T->left;
  return T;
}

Node* Tree::insertBST(Node *B, int new_key) {   // B는 이원 탐색 트리, new_key는 삽입할 키 값
  Node *newNode = getNode(); // 삽입할 노드를 만듦
  newNode->key = new_key;
  if (B == NULL)  {return newNode;}// 공백 이원 탐색 트리인 경우
  else if (new_key < B->key) B->left=insertBST(B->left, new_key);
  else if(new_key>B->key) B->right=insertBST(B->right,new_key);
  return B;
}

void Tree::deleteBST(Node *B, int d_key){
  Node *p, *parent;
  p = B; // 주어진 키 d_key를 가진 노드
  parent = root; // 삭제할 노드의 부모 노드
  while(parent->key!=B->key){
    if(parent->key>B->key) parent=parent->left;
    else parent=parent->right;
  }
  while(p){
    if(p->key==d_key) break;
    else if(p->key<d_key) {
      parent=p;
      p=p->right;
    }
    else if(p->key>d_key){
      parent=p;
      p=p->left;
    }
    else break;
  }
  if (p == NULL)  return; // 삭제할 원소가 없음
  else if( p->left==NULL and p->right==NULL){ // 삭제할 노드의 차수가 0인 경우 (리프 노드)
      if (root==p) root=NULL;
      else if(parent->left == p)  parent->left = NULL;
      else parent->right = NULL;
  }
  else if(p->left==NULL or p->right==NULL){ // 삭제할 노드의 차수가 1인 경우
    if (p->left == NULL)  {
      if(parent==p) root=p->right;
      else if(parent->left == p) parent->left = p->right;
      else parent->right = p->right;
    }
    else{
      if (parent==p) root=p->left;
      else if(parent->right == p) parent->right = p->left;
      else parent->left = p->left;
    }
  }
  else if(p->left != NULL and p->right != NULL){ // 삭제할 노드의 차수가 2인 경우
    if((height(p->left)>height(p->right))||
    ((height(p->left)==height(p->right))&&(noNodes(p->left)>=noNodes(p->right)))) {
      Node *q=maxNode(p->left); // 왼쪽 서브트리에서 최대 키 값의 노드를 탐색
      p->key = q->key;
      deleteBST(p->left, q->key);
    }
    else{
      Node *q=minNode(p->right);
      p->key = q->key;
      deleteBST(p->right, q->key);
    }
  }
}

void inorder(Node *T){
  if(T) {
    inorder(T->left);
    cout << T->key<<" ";
    inorder(T->right);
  }
}


int main(){
  Tree T;
  T.root=T.insertBST(T.root, 8); inorder(T.root); cout <<'\n';
  T.insertBST(T.root, 18);  inorder(T.root); cout <<'\n';
  T.insertBST(T.root, 11);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 5);   inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 15);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 4);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 9);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 1);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 7);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 17);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 6);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 14);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 10);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 3);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 19);    inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 20);  inorder(T.root);  cout <<'\n';
  cout <<" //삭제 1\n";
  T.deleteBST(T.root, 8);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 18);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 11);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 5);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 15);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 4);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 9);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 1);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 7);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 17);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 6);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 14);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 10);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 3);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 19);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 20);  inorder(T.root);  cout <<'\n';
  cout <<" //재삽입\n";
  T.root=T.insertBST(T.root, 8);   inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 18);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 11);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 5);   inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 15);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 4);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 9);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 1);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 7);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 17);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 14);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 6);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 10);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 3);  inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 19);    inorder(T.root);  cout <<'\n';
  T.insertBST(T.root, 20);  inorder(T.root);  cout <<'\n';
  cout <<" //삭제 2\n";
  T.deleteBST(T.root, 20);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 19);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 3);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 10);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 14);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 6);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 17);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 7);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 9);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 1);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 4);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 15);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 5);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 11);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 18);  inorder(T.root);  cout <<'\n';
  T.deleteBST(T.root, 8);  inorder(T.root);  cout <<'\n';


}
