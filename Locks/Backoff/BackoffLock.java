/*
IMPLEMENTATION OF BACKOFF LOCK
*/

import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;


public class BackoffLock implements Lock{

	private AtomicBoolean state = new AtomicBoolean(false);
	private static int MIN_DELAY ;
	private static int MAX_DELAY ;

	public BackoffLock(int min,int max) {
		MIN_DELAY = min;
		MAX_DELAY = max;
		
	}
	
	
	
	@Override
	public void lock() {
		Backoff backoff = new Backoff(MIN_DELAY, MAX_DELAY);
		while (true) 
		{
			while (state.get()) {};
			if (!state.getAndSet(true)) 
			{
				return;
			}
			else 
			{
				try 
				{
					backoff.backoff();
				} catch (InterruptedException e) 
				{
					
					e.printStackTrace();
				}
			}
		}

		
	}

	@Override
	public void lockInterruptibly() throws InterruptedException {
		// TODO Auto-generated method stub
		
	}

	@Override
	public Condition newCondition() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean tryLock() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean tryLock(long arg0, TimeUnit arg1)
			throws InterruptedException {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void unlock() {
		state.set(false);

		
	}

}
