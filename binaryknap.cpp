#include <iostream>
#include <algorithm>
using namespace std;
class item{
    public:
     int item_id;
     int profit;
     int weight;
};

bool profit_sort(item c1, item c2){
   return(c1.profit>c2.profit);
}

void item_loading(int n, int max_weight, item c[20]){
    bool x[10]={false};
    int i=0;
    while(i<n&&c[i].weight<=max_weight){
        x[c[i].item_id]=1;
        max_weight=max_weight-c[i].weight;
        i++;
    }
    for(int j=0;j<n;j++){
        cout<<x[j]<<" ";
    }
}

int main(){
    int weight[20];
    item c[20];
    int max_weight;
    int n;

    cout<<"Enter the no. of items: ";
    cin>>n;

    cout<<"\nEnter the weights: ";
    for(int i=0;i<n;i++){
        c[i].item_id=i;
        cin>>c[i].weight;
        cin>>c[i].profit;
    }
    cout<<"\nEnter the total capacity of container: ";
    cin>>max_weight;
    sort(c,c+n,profit_sort);

    item_loading(n,max_weight,c);
    return 0;
}
