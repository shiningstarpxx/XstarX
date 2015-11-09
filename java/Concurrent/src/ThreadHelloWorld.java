
public class ThreadHelloWorld {
  
  public static void main(String[] args) throws InterruptedException {
    Thread myThread = new Thread() {
      public void run() {
        System.out.println("Hello from new thread");
      }
    };
    
    myThread.start();
    /* 此句表示主线程要让出cpu，那么可能新的线程会得到cpu，但是这个并得不到保证 */
    Thread.yield();
    /* 此句表示主线程要休眠一下，那么新线程将几乎获得cpu，完成打印 */
    // Thread.sleep(1);
    System.out.println("Hello from main thread");
    myThread.join();
  }
}