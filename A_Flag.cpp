#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int INF = 1e9;

pair<int,int> lis(string const& a) {
    int n = a.size();
    vector<int> d(n+1, INF);
    vector<int> ind(n+1, 0);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]-'A') - d.begin();
        if (d[l-1] <= (a[i]-'A') && (a[i]-'A') <= d[l])
            d[l] = a[i]-'A';
            ind[l] = i;
    }
    pair<int,int> ans;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = {l, ind[l]};
    }
    return ans;
}


void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<char> letras = {'A', 'B', 'C', 'D'};
    sort(letras.begin(), letras.end());
    int ans = 1e9;
    do {
        vector <char> aux = letras;
        vector <int> val(4, 0);
        for (int i = 0; i < 4; i++) {
            val[aux[i]-'A'] = i;
        }
        // for (int i = 0; i < 4; i++) {
        //     cout << val[i] << " ";
        // }
        // cout <<endl;
        string cp = s;
        for (int i = 0; i < n; i++) {
            cp[i] = 'A' + val[s[i]-'A'];
        }
        for (int i = 0; i < n; i++) {
            cout << cp[i];
        }
        cout << endl;

        pair<int,int> ind = lis(cp);
        int acc = 0;
        for (int i = ind.ss; i < n; i++) {
            if (s[i] == letras[0]) acc++;
        }
        ans = min(ans, n - ind.ff - acc);

        for (char letra : aux) {
            cout << letra << " ";
        }
        cout << " -> " << ind.ff << " " << ind.ss << " " << acc << endl; 

    } while (next_permutation(letras.begin(), letras.end()));
    cout << ans << endl;
}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

