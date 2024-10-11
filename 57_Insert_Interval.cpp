class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>ans;
        bool flag = false;
        int idx = 0;
        vector<int>v(2);

        auto complete_interval = [&](){
            bool s = false;
            while(idx < intervals.size()){
                if(newInterval[1] >= intervals[idx][0] && newInterval[1] <= intervals[idx][1]){
                    v[1] = intervals[idx][1];
                    ans.push_back(v);
                    s = true;
                    idx++;
                    break;
                }else if(newInterval[1] < intervals[idx][0]){
                    v[1] = newInterval[1];
                    ans.push_back(v);
                    s = true;
                    break;
                }
                idx++;
            }
            if(!s){
                v[1] = newInterval[1];
                ans.push_back(v);
            }
        };

        while(idx < intervals.size()){

            if(!flag && newInterval[1] < intervals[idx][0]){
                ans.push_back(newInterval);
                flag = true;
            }else if(!flag && newInterval[0] < intervals[idx][0] && newInterval[1] >= intervals[idx][0]){
                flag = true;
                v[0] = newInterval[0];
                complete_interval();
            }
            else if(!flag && newInterval[0] >= intervals[idx][0] && newInterval[0] <= intervals[idx][1]){
                flag = true;
                v[0] = intervals[idx][0];
                complete_interval();
            }else{
                ans.push_back(intervals[idx]);
                idx++;
            }
            
        }

        if(!flag)ans.push_back(newInterval);

        return ans;
        

    }
};
