vector<ll> vpr(n, -1);
stack<ll> se;
se.push(0);

for (ll i = 1; i < n; i++)
{
    while (se.sz > 0 && v[se.top()] > v[i])
    {
        se.pop();
    }
    if (se.sz > 0)
    {
        vpr[i] = se.top();
    }
    se.push(i);
}
