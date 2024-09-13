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

int main() {
    fastio;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int val = 0, las = 5e5+12;
    vector<pair<pair<int,int>, char>> qq(q);
    for(int i = 0; i < q; i++) {
        cin >> qq[i].F.F >> qq[i].F.S >> qq[i].S;
        if(qq[i].F.F == 1) {
            s[qq[i].F.S-1] = qq[i].S;
        }
        if(qq[i].F.F == 2) {val = 1; las = i;}
        if(qq[i].F.F == 3) {val = 2; las = i;}
    }
    for(int i = 0; i < n; i++) {
        if(val == 1) s[i] = tolower(s[i]);
        if(val == 2) s[i] = toupper(s[i]);
    }
    for(int i = las+1; i < q; i++) {    
        if(qq[i].F.F == 1) s[qq[i].F.S-1] = qq[i].S;
    }
    cout << s << endl;
}