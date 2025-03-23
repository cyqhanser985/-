#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    vector<int> nums={2,4,6,8};
    vector<int> prefix(4);

    partial_sum(nums.begin(),nums.end(),prefix.begin());
    for(auto i:prefix){
        cout<<i<<endl;
    }
}
