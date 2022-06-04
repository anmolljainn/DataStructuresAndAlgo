class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string> board)
{
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q' && i != row)
        {
            return false;
        }
        if (board[row][i] == 'Q' && i != col)
        {
            return false;
        }
    }
    int i = row-1, j = col-1;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }
    i = row - 1, j = col + 1;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}
void helperfunc(int idx, int n, vector<string> board, vector<vector<string>> &res)
{
    if (idx >= n)
    {
        res.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        board[idx][i] = 'Q';
        if (isSafe(idx, i, n, board) == true)
        {
            helperfunc(idx + 1, n, board, res);
        }
        board[idx][i] = '.';
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    helperfunc(0, n, board, res);
    return res;
}
};