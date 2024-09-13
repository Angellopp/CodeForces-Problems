




















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
    int n, k;
    cin>> n >> k;
    vector <int> v(n);
    string s;
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> s;
    s.push_back('1');
    n++;
    char curr = s[0];
    int l = 0, r = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == curr) {
            r++;
        }
        else {
            vector <int> aux(v.begin() + l, v.begin() + r);
            sort(rall(aux));
            for(int j = 0; j < min((int)aux.size(), k); j++) {
                sum += 1ll * aux[j];
            }
            curr = s[i];
            l = i;
            r = i+1;
        }
    }
    cout << sum << endl;
}
