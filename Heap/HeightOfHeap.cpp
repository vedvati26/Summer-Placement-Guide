class Solution{
public:
    int heapHeight(int N, int arr[]){
        int count = 1;
	    int i = 0, mul = 1;
	    while(i < N-1){
	        if(i + mul*2 < N-1)
	            count++;
	        mul *= 2;
	        i += mul;
	    }
	    return count;
    }
};