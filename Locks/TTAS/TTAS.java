/*
IMPLEMENTATION OF TEST-TEST-AND-SET LOCK

*/

import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;


public class TTAS implements Lock{

	AtomicBoolean state = new AtomicBoolean(false);
	
	
	@Override
	public void lock() {
		while (true) {
			while (state.get()) {};
			if (!state.getAndSet(true))
			return;
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
