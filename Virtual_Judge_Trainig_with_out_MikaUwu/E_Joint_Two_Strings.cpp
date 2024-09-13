#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

ll f (string &t, string &s) {
    ll cont = 0;
    for(int i = 0; i < (int)t.size(); i++){
        if ((int)s.size() <= cont) return cont;
        if (s[cont] == t[i]) cont++;
    }
    return cont++;
}   

int main() {
    fastio;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector <string> v(n+5);
    vector <ll> pre(n+5), suf(n+5);
    vector <ll> acc(n+5);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
        pre[i] = f(v[i], s);
        // cout << pre[i] << "\n";
    }
    reverse(all(s));
    for (int i = 1; i <= n; i++) {
        reverse(all(v[i]));
        suf[i] = f(v[i], s);
        // cout << suf[i] << "\n";
        acc[suf[i]]++;
    }
    // sort(all(suf));

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int dif = (int)s.size() - pre[i];
        for (int j = max(0, dif); j <= (int)s.size(); j++){
            ans += 1ll * acc[j];
        }
    }
    cout << ans << "\n";


  


    
}