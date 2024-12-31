import java.util.*;

class Producer implements Runnable {
    private final List<Integer> taskq; // producers own queue
    private final int max; // only prodcuer has means to decide capacity

    public Producer(List<Integer> sharedq, int size) {// constructor
        this.taskq = sharedq; // the given queue is initialised
        this.max = size;
    }

    public void run() { // this is the abstract method to override
        int c = 1;
        while (true) {
            try {
                produce(c++);
            } catch (InterruptedException e) {
                System.out.println("Interrupted Execution at Producers side");
                e.printStackTrace();
            }
        }
    }

    private void produce(int i) throws InterruptedException {
        synchronized (taskq) // to ensure only single thread has access to taskq
        {
            while (taskq.size() == max) // once queue is full
            {
                System.out.println("Buffer Overflow"); // print
                System.out.println(Thread.currentThread().getName() + " is waiting , size:  " + taskq.size());
                taskq.wait(); // suspend thread until notifyall is called by consumer
            }
            Thread.sleep(1000);// sleep till one second
            taskq.add(i); // add it to queue
            System.out.println("produced: " + i); // indiciate produce
            taskq.notifyAll();
        }
    }
}

class Consumer implements Runnable {
    private final List<Integer> taskq;

    public Consumer(List<Integer> sharedq) {
        this.taskq = sharedq;
    }

    public void run() {
        while (true) {
            try {
                consume();
            } catch (InterruptedException e) {
                System.out.println("Interrupted Execution at Consumers side");
                e.printStackTrace();
            }
        }
    }

    private void consume() throws InterruptedException {
        synchronized (taskq) {
            while (taskq.isEmpty()) {
                System.out.println("Buffer Underflow ");
                System.out.println(Thread.currentThread().getName() + " is waiting,size: " + taskq.size());
                taskq.wait();
            }
            Thread.sleep(1000);
            int i = (Integer) taskq.remove(0);
            System.out.println("consumed: " + i);
            taskq.notifyAll();
        }
    }
}

public class Producer_consumer

{
    public static void main(String args[]) {
        System.out.println(">-------------------------Producer Consumer Problem-------------------------<");
        List<Integer> taskq = new ArrayList<Integer>();
        int max = 3;
        Thread tp = new Thread(new Producer(taskq, max), "Producer");
        Thread tc = new Thread(new Consumer(taskq), "Consumer");
        tp.start();
        tc.start();
    }
}