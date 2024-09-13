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

int  pow(string a) {
    int A= 0, B = 0;
    for(int i = 0; i < a.size(); i++) {
        int n = a[i] - '0';
        int M = a[i] - 'A';
        int m = a[i] - 'a';
        if(m >= 0) A += (m + 10);
        else if(M >= 0) A += (M + 10)*2;
        else if(n >= 0) A += (n);
        // dbg(A);
    }
    return A;
}

int main() {
    fastio;
    string a, b;
    cin >> a >> b;
    int A = pow(a);
    int B = pow(b);
    if(A  > B) cout << "Ana " << A << "\n";
    else cout << "Carolina " << B << "\n" ;
}