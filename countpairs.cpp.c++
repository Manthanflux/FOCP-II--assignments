#include <iostream>
using namespace std;

const int MAXN = 10000000;

int spf[MAXN + 1];  // smallest prime factor
int distinctPrimeCount[MAXN + 1];

void computeSPF() {
    for (int i = 1; i <= MAXN; i++) {
        spf[i] = i;
    }

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { // prime
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void computeDistinctPrimes() {
    distinctPrimeCount[1] = 0;

    for (int i = 2; i <= MAXN; i++) {
        int x = i;
        int count = 0;

        while (x > 1) {
            int p = spf[x];
            count++;
            while (x % p == 0) {
                x /= p;
            }
        }

        distinctPrimeCount[i] = count;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    computeSPF();
    computeDistinctPrimes();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = distinctPrimeCount[n];
        int ans = 1 << k;  // 2^k

        cout << ans << '\n';
    }

    return 0;
}