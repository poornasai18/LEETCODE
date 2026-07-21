class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=0;
        sort(intervals.begin(),intervals.end());
        int lastend=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<lastend){
                cnt++;
                lastend=min(lastend,intervals[i][1]);
            }
            else{
                lastend=intervals[i][1];
            }
        }
        return cnt;
    }
};