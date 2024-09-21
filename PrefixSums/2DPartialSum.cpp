// Function to perform the query operation
void processQuery(int U, int D, int L, int R, int X) {
    Arr[U][L] += X;
    Arr[U][R+1] -= X;
    Arr[D+1][L] -= X;
    Arr[D+1][R+1] += X;
}

// After that we will do 2D prefix sum as we do in 2D Prefix Sum section
