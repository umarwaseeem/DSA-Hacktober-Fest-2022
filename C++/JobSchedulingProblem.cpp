class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool myComp(Job j1, Job j2)
    {
        if(j1.profit==j2.profit)
            return j1.dead>j2.dead;
            
        return j1.profit>j2.profit;
    }
     
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int jobs=0;
        int totalProfit=0;
        
        bool schedule[n];
        
        for(int i=0; i<n; i++)
            schedule[i]=0;
        
        sort(arr, arr+n, myComp);
        
        for(int i=0; i<n; i++)
        {
            int j=arr[i].dead;
            j--;
            
            while(j>=0)
            {
                if(schedule[j]==0)
                {
                    totalProfit+=arr[i].profit;
                    jobs++;
                    schedule[j]=1;
                    break;
                }
                j--;
            }
        }
        
        vector<int>ans;
        ans.push_back(jobs);
        ans.push_back(totalProfit);
        
        return ans;
    } 
};
