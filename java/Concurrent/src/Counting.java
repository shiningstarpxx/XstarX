
public class Counting {

  public static void main(String[] args) throws InterruptedException {
    class Counter {
      private int count = 0;
      /* 如果不加synchronized，那么就无法保证竞态，count会有问题 */
      public synchronized void increment() { ++count; }
      /* 潜在bug，此处不加synchronized, 得到count有可能会有问题 */
      public int getCount() { return count; }
    }
    
    final Counter counter = new Counter();
    
    class CountingThread extends Thread {
      public void run() {
        for (int x = 0; x < 10000; ++x) {
          counter.increment();
        }
      }
    }
    
    CountingThread t1 = new CountingThread();
    CountingThread t2 = new CountingThread();
    t1.start();
    t2.start();
    t1.join();
    t2.join();
    System.out.println(counter.getCount());
  }
}
