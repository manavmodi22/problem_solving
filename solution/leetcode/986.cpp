// https://leetcode.com/problems/interval-list-intersections/
// basic sweep line

class Solution {
public:
    #define pi pair<int, int>
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > ans;
        vector<pi> intervals;
        for (auto it:A) {
            pi var = {it[0], it[1]};
            intervals.push_back(var);
        }
        for (auto it:B) {
            pi var = {it[0], it[1]};
            intervals.push_back(var);
        }
        
        sort(intervals.begin(), intervals.end());
        int first = -1, last = -1;
        
        for (auto it: intervals) {
            if (last < it.first) {
                first = it.first;
                last = it.second;
                continue;
            }
            
            vector<int> v = {it.first, min(it.second, last)};
            ans.push_back(v);
            
            first = it.first;
            last = max(last, it.second);
        }
        
        return ans;
    }
};