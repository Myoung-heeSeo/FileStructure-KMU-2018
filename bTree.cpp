#include  <iostream>
using namespace std;
#define m 3

class Node {
public:
  Node *p[m];
  int k[m];
  int n=0;
friend class Tree;
};


Node* getNode(int m){
  Node *temp=new Node();
  for(int i=0; i<m; i++){
    temp-> p[i] = NULL;
    temp -> k[i] = 0;
  }
  temp -> n=0;
  return temp;
}

void inorder(Node *T, m){
  if(T) {
    for ( int i=0; i<m-1; i++){
      inorder(T->p[i], m);
      cout << T->k[i];
    }
    cout << T->p[m-1];
  }
}

insertBT(T, m, newKey) {
  if(T=NULL) {  //루트 노드 생성
    T <- getNode(m);   //T.n <- 0; T.Ki <- null; Pi <- null;
    T->k[0] = newKey; T->n = 1;
    return;
  }
  // x 노드의 주소를 스택에 저장하면서 newKey가 삽입될 위치를 탐색한다.
  Node *x = T;
  stack<Node *> s;

  do {
    int i = 0;
    while (i< x->n && newKey > x->k[i]){
      i++ ;
    }
    if (i < x->n && newKey == x.k[i]) return; // 삽입할 키를 발견함. 삽입 불가.
    //for some i where Ki-1 < oldKey < Ki, 삽입할 키를 아직 발견하지 못함.
    s.push(x);
    x=x->p[i];
  } while ((x <- x.P[i]-1)!= null);
  //삽입할 키를 발견 못 함. 이제 x는 null
  //newKey를 B-트리에 삽입한다.
  //tempNode: 오버플로를 위한 노드 (x 노드와 newKey를 저장하기 위한 임시 노드)

  bool finished = false;
  x = s.top;
  s.pop;     <- pop a value from the top of the stack;

  int i=0;
  for(int i<x->n && newKey>x->k[i]){
    i++;
  }

  do {
    if(x.n < m-1){
      for(int j = x -> n; j > i; j--) {
          x -> p[j+1] = x -> p[j];
          x -> k[j] = x -> k[j-1];
          x -> p[j] = x -> p[j-1];
      };
      finished=true;
    }

    if(p!=NULL) {
        x -> P[i] = p -> P[0];
        x -> K[i] = p -> K[0];
        x -> P[i+1] = p -> P[1];
        x -> n += 1;
    }
    else {
        x -> K[i] = newKey;
        x -> n += 1;
    }

    Node *temp = x;

    //insert newKey at an appropriate position of tempNode;

    newKey <- center key of tempNode;
    copy 1st half of tempNode to x;
    y <- getNode();
    copy 2nd half of tempNode to y;

    if (stack is not empty) {
      x <- pop a value from the top of the stack;
    }
    else {  // 트리의 레벨이 하나 증가한다.
      T <- getNode(); // T.n <- 0; T.Ki <- null; Pi <- null;
      T.K[1] <- newKey;
      T.P[0] <- x;
      T.P[1] <- y;
      finish = True;
    }
  } while (!finish);
}

int main(){
  Tree t;
}
