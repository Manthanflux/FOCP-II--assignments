#include <iostream>
#include <string>
using namespace std;

bool canTurnOff(string &bulbs, int n, int m, int k) {
    int operations = 0;

    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            operations++;
            if (operations > m) return false;
            i += k;  // skip k bulbs
        } else {
            i++;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n, ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, m, mid)) {
            ans = mid;
            right = mid - 1; // try smaller k
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}