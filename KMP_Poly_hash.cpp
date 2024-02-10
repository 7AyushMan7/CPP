/*

  for KMP rolling hash over subtring check this out: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
  note that the mod taken should be a prime greater than n square...simultaneously, u need to make sure that overflow does not happen
  u can use the rolling hash for substrings (MAYBE), can do this by divinding the whole thingy by base (maths!), use mod inverse for division






*/



#include <bits/stdc++.h>
#define ll long long int
#define srv(v) sort(v.begin(),v.end())
#define rrv(s1) sort(s1.begin(),s1.end(),greater()<int>)
#define str string
#define sz size()
#define dv(v) vector<ll> v
#define ds(s) set<ll> s
#define dm(mp) map<ll,ll> mp
#define MOD 999999999999989        //this value matters along with base
using namespace std;
const int N=1e6+5;
ll base=612;
ll km[N];
map<ll,ll>mp;
int main()
{
    ll n;
    cin>>n;
    vector<str>v;
    str x;
    km[0]=1;
    for (ll i = 1; i <N; i++)   // building kmp array
    {
        km[i]+=(km[i-1]*base);
        km[i]%=MOD;
    }
    for (int i = 0; i < n; i++)
    {
       cin>>x;
       v.push_back(x);
       ll h=0;
        for (int ii = 0; ii < x.sz; ii++)    // this stores the hashes of all prefixes of all the input strings in the map
        {
            h+=(km[ii]*x[ii]);
            h%=MOD;
            mp[h]++;
        }
    }
    for (auto val : v)
    {
        ll h=0;
        int cnt=0;
        for (int i = val.sz - 1; i >= 0; i--)
        {
            
            h+=(km[cnt]*val[i]);
            h%=MOD;                // here, for different "i", "h" is the hash of all the suffixes of string val
        }
        
        
    }

    return 0;
}
