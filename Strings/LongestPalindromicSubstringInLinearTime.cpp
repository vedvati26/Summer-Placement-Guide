string LongestPalindromeSubString(string text)
{
    int size = 2 * text.size() - 1;
    int* pairs = new int[size]();
    
    
    int longest = 1, index = 0;

    int box = 0, mirror;

    for( int i=1 ; i < size ; i++ )
    {
        int left_c = (i-1)/2;
        int right_c = (i+2)/2;
        
        if( right_c < box )
        {
            int identical = pairs[ mirror - ( i - mirror ) ];

            if(right_c + identical > box+1)
                identical = box+1 - right_c;
            
            right_c += identical;
            pairs[i] = identical;
            left_c -= identical;
            
            if( right_c <= box || right_c == text.size() )
                continue;
        }
        
        while( left_c>=0 && right_c<text.size() && ( text[left_c] == text[right_c] ) )
        {
            left_c--;
            right_c++;
            pairs[i]++;
        }
        
        if(pairs[i] > 1 && right_c-1 > box)
        {
            box = right_c - 1;
            mirror = i;
        }
        
        int length = 2*pairs[i];
        if(i%2==0) length++;
        
        if(length>longest)
        {
            longest = length;
            index = (i+1)/2 - length/2;
        }
    }
    
    return text.substr(index,longest);
}