#include "bits/stdc++.h"
using namespace std;
// long long power(long long x, long long y, long long p)       // use when below doesnt work
// {
 
//     // Initialize answer
//     long long res = 1;
 
//     // Check till the number becomes zero
//     while (y > 0) {
 
//         // If y is odd, multiply x with result
//         if (y % 2 == 1)
//             res = (res * x)%p;
 
//         // y = y/2
//         y = y >> 1;
 
//         // Change x to x^2
//         x = (x * x)%p;
//     }
//     return res % p;
// }
unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; 
 
    x = x % p; 
 
    while (y > 0) 
    {
     
        if (y & 1)
            res = (res * x) % p;
 
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}
 
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}

unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
#define MAXN 100001
int spf[MAXN];
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)
		spf[i] = i;
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAXN; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}
vector<int> getFactorization(int x)
{
	vector<int> ret;
	while (x != 1) {
		ret.push_back(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

int main(int argc, char const* argv[])
{

	sieve();
	
	return 0;
}
