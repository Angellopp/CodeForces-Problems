




















#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

const int maxn = 1e5+3;

int main() {
    fastio;
    int n;
    cin >> n;
    vector <int> v(2*n);
    vector <vector<int>> pos(2*n+1);
    for (int i = 0; i < 2*n; i++) cin>> v[i];
    for (int i = 0; i < 2*n; i++) {
        pos[v[i]].push_back(i);
    }
    pos[0].push_back(0);
    pos[0].push_back(0);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int d1 = abs(pos[i][0] - pos[i-1][0]) + abs(pos[i][1] - pos[i-1][1]);
        int d2 = abs(pos[i][0] - pos[i-1][1]) + abs(pos[i][1] - pos[i-1][0]);
        sum += 1ll * min(d1,d2); 
    }
    cout << sum << endl;

}
