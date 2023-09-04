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
const int N=2e5;
const int lg=20;
vector<int>tree[N];
int up[N][lg];
void binlift(int src,int par){
    up[src][0]=par;
    for (int i = 1; i < 20; i++)
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
    for (int i = 19; i >= 0; i--)
    {
        if (jump>=(1<<i))
        {
           return ans_query(up[node][i],jump-(1<<i));
        }
        
    }
    
}

int main()
{
    return 0;
}