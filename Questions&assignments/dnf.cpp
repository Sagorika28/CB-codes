#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void dnf(int *arr, int n)
{

  int start = 0, mid = 0, end = n - 1;

  while (mid <= end)
  {
    if (arr[mid] == 1)
      mid++;
    else if (arr[mid] == 0)
    {

      swap(arr[start], arr[mid]);
      start++;
      mid++;
    }

    else
    {

      swap(arr[mid], arr[end]);
      end--;
    }
  }
}

int main()
{
  int n, i, temp;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++)
    cin >> arr[i];

  dnf(arr, n);

  for (i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}
