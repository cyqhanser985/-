#include<bits.stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> permutations{
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        backtrack(result,{},0);
        return result;
    }

private:
    void backtrack(vector<vector<int>> &res,vector<int>&path,int start){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            backtrack(res,path,i+1);
            path.pop_back();
        }
    }

    vector<int> nums = {1,2,3,4};
}