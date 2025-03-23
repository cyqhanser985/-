#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    vector<vector<int>> nums={{1,2},{3,4},{5,6}}
    vector<vector<int>> prefix(nums.size(),vector<int>(nums[0].size(),0));

    for(int i=0;i<nums.size();i++){
        partial_sum(nums[i].begin(),nums[i].end(),prefix[i].begin());
    }

    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            cout<<prefix[i][j]<<" ";
        }
        cout<<endl;
    }
}
