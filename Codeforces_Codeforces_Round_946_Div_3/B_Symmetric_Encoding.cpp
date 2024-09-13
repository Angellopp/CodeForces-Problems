#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

int main() {
    fastio;
    int tt;
    cin  >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set <char> st;
        for (int i = 0; i < n; i++) st.insert(s[i]);
        map<char, int> v;
        map<int, char> vv;
        int cnt = 0;
        for (auto x : st) {
            vv[cnt] = x;
            v[x] = cnt;
            cnt++;
        }
        for (int i = 0; i < n; i++ ){
            int ind = v[s[i]];
            cout << vv[cnt - ind - 1];
        }
        cout << '\n';
    }
}