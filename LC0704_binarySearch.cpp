#include <vector>

using namespace std;

class Solution {
public:    
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j){
            int curr = i + (j - i) /2;
            if (nums[curr] == target)
                return curr;
            else if (nums[curr] < target)
                i = curr + 1;
            else if (nums[curr] > target)
                j = curr - 1;  
        }
        return -1;
    }
};