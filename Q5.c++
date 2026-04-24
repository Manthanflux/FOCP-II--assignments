#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings; // movieId -> set of userIds
    unordered_map<int, int> available; // movieId -> available tickets

public:
    bool book(int user, int movie) {
        // initialize movie if not present
        if (available.find(movie) == available.end()) {
            available[movie] = 100;
        }

        // already booked
        if (bookings[movie].count(user)) {
            return false;
        }

        // no tickets left
        if (available[movie] == 0) {
            return false;
        }

        bookings[movie].insert(user);
        available[movie]--;
        return true;
    }

    bool cancel(int user, int movie) {
        if (bookings[movie].count(user) == 0) {
            return false;
        }

        bookings[movie].erase(user);
        available[movie]++;
        return true;
    }

    bool isBooked(int user, int movie) {
        return bookings[movie].count(user) > 0;
    }

    int availableTickets(int movie) {
        if (available.find(movie) == available.end()) {
            return 100;
        }
        return available[movie];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.availableTickets(Y) << endl;
        }
    }

    return 0;
}