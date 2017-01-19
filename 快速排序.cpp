/**
 快速排序 时间复杂度 o(n*log(n))

 @param arr 带排序数组
 @param left 左坐标
 @param right 右坐标
 
 */

void quick_sort (int arr[]){

    int length = sizeof(arr)/sizeof(arr[0]);
    if(length <= 1) return;
    
	qsort(arr,0,length-1);
}

void qsort (int arr,int left,int right){
	
    if (left >= right) return;
    
	int i = left,j = right;
	int key = arr[left];
    
	while(i<j){
        
		while (i<j &&arr[j]>key)
			j--;
        
		if(i<j)
        {
			arr[i] = arr[j];
			i++;
		}
        
		while (i<j&&arr[i]<key)
			i++;
        
		if(i<j)
        {
			arr[j]=arr[i];
			j--;
		}
        
		arr[i]=key;
		qsort(arr,left,i-1);
		qsort(arr,i+1,right);
	}
}
