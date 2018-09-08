#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct {
    bool operator()(string a, string b) {
        string c = a + b;
        string d = b + a;
        return c > d;
    }
}Compare;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return "";
        }
        string res_number = "";
        vector<string> nums_tmp;
        for (int i = 0; i < nums.size(); i++) {
            nums_tmp.push_back(to_string(nums[i]));
        }
        sort(nums_tmp.begin(), nums_tmp.end(), Compare);

        for (int i = 0; i < nums_tmp.size(); i++){
            res_number.append(nums_tmp[i]);
        }
        if (res_number[0] == '0')
        {
            return "0";
        }
        return res_number;
    }
};

int main(int argc, char const *argv[])
{
    int c[] = {10, 2};
    Solution *s = new Solution;
    vector<int> n(c, c + sizeof(c)/sizeof(int));

    string r = s->largestNumber(n);
    cout << r << endl;

    return 0;
}
