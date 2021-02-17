#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k)
{

	int good = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] <= k)
			++good;

	int bad = 0;											
	for (int i = 0; i < good; ++i)										//no of bad in window of size of good
		if (arr[i] > k)
			++bad;

	int ans = bad;

	for (int i = 0, j = good; j < n; ++i, ++j)
	{

		// Decrement count of previous window
		if (arr[i] > k)
			--bad;

		// Increment count of current window
		if (arr[j] > k)
			++bad;

		ans = min(ans, bad);
	}
	return ans;
}

int main()
{
	int arr1[] = {2, 7, 9, 5, 8, 7, 4};
	int n = (sizeof(arr1) / sizeof(arr1[0]));
	int k=6;
	cout<<minSwap(arr1,n,k);

}
