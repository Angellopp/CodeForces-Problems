#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

void solve() {
    ll n;
    cin >> n;
    // cout << n;
    vector <int> div;
    for (int i = 2; i*i < min(1ll*1000000, n); i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n=n/i;
        }
        if(cnt > 0) div.emplace_back(cnt);
    }
    if(n > 1) div.emplace_back(1);
    int ans = 1;
    for(int i = 0 ; i < div.size(); i++) {
        ans *= 2;
    }
    ans -= div.size()+1;
    cout << ans << endl;

}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

void solve() {
    ll n;
    cin >> n;
    // cout << n;
    vector <int> div;
    for (int i = 2; i*i < min(1ll*1000000, n); i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n=n/i;
        }
        if(cnt > 0) div.emplace_back(cnt);
    }
    if(n > 1) div.emplace_back(1);
    int ans = 1;
    for(int i = 0 ; i < div.size(); i++) {
        ans *= 2;
    }
    ans -= div.size()+1;
    cout << ans << endl;

}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
