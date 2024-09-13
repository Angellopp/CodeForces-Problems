#include <bits/stdc++.h>
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define print_v(x) cerr << #x << "[]: "; for (auto e : x) cerr << e <<" "; cerr << '\n'
#define RAYA cerr << string(15,'=')
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int MAXN = 4e5+5; 
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
// int get (int a) {
//     return getFT(a);
// }
// void update (int a, int b, int v) {
//     setFT(a, v);
//     setFT(b+1, -v);
// }



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector <pair<int,int>> v(n);
    vector<int> idx(n+1);
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        idx[i+1] = v[i].second;
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * getFT(idx[i]) * v[i-1].first;
        update(idx[i], 1);
    }
    for (int i = 0; i < MAXN; i++) FT[i] = 0;
    reverse(idx.begin()+1, idx.end());
    for (int i = 1; i <= n; i++) {
        ans -= 1ll * (i-1-getFT(idx[i])) * v[n-i].first;
        update(idx[i], 1);
    }   
    cout << ans << "\n";
    return 0;
}
