#include <iostream>
#include "stackt.h"

using namespace std;

// Function to implement the Towers of Hanoi
void TowersOfHanoi(int N, Stackt<int>& source, Stackt<int>& target, Stackt<int>& aux, int& moveCount, const string& sourceLabel, const string& targetLabel, const string& auxLabel) {
    if (N == 1) {
        int disk = source.pop();
        target.push(disk);
        cout << "Move disk 1 from " << sourceLabel << " to " << targetLabel << endl;
        moveCount++;
    }
    else {
        TowersOfHanoi(N - 1, source, aux, target, moveCount, sourceLabel, auxLabel, targetLabel);

        int disk = source.pop();
        target.push(disk);
        cout << "Move disk " << N << " from " << sourceLabel << " to " << targetLabel << endl;
        moveCount++;

        TowersOfHanoi(N - 1, aux, target, source, moveCount, auxLabel, targetLabel, sourceLabel);
    }
}

int main() {
    int N;
    cout << "THE TOWERS OF HANOI GAME \n";
    cout << "--------------------------------------\n\n";
    cout << "Enter the number of disks: ";
    cin >> N;

    Stackt<int> pegA(N);
    Stackt<int> pegB(N);
    Stackt<int> pegC(N);

    int moveCount = 0;
    char ch;

    cout << "\n\n-----------------------------------\n\n";
    cout << "Initial state:" << endl;
    cout << "Peg A: ";
    for (int i = N; i >= 1; i--) {
        pegA.push(i);
        cout << i << " ";
    }
    cout << "\n";

    cout << "Peg B: ";
    cout << "\n";

    cout << "Peg C: ";
    cout << "\n";

    cout << "-----------------------------------\n";

    TowersOfHanoi(N, pegA, pegC, pegB, moveCount, "Peg A", "Peg B", "Peg C");

    cout << "-----------------------------------\n";
    cout << "Final state:\n";
    cout << "Peg A: ";
    while (!pegA.isEmpty()) {
        cout << pegA.pop() << " ";
    }
    cout << "\n";

    cout << "Peg B: ";
    while (!pegB.isEmpty()) {
        cout << pegB.pop() << " ";
    }
    cout << "\n";

    cout << "Peg C: ";
    while (!pegC.isEmpty()) {
        cout << pegC.pop() << " ";
    }
    cout << "\n";

    cout << "Total moves needed: " << moveCount << "\n";
    
    cout << "Another round?  (Y/N)" << endl; 
    cin >> ch; 
    if (ch == 'Y' || ch == 'y') {
        main(); 
    }
    else { 
        cout << "Thank you for playing the game" << endl; 
        exit(0);
    }
    return 0;
}
