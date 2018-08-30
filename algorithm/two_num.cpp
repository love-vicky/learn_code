#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> element;
        for (int i = 0; i < nums.size(); i++)
        {
            if (element.count(target - nums[i]))
            {
                res.push_back(element[target - nums[i]]);
                res.push_back(i);
                break;
            }
            else 
            {
                element[nums[i]] = i;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int a[3] = {3,2,4};
    vector<int> res;
    vector<int> list(a, a + sizeof(a) / sizeof(int));
    cout << list.size() << endl;
    Solution *s = new Solution;
    res = s->twoSum(list, 6);
    for(int i = 0; i < res.size();i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}
