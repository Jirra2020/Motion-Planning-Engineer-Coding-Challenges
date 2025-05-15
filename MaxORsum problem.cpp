#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

	long long maximumOr(vector<int>& nums, int k) {
		long long result = 0;
		int n = nums.size();
		vector<long long> sum;

		for (int i = 0; i < n; i++) {
			long long x = (long long)nums[i] << k;
			sum.push_back(x);
		}

		vector<long long> newsum(n, 0);
		long long prefix = 0;

		for (int i = 0; i < n; i++) {
			newsum[i] = prefix;
			prefix |= nums[i];
		}

		long long suffix = 0;
		for (int i = n - 1; i >= 0; i--) {
			newsum[i] |= suffix;
			suffix |= nums[i];
		}

		for (int i = 0; i < n; i++) {
			newsum[i] |= sum[i];
		}

		result = *max_element(newsum.begin(), newsum.end());

		return result;
	}

};
int main ()
{
	int k,n;
	cin>>k>>n;
	vector<int>numinput;
	for (int i=0; i<n; i++)
	{	int num;
		cin>>num;
		numinput.push_back(num);
	}
	Solution obj;
	long long result=obj.maximumOr(numinput,k);
	cout<<"The max or of the given array is:"<<result;
	return 0;
}