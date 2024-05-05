#include <iostream>
#include <algorithm>
using namespace std;

class container{
   public:
    int container_id;
    int weight;
};

bool weight_sort(container c1, container c2){
    return (c1.weight<c2.weight);
}

void container_loading(int n, int max_weight, container c[20]){
    bool x[20] = {false}; // Array to track loading status of each container
    int loaded_weight = 0; // Variable to track the total weight loaded onto the ship
    for(int i = 0; i < n; i++){
        if(loaded_weight + c[i].weight <= max_weight){
            x[c[i].container_id] = true; // Mark container as loaded
            loaded_weight += c[i].weight; // Update the loaded weight
        }
        else{
            break; // Stop loading if adding the next container exceeds the weight limit
        }
    }
    // Print loading status of each container
    for(int j = 0; j < n; j++){
        cout << x[j] << " ";
    }
}

int main(){
    int weight[20];
    container c[20];
    int max_weight;
    int n;

    cout<<"Enter the number of container: ";
    cin>>n;
    cout<<"\nEnter the weights: ";
    for(int i =0;i<n;i++){
        c[i].container_id=i;
        cin>>c[i].weight;
    }

    cout<<"\nEnter the total capacity of container: ";
    cin>>max_weight;
    sort(c,c+n,weight_sort);
    container_loading(n,max_weight,c);
    return 0;

}