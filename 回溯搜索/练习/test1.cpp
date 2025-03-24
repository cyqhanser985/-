#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> combinationSum(){
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        backtrack(result,{},0);
        return result;
    }


private:
    void backtrack(vector<vector<int>> &res,vector<int>& path,
    int start){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=start;i<nums.size();i++){
            //剪枝1：如果当前数大于剩余目标，后面的数更大，直接跳过
            if(nums[i]>target) break;
            //剪枝2：跳过重复元素（前提是数组已排序）
            if(i>start&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);  //将当前数加入路径
            target-=nums[i];  //更新目标值
            backtrack(res,path,i+1);  //注意这里是i+1，因为每个数只能使用一次
            path.pop_back();  //用于回溯
        }
    }



    vector<int> nums = {2,3,6,7};
    int target = 9;
};
