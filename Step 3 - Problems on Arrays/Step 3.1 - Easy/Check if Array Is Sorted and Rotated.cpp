//Approach - 1
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int minindex=-1;
        for(int i=0;i<n;i++)
        {
            if(mini>nums[i])
            {
                mini=nums[i];
                minindex=i;
            }
        }
        int unsort=0;
        for (int i = minindex; i < n+minindex; i++)
        {
            if(nums[(i % n)]>nums[((i+1) % n)])
            {
                unsort++;
            }
            
        }
        if(unsort==0||unsort==1)
        {
            return true;
        }
        return false;
    }
};

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int unsort=0;
        for (int i = 1; i < n; i++)
        {
            if(nums[i-1]>nums[i])
            {
                unsort++;
            }
        }
        if(nums[n-1]>nums[0])
        {
            unsort++;
        }
        if(unsort==0||unsort==1)
        {
            return true;
        }
        return false;
    }
};



