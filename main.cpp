#include <iostream>
using namespace std;

int main() {
    int age;
    double interPercent, testPercent;
    int streamChoice, programChoice;
    char nonLocal;

    cout << "=========================================\n";
    cout << " University Admission Eligibility System \n";
    cout << "=========================================\n\n";

    // Input
    cout << "Enter age: ";
    cin >> age;

    cout << "Enter Intermediate percentage (0-100): ";
    cin >> interPercent;

    cout << "Enter Entry Test percentage (0-100): ";
    cin >> testPercent;

    cout << "\nSelect your stream:\n";
    cout << "1. Pre-Engineering\n";
    cout << "2. ICS\n";
    cout << "3. Pre-Medical\n";
    cout << "4. Commerce\n";
    cout << "5. Arts\n";
    cout << "Enter choice (1-5): ";
    cin >> streamChoice;

    cout << "\nAre you Non-Local? (Y/N): ";
    cin >> nonLocal;

    cout << "\nSelect the program you want to apply for:\n";
    cout << "1. Computer Science (CS)\n";
    cout << "2. Engineering\n";
    cout << "3. BBA\n";
    cout << "4. Arts\n";
    cout << "Enter choice (1-4): ";
    cin >> programChoice;

    cout << "\n-----------------------------------------\n";

    // Basic eligibility check
    bool eligible = true;

    if (age < 17) {
        eligible = false;
        cout << "Not eligible: Age must be 17 or above.\n";
    }
    if (interPercent < 50) {
        eligible = false;
        cout << "Not eligible: Intermediate percentage must be at least 50%.\n";
    }
    if (testPercent < 40) {
        eligible = false;
        cout << "Not eligible: Entry test percentage must be at least 40%.\n";
    }

    if (!eligible) {
        cout << "\nFinal Status: NOT ELIGIBLE TO APPLY.\n";
        cout << "-----------------------------------------\n";
        return 0;
    }

    cout << "Basic Eligibility: ELIGIBLE TO APPLY.\n\n";

    // Program-wise selection
    bool selected = false;
    bool streamOk = true;   // used to explain stream mismatch

    if (programChoice == 1) { // CS
        // Stream must be ICS or Pre-Engineering
        if (!(streamChoice == 2 || streamChoice == 1)) {
            streamOk = false;
        }
        if (streamOk && interPercent >= 60 && testPercent >= 50) {
            selected = true;
        }

        cout << "Applied Program: Computer Science (CS)\n";
        if (!streamOk) {
            cout << "Selection Result: NOT SELECTED (Stream not eligible for CS).\n";
            cout << "Required Stream: ICS or Pre-Engineering.\n";
        }
        else if (!selected) {
            cout << "Selection Result: NOT SELECTED (Merit criteria not met).\n";
            cout << "Required: Inter >= 60% AND Test >= 50%.\n";
        }
        else {
            cout << "Selection Result: SELECTED.\n";
        }
    }
    else if (programChoice == 2) { // Engineering
        // Stream must be Pre-Engineering
        if (streamChoice != 1) {
            streamOk = false;
        }
        if (streamOk && interPercent >= 65 && testPercent >= 55) {
            selected = true;
        }

        cout << "Applied Program: Engineering\n";
        if (!streamOk) {
            cout << "Selection Result: NOT SELECTED (Only Pre-Engineering students can apply).\n";
        }
        else if (!selected) {
            cout << "Selection Result: NOT SELECTED (Merit criteria not met).\n";
            cout << "Required: Inter >= 65% AND Test >= 55%.\n";
        }
        else {
            cout << "Selection Result: SELECTED.\n";
        }
    }
    else if (programChoice == 3) { // BBA
        // Stream must be Commerce or Arts
        if (!(streamChoice == 4 || streamChoice == 5)) {
            streamOk = false;
        }
        if (streamOk && interPercent >= 55 && testPercent >= 45) {
            selected = true;
        }

        cout << "Applied Program: BBA\n";
        if (!streamOk) {
            cout << "Selection Result: NOT SELECTED (Stream not eligible for BBA).\n";
            cout << "Required Stream: Commerce or Arts.\n";
        }
        else if (!selected) {
            cout << "Selection Result: NOT SELECTED (Merit criteria not met).\n";
            cout << "Required: Inter >= 55% AND Test >= 45%.\n";
        }
        else {
            cout << "Selection Result: SELECTED.\n";
        }
    }
    else if (programChoice == 4) { // Arts
        // Any stream allowed, only merit check
        if (interPercent >= 50 && testPercent >= 40) {
            selected = true;
        }

        cout << "Applied Program: Arts\n";
        if (!selected) {
            cout << "Selection Result: NOT SELECTED (Merit criteria not met).\n";
            cout << "Required: Inter >= 50% AND Test >= 40%.\n";
        }
        else {
            cout << "Selection Result: SELECTED.\n";
        }
    }
    else {
        cout << "Invalid program choice.\n";
        cout << "-----------------------------------------\n";
        return 0;
    }

    // Merit category
    if (selected) {
        if (interPercent >= 80 && testPercent >= 70) {
            cout << "Merit Category: OPEN MERIT\n";
        }
        else if (interPercent >= 60 && testPercent >= 50) {
            cout << "Merit Category: SELF FINANCE\n";
        }
        else {
            // selected but lower category condition not met (rare due to criteria),
            // still keep a safe output
            cout << "Merit Category: SELECTED (Category not assigned)\n";
        }
    }
    else {
        cout << "Merit Category: NOT SELECTED\n";
    }

    // Hostel eligibility (simple)
    if (nonLocal == 'Y' || nonLocal == 'y') {
        cout << "Hostel Status: Eligible (Non-Local)\n";
    }
    else if (nonLocal == 'N' || nonLocal == 'n') {
        cout << "Hostel Status: Not Eligible (Local)\n";
    }
    else {
        cout << "Hostel Status: Unknown (Invalid input)\n";
    }

    cout << "-----------------------------------------\n";
    cout << "Program finished.\n";

    return 0;
}
