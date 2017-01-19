/**
 冒泡排序 时间复杂度 o(n * n)
 将最大的数沉到最下面
 
 // 优化1 如果一遍遍历没有数据交互 说明已经排好序了，不用再迭代了
 // 优化2 记录某次遍历最后发生数据交换的位置，这个位置之后的数据已经有序了，不用再排序了。就可以确定下次交互位置循环范围
 
 @param arr 待排序数组
 
 */

void bubble_sort (int arr[]){

    int length = sizeof(arr)/sizeof(arr[0]);
    
    if(length <= 1){
        return ;
    }
	
	for (int i = 0; i < length - 1; ++i)
	{
		for (int j = 1; j < length - i; ++j)
		{
			if(arr[j] < arr[j-1]){
				int temp = arr[j];
				arr[j] = arr [j-1];
				arr[j-1] = temp;
			}
		}
	}
}

