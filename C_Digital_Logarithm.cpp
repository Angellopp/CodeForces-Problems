#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

int f(int n) {
    int ans = 0;
    while(n) {
        n/=10;
        ans++;
    }
    return ans;
}

void solve() {
    int n, xd;
    cin >> n;
    vector <int> va(n), vb(n), nca(10,0), ncb(10,0);
    map<int,int> a, b;
    int ans = 0;
    for (int i = 0; i < n; i++) {cin >> va[i]; a[va[i]]++;}
    for (int i = 0; i < n; i++) {cin >> vb[i]; b[vb[i]]++;}
    for(auto& x : a) nca[f(x.ff)]++;
    for(auto& x : b) ncb[f(x.ff)]++;
    for(auto x : va) {
        int fx = f(x);
        if(b[x]) {a[x]--; b[x]--; nca[fx]--; ncb[fx]--;}
    }
    for(auto x : va) {
        int fx = f(x);
        if(a[x] and b[fx]) {ans++; b[fx]--; a[x]--; ncb[f(fx)]--; nca[fx]--;}
    }
    for(auto x : vb) {
        int fx = f(x);
        if(b[x] and a[fx]) {ans++; b[x]--; a[fx]--; ncb[f(fx)]--; nca[f(fx)]--;}
    }
    vector <int> cnca = nca;
    vector <int> cncb = ncb;
    map<int,int> ca = a;

    for(auto x : va) {
        int fx = f(x);
        if(ca[x]) {
            if(cncb[fx]) {ca[x]--; cncb[fx]--;}
        }
    }
    for(auto x : va) {
        if(ca[x]) {
            if(1 < x and x < 10) ans++;
            else if(x >= 10) ans+=2;
        }
    }
    for(auto x : vb) {
        int fx = f(x);
        if(b[x]) {
            if(nca[fx]) {b[x]--; nca[fx]--;}
        }
    }
    for(auto x : vb) {
        if(b[x]) {
            if(1 < x and x < 10) ans++;
            else if(x >= 10) ans+=2;
        }
    }
    int acc = 0;
    // for(int i = 0; i < 10; i++) acc += ncb[i];
    dd(acc);
    


    dd(ans);
    cout << ans + 4*acc << endl;

}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    // tt =1;
    while(tt--) {
        solve();
    }
}

/*
75019 709259 5 611271314 9024533 81871864 9 3 6 4865
9503 2 371245467 6 7 37376159 8 364036498 52295554 169
1234 4
4  

*/