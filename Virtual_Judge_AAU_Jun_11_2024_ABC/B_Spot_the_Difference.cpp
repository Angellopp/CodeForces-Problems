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
using namespace std;

int main() {
    fastio;
    int n;
    cin >> n;
    char a[101][101], b[101][101];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin >> b[i][j];
    }
    int aux = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if(a[i][j] != b[i][j]) {
                cout << i+1 << " " << j+1 << "\n";
                return 0;
            }
        } 
    }

}