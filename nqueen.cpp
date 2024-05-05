#include <iostream>
using namespace std;

void printSolution(int **board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        cout << endl;
    }
}

bool isSafe(int **board, int row, int col, int N) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int **board, int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1, N))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool solveNQ(int N) {
    int **board = new int *[N];
    for (int i = 0; i < N; ++i) {
        board[i] = new int[N];
        for (int j = 0; j < N; ++j)
            board[i][j] = 0;
    }

    if (solveNQUtil(board, 0, N) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board, N);
    return true;
}

int main() {
    int N;
    cout << "Enter the size of the chessboard: ";
    cin >> N;

    if (N <= 0) {
        cout << "Invalid input.";
        return 1;
     }

    solveNQ(N);
    
    return 0;
}
