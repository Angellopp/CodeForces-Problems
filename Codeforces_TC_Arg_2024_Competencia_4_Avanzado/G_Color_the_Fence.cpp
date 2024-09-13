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


int main() {
    fastio;
    int v;
    cin >> v;
    vector <int> n(10);
    for (int i = 1; i < 10; i++) cin >> n[i];
    int mn = 1e7;
    for (int i = 9; i >= 1; i--) {
        mn = min(mn, n[i]);
    }
    if(v / mn == 0) {
        cout << -1 << endl;
        return 0;
    }
    string s;
    int c;
    for (int i = 9; i >= 1; i--) {
        if(mn == n[i]) {
            for(int j = 0; j < v / mn; j++) s.push_back('0'+i);
            c = i;
            break;
        }
    }
    int res = v % n[c];
    for (int j = 0; j < s.size(); j++) {
        if(res < 1) break;
        for(int i = 9; i > c; i--) {
            if(res - n[i] + n[c] >= 0ll) {
                s[j] = '0' + i;
                res = res - n[i] + n[c];
                break;
            }
        }
    }
    cout << s;

}
