//
//  main.cpp
//  CCCC
//
//  Created by mrs_empress on 2018/3/5.
//  Copyright © 2018年 mrs_empress. All rights reserved.
//

//L1-010
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int a[3];
//int main() {
//    for(int i=1;i<=3;i++)
//        scanf("%d",&a[i]);
//    sort(a+1,a+4);
//    printf("%d->%d->%d\n",a[1],a[2],a[3]);
//    return 0;
//}

//L1-011
//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <cstring>
//using namespace std;
//const int maxn=1e4+10;
//char c[200];
//int main(){
//    string a,b;
//    getline(cin,a);
//    getline(cin,b);
//    int len=b.length();
//    for(int i=0;i<len;i++){
//        c[b[i]]=1;
//    }
//    len=a.length();
//    string ans="";
//    for(int i=0;i<len;i++){
//        if(!c[a[i]])ans+=a[i];
//    }
//    cout<<ans<<endl;
//    return 0;
//}

//L1-012
//#include <iostream>
//#include <cstdio>
//using namespace std;
//int a[]={1,2,4,8,16,32,64,128,256,512,1024};
//int main(){
//    int n;
//    scanf("%d",&n);
//    printf("2^%d = %d\n",n,a[n]);
//    return 0;
//}

//L1-013
//#include <iostream>
//#include <cstdio>
//using namespace std;
//int a[]={0,1,3,9,33,153,873,5913,46233,409113,4037913};
//int main(){
//    int n;
//    scanf("%d",&n);
//    printf("%d\n",a[n]);
//    return 0;
//}

//L1-014
//#include <iostream>
//using namespace std;
//int main(){
//    cout<<"This is a simple problem."<<endl;
//    return 0;
//}

//L1-015
//#include <iostream>
//using namespace std;
//int main(){
//    int r,c;char ch;
//    cin>>c>>ch;
//    r=(c+1)/2;
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout<<ch;
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//L1-016
//#include <iostream>
//using namespace std;
//char m[]={'1','0','X','9','8','7','6','5','4','3','2'};
//int q[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
//int main(){
//    int n;
//    cin>>n;
//    int flag=0;
//    for(int i=0;i<n;i++){
//        string s;
//        cin>>s;
//        int tmp=0;
//        int j;
//        for(j=0;j<17;j++){
//            if(s[j]>='0'&&s[j]<='9'){
//                tmp+=(s[j]-'0')*q[j];
//                continue;
//            }
//            cout<<s<<endl;
//            flag=1;
//            break;
//        }
//        if(j==17){
//            if(m[tmp%11]!=s[17]){
//                cout<<s<<endl;
//                flag=1;
//            }
//        }
//    }
//    if(!flag)cout<<"All passed"<<endl;
//    return 0;
//}

//L1-017
//#include <iostream>
//#include <string>
//#include <cstdio>
//using namespace std;
//int main(){
//    string s;
//    cin>>s;
//    double ans=1;
//    int len=s.length();
//    int tot=len;
//    if(s[0]=='-'){
//        ans*=1.5;
//        tot--;
//    }
//    int n=0;
//    for(int i=0;i<len;i++){
//        if(s[i]=='2')n++;
//    }
//    if(!((s[len-1]-'0')%2)) ans*=2;
//    printf("%.2lf%%\n",ans*n/tot*100);
//    return 0;
//}

//L1-018
//#include <iostream>
//#include <cstdio>
//using namespace std;
//int main(){
//    int h,m;
//    scanf("%d:%d",&h,&m);
//    if(h<12||(h==12&&m==0)){
//        cout<<"Only ";
//        if(h<10)cout<<"0";
//        cout<<h<<":";
//        if(m<10)cout<<"0";
//        cout<<m<<".  Too early to Dang."<<endl;
//        //printf("Only %02d:%02d.  Too early to Dang.", hour, min);
//    }
//    else{
//        if(m!=0)h++;
//        h-=12;
//        for(int i=0;i<h;i++){
//            cout<<"Dang";
//        }
//        cout<<endl;
//    }
//    return 0;
//}

//L1-019
//#include <iostream>
//using namespace std;
//int main(){
//    int a,b,n;
//    cin>>a>>b>>n;
//    int x=0,y=0;
//    a++;b++;
//    for(int i=0;i<n;i++){
//        int x1,y1,x2,y2;
//        cin>>x1>>y1>>x2>>y2;
//        if(x1+x2==y1)x++;
//        if(x1+x2==y2)y++;
//        if(y1==y2&&y1==x1+x2)x--,y--;
//        if(a==x){
//            cout<<"A\n"<<y<<endl;
//            break;
//        }
//        if(b==y){
//            cout<<"B\n"<<x<<endl;
//            break;
//        }
//    }
//    return 0;
//}
//

//L1-020
//#include <iostream>
//#include <set>
//#include <vector>
//#include <string>
//using namespace std;
//set<string>s;
//vector<string>::iterator it;
//vector<string>ans;
//int main(){
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        int x;cin>>x;string y;
//        if(x==1)cin>>y;
//        else{
//            for(int j=0;j<x;j++){
//                cin>>y;
//                s.insert(y);
//            }
//        }
//    }
//    cin>>n;
//    for(int i=0;i<n;i++){
//        string y;
//        cin>>y;
//        if(s.find(y)==s.end()){
//            ans.push_back(y);
//            s.insert(y);
//        }
//    }
//    int len=ans.size();
//    if(ans.size()==0){
//        cout<<"No one is handsome"<<endl;
//        return 0;
//    }
//    it=ans.begin();
//    for(int i=0;i<len-1;i++){
//        cout<<(*it)<<" ";
//        it++;
//    }
//    cout<<(*it)<<endl;
//    return 0;
//}

//L1-021
//#include <iostream>
//using namespace std;
//int main(){
//    cout<<"I'm gonna WIN!"<<endl;
//    cout<<"I'm gonna WIN!"<<endl;
//    cout<<"I'm gonna WIN!"<<endl;
//    return 0;
//}

//L1-022
//#include <iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    int a=0,b=0;
//    for(int i=0;i<n;i++){
//        int x;
//        cin>>x;
//        if(x%2)a++;
//        else b++;
//    }
//    cout<<a<<" "<<b<<endl;
//    return 0;
//}

//L1-023
//#include <iostream>
//#include <string>
//using namespace std;
//int main(){
//    string s;
//    cin>>s;
//    int n=s.length();
//    int g=0,p=0,l=0,t=0;
//    for(int i=0;i<n;i++){
//        if(s[i]=='G'||s[i]=='g')g++;
//        if(s[i]=='P'||s[i]=='p')p++;
//        if(s[i]=='L'||s[i]=='l')l++;
//        if(s[i]=='T'||s[i]=='t')t++;
//    }
//    while(g||p||l||t){
//        if(g){
//            cout<<"G";
//            g--;
//        }
//        if(p){
//            cout<<"P";
//            p--;
//        }
//        if(l){
//            cout<<"L";
//            l--;
//        }
//        if(t){
//            cout<<"T";
//            t--;
//        }
//    }
//    return 0;
//}

//L1-024
//#include <iostream>
//using namespace std;
//int main(){
//    int n;
//    cin>>n;
//    if(n==7)n=2;
//    else if(n==6)n=1;
//    else n=n+2;
//    cout<<n<<endl;
//    return 0;
//}

//L2-001
//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//using namespace std;
//const int maxn=600;
//const int INF=0x3f3f3f3f;
//int cost[maxn][maxn],dist[maxn],pre[maxn];
//bool vis[maxn];
//int safe[maxn],w[maxn],num[maxn];
//int n,m,s,d;
//vector<int>ve;
//void dijkstra(int s){
//    memset(dist, INF, sizeof(dist));
//    memset(vis, 0, sizeof(vis));
//    memset(pre, -1, sizeof(pre));
//    dist[s]=0;w[s]=safe[s];num[s]=1;
//
//    int v;
//    for(int j=0;j<n;j++){
//        int minn=INF;
//        for(int k=0;k<n;k++){
//            if(!vis[k]&&(dist[k]<minn)){//找到离s最近的未被访问过的一个点
//                v=k;
//                minn=dist[k];
//            }
//        }
//        vis[v]=1;//加入未访问的集合
//
//        for(int i=0;i<n;i++){
//            if(!vis[i]&&cost[i][v]!=INF){//有边且未加入最短集合中
//                if(dist[i]>dist[v]+cost[v][i]){
//                    dist[i]=dist[v]+cost[v][i];
//                    pre[i]=v;
//                    num[i]=num[v];
//                    w[i]=w[v]+safe[i];
//                }
//                else if(dist[i]==dist[v]+cost[v][i]){
//                    num[i]+=num[v];
//                    if(w[i]<w[v]+safe[i]){
//                        w[i]=w[v]+safe[i];
//                        pre[i]=v;
//                    }
//                }
//            }
//        }
//    }
////    while(1){
////        int v=-1;
////        for(int i=0;i<n;i++){
////            if(!vis[i]&&(v==-1||dist[i]<dist[v])){//找到离s最近的未被访问过的一个点
////                v=i;
////            }
////        }
////        if(v==-1)break;//如果每一个点都更新过了
////        vis[v]=1;//加入未访问的集合
////
////        for(int i=0;i<n;i++){
////            if(!vis[i]&&cost[i][v]!=INF){//有边且未加入最短集合中
////                if(dist[i]>dist[v]+cost[v][i]){
////                    dist[i]=dist[v]+cost[v][i];
////                    pre[i]=v;
////                    num[i]=num[v];
////                    w[i]=w[v]+safe[i];
////                }
////                else if(dist[i]==dist[v]+cost[v][i]){
////                    num[i]+=num[v];
////                    if(w[i]<w[v]+safe[i]){
////                        w[i]=w[v]+safe[i];
////                        pre[i]=v;
////                    }
////                }
////            }
////        }
////    }
//}
//
//int main(){
//    scanf("%d%d%d%d",&n,&m,&s,&d);
//    for(int i=0;i<n;i++){
//        scanf("%d",&safe[i]);
//    }
//    memset(cost,INF,sizeof(cost));
//    for(int i=0;i<m;i++){
//        int from,to,len;
//        scanf("%d%d%d",&from,&to,&len);
//        cost[from][to]=cost[to][from]=len;
//    }
//    dijkstra(s);
//    printf("%d %d\n",num[d],w[d]);
//    for(int i=d;i!=-1;i=pre[i]){
//        ve.push_back(i);
//    }
//    int n=ve.size();
//    for(int i=n-1;i>0;i--){
//        printf("%d ",ve[i]);
//    }
//    printf("%d\n",ve[0]);
//    return 0;
//}

//L2-002
//#include <iostream>
//#include <cstdio>
//#include <set>
//#include <queue>
//#include <cmath>
//#include <vector>
//#include <cstring>
//using namespace std;
//const int maxn=1e6+10;
//int key[maxn],nex[maxn];
//set<int>rem;
//vector<int>v;
//int main(){
//    int now,n;
//    scanf("%d%d",&now,&n);
//    for(int i=0;i<n;i++){
//        int add,k,n;
//        scanf("%d%d%d",&add,&k,&n);
//        key[add]=k;
//        nex[add]=n;
//    }
//
//    printf("%05d %d ",now,key[now]);
//    rem.insert(abs(key[now]));
//    while(now!=-1){
//        int tmp=nex[now];
//        if(tmp==-1){
//            break;
//        }
//        if(rem.find(abs(key[tmp]))!=rem.end()){
//            while(rem.find(abs(key[tmp]))!=rem.end()){
//                //                cout<<endl<<endl<<tmp<<endl;
//                v.push_back(tmp);
//                tmp=nex[tmp];
//                if(tmp==-1) break;
//            }
//            nex[now]=tmp;
//        }
//        if(tmp==-1){
//            break;
//        }
//        else printf("%05d\n%05d %d ",tmp,tmp,key[tmp]);
//        rem.insert(abs(key[tmp]));
//        now=tmp;
//    }
//    printf("-1\n");
//
//    int len=v.size();
//    if(len){
//        for(int i=0;i<len-1;i++){
//            printf("%05d %d %05d\n",v[i],key[v[i]],v[i+1]);
//        }
//        printf("%05d %d -1\n",v[len-1],key[v[len-1]]);
//    }
//    return 0;
//}
//

//L2-003
//#include <iostream>
//#include <algorithm>
//#include <iomanip>
//#include <cstdio>
//using namespace std;
//const int maxn=1e3+100;
//struct ty{
//    double yuan;
//    double t;
//}yb[maxn];
//
//bool operator<(ty a,ty b){
//    return a.yuan>b.yuan;
//}
//
//int main(){
//    int n;double m;
//    cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        cin>>yb[i].t;
//    }
//    for(int i=1;i<=n;i++){
//        cin>>yb[i].yuan;
//        yb[i].yuan=yb[i].yuan/yb[i].t;
//    }
//
//    sort(yb+1,yb+1+n);
//
//    double ans=0;int idx=1;
//    while(m>0&&idx<=n){
////        cout<<m<<" "<<yb[idx].t<<" "<<ans<<endl;
//        if(yb[idx].t>=m){
//            ans+=m*yb[idx].yuan;
//            m=0;
//        }
//        else{
//            ans+=yb[idx].t*yb[idx].yuan;
//            m-=yb[idx].t;
//        }
//        idx++;
//    }
//    printf("%.2lf\n",ans);
//    return 0;
//}

//L2-004
//子树对换，不是点对换
//#include <iostream>
//#include <cstdio>
//#include <vector>
//using namespace std;
//bool isMirror;
//vector<int> pre;
//vector<int> post;
//
//void getpost(int root, int tail) {
//    if(root > tail) return ;
//    int i = root + 1, j = tail;
//    if(!isMirror) {
//        while(i <= tail && pre[root] > pre[i]) i++;
//        while(j > root && pre[root] <= pre[j]) j--;
//    } else {
//        while(i <= tail && pre[root] <= pre[i]) i++;
//        while(j > root && pre[root] > pre[j]) j--;
//    }
//    if(i - j != 1) return ;
//    getpost(root + 1, j);///左
//    getpost(i, tail);///右
//    post.push_back(pre[root]);//中
//}
//
//int main() {
//    int n;
//    scanf("%d",&n);
//    pre.resize(n);
//    for(int i = 0; i < n; i++)
//        scanf("%d", &pre[i]);
//    getpost(0, n - 1);
//
//    if(post.size() != n) {
//        isMirror = true;
//        post.clear();
//        getpost(0, n - 1);
//    }
//
//    if(post.size() == n) {
//        printf("YES\n%d", post[0]);
//        for(int i = 1; i < n; i++)
//            printf(" %d", post[i]);
//    } else {
//        printf("NO");
//    }
//    return 0;
//}

//L2-005
//#include <iostream>
//#include <cstdio>
//#include <set>
//using namespace std;
//const int maxn=55;
//set<int>s[maxn];
//set<int>::iterator it;
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        s[i].clear();
//        int m;scanf("%d",&m);
//        for(int j=1;j<=m;j++){
//            int x;scanf("%d",&x);
//            s[i].insert(x);
//        }
//    }
//
//    int k;scanf("%d",&k);
//    for(int i=1;i<=k;i++){
//        int x,y;
//        scanf("%d%d",&x,&y);
//        int nc=0;
//        for(it=s[x].begin();it!=s[x].end();it++){
//            if(s[y].find(*it)!=s[y].end()){
//                nc++;
//            }
//        }
//        int nt=s[x].size()+s[y].size()-nc;
//        printf("%.2lf%%\n",1.0*nc/nt*100);
//    }
//    return 0;
//}

//L2-006
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//const int maxn=50;
//int mid[maxn],be[maxn];
//struct node{
//    int l,r;
//}a[maxn];
//
//int build(int la,int ra,int lb,int rb)//la,ra表示中序遍历 lb,rb表示后序遍历
//{
//    if(la>ra)
//        return 0;
//    int rt=be[rb],p1,cnt;
//    p1=la;
//    while(mid[p1]!=rt)    p1++;//在中序遍历中找到根节点
//    cnt=p1-la;
//    a[rt].l=build(la,p1-1,lb,lb+cnt-1);
//    a[rt].r=build(p1+1,ra,lb+cnt,rb-1);
//    return rt;
//}
//
//void bfs(int x)//层序遍历
//{
//    queue<int>q;
//    vector<int>v;
//    q.push(x);
//    while(!q.empty())
//    {
//        int w=q.front();
//        q.pop();
//        if(w==0)
//            break;
//        v.push_back(w);
//        if(a[w].l!=0)
//            q.push(a[w].l);
//        if(a[w].r!=0)
//            q.push(a[w].r);
//    }
//    int len=v.size();
//    for(int i=0;i<len-1;i++)
//        printf("%d ",v[i]);
//    printf("%d\n",v[len-1]);
//    return;
//}
//
//int main(){
//    int n,i,j;
//    cin>>n;
//    for(i=0;i<n;i++) scanf("%d",&be[i]);
//    for(i=0;i<n;i++) scanf("%d",&mid[i]);
//    build(0,n-1,0,n-1);
//    int root=be[n-1];
//    bfs(root);
//    return 0;
//}

//L2-007
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//const int maxn=11000;
//int vis[maxn],m[maxn];
//int p[10010];
//struct node{
//    double fz,area;
//    int id,num=0;
//};
//
//bool cmp(node a,node b){
//    if(a.area!=b.area)
//        return a.area>b.area;
//    return a.id<b.id;
//}
//
//void init(){
//    for(int i=0;i<=10000;i++)
//        p[i]=i;
//}
//
//int find(int x){
//    if(x==p[x])
//        return x;
//    else
//        return p[x]=find(p[x]);
//}
//
//void un(int a,int b){
//    int x=find(a);
//    int y=find(b);
//    if(x!=y){
//        if(x>y)
//            p[x]=y;
//        else
//            p[y]=x;
//    }
//}
//
//
//int main(){
//    int i,j,n;
//    node a[10005];
//    node b[10005];
//    node mul[10005];
//    cin>>n;
//    init();
//    memset(vis,0,sizeof(vis));
//    memset(m,0,sizeof(m));
//    for(i=0;i<n;i++){
//        int p1,p2,d,k;
//        cin>>a[i].id>>p1>>p2;
//        vis[a[i].id]=1;
//        if(p1!=-1){
//            un(p1,a[i].id);
//            vis[p1]=1;
//        }
//        if(p2!=-1){
//            un(p2,a[i].id);
//            vis[p2]=1;
//        }
//        cin>>k;
//        while(k--){
//            cin>>d;
//            if(d!=-1){
//                un(a[i].id,d);
//                vis[d]=1;
//            }
//        }
//        cin>>a[i].fz>>a[i].area;
//    }
//
//    for(i=0;i<n;i++){
//        int id=find(a[i].id);
//        mul[id].id=id;
//        mul[id].fz+=a[i].fz;
//        mul[id].area+=a[i].area;
//    }
//
//    for(i=0; i<10000; i++)
//        if(vis[i]){
//            mul[find(i)].num++;
//        }
//
//    int cnt=0;
//    for(i=0;i<10000;i++){
//        if(vis[i]){
//            int id=find(i);
//            if(!m[id]){
//                m[id]=1;
//                int x=mul[id].num;
//                b[cnt].fz=mul[id].fz*1.0/x;
//                b[cnt].area=mul[id].area*1.0/x;
//                b[cnt].id=id;
//                b[cnt++].num=x;
//            }
//        }
//    }
//
//    cout<<cnt<<endl;
//    sort(b,b+cnt,cmp);
//    for(i=0;i<cnt;i++)
//        printf("%04d %d %.3lf %.3lf\n",b[i].id,b[i].num,b[i].fz,b[i].area);
//    return 0;
//}
//

//L2-008
//forces
//#include <iostream>
//#include <cstdio>
//#include <string>
//using namespace std;
//int main(){
//    string s;
//    getline(cin,s);
//    int n=s.length();
//    int ans = 0;
//    for(int i=0;i<n;i++){
//        for(int j=0;i-j>=0&&i+j<n;j++){
//            if(s[i-j]!=s[i+j]){
//                break;
//            }
//            if(2*j+1>ans){
//                ans = 2*j+1;
//            }
//        }
//        for(int j=0;i-j>=0&&i+j+1<n;j++){
//            if(s[i-j]!=s[i+j+1]){
//                break;
//            }
//            if (2*j+2>ans){
//                ans=2*j+2;
//            }
//        }
//    }
//    printf("%d\n",ans);
//    return 0;
//}

//dp
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <string>
//#include <sstream>
//using namespace std;
//#define N 100000
//int p[N];
//char str[N];
//int main(){
//    gets(str);
//    int len=strlen(str);
//    for(int i=len;i>=0;i--){
//        str[i+i+2]=str[i];
//        str[i+i+1]='#';
//    }
//    str[0]='*';
//    int id=0, maxt=0;
//    for(int i=2;i<2*len+1;i++){
//        if(id+p[id]>i){
//            p[id]=min(p[id+id-i],p[id]+id-i);
//        }
//        else{
//            p[i]=1;
//        }
//        while(str[i-p[i]]==str[i+p[i]]) p[i]++;
//        if(i+p[i]>id+p[id])
//            id=i;
//        if(p[i]>=maxt)
//        {
//            maxt=p[i];
//        }
//    }
//    cout<<maxt-1<<endl;
//    return 0;
//}

//L2-009
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//const int maxn=1e4+100;
//const int INF=0x3f3f3f3f;
//struct ty{
//    double m=0;
//    int num=0;
//    int no=-1;
//}r[maxn];
//bool operator<(ty a,ty b){
//    if(a.m==b.m){
//        if(a.num==b.num){
//            return a.no<b.no;
//        }
//        else return a.num>b.num;
//    }
//    else return a.m>b.m;
//}
//
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        int k;scanf("%d",&k);
//        int tmp=0;
//        for(int j=1;j<=k;j++){
//            int n_i,p_i;
//            scanf("%d%d",&n_i,&p_i);
//            tmp+=p_i;
//            r[n_i].m+=1.0*p_i/100;
//            r[n_i].num++;
//            r[n_i].no=n_i;
//        }
//        r[i].m-=1.0*tmp/100;
//        r[i].no=i;
//    }
//    sort(r,r+maxn);
//    int idx=0;
//    while(idx<maxn){
//        if(r[idx].no==-1){
//            idx++;continue;
//        }
//        printf("%d %.2lf\n",r[idx].no,r[idx].m);
//        idx++;
//    }
//    return 0;
//}

//L2-010
//1表示是朋友，-1表示是死对头
//#include <iostream>
//#include <cstdio>
//using namespace std;
//const int maxn=200;
//int p[maxn];
//int M[maxn][maxn];
//void init(int n){
//    for(int i=0;i<n;i++)
//        p[i]=i;
//}
//
//int find(int x){
//    if(x==p[x])return x;
//    else return p[x]=find(p[x]);
//}
//
//void Union(int x,int y){
//    int a=find(x);int b=find(y);
//    if(a>b){
//        p[a]=b;
//    }
//    else p[b]=a;
//}
//
//int main(){
//    int n,m,k;
//    scanf("%d%d%d",&n,&m,&k);
//    init(n);
//    for(int i=0;i<m;i++){
//        int x,y,v;
//        scanf("%d%d%d",&x,&y,&v);
//        M[x][y]=M[y][x]=v;
//        if(v==1)
//            Union(p[x], p[y]);
//    }
//
//    for(int i=0;i<k;i++){
//        int a,b;
//        scanf("%d%d",&a,&b);
//        if(M[a][b]==1) printf("No problem\n");
//        else if(M[a][b]==-1){
//            if(find(a)==find(b))printf("OK but...\n");
//            else printf("No way\n");
//        }
//        else printf("OK\n");
//    }
//
//    return 0;
//}

//L2-011
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <queue>
//using namespace std;
//const int maxn=50;
//int mid[maxn],pos[maxn];
//struct node{
//    int l,r;
//}a[maxn];
//
//int build(int la,int ra,int lb,int rb)//la,ra表示中序遍历 lb,rb表示前序遍历
//{
//    if(la>ra)
//        return 0;
////    if(la==ra)return pos[lb];
//    int rt=pos[lb],p1,cnt;
////    cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<rt<<endl;
//    p1=la;
//    while(mid[p1]!=rt)    p1++;//在中序遍历中找到根节点
//    cnt=p1-la;
//    a[rt].r=build(la,p1-1,lb+1,lb+cnt);
//    a[rt].l=build(p1+1,ra,lb+cnt+1,rb);
//    return rt;
//}
//
//void bfs(int x)//层序遍历
//{
//    queue<int>q;
//    vector<int>v;
//    q.push(x);
//    while(!q.empty())
//    {
//        int w=q.front();
//        q.pop();
//        if(w==0)
//            break;
//        v.push_back(w);
//        if(a[w].l!=0)
//            q.push(a[w].l);
//        if(a[w].r!=0)
//            q.push(a[w].r);
//    }
//    int len=v.size();
//    for(int i=0;i<len-1;i++)
//        printf("%d ",v[i]);
//    printf("%d\n",v[len-1]);
//    return;
//}
//
//int main(){
//    int n,i,j;
//    cin>>n;
//    for(i=0;i<n;i++) scanf("%d",&mid[i]);
//    for(i=0;i<n;i++) scanf("%d",&pos[i]);
//    build(0,n-1,0,n-1);
//    int root=pos[0];
//    bfs(root);
//    return 0;
//}
//

//L2-012
//#include<iostream>
//#include<cstdio>
//#include <algorithm>
//#include <string>
//using namespace std;
//int a[1005];
//int location(int key){
//    int k=0;
//    while(a[k]!=key)k++;
//    return k;
//}
//
//int to_int(char s[]){
//    if(s[0]=='-'){
//        int temp=0;
//        for(int i=1;s[i]!=' '&&s[i]!='\0';i++)
//            temp=temp*10+s[i]-'0';
//        return -temp;
//    }else{
//        int temp=0;
//        for(int i=0;s[i]!=' '&&s[i]!='\0';i++)
//            temp=temp*10+s[i]-'0';
//        return temp;
//    }
//}
//
//int main(void){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    for(int i=0;i<n;i++){
//        scanf("%d",a+i);
//        int k=i;
//        while(k&&a[k]<a[(k-1)/2]){
//            swap(a[k],a[(k-1)/2]);
//            k=(k-1)/2;
//        }
//    }
//    while(m--){
//        bool flag;
//        string s;
//        int x;
//        scanf("%d",&x);
//        getline(cin,s);
//        if(s[4]=='t'&&s[8]=='r'){//root
//            if(a[0]==x)flag=1;
//            else flag=0;
//        }
//        else if(s[4]==' '){//siblings
//            int y=to_int(&s[5]);
//            int t=location(x);
//            if(t){
//                if(t&1){
//                    if(a[t+1]==y)flag=1;
//                    else flag=0;
//                }
//                else{
//                    if(a[t-1]==y)flag=1;
//                    else flag=0;
//                }
//            }
//            else flag=0;
//        }
//        else if(s[4]=='t'&&s[8]=='p'){//parent
//            int y=to_int(&s[18]);
//            int t=location(y);
//            if(t&&a[(t-1)/2]==x)flag=1;
//            else flag=0;
//        }
//        else if(s[4]=='a'){//child
//            int y=to_int(&s[15]);
//            int t=location(x);
//            if(t&&a[(t-1)/2]==y)flag=1;
//            else flag=0;
//        }
//        if(flag)printf("T\n");
//        else printf("F\n");
//    }
//    return 0;
//}
//

//L2-013
//#include <iostream>
//#include <cstdio>
//#include <set>
//#include <cstring>
//using namespace std;
//struct ty{
//    int x,y;
//}p[6000];
//int f[600];
//bool vis[600];
//set<int>city;
//void init(int n){
//    for(int i=0;i<n;i++){
//        f[i]=i;
//    }
//}
//
//int find(int x){
//    if(f[x]==x)return x;
//    else return f[x]=find(f[x]);
//}
//
//void Union(int a,int b){
//    int x=find(a);
//    int y=find(b);
//    if(x<y){
//        f[y]=x;
//    }
//    else{
//        f[x]=y;
//    }
//}
//
//int con_graph(int n){
//    int cnt=0;
//    for(int i=0;i<n;i++){
//        if(f[i]==i)
//            cnt++;
//    }
//    return cnt;
//}
//
//int main(){
//    int n,m;
//    scanf("%d%d",&n,&m);
//    init(n);
//    for(int i=0;i<m;i++){
//        int x,y;
//        scanf("%d%d",&x,&y);
//        p[i].x=x;p[i].y=y;
//        Union(x, y);
//    }
//
//    city.clear();
//    int cnt=con_graph(n);
//
//
//    memset(vis,0,sizeof(vis));
//    int k;scanf("%d",&k);
//    for(int i=0;i<k;i++){
//        init(n);
//        int x;scanf("%d",&x);
//        vis[x]=1;
//        for(int i=0;i<m;i++){
//            if(vis[p[i].x]||vis[p[i].y]){
//                continue;
//            }
//            else{
//                Union(p[i].x, p[i].y);
//            }
//        }
//        int nums=con_graph(n);
//        if(cnt==nums||cnt+1==nums){
//            cout<<"City "<<x<<" is lost."<<endl;
//        }
//        else{
//            cout<<"Red Alert: City "<<x<<" is lost!"<<endl;
//        }
//        cnt=nums;
//    }
//    int nums=0;
//    for(int i=0;i<n;i++){
//        if(vis[i]){
//            nums++;
//        }
//    }
//    if(nums==n){
//        cout<<"Game Over."<<endl;
//    }
//    return 0;
//}

//L2-014
//internet
//必须要车号大的先出，小的后出。所以列车排队的每一队必须是从大到小排列（从右往左看），才能保证开出去的车也是从大到小的。
//对于每一个想要进入并列铁轨的车，如果车号大于每一队的队尾的车号，说明不能进入已经有的队伍，必须进入新的铁轨
//否则，选择一个最接近它车号的尾部车号的队伍进入
//其实无需保存每一个并行队列的所有值，只需要保存当前队伍的车尾（就是每一列最左边 即 每一列的最小值）即可
//因为每一次都是需要排序比较大小的，所以用set自动排序
//首先把set里面放入一个0值。每一次set的最后一个值s.rbegin()都是当前所有队列队尾的最大值.
//如果当前想要进入排队队伍的t值比集合里面最大值小，就移除第一个比他大的值，然后把t插入集合中。表示的是将t值插入了最接近它车号的队伍的队尾
//否则就直接插入进去t值。作为新的队伍。
//s.upper_bound(t)返回的是第一个大于t的迭代器的位置
//在前面加星号表示取这个位置的值
//所以s.erase(*(s.upper_bound(t)));表示删除当前这个刚好大于t的位置处的值
//因为一开始插入了一个没有的0，所以最后输出是s.size()-1;
//#include <iostream>
//#include <set>
//using namespace std;
//int main() {
//    int n, t;
//    cin >> n;
//    set<int> s;
//    s.insert(0);
//    for(int i = 0; i < n; i++) {
//        cin >> t;
//        if(t < *s.rbegin()) {
//            s.erase(*(s.upper_bound(t)));
//        }
//        s.insert(t);
//    }
//    cout << s.size() - 1;
//    return 0;
//}

//internet
//由Dilworth定理（最小反链划分 == 最长链）可知最少的下降序列个数就等于整个序列最长上升子序列的长度
//这样求最长上升子序列长度即可
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <cstdlib>
//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <stack>
//#include <list>
//#include <algorithm>
//#include <map>
//#include <set>
//#define LL long long
//#define Pr pair<int,int>
//#define fread(ch) freopen(ch,"r",stdin)
//#define fwrite(ch) freopen(ch,"w",stdout)
//
//using namespace std;
//const int INF = 0x3f3f3f3f;
//const int msz = 10000;
//const int mod = 1e9+7;
//const double eps = 1e-8;
//
//int dp[111111];
//
//int main()
//{
//    //fread("");
//    //fwrite("");
//
//    int n,x;
//
//    scanf("%d",&n);
//    int len = 0;
//
//    while(n--)
//    {
//        scanf("%d",&x);
//        if(len == 0 || dp[len-1] <= x) dp[len++] = x;
//        else
//        {
//            int l = 0,r = len-1;
//
//            while(l <= r)
//            {
//                int mid = (l+r)/2;
//                if(dp[mid] <= x) l = mid+1;
//                else r = mid-1;
//            }
//
//            dp[l] = min(dp[l],x);
//        }
//    }
//
//    printf("%d\n",len);
//
//    return 0;
//}

//wrong
////下面这组样例就可以看出，5应该插在4之后更好
////9
////8 4 2 5 3 9 1 6 7
////1 1
////2 2
////3 3
////4 1 3
////5 1 3
////6 1 5
////7 4
////8 1 7
////9 1 8
////4
//#include <iostream>
//#include <cstdio>
//using namespace std;
//const int maxn=1e5+100;
//int dp[maxn];
//int train[maxn];
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i=1;i<=n;i++){
//        scanf("%d",&train[i]);
//    }
//
//    int cnt=0;
//    for(int i=1;i<=n;i++){
//        int j;
//        for(j=i-1;j>0;j--){
//            if(train[i]>train[j]){
//                dp[i]=dp[j];
//                cout<<i<<" 1 "<<j<<endl;
//                break;
//            }
//        }
//        if(!j){
//            dp[i]=++cnt;
//            cout<<i<<" "<<cnt<<endl;
//        }
//    }
//    cout<<cnt<<endl;
//    return 0;
//}

//L2-015
//#include <iostream>
//#include <algorithm>
//#include <cstdio>
//using namespace std;
//const int maxn=1e4+10;
//double grade[maxn];
//double orign[20];
//int main(){
//    int n,k,m;
//    cin>>n>>k>>m;
//    for(int i=0;i<n;i++){
//        double sum=0;
//        for(int j=0;j<k;j++){
//            cin>>orign[j];
//            sum+=orign[jaq2];
//        }
//        sort(orign,orign+k);
//        sum-=orign[0]+orign[k-1];
//        grade[i]=sum/(k-2);
//    }
//    sort(grade,grade+n);
//    for(int i=n-m;i<n-1;i++){
//        printf("%.3lf ",grade[i]);
//    }
//    printf("%.3lf\n",grade[n-1]);
//    return 0;
//}

//L2-016
//用exist数组标记是否存在这个结点，否则避免不小心把0压入。。。到队列里面（就是求对于一个父母，他们可能不存在在本人id里面，那么把他们的孩子结点放入queue里面就会出现0.。不断标记0的话把0当他们的共同祖先可能会误输出No）

//#include <iostream>
//#include <cstdio>
//#include <set>
//#include <queue>
//#include <cstring>
//using namespace std;
//const int maxn=1e6+10;
//struct ty{
//    char c;
//    int f,m;
//}pe[maxn];
//bool exist[maxn];
//int level[maxn];
//bool marry(int x,int y){
//    queue<int>q;
//    q.push(x);
//    q.push(y);
//    level[x] = 1;
//    level[y] = 1;
//    set<int>s;
//    while(!q.empty()){
//        int top=q.front();
//        q.pop();
//        int size=s.size();
//        s.insert(top);
//        if(size == s.size()) {
//            return false;
//        }
//        if(exist[top] == false) continue;
//        if(level[top] <= 4) {
//            int fa = pe[top].f;
//            int mo = pe[top].m;
//            if(fa != -1) {
//                q.push(fa);
//                level[fa] = level[top] + 1;
//            }
//            if(mo != -1) {
//                q.push(mo);
//                level[mo] = level[top] + 1;
//            }
//        }
//    }
//    return true;
//}
//
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        int x,y,z;char cc;
//        scanf("%d %c %d %d",&x,&cc,&y,&z);
//        pe[x].c=cc;pe[x].f=y;pe[x].m=z;
//        exist[x]=1;
//        if(y!=-1)pe[y].c='M';
//        if(z!=-1)pe[z].c='F';
//    }
//    int k;scanf("%d",&k);
//    for(int i=0;i<k;i++){
//        int x,y;
//        scanf("%d%d",&x,&y);
//        if(pe[x].c==pe[y].c){
//            printf("Never Mind\n");
//            continue;
//        }
//        else{
//            memset(level,0,sizeof(level));
//            if(marry(x, y))
//                printf("Yes\n");
//            else
//                printf("No\n");
//        }
//    }
//    return 0;
//}

//L2-017
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int maxn=1e5+10;
//ll pe[maxn];
//int main(){
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        cin>>pe[i];
//    }
//    sort(pe,pe+n);
//    int i=0,j=n-1;
//    ll tmp1=0,tmp2=0;
//    while(i<j){
//        tmp1+=pe[i++];
//        tmp2+=pe[j--];
//    }
//    if(i==j)tmp2+=pe[j];
//    cout<<"Outgoing #: "<<n-i<<endl;
//    cout<<"Introverted #: "<<i<<endl;
//    cout<<"Diff = "<<tmp2-tmp1<<endl;
//    return 0;
//}

//L2-018
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int maxn=1e5;
//double a[maxn],b[maxn],c[maxn];
//int maxa=0,maxb=0,na,nb;
//
//int main(){
//    cin>>na;
//    for(int i=0;i<na;i++){
//        int x;double y;
//        cin>>x>>y;
//        a[x]=y;
//        maxa=max(maxa,x);
//    }
//
//    cin>>nb;
//    for(int i=0;i<nb;i++){
//        int x;double y;
//        cin>>x>>y;
//        b[x]=y;
//        maxb=max(maxb,x);
//    }
//
//    for(int i=maxa;i>=maxb;i--){
//        c[i-maxb]=a[i]/b[maxb];
//        for(int j=maxb;j>=0;j--){
//            a[i-maxb+j]-=c[i-maxb]*b[j];
//        }
//    }
//
//    int cntc=0,cnta=0;
//    for(int i=maxa-maxb;i>=0;i--){
//        if(fabs(c[i])<0.05)continue;
//        cntc++;
//    }
//
//    for(int i=maxb;i>=0;i--){
//        if(fabs(a[i])<0.05)continue;
//        cnta++;
//    }
//
//    cout<<cntc;
//    if(cntc==0){
//        cout<<" 0 0.0";
//    }
//    else{
//        for(int i=maxa-maxb;i>=0;i--){
//            if(fabs(c[i])<0.05)continue;
//            printf(" %d %.1lf",i,c[i]);
//        }
//    }
//
//    cout<<endl<<cnta;
//    if(cnta==0){
//        cout<<" 0 0.0";
//    }
//    else{
//        for(int i=maxb;i>=0;i--){
//            if(fabs(a[i])<0.05)continue;
//            printf(" %d %.1lf",i,a[i]);
//        }
//        cout<<endl;
//    }
//
//    return 0;
//}

//L2-019
//#include <iostream>
//#include <cstdio>
//#include <set>
//#include <algorithm>
//#include <map>
//using namespace std;
//typedef long long ll;
//const int maxn=1e4+100;
//struct ty{
//    string name;
//    double nums;
//}a[maxn];
//set<string>gz;
//set<string>ans;
//set<string>::iterator it;
//bool operator<(ty a,ty b){
//    if(a.nums==b.nums)return a.name<b.name;
//    return a.nums>b.nums;
//}
//
//int main(){
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++){
//        string s;
//        cin>>s;
//        gz.insert(s);
//    }
//    int k;scanf("%d",&k);
//    double sum=0;
//    for(int i=0;i<k;i++){
//        cin>>a[i].name>>a[i].nums;
//        sum+=a[i].nums;
//    }
//    sum=sum/k;
//    sort(a,a+k);
//    for(int i=0;i<k;i++){
//        if(a[i].nums<=sum)break;
//        if(gz.find(a[i].name)==gz.end()){
//            ans.insert(a[i].name);
//        }
//    }
//    int len=ans.size();
//
//    if(len){
//        for(it=ans.begin();it!=ans.end();it++){
//            cout<<(*it)<<endl;
//        }
//    }
//    else{
//        cout<<"Bing Mei You"<<endl;
//    }
//    return 0;
//}

//L2-20
//#include <iostream>
//#include <vector>
//using namespace std;
//const int maxn=1e5+10;
//vector<int>v[maxn];
////vector<int>::iterator it; 不可用啊！！！
//int ddz[maxn];
//double sum=0;
//int n;double z,r;
//
//void dfs(int now,double gl){
////    cout<<now<<" "<<gl<<" "<<sum<<endl;
//    if(!v[now].size()){
//        sum+=gl*ddz[now];
//    }
//    else{
//        //dedao zhe gongli
//        int len=v[now].size();
//        for(int i=0;i<len;i++){
//            dfs(v[now][i], gl*r);
//        }
//    }
//    return ;
//}
//
//int main(){
//    cin>>n>>z>>r;
//    r=(100-r)/100;
//
//    for(int i=0;i<n;i++){
//        v[i].clear();
//        int k;cin>>k;
//        if(k==0){
//            int x;cin>>x;
//            ddz[i]=x;
//        }
//        for(int j=0;j<k;j++){
//            int x;cin>>x;
//            v[i].push_back(x);
//        }
//    }
//
//    dfs(0, z);
//    cout<<(int)sum<<endl;
//    return 0;
//}

//L2-021
//#include <iostream>
//#include <set>
//#include <map>
//#include <string>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int maxn=110;
//struct ty{
//    string name;
//    ll num=0;
//    double ave=0;
//    
//}pe[maxn];
//set<int>ss;
//bool operator<(ty a,ty b){
//    if(a.num==b.num){
//        return a.ave<b.ave;
//    }
//    else{
//        return a.num>b.num;
//    }
//}
//
//int main(){
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++){
//        string s;int k;
//        cin>>s>>k;
//        s.clear();
//        pe[i].num=0;
//        for(int i=0;i<k;i++){
//            ll x;cin>>x;
//            if(ss.find(x)==ss.end()){
//                ss.insert(x);
//
//            }
//        }
//    }
//}

