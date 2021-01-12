int minSwap(int *arr, int n, int k) 
{ 
	
	int count = 0; 
	for (int i = 0; i < n; ++i) 
		if (arr[i] <= k) 
			++count; 
	
	int bad = 0; 
	for (int i = 0; i < count; ++i) 
		if (arr[i] > k) 
			++bad; 
	
	int ans = bad; 
	for (int i = 0, j = count; j < n; ++i, ++j) { 
		
		// Decrement count of previous window 
		if (arr[i] > k) 
			--bad; 
		
		// Increment count of current window 
		if (arr[j] > k) 
			++bad; 
		
		// Update ans if count of 'bad' 
		// is less in current window 
		ans = min(ans, bad); 
	} 
	return ans; 
} 

