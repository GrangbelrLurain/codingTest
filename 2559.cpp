#include <iostream>
using namespace std;

int main()
{
    int T, N;

    cin >> T >> N;

    int *A = new int[T + 1];

    for (int i = 1; i <= T; i++)
    {
        int a;
        cin >> a;
        A[i] = A[i - 1] + a;
    }

    int max = -100 * N;

    for (int i = T; i >= N; i--)
    {
        int value = A[i] - A[i - N];

        if (value > max)
        {
            max = value;
        }
    }

    cout << max;

    return 0;
}