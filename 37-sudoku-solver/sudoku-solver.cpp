class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) 
    {
        for (int i = 0; i < 9; i++) 
        {
            if (board[row][i] == num || board[i][col] == num || 
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) 
                {
                return false;
            }
        }

        return true;
    }

    bool findEmptyCell(vector<vector<char>>& board, int& row, int& col) 
    {
        for (row = 0; row < 9; row++) 
        {
            for (col = 0; col < 9; col++) 
            {
                if (board[row][col] == '.') 
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool solveHelper(vector<vector<char>>& board) 
    {
        int row, col;
        if (!findEmptyCell(board, row, col)) 
        {
            return true;
        }

        for (char num = '1'; num <= '9'; num++) 
        {
            if (isValid(board, row, col, num)) 
            {
                board[row][col] = num;

                if (solveHelper(board)) 
                {
                    return true;
                }

                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) 
    {
        solveHelper(board);
    }
};

void printSudoku(vector<vector<char>>& board) 
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}