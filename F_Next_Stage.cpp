#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(rall(v));
    int last = 0;
    int i = 0;
    for(i = 0; i < n; i++) {
        k--;
        if(k == 0) break;
    }
    int ans = i;
    // dd(ans);
    for (int j = i+1; j < n; j++) {
        if(v[j] == v[i]) ans++;
    }
    cout << ans + 1<< endl;

}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
