#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long
#define double long double
using namespace std;

int n, k;

int f(int n) {
    if(n == 1) return 0;
    if(n <= k) return 1;
    int rep = min((n+k-1)/k, k);
    return (1 + (rep - 1) + f(k + n - rep*k));
}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        cin >> n >> k;
        cout << f(n) << endl;
    }
}