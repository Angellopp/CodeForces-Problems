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

int main() {
    fastio;
    ll x, y, h, v, xd1, xd2;
    cin >> x >> y >> h >> v;

    ll ix = 0, iy = 0;
    vector <pair<ll, ll>> vp(h), otro(h);
    for (int i = 0; i < h; i++) {
        cin >> xd1 >> xd2;
        vp[i] = {xd1, xd2};
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < h; i++) {
        otro[i] = {vp[i].second, (i+1)};
    }
    sort(all(otro));

    for (int i = h-1; i >= 0; i--) {
        update(otro[i].second, 1);
        ix += 1ll * getFT(otro[i].second - 1);
        // cout << otro2[i].second << " ";
    }
    for (int i = 0; i < MAXN; i++) FT[i] = 0;

    vector <pair<ll, ll>> vp2(v), otro2(v);
    for (int i = 0; i < v; i++) {
        cin >> xd1 >> xd2;
        vp2[i] = {xd1, xd2};
    }
    sort(vp2.begin(), vp2.end());
    for (int i = 0; i < v; i++) {
        otro2[i] = {vp2[i].second, (i+1)};
    }
    sort(all(otro2));
    for (int i = v-1; i >= 0; i--) {
        update(otro2[i].second, 1);
        iy += 1ll * getFT(otro2[i].second - 1);
        // cout << otro2[i].second << " ";
    }
    // dbg(ix);
    // cout << "\n";

    cout << 1ll * (h+1) * (v+1) + ix + iy << "\n";
}