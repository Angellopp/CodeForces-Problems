    #include <bits/stdc++.h>
    #define all(x) begin(x), end(x)
    #define rall(x) rbegin(x), rend(x)
    // #define endl '\n';
    #define dd(x) cerr << #x << "=" << x << "." << endl;
    #define ll long long
    using namespace std;

    const int maxn = 1e3+3;
    vector <vector<char>> v(maxn, vector<char> (maxn));
    int n;

    void solve() {
        int n, m; cin >> n >> m;
        int t, a, p;
        t = a = p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        for (int j = m-1; j >= 2; j--) {
            for (int i = n-1; i >= 0; i--) {
                if(v[i][j] == '#') {
                    // cout <<endl<< i << " "<< j << endl;
                    if (i+1 < n and v[i][j-1] == '#' and v[i+1][j-1] == '#') {
                        t++;
                        v[i][j] = '.';
                        v[i][j-1] = '.';
                        v[i][j-2] = '.';
                        v[i+1][j-1] = '.';
                        v[i+2][j-1] = '.';
                        v[i+3][j-1] = '.';
                        v[i+4][j-1] = '.';
                    }
                    else if (v[i][j-1] == '.') {
                        a++;
                        v[i][j] = '.';
                        v[i-1][j] = '.';
                        v[i-2][j] = '.';
                        v[i-3][j] = '.';
                        v[i-4][j] = '.';
                        v[i][j-2] = '.';
                        v[i-1][j-2] = '.';
                        v[i-2][j-2] = '.';
                        v[i-3][j-2] = '.';
                        v[i-4][j-2] = '.';
                        v[i-2][j-1] = '.';
                        v[i-4][j-1] = '.';
                    }
                    else {
                        p++;
                        v[i][j] = '.';
                        v[i-1][j] = '.';
                        v[i-2][j] = '.';
                        v[i][j-1] = '.';
                        v[i-2][j-1] = '.';
                        v[i-1][j-2] = '.';
                        v[i-2][j-2] = '.';
                        v[i][j-2] = '.';
                        v[i+1][j-2] = '.';
                        v[i+2][j-2] = '.';
                    }
                }
            }
        }
        cout << t << " " << a << " " << p << endl; 

    }

    int main() {
        int tt = 1;
        // cin >> tt;
        while(tt--) {
            solve();
        }
    }