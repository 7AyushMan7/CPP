const int MAX_N = 200005;
const int LOG = 18;
ll m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
ll bin_log[MAX_N];
 
ll query(ll L, ll R) { // O(1)
	ll length = R - L + 1;
	ll k = bin_log[length];
	return max(m[L][k], m[R-(1<<k)+1][k]);
}
void spx(ll n,vector<ll>a){
    	bin_log[1] = 0;
	for(ll i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	for(ll i = 0; i < n; i++) {
		m[i][0] = a[i];
	}
	// 2) preprocessing, O(N*log(N))
	for(ll k = 1; k < LOG; k++) {
		for(ll i = 0; i + (1 << k) - 1 < n; i++) {
			m[i][k] = max(m[i][k-1], m[i+(1<<(k-1))][k-1]);
		}
	}
}
