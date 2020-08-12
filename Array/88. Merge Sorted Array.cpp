void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int tot = m+n-1;
        
        
        if(m==0){
            for(int i=0 ; i<n ; i++){
                nums1[i] = nums2[i];
            }
            return;
        }
        m--,n--;
        bool flag = true;
        while(tot + 1 && n + 1){
            if(flag && nums1[m] >= nums2[n]){
                nums1[tot] = nums1[m];
                if(m-1>=0){
                    m--;
                }else 
                    flag = false;
            }else {
                nums1[tot] = nums2[n];
                n--;
            }
            tot--;
            
        }
}