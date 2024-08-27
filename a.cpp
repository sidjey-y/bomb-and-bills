#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    // Read the dimensions of the room and the number of swaps allowed
    int n, m, k;
    cin >> n >> m >> k;
    string line[n];

    // Arrays to store whether there is a bill in each row and column
    bool row[n], col[m];
    memset(row, 0, sizeof(row));  // Initialize row array with all zeros
    memset(col, 0, sizeof(col));  // Initialize col array with all zeros

    // Read the room configuration and update the row and column arrays
    for (int i = 0; i < n; i++) {
        cin >> line[i];
        for (int j = 0; j < m; j++) {
            if (line[i][j] == 'B') {
                row[i] = true;   // Mark the row as having a bill
                col[j] = true;   // Mark the column as having a bill
            }
        }
    }

    // Separate the bills into two vectors based on whether they are in a row or column with a bill
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (line[i][j] == 'B')
                continue;
            if (row[i] || col[j])
                a.push_back(line[i][j] - '0');  // Bill is in a row or column with a bill
            else
                b.push_back(line[i][j] - '0');  // Bill is not in a row or column with a bill
        }
    }

    // Sort the bills in ascending order and descending order for the two vectors
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int bill = 0;
    // Start with the bills that are in a row or column with a bill
    while (k > 0 && !a.empty() && !b.empty() && a.back() >= b.back()) {
        bill += a.back();
        a.pop_back();
        b.pop_back();
        k--;
    }
    // Add the remaining bills that are not in a row or column with a bill
    while (!b.empty()) {
        bill += b.back();
        b.pop_back();
    }

    // Output the result
    cout << "Safe Positions:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ((line[i][j] == 'B') ? "*" : " ");
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Maximum number of $100 bills saved is: " << bill << endl;

    return 0;
}
