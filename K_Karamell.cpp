
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;
const int M = 1e4+5;
int dp[100+5][M];
vector<vector<int>> track(100 + 5, vector<int>(M + 1, -1));

int sum = 0;


void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) sum += v[i];
    //  = 0;
    dp[0][0] = 1;
    
    if(sum & 1) {
        cout << -1 << endl; return;
    }
    sum/=2;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = true; 
        for (int j = 1; j <= M; ++j) {
            if (j >= v[i - 1] && dp[i - 1][j - v[i - 1]]) {
                dp[i][j] = true;
                track[i][j] = i - 1; 
            } 
            else if (dp[i - 1][j]) {
                dp[i][j] = true;
                track[i][j] = -1; 
            }
        }
    }
    if (!dp[n][sum]) {
        cout << -1 << endl;
        return;
    }
    // sum;
    vector<int> a, b;
    for (int i = n; i > 0 and sum > 0; --i) {
        if (track[i][sum] != -1) {
            a.push_back(v[track[i][sum]]);
            sum -= v[track[i][sum]];
        }
    }
    int j = 0;
    for (int i = n-1; i >= 0; i--) {
        if(j < a.size() and a[j] == v[i]) j++;
        else b.push_back(v[i]);
    }
    int acc = a[0];
    int i = 1; j = 0;
    cout << a[0] << " ";
    while(i < a.size() or j < b.size()) {
        if(acc > 0) {
            cout << b[j] << " ";
            acc -= b[j++];        
        }
        else {
            cout << a[i] << " ";
            acc += a[i++];
        }
    }
    cout << endl;

    // for (int num : a) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    // for (int num : b) {
    //         cout << num << " ";
    //     }
    //     cout << endl;
    return;
}

int main() {
    fastio;
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}

