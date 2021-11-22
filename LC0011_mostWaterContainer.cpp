#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Instantiate return variable and 2 pointers for sliding window
        int maxArea = 0, L = 0, R = height.size() - 1;
        // While the 2 pointers don't cross each other
        while (L < R){
            // Compare the max area with current area = base * min(height of both sides of container)
            maxArea = max(maxArea, (R-L) * min(height[L], height[R]));
            // If height[R] < height[L], try to be greedy and see if the height[R-1] has a higher height
            if (height[L] > height[R])
                R--;
            // If it's the other way around, move left pointer to the right 
            else if (height[L] <= height[R])
                L++;
        }
        return maxArea;
            
    }
};