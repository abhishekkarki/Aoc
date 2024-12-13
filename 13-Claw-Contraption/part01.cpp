#include <iostream>
#include <cmath>
#include <tuple>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Extended Euclidean Algorithm
tuple<int, int, int> extendedGCD(int a, int b) {
    if (b == 0) {
        return {a, 1, 0}; // gcd, x, y
    }
    auto [gcd, x1, y1] = extendedGCD(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;
    return {gcd, x, y};
}

// Solve linear Diophantine equation and find minimal cost
int solveMachine(int pX, int qX, int prizeX, int pY, int qY, int prizeY) {
    // Solve the X-axis equation: pX * a + qX * b = prizeX
    auto [gcdX, x0, y0] = extendedGCD(pX, qX);
    if (prizeX % gcdX != 0) {
        cout << "No solution for X equation!" << endl;
        return -1;
    }

    // Scale the solution for prizeX
    int scaleX = prizeX / gcdX;
    x0 *= scaleX;
    y0 *= scaleX;

    // General solution for X-axis
    int aX = x0, bX = y0;
    int tX = qX / gcdX, tY = pX / gcdX;

    // Solve the Y-axis equation: pY * a + qY * b = prizeY
    auto [gcdY, x1, y1] = extendedGCD(pY, qY);
    if (prizeY % gcdY != 0) {
        cout << "No solution for Y equation!" << endl;
        return -1;
    }

    // Scale the solution for prizeY
    int scaleY = prizeY / gcdY;
    x1 *= scaleY;
    y1 *= scaleY;

    // General solution for Y-axis
    int aY = x1, bY = y1;
    int uX = qY / gcdY, uY = pY / gcdY;

    // Find overlap of X and Y solutions with minimal cost
    long long minCost = numeric_limits<long long>::max();
    int bestA = -1, bestB = -1;

    for (int t = -10000; t <= 10000; ++t) { // Search range for t (t should be finite)
        int a = aX + t * tX;
        int b = bX - t * tY;

        if (a >= 0 && b >= 0) {
            // Check if it satisfies the Y equation
            if (pY * a + qY * b == prizeY) {
                long long cost = 3 * a + b; // Calculate cost
                if (cost < minCost) {
                    minCost = cost;
                    bestA = a;
                    bestB = b;
                }
            }
        }
    }

    if (bestA != -1 && bestB != -1) {
        cout << "Solution found!" << endl;
        cout << "Press A: " << bestA << " times, B: " << bestB << " times" << endl;
        cout << "Minimum cost: " << minCost << endl;
        return minCost;
    } else {
        cout << "No solution found!" << endl;
        return -1;
    }
}

// Parse input file and extract values into a list
void parseInput(const std::string& filename, std::vector<int>& list) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        int xValue = 0, yValue = 0;

        // Extract X and Y values
        while (ss >> token) {
            if (token.find("X") != std::string::npos) {
                xValue = stoi(token.substr(2)); // Skip "X+"
            } else if (token.find("Y") != std::string::npos) {
                yValue = stoi(token.substr(2)); // Skip "Y+"
            }
        }

        list.push_back(xValue);
        list.push_back(yValue);
    }

    inputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide the input file." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::vector<int> list;
    parseInput(filename, list);

    if (list.size() % 6 != 0) {
        std::cerr << "Invalid input format! Ensure each machine has exactly 6 values." << std::endl;
        return 1;
    }

    long long totalMinCost = 0;
    int prizesWon = 0;

    for (size_t i = 0; i < list.size(); i += 6) {
        int pX = list[i];
        int pY = list[i + 1];
        int qX = list[i + 2];
        int qY = list[i + 3];
        int prizeX = list[i + 4];
        int prizeY = list[i + 5];
        //solveMachine(pX, qX, prizeX, pY, qY, prizeY);
        int cost = solveMachine(pX, qX, prizeX, pY, qY, prizeY);
        if (cost != -1) {
            totalMinCost += cost;
            prizesWon++;
        }
    }

    std::cout << "Total prizes won: " << prizesWon << std::endl;
    std::cout << "Total minimum cost: " << totalMinCost << std::endl;

    return 0;
}