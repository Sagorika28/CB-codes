// 1
// 37 9
// 8723 9741 5127 778 1115 3035 10989 1842 288 7704 9040 8942 8063 246 5044 1403 4689 6729 1968 4149 3805 8699 1991 3548 8428 1422 1682 8753 7555 639 4966 7376 2730 3906 5743 10037 2224
// 122 5537 10337 4917 2082 527 5340 4833 8713

// 8 8 5 2 2 3 9 2 1 7 8 8 7 1 5 2 3 7 2 3 3 7 2 3 7 2 2 8 7 2 5 7 3 3 7 8 3 

// { Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>
 
using namespace std;
 
// function returns the index of largest element 
// smaller than equal to 'x' in 'arr'. For duplicates
// it returns the last index of occurrence of required
// element. If no such element exits then it returns -1. 
int binary_search(int arr[], int l, int h, int x);

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
vector <int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        vector <int> res = countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    }
    return 0;
}// } Driver Code Ends


// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                             int m, int n)
{
//Your code goes here
    sort(arr2, arr2+n);
    vector<int> count(m, 0);
    int i, j, c;
    for(i=0; i<m; i++) {
        c=0;
        j=0;
        while(arr2[j]<=arr1[i]) {
            c++;
            j++;
        }
        count[i]=c;
    }
    return count;
}

//8 8 5 2 2 3 9 2 1 7 8 8 7 1 5 2 3 7 2 3 3 7 2 3 7 2 2 8 7 2 5 7 3 3 7 8 3
