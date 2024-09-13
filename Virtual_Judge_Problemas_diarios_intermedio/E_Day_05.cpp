#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    ll sum = 0;
    vector <ll> v(n+1,0);
    for (int i = 0; i < n; i++) {
        cin >> v[i+1];
        sum += v[i+1];
    }
    sort(v.begin(), v.end());
    ll v2 = 2*abs(v[1] - v[2]);
    ll s1 = 0, s2 = -v[1];
    for(int i = 3; i <= n; i++) {
        s1 += v[i]*(i-1);
    }
    for(int i = 1; i < n; i++) {
        s2 += v[i]*(n-i);
    }
    ll num = sum + v2 + (s1 - s2) * 2;
    ll den = n;
    ll gcd = __gcd(num, den);
    cout << num / gcd << " " << den / gcd << "\n";
    return 0;
}
			   	   	  				    			  			