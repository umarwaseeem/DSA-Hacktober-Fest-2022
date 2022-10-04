class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        multimap<int, int, greater<int>>mp;//profit->deadline
        int maxi=INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            mp.insert({arr[i].profit, arr[i].dead});
            maxi=max(maxi, arr[i].dead);
        }
        
        
        int k=0;
        int cnt=0;
        int profit=0;
        bool avail[maxi+1];
        
        for(int i=0; i<=maxi; i++)
            avail[i]=false;
        
        avail[0]=true;
        
        for(auto it:mp)
        {
            int k=it.second;
            while(k)
            {
                if(avail[k]==false)
                {
                    avail[k]=true;
                    profit+=it.first;
                    cnt++;
                    break;
                }
                k--;
            }
        }
        
        vector<int>ans;
        ans.push_back(cnt);
        ans.push_back(profit);
        
        return ans;
    } 
};
