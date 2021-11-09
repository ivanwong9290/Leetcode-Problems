#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int temp1 = 1, temp2 = 1;
        for (int i = 0; i < nums.size(); i++){
            answer[i] = temp1;
            temp1 *= nums[i];
        }
        for (int i = nums.size()-1; i >= 0; i--){
            answer[i] *= temp2;
            temp2 *= nums[i];
        }
        return answer;
    }
};