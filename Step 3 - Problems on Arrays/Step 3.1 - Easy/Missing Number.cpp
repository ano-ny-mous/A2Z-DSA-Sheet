//Approach - 1
//Time Complexity: O(n^2)
//Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<=n;i++)
        {
            bool present=false;
            for(int j=0;j<n;j++)
            {
                if(i==nums[j])
                {
                    present=true;
                    break;
                }
            }
            if(!present)
            {
                return i;
            }
        }
        return -1;
    }
};

//Approach - 2
//Time Complexity: O(n) + O(n)
//Space Complexity: O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<n+1;i++)
        {
            if(freq[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};

//Approach - 3
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total=(n*(n+1))/2;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        return total-sum;
    }
};

//Approach - 4
//Time Complexity: O(n)
//Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0;
        int xor2=0;
        int i;
        for(i=0;i<n;i++)
        {
            xor1=xor1^nums[i];
            xor2=xor2^i;
        }
        xor2=xor2^i;
        return xor1^xor2;
    }
};