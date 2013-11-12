/*
IMPLEMENTATION OF CLH LOCK
*/
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicReference;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;


public class CLHLock implements Lock{

	private final AtomicReference<QNode> tail;
	private final ThreadLocal<QNode> myPred;
	private final ThreadLocal<QNode> myNode;

	public CLHLock() {
		tail = new AtomicReference<QNode>(new QNode());
		myNode = new ThreadLocal<QNode>(){
			protected QNode initialValue() {
				return new QNode();
			}
		};
		
		myPred = new ThreadLocal<QNode>();
	}
	
	
	
	@Override
	public void lock() {
		QNode qnode = myNode.get();
		qnode.locked = true;
		QNode pred = tail.getAndSet(qnode);
		myPred.set(pred);
		while (pred.locked) {}
	
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
		QNode qnode = myNode.get();
		qnode.locked = false;
		myNode.set(myPred.get());
	
	}

}
