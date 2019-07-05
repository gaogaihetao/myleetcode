class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0)
            return 0;
        if(envelopes.size()==1)
            return 1;
        sort(envelopes.begin(), envelopes.end(), compare);
        int i=0;
        int j=1;
        vector<int> dp(envelopes.size(),1);
        int max=1;
        for(int i=1;i<envelopes.size();i++){
            for(int j=i-1;j>=0;j--){
                if(isFit(envelopes[j],envelopes[i])){
                    dp[i] = dp[i]>dp[j]+1 ? dp[i] : dp[j]+1;                }
                max = max>dp[i] ? max : dp[i];
            }
        }
        return max;
    }
    
    static bool compare(vector<int>& env1, vector<int>& env2){
        if(env1[0]<env2[0])
            return true;
        if(env1[0]>env2[0])
            return false;
        return env1[1]<env2[1];
    }
    
    bool isFit(vector<int>& env1, vector<int>& env2){
        if(env1[0]>=env2[0])
            return false;
        return env1[1]<env2[1];
    }
};