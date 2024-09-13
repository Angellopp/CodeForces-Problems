#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;

// const int N = 2e6 + 5;
// const int MOD = 1e9 + 7;
const int N = 1e5+5;
// const int INF = 1e9;
// vector <int> dp(N);

void solve() {
    int n, m; cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
		a[i] = n;
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--;y--;
		if (x > y) swap(x, y);
		a[x] = min(a[x], y);
	}
    
	int r = n;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		r = min(r, a[i]);
		ans += r - i;
	}
	cout << ans << endl;
}

int main() {
    fastio;
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}

