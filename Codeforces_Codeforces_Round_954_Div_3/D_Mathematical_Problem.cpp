#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int ev(const string& s) {
    stack<int> nn;
    stack<char> op;

    int num = 0;
    bool can = 0;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            can = 1;
        } 
        else if (ch == '+' || ch == '*') {
            if (can) {
                nn.push(num);
                num = 0;
                can = 0;
            }
            while (!op.empty() && op.top() == '*') {
                int r = nn.top(); nn.pop();
                int l = nn.top(); nn.pop();
                nn.push(l * r);
                op.pop();
            }
            op.push(ch);
        }
    }
    if (can) {
        nn.push(num);
    }

    while (!op.empty()) {
        char ope = op.top(); op.pop();
        int r = nn.top(); nn.pop();
        int l = nn.top(); nn.pop();
        if (ope == '+') nn.push(l + r);
        else if (ope == '*') nn.push(l * r);
    }

    return nn.top();
}

int sol(string s) {
    int ans = 1e9+1;
    int n = s.size();
    for(int j = 0; j < n-1; j++) {
        string ns;
        for (int i = 0; i < n-1; i++) {
            ns.push_back(s[i]);
            if (i == j) continue;
            ns.pb('+');
        }
        ns.pb(s.back());
        for (int i = 1; i+1 < ns.size(); i++) {
            if(ns[i] == '+') {
                if (i == 1) {if(ns[0] == '1') ns[i] = '*';}
                else if (i == ns.size()-2 and ns.back() == '1') ns[i] = '*';  
                else if (ns[i-1] == '1' and !isdigit(ns[i-2])) ns[i] = '*';
            }
            
        }
        ans = min(ans, ev(ns));
    }
    return ans;
}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        int n;
        string s;
        cin >> n >> s;
        bool had0 = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '0') had0 = 1;
        }
        if(n == 2) {
            cout << stoi(s) << endl;
            continue;
        }
        if(n==3 and had0) {
            if (s[0] == '0' or s[2] == '0') {
                cout << 0 << endl;
            }
            else {
                int n1 = s[0]-'0', n2 = s[2] - '0';
                cout << min ({n1 + n2, n1 * n2}) << endl;
            }
            continue;
        }
        if(had0) {
            cout << 0 << endl;
            continue;
        }
        
        int sol1 = sol(s);
        // reverse(all(s));
        // int sol2 = sol(s);
        cout << min(sol1, sol1) << endl;
        // int ans = 1e9+1;
        // for(int j = 0; j < n-1; j++) {
        //     string ns;
        //     for (int i = 0; i < n-1; i++) {
        //         ns.push_back(s[i]);
        //         if (i == j) continue;
        //         ns.pb('+');
        //     }
        //     ns.pb(s.back());
        //     for (int i = 1; i+1 < ns.size(); i++) {
        //         if(ns[i] == '+') {
        //             if (i == 1) {if(ns[0] == '1') ns[i] = '*';}
        //             else if (i == ns.size()-2 and ns.back() == '1') ns[i] = '*';  
        //             else if (ns[i-1] == '1' and !isdigit(ns[i-2])) ns[i] = '*';
        //         }
                
        //     }
        //     ans = min(ans, ev(ns));
        //     // cerr << ns << endl;
        // }
        // cout << ans << endl;
    }

    return 0;
}
