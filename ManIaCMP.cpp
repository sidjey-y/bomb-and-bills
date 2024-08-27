#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to count the maximum number of bills that can be saved
int countSavedBills(const vector<vector<char>>& room, int k) {
    int n = room.size();
    int m = room[0].size();

    // Calculate the sum of all bills in the room
    int totalBills = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (room[i][j] >= '1' && room[i][j] <= '9') {
                totalBills += room[i][j] - '0';
            }
        }
    }

    // Initialize the counters for rows and columns
    vector<int> rowSum(n, 0);
    vector<int> colSum(m, 0);

    // Calculate the sum of bills in each row and column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (room[i][j] >= '1' && room[i][j] <= '9') {
                rowSum[i] += room[i][j] - '0';
                colSum[j] += room[i][j] - '0';
            }
        }
    }

    // Calculate the maximum sum of bills that can be saved
    int maxSavedBills = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int savedBills = totalBills - rowSum[i] - colSum[j];
            if (room[i][j] == 'B') {
                savedBills += rowSum[i] + colSum[j];
            }
            maxSavedBills = max(maxSavedBills, savedBills);
        }
    }

    // If swapping is allowed, check if swapping two bills can increase the saved bills count
    if (k > 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (room[i][j] >= '1' && room[i][j] <= '9') {
                    for (int x = i + 1; x < n; x++) {
                        for (int y = 0; y < m; y++) {
                            if (room[x][y] >= '1' && room[x][y] <= '9') {
                                int swapSavedBills = totalBills - rowSum[i] - colSum[j] - rowSum[x] - colSum[y];
                                swapSavedBills += rowSum[i] + colSum[y] + rowSum[x] + colSum[j];
                                maxSavedBills = max(maxSavedBills, swapSavedBills);
                            }
                        }
                    }
                }
            }
        }
    }

    return maxSavedBills;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./program_name input_file" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    int n, m, k;
    inputFile >> n >> m >> k;

    // Create a 2D vector to represent the room
    vector<vector<char>> room(n, vector<char>(m));

    // Read the room configuration from the input file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> room[i][j];
        }
    }

    inputFile.close();

    // Call the function to count the maximum number of saved bills
    int maxSavedBills = countSavedBills(room, k);

    // Print the safe positions
    cout << "Safe Positions:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ((room[i][j] == 'B') ? "*" : " ");
            cout << " ";
        }
        cout << "\n";
    }

    // Print the maximum number of $100 bills saved
    cout << "\nMaximum number of $100 bills saved is: " << maxSavedBills << endl;

    return 0;
}
