#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<iostream>
#include<vector>
#include<sstream>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
#define NM 100005
#define inf 10000005
typedef long long int ll;
using namespace std;
vector <int> adj[100005]; vector <pair<int,int> > v;
//map<pair<int,int>,int> ma;
int par[100005],val[100005],n,l,ma[100005];

void scanf_(int &num) {  
    char in;  
    bool neg=false;  
    while(((in=getchar()) > '9' || in<'0') && in!='-') ;  
    if(in=='-')  
    {  
        neg=true;  
        while((in=getchar()) >'9' || in<'0');  
    }  
    num=in-'0';  
    while(in=getchar(),in>='0'&&in<='9')  
        num*=10,num+=in-'0';  
    if(neg)  
        num=0-num;  
}  
  


/////////////////////////////////

vector <int> g[100005];
vector <int> tin, tout;
int timer;
vector <vector <int>> up;
void dfs (int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs (to, v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}




/////////////////////////////////


int dfs1(int i,int p){int j;
par[i]=p;
rep(j,adj[i].size()){
if(adj[i][j]!=p){
dfs1(adj[i][j],i);
}}
return 0;}

int rec(int i,int p){int ret=0,j;

//if(i==-1){return ;}

//if(mark[i]){return ;}

//mark[i]=1;
rep(j,adj[i].size()){
if(adj[i][j]!=p){
ret+=rec(adj[i][j],i);}}
ret+=val[i];
val[i]=ret;

return ret;}

int fck(int i,int p){int ret=0,j;

rep(j,adj[i].size()){
if(adj[i][j]!=p){
ret+=fck(adj[i][j],i);
}}
ret+=ma[i];      //assert(p==par[i]);
ma[(i)]=ret;//ma[mp(par[i],i)]=ret;
return ret;}




int main(){
int t,kase=0;
si(t);
while(t--){kase++;v.clear();


int i,j,k,m,z,x,y;


si(n);si(m);

rep(i,n){
ma[i]=0;val[i]=0;
adj[i].clear();

g[i].clear();
}

rep(i,n-1){
scanf_(x); scanf_(y);
x--;y--;
adj[x].push_back(y);adj[y].push_back(x);
g[x].push_back(y);g[y].push_back(x);
v.push_back(make_pair(x,y));
}

///////////////////////////////

tin.resize (n), tout.resize (n), up.resize (n);
    l = 1;
    while ((1 << l) <= n) ++ l;
    for (i = 0; i <n; i ++) up [i] .resize (l + 1);
    dfs (0);

///////////////////////////////

dfs1(0,-1);
char s[10];
rep(i,m){
scanf("%s",s);  
            scanf_(x); scanf_(y); scanf_(k);  x--;y--;z=lca(x,y);
//cout<<s;pn;
if(s[3]=='1'){
//cout<<z+1;pw;cout<<par[z]+1;pn;

val[z]-=k;

if(par[z]!=-1){val[par[z]]-=k;}

val[x]+=k;val[y]+=k;

}

else{
ma[z]-=2*k;//ma[mp(z,par[z])]-=2*k;
ma[x]+=k;//ma[mp(x,par[x])]+=k;
ma[y]+=k;//ma[mp(y,par[y])]+=k;
}
}

rec(0,-1);fck(0,-1);


//rep(i,lev.size()){if(mark[lev[i]]==0){sum1=0;sum2=0;rec(lev[i]);}}
printf("Case #%d:",kase);pn;
rep(i,n){
pi(val[i]);pw;}
pn;

rep(i,n-1){
if(par[v[i].first]==v[i].second){
pi(ma[v[i].first]);
}
else{
pi(ma[v[i].second]);}

pw;}

pn;}


return 0;}