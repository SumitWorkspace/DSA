class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = nums[0];       
        int bestSum = nums[0];
        int currentBest = nums[0];
        int worstSum = nums[0];
        int currentWorst = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentBest = max(nums[i], currentBest + nums[i]);
            bestSum = max(bestSum, currentBest);
            currentWorst = min(nums[i], currentWorst + nums[i]);
            worstSum = min(worstSum, currentWorst);
            total += nums[i];
        }
        if (bestSum < 0)
            return bestSum;
        return max(bestSum, total - worstSum);
    }
};