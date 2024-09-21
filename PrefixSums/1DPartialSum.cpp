#include <iostream>
#include <vector>

using namespace std;

/*
Given an array A of size N, initially all 0's. There are Q queries of the form: +LRx -> add x to all indices in the range [L, R]. 
After all queries, you need to find the final array.
*/

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N, 0); // Initialize the array with zeros

    // Process queries
    while (Q--)
    {
        int L, R, x;
        cin >> L >> R >> x;

        // Update the partial sum array
        arr[L - 1] += x;
        if (R < N)
        {
            arr[R] -= x;
        }
    }

    // Compute final array using partial sum
    for (int i = 1; i < N; ++i)
    {
        arr[i] += arr[i - 1];
    }

    // Print the final array
    for (int i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
