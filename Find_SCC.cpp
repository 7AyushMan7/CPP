void dfs(ll node, vector<ll> &vis, vector<ll> adj[],
         stack<ll> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}
void dfs3(ll node, vector<ll> &vis, vector<ll> adjT[],vector<ll>&v)
{
    vis[node] = 1;
    v.push_back(node);
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adjT,v);
        }
    }
}
ll kosaraju(ll V, vector<ll> adj[],vector<vector<ll> >&v)
{
    vector<ll> vis(V, 0);
    stack<ll> st;
    for (ll i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    vector<ll> adjT[V];
    for (ll i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            // i -> it
            // it -> i
            adjT[it].push_back(i);
        }
    }
    ll scc = 0;
    vector<ll>vx;
    while (!st.empty())
    {
        ll node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            
            dfs3(node, vis, adjT,vx);
            v.push_back(vx);
            while (vx.sz>0)
            {
                vx.pop_back();
            }
            
        }
    }
    return scc;
}
