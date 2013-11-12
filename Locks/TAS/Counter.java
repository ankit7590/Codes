
class Counter implements Runnable 
{
	private int value;
	private TAS lock = new TAS();
	int num_iterations;
	
	public Counter(int c,int n) 
	{ 
		value = c;
		num_iterations = n;
	}


	public int getAndIncrement() 
	{
		int temp=0;
			
		//System.out.println("Thread " + (int)(Thread.currentThread().getName().charAt(0) - 'A') + " is trying to enter CS");
		System.out.println("Thread " + Thread.currentThread().getId() + " is trying to enter CS");
		lock.lock();
		System.out.println("Thread " + Thread.currentThread().getId() + " entered CS");
		try
		{
			temp = value;
			value = temp+1;			
			
			System.out.println("Thread " + Thread.currentThread().getId()  + " changed the value from " + temp + " to " + value);
		}
		finally
		{
			System.out.println("Thread " + Thread.currentThread().getId() + " is leaving CS");
			lock.unlock();
			System.out.println("Thread " + Thread.currentThread().getId() + " left CS");
		}
		return temp;
	}
 
	public void run()
	{
		for(int i=0;i<num_iterations;i++)
		{
			getAndIncrement();
			/*try {
				//Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}*/
		}
	}
}
