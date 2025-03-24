#include<bits.stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> subsets(){
        vector<vector<int>> result;
        backtrack(result,{},0);
        return result;
    }

private:
    void backtrack(vector<vector<int>> &res,vector<int>& path,int start){
        res.push_back(path); //ÿ�εݹ鶼���浱ǰ·��
        for(int i=start;i<nums.size(),i++){
            path.push_back(nums[i]);
            backtrack(res,path,i+1);
            path.pop_back();
        }
    }

    vector<int> nums={2,3,6,7};
};