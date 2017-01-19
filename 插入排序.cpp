/**
 插入排序 时间复杂度 o(n * n)
 数组顺序是 小->大
 
 @param arr 待排序数组
 */

void insert_sort (int arr[]){

    int length = sizeof(arr[])/sizeof(arr[0]);
    
    if (length <= 1){
        return ;
    }

	for (int i = 1; i < length; ++i) {
		int temp = arr[i];
		int index = i;
		for (int j = i-1; j >= 0; --j)
		{
			if(arr[j] > temp){
				arr[j+1] = arr[j];
				index = j;
			}
		}
		arr[index] = temp;
	}
}
