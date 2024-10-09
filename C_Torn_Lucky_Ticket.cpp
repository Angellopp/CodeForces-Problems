#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20,'=') << endl << endl;
#define ll long long 
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    vector<vector<vector<vector<int>>>> pre(6,vector<vector<vector<int>>>(6, vector<vector<int>>(46, vector<int>(46,0))));
    vector<vector<vector<vector<int>>>> suf(6,vector<vector<vector<int>>>(6, vector<vector<int>>(46, vector<int>(46,0))));
    for (int i = 0; i < n; i++) {
        cin >> s;
        int acc = 0, sum = 0;
        for (auto& c : s) sum += (c-'0');
        for (int j = 0; j < s.size(); j++) {
            acc += (s[j] - '0');
            pre[s.size()][j+1][acc][sum]++;
        }
        acc = 0;
        for (int j = s.size()-1; j >= 0; j--) {
            acc += (s[j] - '0');
            suf[s.size()][s.size()-j][acc][sum]++;
        }
    }    
    ll ans = 0;
    for (int i = 1; i <= 5; i++) {
        for(int j = (((i%2)^1) + 1); j <= 5; j+=2) {
            int mid = (i+j) / 2;
            if (i == j) {
                for(int k = 0; k < 46; k++) {
                    int s1 = pre[i][i][k][k];
                    ans += 1ll * s1 * s1 ;
                }
            }
            else if(i < j) {
                for(int k = 0; k < 46; k++) {
                    for(int l = 0; l <= k; l++) {
                        int s2 = suf[j][mid][l][k];
                        ans += pre[i][i][max(0,2*l-k)][max(0,2*l-k)] * s2;
                    }
                }
            }
            else {
                for(int k = 0; k < 46; k++) {
                    for(int l = 0; l <= k; l++) {
                        int s2 = pre[i][mid][l][k];
                        ans += pre[j][j][max(0,2*l-k)][max(0,2*l-k)] * s2;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int tt = 1;
    while(tt--) {
        solve();
    }
}