#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    cout << "Enter student name: ";
    getline(cin, name);

    // Handle empty input
    if(name.empty()) {
        cout << "Name cannot be empty!" << endl;
        return 0;
    }

    // Excuse templates
    vector<string> excuses = {
        "{name} couldn't attend class because the Wi-Fi stopped working.",
        "{name}'s laptop battery died during the online exam.",
        "{name} forgot the homework because the dog hid the notebook.",
        "{name} was late because the alarm clock betrayed them.",
        "{name}'s brain was still loading on Monday morning.",
        "{name} tried to study, but YouTube distracted them.",
        "{name} accidentally submitted the wrong file.",
        "{name}'s internet disappeared at the worst possible moment.",
        "{name} couldn't finish the assignment because of a 'technical issue'.",
        "{name}'s printer jammed right before submission."
    };

    // Random seed
    srand(time(0));

    // Random index
    int randomIndex = rand() % excuses.size();

    // Get random excuse
    string excuse = excuses[randomIndex];

    // Replace placeholder
    size_t pos = excuse.find("{name}");
    if(pos != string::npos) {
        excuse.replace(pos, 6, name);
    }

    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}