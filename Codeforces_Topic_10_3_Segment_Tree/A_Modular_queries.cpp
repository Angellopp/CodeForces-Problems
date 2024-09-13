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

const int maxn = 1e5 + 5;
 
int m;
int a[maxn];
int t[4 * maxn];
 
int f(int a, int b) {
    return a * 1ll * b % m;
}
 
int neutro = 1;

// O(n)
void build(int v, int tl, int tr) {
    // Llega a una hoja
    if(tl == tr) {
        t[v] = a[tl]; // T[v] es el valor de mi nodo
        return;
    }
    else {
        int tm = (tl+tr)/2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);
        t[v] = f(t[v * 2], t[v * 2 + 1]);
    }
}
 
// O(logn)
void update(int v, int tl, int tr, int pos, int new_value) {
    if(tl == tr) {
        t[v] = new_value;
        return;
    }
    else {
        int tm = (tl+tr) >> 1;
 
        if(pos > tm) update(v * 2 + 1, tm+1, tr, pos, new_value);
        else update(v * 2, tl, tm, pos, new_value);
 
        t[v] = f(t[v * 2], t[v * 2 + 1]);
    }
}
 
// O(logn)
int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return neutro;
    if(l == tl and r == tr) {
        return t[v];
    } 
    else {
        int tm = (tl + tr) >> 1;
 
        // [tl, tm] intersectado [l, r]
        int valL = query(v * 2, tl, tm, l, min(r, tm));
 
        // [tm+1, tr] intersectado [l, r]
        int valR = query(v * 2 + 1, tm+1, tr, max(l, tm+1), r);
 
        return f(valL, valR);
    }
}
 
int main() {
    fastio;
    int n; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);
 
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 0) {
            int p, r; cin >> p >> r;
            p--;
 
            update(1, 0, n-1, p, r);
        }
        else {
            int l, r; cin >> l >> r; l--; r--;
            cout << query(1, 0, n-1, l, r) << "\n";
        }
    }
 
    return 0;
}