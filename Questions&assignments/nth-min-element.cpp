#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    while(k--)
    {
        int min = arr[0];
        for(int i=0; i<n; i++)
        {
            if(arr[i]<min)
            min = arr[i];   
        }  
        if(k==0)  
        cout<<min<<endl;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==min)
            arr[i] = INT_MAX;
        }
    }
    return 0;
}
