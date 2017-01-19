/**
 堆排序 时间复杂度 o(n * logn)
 
 采用最大堆，数组中最大的数在堆顶
 
 @param arr 待排序数组
 */

void heap_sort (int arr[]){

    int length = sizeof(arr)/sizeof(arr[0]);
    
    if(length <= 1) return ;
    
    for (int i = (length -1) * 0.5; i >= 0; --i)
    {
        heap_adjust(arr,i,length);
    }
    
    for (int i = length - 1; i > 0; --i)
    {
        int temp = arr[i];
        arr[i]   = arr[0];
        arr[0]   = temp;
        
        heap_adjust(arr,0,i);
    }
}


/**
 调整最大堆

 @param arr 待排序数组
 @param node 叶子节点
 @param length 长度
 */

void heap_adjust(int arr[],int node, int length){
    
    int tmp     = arr[node];
    int l_child = 2 * node + 1;
    int r_child = 2 * node + 2;
    int  max_index = node;
    
    if (l_child < length && arr[l_child] > tmp)
    {
        max_index = l_child;
    }
    if(r_child < length && arr[r_child] > tmp)
    {
        max_index = r_child;
    }
    
    if(max_index != node){
        arr[node] = arr[max_index];
        node = max_index;
        arr[max_index] = tmp;
        heap_max_adjust (arr,node,length);
    }
    
}

