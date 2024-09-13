#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

tuple<ll, ll, ll> gcdExtendedRecursive(ll a, ll b) {
    if (a == 0)
        return make_tuple(b, 0, 1);
    ll g, x1, y1;
    tie(g, x1, y1) = gcdExtended(b % a, a);
    ll x = y1 - (b / a) * x1;
    ll y = x1;
    return make_tuple(g, x, y);
}
tuple<ll, ll, ll> gcdExtendedIterative(ll a, ll b) {
    ll r0 = a, r1 = b, s0 = 1, t0 = 0, s1 = 0, t1 = 1;
    int i = 1;
    while (r1 != 0) {
        
    }
    if (a == 0)
        return make_tuple(b, 0, 1);
    ll g, x1, y1;
    tie(g, x1, y1) = gcdExtended(b % a, a);
    ll x = y1 - (b / a) * x1;
    ll y = x1;
    return make_tuple(g, x, y);
}

int main() {
    fastio;
    ll a, b;
    cin >> a >> b;
    ll gcd = __gcd(a, b);
    // cout << gcd << "\n";
    if(abs(gcd) > 2*1ll) {
        cout << "-1\n";
        return 0;
    }
    else {
        a *= -1ll;
        ll a_ = a / abs(gcd);
        ll b_ = b / abs(gcd);
        ll g, x, y;
        tie(g, x, y) = gcdExtendedRecursive(b_, a_);
        x /= g; y /= g;
        if (abs(gcd) == 1LL) {
            x*=(2 * 1ll) ; y*= (2 * 1ll);
        }
        cout << x << " " << y << "\n";
    }
    
}