/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. 
As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. 
However, the reserved squares do not prevent queens from attacking each other.
How many possible ways are there to place the queens?
*/

char matrix[8][8];
int cnt;

bool check(int rr, int cc, vector<int> &colPos)
{
    for (int pr = 0; pr < rr; pr++)
    {
        int pc = colPos[pr];

        if (pc == cc || abs(pc - cc) == abs(pr - rr) || matrix[rr][cc] == '*')
        {
            return 0;
        }
    }

    return 1;
}

void rec(int rowNum, vector<int> &colPos)
{
    if (rowNum == 8)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (matrix[rowNum][i] == '.')
        {
            if (check(rowNum, i, colPos))
            {
                colPos.push_back(i);
                rec(rowNum + 1, colPos);
                colPos.pop_back();
            }
        }
    }
}
void solve()
{
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            matrix[i][j] = s[j];
        }
    }

    vector<int> colPos;

    cnt = 0;
    rec(0, colPos);

    cout << cnt << "\n";
}