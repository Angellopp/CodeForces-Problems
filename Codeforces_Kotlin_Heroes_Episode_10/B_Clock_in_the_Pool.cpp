#include <bits/stdc++.h>

using namespace std;

int main() {

    int tt;
    cin >> tt;
    while (tt--) {
        int k, n;
        cin >> k >> n;
        int div = n / k;
        if (div % 3 == 0) {
            cout <<  (div + 2) * k - n << endl;
        }
        else if (div % 3 == 1) {
            cout << (div + 1) * k - n << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}