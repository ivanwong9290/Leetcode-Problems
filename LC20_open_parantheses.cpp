#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;
        stack<char> openList;
        for (const char& c: s){
            // Check if it's an open parantheses
            if (c == '{' || c == '(' || c == '['){
                openList.push(c);
            }
            // If it corresponds with the closing parantheses, get rid of it
            else if (!openList.empty()){
                if (c == '}' && openList.top() == '{')
                    openList.pop();
                else if (c == ']' && openList.top() == '[')
                    openList.pop();
                else if (c == ')' && openList.top() == '(')
                    openList.pop();
                else
                    return false;
            }
            else
                return false;
        }
        // If nothing is in open list, that means every open parantheses was associated with closed version of it
        if(openList.empty())
            return true;
        else
            return false;
    }
};