#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);
        int check = 0;
        for(int i = 0; i < str_x.length(); i++)
        {
            if (str_x[i] == str_x[str_x.length()-i-1])
                check++;
        }
        if (check == str_x.length())
            return true;
        return false;
    }
};