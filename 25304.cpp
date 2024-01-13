#include <iostream>
using namespace std;

int main()
{
    int total, count, nTotal;

    cin >> total;
    cin >> count;

    nTotal = 0;
    for (int i = 0; i < count; i++)
    {
        int price, priceCount;
        cin >> price >> priceCount;
        nTotal += (price * priceCount);
    }
    if (total == nTotal)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}