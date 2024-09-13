#include <bits/stdc++.h>
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define print_v(x) cerr << #x << "[]: "; for (auto e : x) cerr << e <<" "; cerr << '\n'
#define RAYA cerr << string(15,'=')
using namespace std;
typedef long long ll;
const int maxn = 5000+7;
double dp[maxn][maxn];
double ans[maxn];
int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision (10);
    cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <double> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin()+1, v.end(), [] (double a, double b) { return a > b;});
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = dp[i-1][i-1] * v[i];
        dp[i][0] = dp[i-1][0] * (1.0 - v[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j] * (1.0 - v[i]) + v[i] * dp[i-1][j-1];
        }
    }
    double xd = 0;
    for (int i = k; i <= n; i++) {
        for (int j = i; 2*j >= (i + k) ; j--) {
            ans[i] += dp[i][j];
        }
        xd = max(xd, ans[i]);
    }
    cout << xd << "\n";
    return 0;
}
