#include <stdio.h>
#include <string.h>

int serch(int *arr, int res, int size) {
	int left = 0, right = size-1;
	while(left <= right) {
		int mid = left + ((right-left)>>1);
		if(arr[mid] == res) {
			return arr[mid];
		} else if(arr[mid] > res){
			right = mid-1;
		} else {
			left = mid+1;
		}
	}

	return -1;
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size = sizeof(arr)/sizeof(arr[0]);
	int ret = serch(arr, 5, size);

	if(ret == -1) {
		printf("not found...\n");
	} else {
		printf("found %d\n", ret);
	}
	return 0;
}
