class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
        int start = 0;
        int end=1;
        int cur_pet = p[start].petrol-p[start].distance;
        while(end!=start or cur_pet <0)
        {
            while(cur_pet<0 and  start!=end)
            { 
                cur_pet -=p[start].petrol-p[start].distance;
                start=(start+1)%n;
                if(start==0)
                    return -1;
            }
            cur_pet +=p[end].petrol - p[end].distance;
            end=(end+1)%n;
        }
        return start;
    }
};
