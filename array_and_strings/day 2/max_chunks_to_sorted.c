int maxChunksToSorted(int* arr, int arrSize) {
    int c=0,max=arr[0];
    for(int i=0;i<arrSize;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(max==i) c++;
    }
    return c;
}
