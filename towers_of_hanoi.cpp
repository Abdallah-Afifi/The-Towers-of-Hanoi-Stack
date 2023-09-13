#include <iostream>
#include "stackt.h"

using namespace std;

// Function to implement the Towers of Hanoi
void TowersOfHanoi(int N, Stackt<int>& source, Stackt<int>& target, Stackt<int>& aux, int& moveCount, const string& sourceLabel, const string& targetLabel) {
    if (N == 1) {
        int disk = source.pop();
        target.push(disk);
        cout << "Move disk " << disk << " from " << sourceLabel << " to " << targetLabel << endl;
        moveCount++;
    } else {
        TowersOfHanoi(N - 1, source, aux, target, moveCount, sourceLabel, targetLabel);

        int disk = source.pop();
        target.push(disk);
        cout << "Move disk " << disk << " from " << sourceLabel << " to " << targetLabel << endl;
        moveCount++;

        TowersOfHanoi(N - 1, aux, target, source, moveCount, sourceLabel, targetLabel);
    }
}

int main() {
    int N;
    cout << "Enter the number of disks: ";
    cin >> N;

    Stackt<int> pegA(N);
    Stackt<int> pegB(N);
    Stackt<int> pegC(N);

    int moveCount = 0;

    cout << "-----------------------------------" << endl;
    cout << "Initial state:" << endl;
    cout << "Peg A: ";
    for (int i = N; i >= 1; i--) {
        pegA.push(i);
        cout << i << " ";
    }
    cout << endl;

    cout << "Peg B: ";
    cout << endl;

    cout << "Peg C: ";
    cout << endl;

    cout << "-----------------------------------" << endl;

    TowersOfHanoi(N, pegA, pegC, pegB, moveCount, "Peg A", "Peg C");

    cout << "-----------------------------------" << endl;
    cout << "Final state:" << endl;
    cout << "Peg A: ";
    while (!pegA.isEmpty()) {
        cout << pegA.pop() << " ";
    }
    cout << endl;

    cout << "Peg B: ";
    while (!pegB.isEmpty()) {
        cout << pegB.pop() << " ";
    }
    cout << endl;

    cout << "Peg C: ";
    while (!pegC.isEmpty()) {
        cout << pegC.pop() << " ";
    }
    cout << endl;

    cout << "Total moves needed: " << moveCount << endl;

    return 0;
}
