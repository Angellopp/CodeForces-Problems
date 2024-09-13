#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;

const int mod = 32768;
vector <int> dp(mod+10);
vector <bool> vis(mod+10);

void solve() {
    int n, aux;
    cin >> n;
    ll imp = 0 , acc = 0;    
    for (int i = 0; i < n; i++){
        cin >> aux; acc += aux;
        if (aux & 1) imp++;
        if (i == 0) {cout << aux << " "; continue;}
        cout << acc - imp/3 - ((imp%3 == 1) ? 1 : 0) << " ";
    }
    cout << endl;

}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}