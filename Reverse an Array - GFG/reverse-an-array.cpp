#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void reverse_array(vector<int>& nums){
    int n = nums.size();
    for(int i=0 ; i<n/2 ; i++){
        swap(nums[i], nums[n-i-1]);
    }
}

int main() {
	//code
	int T;
	cin >> T;
	
	while(T--){
	    int n;
	    cin >> n;
	    vector<int>nums(n);
	    for(int i=0; i<n; i++){
	        cin >> nums[i];
	    }
	    reverse_array(nums);
	    for(auto& x: nums){
	        cout << x << " ";
	    }cout << endl;
	}
	return 0;
}