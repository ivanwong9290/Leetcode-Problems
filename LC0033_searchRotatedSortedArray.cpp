class Solution {
public:
    int search(vector<int>& nums, int target) {
        // If target != num
        if (nums.size() == 1 && nums[0] != target)
            return -1;
        
        // If target == num
        if (nums.size() == 1 && nums[0] == target)
            return 0;
        
        // Initialize 2 pointers for sliding window
        int L = 0, R = nums.size() - 1;
        // While L, R doesn't cross over
        while (L <= R){
            // Find middle point
            int mid = L+(R-L) / 2;
            // If our middle points to target, return mid
            if (nums[mid] == target){
                return mid;
            }
            // If mid is within the left sorted array
            if (nums[mid] >= nums[L]){
                // See if target is within the beginning of left sorted array and mid
                if (nums[mid] >= target && target >= nums[L])
                    // If it is, then refine the right search window to left of mid
                    R = mid - 1;
                    // If it's not, then refine the left search window to right of mid
                else
                    L = mid + 1;
            }
            // If mid is within the right sorted array
            else {
                // See if target is within mid and the end of right sorted array
                if (target >= nums[mid] && target <= nums[R])
                    // If it is, then close in on the search by left moving search window to right of mid
                    L = mid + 1;
                else
                    // If it's not then refine the right search window to left of mid
                    R = mid - 1;
            }
        }
        return -1;
    }
};