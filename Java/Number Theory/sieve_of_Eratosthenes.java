static int N=1_000_000_5;
	static boolean prime[] = new boolean[N];
	static int pf[] = new int[N];
	static void sieve()
	{
	    for(int i=1;i<N;++i)
	        prime[i]=true;
	    prime[1] = false;
	    for(int i=2;i*i<N;++i)
	    {
	        if(prime[i])
	        {
	            for(int k=i*i;k<N;k+=i)
	            {
	                prime[k]=false;
	                pf[k]=i;
	            }
	        }
	    }
	    for(int i=1;i<N;++i) {
	    	if(prime[i])pf[i] = i;
	    }
	}
	
	static void getFactorization(int x)
    {
        
        while (x != 1)
        {
            System.out.print(pf[x]+" ");
            x = x / pf[x];
        }
    }
	 
	public static void process() throws IOException {

		sieve();
		getFactorization(10);

	}
