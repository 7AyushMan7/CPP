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
ll par[N+1];
ll si[N+1];
ll ran[N+1];
ll paren(ll x){
    if (par[x]==x)
    {
        return x;
    }
    return par[x]=paren(par[x]);
    
}
void uni(ll x, ll y){
    ll a = paren(x);
    ll b=paren(y);
    if (a==b)
    {
        return; 
    }
    if (ran[a]>ran[b])
    {
       par[b]=a;
       si[a]+=si[b];
    }
    else if (ran[a]<ran[b])
    {
        par[a]=b;
        si[b]+=si[a];
    }
    else
    {
        ran[a]++;
        par[b]=a;
        si[a]+=si[b];
    }
    
    
    
 
    
}
int main()
{
    return 0;
}