#include <bits/stdc++.h>
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define print_v(x) cerr << #x << "[]: "; for (auto e : x) cerr << e <<" "; cerr << '\n'
#define RAYA cerr << string(15,'=')
#define all(x) x.begin(), x.end()
#define ll long long
using namespace std;
const int MAXN = 1e5+5; 
int FT[ MAXN ]{};
int getFT (int b){
    int v = 0;
    for (int x = b; x; x -= x & -x) v += FT[x];
    return v;
}
void setFT (int p, int v) {
    for (int x = p; x < MAXN; x += x & -x) FT[x] += v;
}
int get (int a, int b) { return getFT(b) - getFT(a-1); }
void update (int x, int v) { setFT(x, v); }

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, aux;
    cin >> n;
    vector <int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    vector <int> pre(n+1), suf(n+1);

    for (int i = n; i >= 1; i--) {
        suf[i] = getFT(v[i]-1);
        // suf[i] = get(1, v[i]-1);
        update(v[i], 1);
    }
    for (int i = 0; i <= n+1; i++) FT[i] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = i - getFT(v[i]) - 1;
        // pre[i] = get(v[i]+1, n);
        update(v[i], 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * pre[i] * suf[i];
    }
    cout << ans << "\n";

    return 0;
}
