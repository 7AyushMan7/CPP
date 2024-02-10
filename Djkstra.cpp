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
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<pair<ll,ll> >g[n+1];
    for (int i = 0; i < n-1; i++)     // note that here the graph has only n-1 edges, u may need to change that accordingly
    {
       ll x,y,w;
       cin>>x>>y>>w;
       g[x].push_back(make_pair(y,w));      // this should be changed depending on whether the graph is directed or undirected
       g[y].push_back(make_pair(x,w));

    }
    multiset<pair<ll,ll> >ml;
    ll maxi = 1e18;
    vector<ll>dis(n+1,maxi);   // maxi can be changed depending on ll/int
    dis[1]=0;    // djkstra starting from the node 1

    ml.insert(make_pair(0,1));
    while (ml.sz>0)
    {
        pair<ll,ll>p1 = *(ml.begin());
        ml.erase(ml.begin());
        for (auto val : g[p1.second])
        {
            if (dis[val.first]>(val.second+p1.first))
            {
               dis[val.first]=(val.second+p1.first);
               ml.insert(make_pair(dis[val.first],val.first));
            }
            
        }
        
    }
    cout<<dis[n]<<endl;
    
    

    return 0;
}
