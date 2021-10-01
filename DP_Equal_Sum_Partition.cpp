#include<bits/stdc++.h>
using namespace std;
#define ln "\n";
#define TC() int t; cin >> t; while(t--)
#define IO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool subsetSum(int *arr, int sum, int n){

	bool dp[n+1][sum+1];

	// Initialization
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < sum+1; j++){
			if(i == 0) dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
		}
	}

	// Step 2: Filling the rest dp array
	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < sum+1; j++){
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j- arr[i-1]] || dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum];
}

// Variation of Knapsack problem
int main(){

	IO();
	
	int n; cin >>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int sum = accumulate(arr,arr+n,0);

	if(sum % 2 != 0){
		cout << "false\n";
	}
	else{
		int ans = subsetSum(arr,sum/2,n);
		if(ans == 1){
			cout <<"true\n";
		}
	}


	return 0;
}
