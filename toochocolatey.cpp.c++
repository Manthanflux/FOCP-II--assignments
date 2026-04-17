#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

string solve(int N, vector<int>& A) {
    // Sort in descending order
    sort(A.begin(), A.end(), greater<int>());

    unordered_set<int> used;
    long long alex = 0, bob = 0;

    bool turn = true; // true = Alex, false = Bob

    for (int i = 0; i < N; i++) {
        if (used.count(A[i])) continue;

        if (turn) {
            alex += A[i];
        } else {
            bob += A[i];
        }

        used.insert(A[i]);
        turn = !turn; // switch turn
    }

    if (alex > bob) return "Alex";
    else return "Bob";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << solve(N, A) << "\n";
    }

    return 0;
}