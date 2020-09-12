#include<bits/stdc++.h>
using namespace std;

int merge(int *a, int s, int e){
	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = 0;

	int temp[e-s+1];

	int cnt = 0;

	while(i <= mid && j <= e){
		if(a[i] <= a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
			cnt += mid - i + 1; 
		}
	}
	while(i <= mid)
		temp[k++] = a[i++];
	while(j <=e)
		temp[k++] = a[j++];
	for(int i = 0; i < k; i++){
		a[s+i] = temp[i];
	}
	return cnt;
}

int inversion_count(int *arr, int s, int e){
	if(s >= e)
		return 0;
	int mid = (s+e)/2;
	int x = inversion_count(arr, s, mid);
	int y = inversion_count(arr, mid+1, e);
	int z = merge(arr ,s, e);
	return x+y+z;
}





int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int arr[] = {1,5,2,6,3,0};
	int n = sizeof(arr)/ sizeof(int);
	cout << inversion_count(arr, 0, n-1);

	return 0;
}