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
const int MOD = 1e9+7; 

void solve() {
    string notas[12] = {"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"};
    int sum[6] = {2,4,5,7,9,11};
    vector<set<string>> mp(12);
    for(int i = 0; i < 12; i++) {
        mp[i].insert(notas[i]);
        for(int j = 0; j < 6; j++) {
            mp[i].insert(notas[(i+sum[j])%12]);
        }
    }
    int n, aux;
    cin >> n;
    set<string> se;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        aux--;
        se.insert(notas[aux%12]);
    } 
    bool can2 = 0;
    for(int i = 0; i < 12; i++) {
        bool can = 1;
        for(auto x : se) {
            if(mp[i].find(x) == mp[i].end()) can = 0;
        }
        if(can) {cout << notas[i] << endl; can2 = 1;return;}
    }
    if(!can2) cout << "desafinado" << endl;
}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
