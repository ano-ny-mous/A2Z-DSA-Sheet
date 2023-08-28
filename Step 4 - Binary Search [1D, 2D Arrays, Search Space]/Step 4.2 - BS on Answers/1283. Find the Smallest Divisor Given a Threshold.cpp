// Approach - 1
// TLE
// Time Complexity: O(max(nums)*n)
// Space Complexity: O(1)
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int divisor = 1, sum = INT_MAX;
        while (sum > threshold)
        {
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += ceil((double)nums[i] / divisor);
            }
            divisor++;
        }
        divisor--;
        return divisor;
    }
};

// Approach - 2
// Time Complexity: O(log(max(nums))*n)
// Space Complexity: O(1)
class Solution
{
public:
    int n;

    bool checksumval(vector<int> &nums, int threshold, int mid)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((double)nums[i] / mid);
        }
        return sum <= threshold;
    }

    int binarysearch(vector<int> &nums, int threshold, int start, int end)
    {
        int res = 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (checksumval(nums, threshold, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        n = nums.size();
        int high = *max_element(nums.begin(), nums.end());
        return binarysearch(nums, threshold, 1, high);
    }
};