//Approach - 1
//Time Complexity - O(nlog(n)) + O(n)
//Space Complexity - O(1)
vector<int> getSecondOrderElements(int n, vector<int> a) {
    vector<int> ans;
    sort(a.begin(),a.end());
    int i=n-1;
    int larget = a[i];
    int smallest = a[0];
    for(;i>=0;i--)
    {
        if(a[i]<larget)
        {
            ans.push_back(a[i]);
            break;
        }
    }
    i=0;
    for(;i<n;i++)
    {
        if(smallest<a[i])
        {
            ans.push_back(a[i]);
            break;
        }
    }
    return ans;
}

//Approach - 2
//Time Complexity - O(n) + O(n)
//Space Complexity - O(1)
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int largest = INT_MIN,smallest = INT_MAX;
    int second_largest = INT_MIN,second_smallest = INT_MAX;
    for(int i=0;i<n;i++)
    {
        smallest = min(smallest,a[i]);
        largest = max(largest,a[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(a[i] != largest && a[i] > second_largest)
        {
            second_largest = max(second_largest,a[i]);
        }

        if(a[i] != smallest && a[i] < second_smallest)
        {
            second_smallest = min(second_smallest,a[i]);
        }
    }
    return {second_largest,second_smallest};
}

//Approach - 3
//Time Complexity - O(n)
//Space Complexity - O(1)
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int largest = INT_MIN,smallest = INT_MAX;
    int second_largest = INT_MIN,second_smallest = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(a[i] > largest)
        {
            second_largest = largest;
            largest = a[i];
        }
        else if(a[i] < largest && second_largest < a[i])
        {
            second_largest = a[i];
        }

        if(a[i] < smallest)
        {
            second_smallest = smallest;
            smallest = a[i];
        }
        else if(a[i] > smallest && second_smallest > a[i])
        {
            second_smallest = a[i];
        }
    }
    return {second_largest,second_smallest};
}

