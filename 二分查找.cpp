/**
 二分查找 时间复杂度 o(logn)

 @param arr 有序数组
 @param key 查找值
 @return -1   ：没有找到该值
         非-1 ：表示坐标值
 */
int binary_search (int arr[],int key){

	int length = sizeof(arr[])/sizeof(arr[0]);

    if (length == 1){
        return arr[0] == key ? 0 : -1;
    }
    
	int left = 0;
	int right = length - 1;
	while (left <= right){
		int middle = left + ((right - left) >> 1);
		if(arr[middle] > key){
			right = middle - 1;
		}else if(arr[middle] < key){
			left = middle + 1;
		}else{
			return middle;
		}
	}
	return -1;
}
