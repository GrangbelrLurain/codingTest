#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMins(char standard, vector<vector<char>> board, int M, int N, int K)
{
    vector<vector<int>> arrays(M, vector<int>(N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int nowValue = ((i + j) % 2) ? board[i][j] == standard : board[i][j] != standard;
            if (i == 0 && j == 0)
            {
                arrays[i][j] = nowValue;
            }
            else if (i == 0)
            {
                arrays[i][j] = nowValue + arrays[i][j - 1];
            }
            else if (j == 0)
            {
                arrays[i][j] = nowValue + arrays[i - 1][j];
            }
            else
            {
                arrays[i][j] = nowValue + arrays[i - 1][j] + arrays[i][j - 1] - arrays[i - 1][j - 1];
            }
        }
    }

    int minimum = INT_MAX;
    for (int i = K - 1; i < M; i++)
    {
        for (int j = K - 1; j < N; j++)
        {
            int leftWing = (i - K < 0) ? 0 : arrays[i - K][j];
            int rightWing = (j - K < 0) ? 0 : arrays[i][j - K];
            int center = (i - K < 0 || j - K < 0) ? 0 : arrays[i - K][j - K];
            int cal = arrays[i][j] - leftWing - rightWing + center;

            minimum = min(cal, minimum);
        }
    }
    return minimum;
}

int main()
{
    ios::sync_with_stdio(0);

    int M, N, K;
    cin >> M >> N >> K;

    vector<vector<char>> board(M, vector<char>(N));

    // 계산 결과 미리 저장
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    int minimum = min(getMins('W', board, M, N, K), getMins('B', board, M, N, K));
    cout << minimum;

    return 0;
}
