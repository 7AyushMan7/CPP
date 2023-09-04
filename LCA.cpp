#include <bits/stdc++.h>
#define ll long long int
#define srv(v) sort(v.begin(),v.end())
#define rrv(s1) sort(s1.begin(),s1.end(),greater()<int>)
#define str string
#define sz size()
#define dv(v) vector<ll> v
#define ds(s) set<ll> s
#define dm(mp) map<ll,ll> mp
#define MOD 1000000007
using namespace std;
const int N=2e5+1;
const int lg=20;
// always make sure that 2^(lg-1)>=N
vector<int>tree[N];
int up[N][lg];
int lvl[N];
void binlift(int src,int par){
    up[src][0]=par;
    for (int i = 1; i < lg; i++)
    {
        if (up[src][i-1]!=-1)
        {
            up[src][i]=up[up[src][i-1]][i-1];
        }
        else
        {
            up[src][i]=-1;
        } 
    }
    for (auto val : tree[src])
    {
        if (val!=par)
        {
           binlift(val,src);
        }
        
    }  
}
int ans_query(int node,int jump){
    if(node==-1||jump==0){
        return node;
    }
    for (int i = lg-1; i >= 0; i--)
    {
        if (jump>=(1<<i))
        {
           return ans_query(up[node][i],jump-(1<<i));
        }
        
    }
    
}
void dfs(int src,int par,int lev){
    lvl[src]=lev;
    for (auto val : tree[src])
    {
        if (val!=par)
        {
            dfs(val,src,lev+1);
        }
        
    }
    
}
int LCA(int u,int v){
    if(lvl[u]<lvl[v]){
        swap(u,v);
    }
    u=ans_query(u,lvl[u]-lvl[v]);
    if(u==v){
        return u;
    }
    for (int i = lg-1; i >=0; i--)
    {
       if (up[u][i]!=up[v][i])
       {
          u=up[u][i];
          v=up[v][i];
       }
       
    }
    return ans_query(u,1);
    
}
int main()
{
    int n,q;
    cin>>n>>q;
    // vector<int>v;
    for (int i = 0; i < n-1; i++)
    {
        int x;
        cin>>x;
        // v.push_back(x);
        tree[x].push_back(i+2);
        tree[i+2].push_back(x);

    }
    memset(up,-1,sizeof(up));
    binlift(1,-1);
    dfs(1,-1,1);


    for (int i = 0; i < q; i++)
    {
       int x,k;
       cin>>x>>k;
       cout<<LCA(x,k)<<endl;
    }
    
    
    
    return 0;
}
