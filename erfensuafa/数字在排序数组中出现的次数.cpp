#include<bits/stdc++.h>
using namespace std;

vector<int> nums;
int n,k;

class Solution {
public:
    int getNumberOfK(vector<int>& A , int k) {
        if(!A.size()) return 0;

        int l1 = 0, r1 = A.size() - 1;
        while(l1 < r1)
        {
            int mid = l1 + r1 >> 1;
            if(A[mid] >= k) r1 = mid;
            else l1 = mid + 1;
        }


        int l2 = 0, r2 = A.size() - 1;
        while(l2 < r2)
        {
            int mid = l2 + r2 + 1 >> 1;
            if(A[mid] <= k) l2 = mid;
            else r2 = mid - 1;
        }

        if(A[l1] != k && A[l2] != k) return 0;

        return l2 - l1 + 1;
    }
};

int main(){
    Solution sovel;
	cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    cout<<sovel.getNumberOfK(nums,k);
    return 0;
}