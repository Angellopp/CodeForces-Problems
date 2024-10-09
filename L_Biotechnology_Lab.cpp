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
const int mx = 3e6+3; 
// const int mx = ; 
typedef std::size_t length_t, position_t;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = s[i] - 'a'+1;
    }
    bitset<mx> ter;
    bitset<mx> total;

    total.set(position_t(v[0]), true);
    ter.set(position_t(v[0]), true);
    int accumulated_shift = 0;
    
    for (int i = 1; i < n; i++) {
        accumulated_shift += v[i];
        ter <<= v[i];
        ter.set(position_t(v[i]), true);
        total |= ter;
    }
    cout << total.count() << endl;
}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
