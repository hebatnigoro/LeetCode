#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> idx;
        idx.reserve(nums.size() * 2);
        idx.max_load_factor(0.7f);

        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            auto it = idx.find(need);
            if (it != idx.end()) return {it->second, i};
            idx.emplace(nums[i], i);
        }
        return {};
    }
};
