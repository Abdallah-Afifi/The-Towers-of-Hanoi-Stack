#include <iostream>
#include "Stackt.h"

void towersOfHanoi(int n, Stackt<int>& source, Stackt<int>& target, Stackt<int>& aux) {
    if (n == 1) {
        int disk = source.top();
        source.pop();
        target.push(disk);
        std::cout << "Move disk " << disk << " from Source to Target directly" << std::endl;
    } else {
        towersOfHanoi(n - 1, source, aux, target);

        int disk = source.top();
        source.pop();
        target.push(disk);
        std::cout << "Move disk " << disk << " from Source to Target directly" << std::endl;

        towersOfHanoi(n - 1, aux, target, source);
    }
}

int main() {
    int numDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    Stackt<int> pegA(numDisks);
    Stackt<int> pegB(numDisks);
    Stackt<int> pegC(numDisks);

    // Initialize peg A with disks in descending order
    for (int i = numDisks; i >= 1; --i) {
        pegA.push(i);
    }

    std::cout << "Initial State:" << std::endl;
    // Display the initial state of the pegs
    std::cout << "Peg A: ";
    for (int i = 0; i < numDisks; ++i) {
        std::cout << pegA.top() << " ";
        pegA.pop();
    }
    std::cout << std::endl;

    std::cout << "Peg B: " << std::endl;
    std::cout << "Peg C: " << std::endl;

    towersOfHanoi(numDisks, pegA, pegC, pegB);

    std::cout << "Final State:" << std::endl;
    // Display the final state of the pegs
    std::cout << "Peg A: ";
    while (!pegA.isEmpty()) {
        std::cout << pegA.top() << " ";
        pegA.pop();
    }
    std::cout << std::endl;

    std::cout << "Peg B: ";
    while (!pegB.isEmpty()) {
        std::cout << pegB.top() << " ";
        pegB.pop();
    }
    std::cout << std::endl;

    std::cout << "Peg C: ";
    while (!pegC.isEmpty()) {
        std::cout << pegC.top() << " ";
        pegC.pop();
    }
    std::cout << std::endl;

    return 0;
}
