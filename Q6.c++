#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Bank {
private:
    unordered_map<int, long long> accounts;

public:
    bool create(int user, long long amount) {
        if (accounts.find(user) == accounts.end()) {
            accounts[user] = amount;
            return true;
        } else {
            accounts[user] += amount;
            return false;
        }
    }

    bool debit(int user, long long amount) {
        if (accounts.find(user) == accounts.end() || accounts[user] < amount) {
            return false;
        }
        accounts[user] -= amount;
        return true;
    }

    bool credit(int user, long long amount) {
        if (accounts.find(user) == accounts.end()) {
            return false;
        }
        accounts[user] += amount;
        return true;
    }

    long long balance(int user) {
        if (accounts.find(user) == accounts.end()) {
            return -1;
        }
        return accounts[user];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "DEBIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CREDIT") {
            int X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.balance(X) << endl;
        }
    }

    return 0;
}