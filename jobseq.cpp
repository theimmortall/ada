#include <iostream>
#include <algorithm>
using namespace std;

class job
{
public:
    int deadLine, profit;
};

bool compare(job A, job B)
{
    return A.profit > B.profit;
}

int main()
{
    int n;
    cout << "Enter count of jobs: ";
    cin >> n;

    job arr[n];
    cout << "Enter the deadline and profit of each job: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i].deadLine >> arr[i].profit;

    sort(arr, arr + n, compare);

    int profit[n], totalProfit = 0;

    for (int i = 0; i < n; i++)
        profit[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int deadLine = arr[i].deadLine;

        for (int j = deadLine; j >= 1; j--)
        {
            if (profit[j] == -1)
            {
                profit[j] = arr[i].profit;
                totalProfit += arr[i].profit; 
                break;
            }
        }
    }

    cout << "Total Profit = " << totalProfit << endl;

    return 0;
}
