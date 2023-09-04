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
const int MAXN = 1e6+10;
int t[4*MAXN];
// vector<int>vz(20,0);
void build(vector<int>&a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void update(int v, int tl, int tr, int pos, int new_val) { // set v to 1 while building, tl and tr should be 0 based indices
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm){
            update(v*2, tl, tm, pos, new_val);
        }
        else{
            update(v*2+1, tm+1, tr, pos, new_val);
        }
        t[v] = t[v*2] + t[v*2+1];
    }
}
 
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    
 
    return 0;
}
