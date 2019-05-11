//(1)所有的叶结点都出现在第k层或k-l层（层次最大的两层）
//(2)对任一结点，如果其右子树的最大层次为L，则其左子树的最大层次为L或L+l。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=25;
struct AVLtree{
    int key;
    AVLtree* l;
    AVLtree* r;
    int height;
    int level;
}*root;
int n,x;
bool flag=false;
queue<AVLtree*>q;
int Height(AVLtree* T){
    if(T==NULL) return 0;
    return T->height;
}

AVLtree* RR(AVLtree* T){
    AVLtree* L=T->l;
    T->l=L->r;
    L->r=T;
    L->height=max(Height(L->l),Height(L->r))+1;
    T->height=max(Height(T->l),Height(T->r))+1;
    return L;
}

AVLtree* LL(AVLtree* T){
    AVLtree* R=T->r;
    T->r=R->l;
    R->l=T;
    R->height=max(Height(R->l),Height(R->r))+1;
    T->height=max(Height(T->l),Height(T->r))+1;
    return R;
}

AVLtree* RL(AVLtree* T){
    T->r=RR(T->r);
    return LL(T);
}

AVLtree* LR(AVLtree* T){
    T->l=LL(T->l);
    return RR(T);
}

AVLtree* insert(AVLtree* now, int x){
    if(now==NULL){
        now=(AVLtree *)malloc(sizeof(struct AVLtree));
        now->key=x;now->l=now->r=NULL;
        now->height=1;
    }else if(x<now->key){
        now->l=insert(now->l,x);
        if(Height(now->l)-Height(now->r)==2){
            if(x<(now->l->key)){
                now=RR(now);
            }
            else {now=LR(now);}
        }
    }else{
        now->r=insert(now->r,x);
        if(Height(now->r)-Height(now->l)==2){
            if(x>=(now->r->key)){
                now=LL(now);
            }
            else{
                now=RL(now);
            }
        }
    }
    now->height=max(Height(now->l),Height(now->r))+1;
    return now;
}

void Level(AVLtree* now,int layer){
    now->level=layer;
    if(now->l) Level(now->l,layer+1);
    if(now->r) Level(now->r,layer+1);
}

void Print(){
    q.push(root);
    AVLtree* tmp=NULL;
    int level=0;
    bool f=false,ff=false;
    while(!q.empty()){
        tmp=q.front();q.pop();
        if(!flag){
            cout<<tmp->key;flag=true;
        }else{
            cout<<' '<<tmp->key;
        }
        if(level!=tmp->level){
            level=tmp->level;
            f=false;
        }
        if(tmp->l!=NULL){
          q.push(tmp->l);
          if(f) ff=true;//完全树的定义是左边可以有，但是左边无的之后就无
        }
        else{
          f=true;
        }
        if(tmp->r!=NULL){
          q.push(tmp->r);
          if(f) ff=true;
        }else{
          f=true;
        }
    }
    
    cout<<'\n';
    if(ff) cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;cin>>x;
    root=(AVLtree*)malloc(sizeof(struct AVLtree));
    root->height=1;root->l=root->r=NULL;
    root->key=x;
    //n=6;
    for(int i=2;i<=n;i++){
        cin>>x;
        //cout<<x<<endl;
        root=insert(root,x);
        // p(root); 
        // cout<<endl;  
    }
    Print();
    return 0;
}
