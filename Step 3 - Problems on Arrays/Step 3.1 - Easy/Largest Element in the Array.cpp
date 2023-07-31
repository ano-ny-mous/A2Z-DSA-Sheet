//Approach - 1
//Time Complexity: O(n*log(n))
//Space Complexity: O(1)
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    return arr[n-1];
}

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(1)
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}