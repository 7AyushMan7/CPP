                                        //Your worst fear owns this
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
 
int q,j=0;
cin>>q;
int arr[q];
while(j<q){


    int n;
    cin>>n;
    vector<int>g[n+1];
    int ind[n+1];
    memset(ind,0,sizeof(ind));
    for (int i = 0; i < n; i++)
    {
       int x,y;
       cin>>x>>y;
       g[x].push_back(y);
       g[y].push_back(x);
       ind[x]++;
       ind[y]++;
    }
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        if (ind[i]==1)
        {
           q.push(i);
           ind[i]--;
        }
    }
    while (q.sz>0)
    {
        int t = q.front();
        q.pop();
        for (auto val : g[t])
        {
            ind[val]--;
            if (ind[val]==1)
            {
                q.push(val);
            }
        }
        
    }

    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if (ind[i]>1)
        {
           cnt++;
        }
        
    }
    cout<<cnt<<endl;
    
    
    
    
    
                        
                              
j++;
}
return 0;
}