#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n;
struct AVLtree{
    int key;
    AVLtree* l;
    AVLtree* r;
    int height;
}*root;
int x,tot=0;
int Height(AVLtree* T){
    if(T==NULL) return 0;
    else return T->height;
}
AVLtree* RR(AVLtree* T){
    AVLtree* L=T->l;
    T->l=L->r;
    L->r=T;
    T->height=max(Height(T->r),Height(T->l))+1;
    L->height=max(Height(L->r),Height(L->l))+1;
    return L;
}

AVLtree* LL(AVLtree* T){
    AVLtree* R=T->r;
    T->r=R->l;
    R->l=T;
    T->height=max(Height(T->r),Height(T->l))+1;
    R->height=max(Height(R->r),Height(R->l))+1;
    return R;
}

AVLtree* LR(AVLtree* T){
    T->l=LL(T->l);
    return RR(T);
}

AVLtree* RL(AVLtree* T){
    T->r=RR(T->r);
    return LL(T);
}

AVLtree* Insert(AVLtree* T, int x){
    if(T==NULL){
        T=(AVLtree *)malloc(sizeof(struct AVLtree));
        if(T){
            T->key=x;
            T->l=T->r=NULL;
            T->height=1;
        }else{
            //memory wrong
        }
        return T;
    }
    else if(x<(T->key)){//左边，可能会RR，或者RL
        T->l=Insert(T->l,x);
        if((Height(T->l)-Height(T->r))==2){
            if(x<T->l->key){//RR
                T=RR(T);
            }else{//RL
                T=LR(T);
            }
        }
    }else if(x>(T->key)){//右边
        T->r=Insert(T->r,x);
        if((Height(T->r)-Height(T->l))==2){
            if(x>T->r->key){//LL
                T=LL(T);
            }else{//LR
                T=RL(T);
            }
        }
    }else{//不插入
        
    }
    T->height=max(Height(T->l),Height(T->r))+1;
    return T;
}
//void Print(AVLtree* T){
//    if(T==NULL) return ;
//    cout<<T->key<<endl;
//    if(T->l!=NULL){
//        cout<<"left kids is: "<<T->l->key<<endl;
//    }else cout<<"No left kids\n";
//    if(T->r!=NULL){
//        cout<<"right kids is: "<<T->r->key<<endl;
//    }else cout<<"No right kids\n";
//    Print(T->l);
//    Print(T->r);
//}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    root=NULL;
    for(int i=1;i<=n;i++){
//        if(i==6){
//            cout<<"Stop";
//        }
        cin>>x;
        root=Insert(root,x);
        //Print(root);
    }
    cout<<root->key<<'\n';
    return 0;
}
