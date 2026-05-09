#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    // Ask for student name
    cout << "Enter student name: ";
    getline(cin, name);

    // Check for empty input
    if (name.empty()) {
        cout << "Name cannot be empty!" << endl;
        return 0;
    }

    // Store excuse templates
    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name}'s computer froze right before clicking the submit button.",
        "{name} accidentally deleted the assignment while cleaning the desktop.",
        "{name} spent hours on the homework until the power suddenly went out.",
        "{name}'s USB drive stopped working at the worst possible moment.",
        "{name} tried studying, but the browser somehow opened YouTube instead.",
        "{name} forgot the assignment because the alarm clock failed completely.",
        "{name}'s keyboard stopped typing right before the deadline."
    };

    // Seed random number generator
    srand(time(0));

    // Generate random index
    int randomIndex = rand() % excuses.size();

    // Select random excuse
    string excuse = excuses[randomIndex];

    // Replace {name} with actual input
    size_t pos = excuse.find("{name}");

    if (pos != string::npos) {
        excuse.replace(pos, 6, name);
    }

    // Display excuse
    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}