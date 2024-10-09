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


const int MAXN = 2e5+5; 
int dif[MAXN]{};

void solve() {
    int n;
    cin >> n;   
    vector <pair<int,int>> v(n);
    for (int i = 0; i <n; i++) {
        cin >> v[i].ff; v[i].ss = i;
    }
    sort(rall(v));
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(v[i].ss);
        auto it = s.find(v[i].ss);
        if (it != s.begin()) {
            auto o = prev(it);
            dif[*o+1]++;
            dif[v[i].ss+1]--;
        }
        else {
            dif[1]++;
            dif[v[i].ss+1]--;
        }
    }
    int acc = 0;
    for(int i = 1; i <= n; i++) {
        acc += dif[i];
        cout << acc << " ";
    }
    cout << endl;
    
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}