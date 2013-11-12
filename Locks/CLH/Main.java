import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main 
{
	static Counter counter;
	
	public static void main(String[] args) throws InterruptedException, NumberFormatException, IOException 
	{
			
			
			System.out.println("Enter Number of Threads : ");
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int num_threads = Integer.parseInt(br.readLine().trim());
			
			System.out.println("Enter number of iterations for each thread : ");
			br = new BufferedReader(new InputStreamReader(System.in));
			int num_iterations = Integer.parseInt(br.readLine().trim());
			
			
			counter = new Counter(20,num_iterations);
			
			Thread [] threads = new Thread[num_threads];;
			
			for(int i=0;i<num_threads;++i)
			{
				threads[i]=new Thread(counter);
				threads[i].start();
			}
			
					
			

			
			long startTime = System.currentTimeMillis();
			
			for(Thread thread : threads)
			{
				thread.join();
			}
			long endTime = System.currentTimeMillis();
			System.out.println("Time Required : " + (endTime - startTime)/1000.00 + " seconds");
			
			
	}
 
}