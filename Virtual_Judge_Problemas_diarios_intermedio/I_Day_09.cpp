#include <bits/stdc++.h>
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define print_v(x) cerr << #x << "[]: "; for (auto e : x) cerr << e <<" "; cerr << '\n'
#define RAYA cerr << string(15,'=')
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int MAXN = 4e5+5;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x0, y0, xt, yt;
    cin >> n >> x0 >> y0 >> xt >> yt;
    vector <pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(all(v));
    for (auto x : v) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
