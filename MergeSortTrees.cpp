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
const int N=1e5+1;
vector<int>seg[N*4+5];
vector<int>vp(N);
vector<int>star(N);
vector<int>subt(N);
//  vector<int>g[N];
void build(int node,int l,int r){
    //if range length is 1 there's only one element to add and no children
    if (l==r){
        seg[node].push_back(vp[l]);
        return;
    }int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    int i=0,j=0;
    // use two pointers to merge the two vectors in O(r-l+1)
    while (i<seg[node*2].size() && j<seg[node*2+1].size()){
        if (seg[node*2][i]<seg[node*2+1][j]) seg[node].push_back(seg[node*2][i++]);
        else seg[node].push_back(seg[node*2+1][j++]);
    }
    while (i<seg[node*2].size()) seg[node].push_back(seg[node*2][i++]);
    while (j<seg[node*2+1].size()) seg[node].push_back(seg[node*2+1][j++]);
    return;
}
//query
int query(int node,int l,int r,int lx,int rx,int x){
    //if outside -> 0
    if (l>rx || r<lx) return 0;
    //if inside do binary search
    if (l>=lx && r<=rx){
        int L=0,R=seg[node].size()-1,mid,ans=0;
        while (L<=R){
            mid=(L+R)/2;
            if (seg[node][mid]<x){
                ans=mid+1;
                L=mid+1;
            }else R=mid-1;
        }return ans;
    }
    int mid=(l+r)/2;
    return query(node*2,l,mid,lx,rx,x)+query(node*2+1,mid+1,r,lx,rx,x);
}
int cnt=1;
void dffs(int cur,int par,vector<vector<int>>&g){

    star[cur]=cnt;
    cnt++;
    int ans=1;
    for (auto val : g[cur])
    {
        if (val!=par)
        {
           dffs(val,cur,g);
           ans+=subt[val];
        }
        
    }
    subt[cur]=ans;

}
int main()
{
            ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
int q,j=0;
cin>>q;
// int arr[q];
while(q--){
      cnt=1;
    //   for (auto &val : g)
    //   {
    //     val.clear();
    //   }

       int n,quer;
       cin>>n>>quer;
    //    vector<int>vp(n+1,0);
        for(int i = 0; i <= 4 * n + 4; i++){
            seg[i].clear();
        }
      vector<vector<int>>g(n+1);
      

       for (int i = 0; i < n-1; i++)
       {
          int u,v;
          cin>>u>>v;
          g[u].push_back(v);
          g[v].push_back(u);
       }
    //    map<int,int>mp;
       for (int i = 1; i <= n; i++)
       {
          cin>>vp[i];
        //   mp[vp[i+1]]=i+1;
       }




       dffs(1,1,g);

       for (int i = 1; i <= n; i++)
       {
           vp[i]=star[vp[i]];
       }
       




       build(1,1,n);

       for (int i = 0; i < quer; i++)
       {
          int l,r,v;
          cin>>l>>r>>v;
          int last = star[v]+subt[v];
        //   cout<<star[v]<<" "<<subt[v]<<endl;
        // //   cout<<last<<endl;
        //   cout<<query(1,1,n,l,r,last)<<endl;

          int less1 = query(1,1,n,l,r,last)-query(1,1,n,l,r,star[v]);
          if (less1>0)
          {
            cout<<"YES"<<endl;
          }
          else
          {
            cout<<"NO"<<endl;
          }
          
          

       }
       cout<<endl;
       





       
       
                        
                              
// j++;
}
return 0;
}
