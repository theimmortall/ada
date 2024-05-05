#include <iostream>
#include <algorithm>
using namespace std;

int optimalmergepattern(int files[], int n)
{
    sort(files, files + n);
    int total_cost = 0;

    while (n > 1)
    {

        int file1 = files[0];
        int file2 = files[1];

        int merge_cost = file1 + file2;
        total_cost += merge_cost;

        for(int i=2;i<n;i++){
            files[i-2]=files[i];
        }

        files[n-2]=merge_cost;
        n--;
    }
    return total_cost;
}

int main(){
    int n;
    cout<<"Enter the number of files: ";
    cin>>n;
    int files[n];
    cout<<"Enter the length of each file: ";
    for(int i=0;i<n;i++){
        cin>>files[i];
    }
    int cost = optimalmergepattern(files,n);
    cout<<"The optimal merge pattern cost is: "<<cost;
    return 0;
}
