
/**
 归并排序 时间复杂度 o( n * log(n) )

 @param arr 待排序数组
 @param temp_arr 辅助数组
 @param start_index 子表起始坐标
 @param mid_index 子表中间坐标
 @param end_index 子表结束坐标
 */

void merge_sort (int arr[],int temp_arr[],int start_index,int end_index){
    
    int length = sizeof(arr)/sizeof(arr[0]);
    if(length <= 1) return;
 
	if(start_index < end_index){
		int mid_index = (end_index + start_index ) * 0.5;
		merge_sort (arr,temp_arr,start_index,mid_index);
		merge_sort (arr,temp_arr,mid_index + 1,end_index);
		merge (arr,temp_arr,start_index,mid_index,end_index);
	}

}

void merge (int arr[],int temp_arr[],int start_index,int mid_index,int end_index){

	 int i = start_index,j=mid_index + 1;
	 int temp = 0;
	 while(i < mid_index + 1 && j < end_index + 1)
	 {
	 	if(arr[i] > arr[j])
	 	{
	 		temp_arr[temp++] = arr[j++];
	 	}
	 	else
	 	{
	 		temp_arr[temp++] = arr[i++];
	 	}
	 	while (i < mid_index + 1)
	 	{
	 		temp_arr[temp++] = arr[i++];
	 	}
	 	while (j< end_index + 1)
	 	{
	 		temp_arr[temp ++] = arr[j++];
	 	}

	 	for (int i = 0,j = start_index; j < end_index + 1; ++i,++j)
	 	{
	 		arr[j] = temp_arr[i];
	 	}
	 }
}
