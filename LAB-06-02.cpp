#include <iostream>
#include <algorithm> // for std::min

using namespace std;

void calculateRoutingTable(int vectors[][6], int delays[], int numRouters) {
    int numDestinations = 6; // Number of destinations (A to F)
    int routingTable[6];

    // Initialize routing table with a large value
    for (int i = 0; i < numDestinations; i++) {
        routingTable[i] = 1000; // A high initial value
    }

    // Adjust the vectors with the delays
    for (int i = 0; i < numRouters; i++) {
        for (int j = 0; j < numDestinations; j++) {
            int adjustedCost = vectors[i][j] + delays[i];
            routingTable[j] = min(routingTable[j], adjustedCost);
        }
    }

    // Set cost to self (C to C) as 0
    routingTable[2] = 0; // Assuming C corresponds to index 2

    // Print the routing table
    cout << "C's New Routing Table:\n";
    cout << "Destination | Cost\n";
    cout << "---------------------\n";
    char destinations[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < numDestinations; i++) {
        cout << destinations[i] << "           | " << routingTable[i] << endl;
    }
}

int main() {
    // Input data
    int vectors[3][6] = {
        {5, 0, 8, 12, 6, 2},   // From B
        {16, 12, 6, 0, 9, 10}, // From D
        {7, 6, 3, 9, 0, 4}     // From E
    };

    int delays[3] = {6, 3, 5}; // Delays to B, D, and E

    // Calculate and display the routing table for C
    calculateRoutingTable(vectors, delays, 3);

    return 0;
}

