class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        if(nums.empty()){
            return;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=0){
                continue;
            }
            for(int j=i;j<nums.size()-1;j++){
                if(nums[j+1]==0){
                    break;
                }
                nums[j]=nums[j+1];
                nums[j+1]=0;
            }
        }
        */
        if(nums.size()<=1)
            return;
        int firstNotZero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                /*
                nums[firstNotZero++]=nums[i];
                if(firstNotZero<=i)
                    nums[i]=0;
                */
                swap(nums[i],nums[firstNotZero++]);
            }
        }
    }
};