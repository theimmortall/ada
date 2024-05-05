#include <iostream>
#include <algorithm>
using namespace std;

class item {
public:
    int item_id;
    int profit;
    int weight;
};

bool profit_sort(item c1, item c2) {
    return (c1.profit / (float)c1.weight > c2.profit / (float)c2.weight);
}

void item_loading(int n, float max_weight, item c[20]) {
    float total_profit = 0;

    cout << "Items loaded (fractional): ";
    for (int i = 0; i < n; ++i) {
        if (max_weight == 0)
            break;

        if (c[i].weight <= max_weight) {
            cout << "1 ";
            total_profit += c[i].profit;
            max_weight -= c[i].weight;
        } else {
            float fraction = max_weight / (float)c[i].weight;
            cout << fraction << " ";
            total_profit += fraction * c[i].profit;
            break;
        }
    }
    cout << endl;

    cout << "Total profit obtained: " << total_profit << endl;
}

int main() {
    item c[20];
    float max_weight;
    int n;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "\nEnter the weights and profits of items: " << endl;
    for (int i = 0; i < n; ++i) {
        c[i].item_id = i;
        cin >> c[i].weight >> c[i].profit;
    }

    cout << "\nEnter the total capacity of the knapsack: ";
    cin >> max_weight;

    sort(c, c + n, profit_sort);

    item_loading(n, max_weight, c);
    return 0;
}
