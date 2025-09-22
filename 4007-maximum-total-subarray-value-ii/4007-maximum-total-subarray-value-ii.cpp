class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        const int n = (int)nums.size();

        auto calc_le = [&](long long T)->pair<long long,long long> {
            deque<pair<long long,int>> dqMax, dqMin;
            long long sumMax = 0, sumMin = 0;
            long long cnt = 0, sum = 0;
            int L = 0;

            auto pushMax = [&](long long v){
                int c = 1;
                while(!dqMax.empty() && dqMax.back().first <= v){
                    sumMax -= dqMax.back().first * dqMax.back().second;
                    c += dqMax.back().second;
                    dqMax.pop_back();
                }
                dqMax.push_back({v,c});
                sumMax += v * c;
            };
            auto pushMin = [&](long long v){
                int c = 1;
                while(!dqMin.empty() && dqMin.back().first >= v){
                    sumMin -= dqMin.back().first * dqMin.back().second;
                    c += dqMin.back().second;
                    dqMin.pop_back();
                }
                dqMin.push_back({v,c});
                sumMin += v * c;
            };
            auto popFrontMax = [&](){
                sumMax -= dqMax.front().first;
                if(--dqMax.front().second == 0) dqMax.pop_front();
            };
            auto popFrontMin = [&](){
                sumMin -= dqMin.front().first;
                if(--dqMin.front().second == 0) dqMin.pop_front();
            };

            for(int R = 0; R < n; ++R){
                pushMax(nums[R]);
                pushMin(nums[R]);

                while(!dqMax.empty() && !dqMin.empty() &&
                      dqMax.front().first - dqMin.front().first > T){
                    popFrontMax();
                    popFrontMin();
                    ++L;
                }

                long long len = R - L + 1;
                cnt += len;
                sum += (sumMax - sumMin);
            }
            return {cnt, sum};
        };

        long long totalCnt = 1LL * n * (n + 1) / 2;
        auto total = calc_le((long long)2e9).second;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        long long lo = 0, hi = 1LL * mx - mn;

        auto ge = [&](long long x)->long long {
            return totalCnt - calc_le(x - 1).first;
        };

        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (ge(mid) >= k) lo = mid;
            else hi = mid - 1;
        }
        long long T = lo;

        long long geT1 = (T < 1LL * mx - mn) ? ge(T + 1) : 0;
        long long sum_ge_T1 = total - calc_le(T).second;

        return sum_ge_T1 + T * (k - geT1);
    }
};
