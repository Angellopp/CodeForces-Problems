#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

int sqrt(int x) {
    int left = 1, right = x, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (1ll*mid * mid <= x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        ll p, q;
        cin >> p >> q;
        int div = __gcd(p, q);
        p /= div;
        q /= div;
        if (p < q) swap(p, q);
        if(p-2*q < 0) {
            cout << 0 << " " << 0 << nn;
            continue;
        }

        int x1 = sqrt(p-2*q);
        int x2 = sqrt(p+2*q);
        // uu(x1);
        // uu(x2);
        if(x1 * x1 == p-2*q and x2 * x2 == p+2*q) {
            cout << (x1 + x2) / 2<< " " << (-x1 + x2) / 2 << nn;
        }
        else cout << 0 << " " <<0 << nn;


    }
    return 0;
}