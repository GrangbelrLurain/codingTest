#include <iostream>
using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    int *A = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int Kn = 0;
    for (int i = N - 1; i > 0; i--)
    {
        int max = A[i - 1];
        int maxIndex = i - 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] > max)
            {
                max = A[j];
                maxIndex = j;
            }
        }
        if (A[i] < max)
        {
            swap(A[i], A[maxIndex]);
            Kn++;
        }
        if (Kn == K)
        {
            cout << A[maxIndex] << ' ' << A[i];
        }
    }

    if (Kn < K)
    {
        cout << -1;
    }

    return 0;
}