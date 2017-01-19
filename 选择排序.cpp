/**
 选择排序 时间复杂度 o(n * n)

 @param arr 待排序数组
 */

void select_sort (int arr[]){

    int length = sizeof(arr)/sizeof(arr[0]);
    
    if(length <= 1){
        return ;
    }
	for (int i = 0; i < length; ++i)
	{
		int min = i;
		for (int j = i + 1; j < length; ++j)
		{
			if ( arr[min]> arr[j])
			{		
				min = j;		
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	}
}
