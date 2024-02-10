const ll maxn = 1e6 + 10;
ll seg[maxn * 4];
ll lazy[maxn * 4];
void build(vector<ll> &a, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        seg[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2 + 1, tl, tm);
        build(a, v * 2 + 2, tm + 1, tr);
        seg[v] = seg[v * 2 + 1] + seg[v * 2 + 2];
    }
}
void upd(ll ind, ll low, ll high, ll l, ll r, ll val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];

        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (r < low || l > high || low > high)
    {
        return;
    }
    if (low >= l && high <= r)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }
    ll mid = (low + high) >> 1;
    upd(2 * ind + 1, low, mid, l, r, val);
    upd(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
}
ll query1(ll ind, ll low, ll high, ll l, ll r, ll val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] += (high - low + 1) * lazy[ind];

        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if (r < low || l > high || low > high)
    {
        return 0;
    }
    if (low >= l && high <= r)
    {
        return seg[ind];
    }
    ll mid = (low + high) >> 1;
    return query1(2 * ind + 1, low, mid, l, r, val) + query1(2 * ind + 2, mid + 1, high, l, r, val);
}
