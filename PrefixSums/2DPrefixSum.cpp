#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000; // Assuming a maximum size for the 2D array

int Arr[MAXN][MAXN];
int P[MAXN][MAXN];

void computePrefixSum(int n, int m) {
    // Calculate the prefix sum using the given formula
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            P[i][j] = Arr[i][j];
            if (i > 0) P[i][j] += P[i - 1][j];
            if (j > 0) P[i][j] += P[i][j - 1];
            if (i > 0 && j > 0) P[i][j] -= P[i - 1][j - 1];
        }
    }
}

int queryRectangleSum(int U, int L, int D, int R) {
    // Calculate the sum of values in the specified rectangle
    int ans = P[D][R];
    if (L > 0) ans -= P[D][L - 1];
    if (U > 0) ans -= P[U - 1][R];
    if (U > 0 && L > 0) ans += P[U - 1][L - 1];
    return ans;
}

int main() {
    int n, m; // Dimensions of the 2D array
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    // Input the values in each cell of the 2D array
    cout << "Enter the values of the 2D array:" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> Arr[i][j];

    // Compute the prefix sum
    computePrefixSum(n, m);

    int Q; // Number of queries
    cout << "Enter the number of queries: ";
    cin >> Q;

    // Process each query
    for (int q = 0; q < Q; ++q) {
        int U, L, D, R; // Coordinates of the rectangle
        cout << "Enter query " << q + 1 << " (U L D R): ";
        cin >> U >> L >> D >> R;

        // Get the sum of values in the specified rectangle
        int result = queryRectangleSum(U, L, D, R);
        cout << "Sum in the rectangle: " << result << endl;
    }

    return 0;
}
