import java.util.*;
class Fruit {
    String fruit;
    int quantity;
    boolean available = false;
 
    public synchronized void produce(String fruit) {
        // if fruit is available, producer has to wait until consumer consumes it
        while (available) {
            try {
                wait();
            } catch (InterruptedException ie) {
                ie.printStackTrace();
            }
        }
        this.fruit = fruit;
        System.out.println("Producer has produced " + fruit);
        available = true;
        notify();
    }
 
    public synchronized void consume() {
        // if fruit is not available, consumer has to wait until producer produces one
        while (!available) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        available = false;
        System.out.println("Consumer has consumed " + fruit);
        this.fruit = "";
        notify();
    }
 
    public int getQuantity() {
        return quantity;
    }
 
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
}

class Producer extends Thread {
    Fruit fruit;

    public Producer(Fruit f) {
        this.fruit = f;
    }

    public void run() {
        List<String> fruits = new ArrayList<String>(0);
        fruits.add("Apple");
        fruits.add("Orange");
        fruits.add("Papaya");
        fruits.add("Banana");
        fruits.add("Watermelon");
        fruits.add("Grapes");
        fruit.setQuantity(fruits.size());
        for (String f : fruits) {
            fruit.produce(f);
            try {
                sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}


 

         
class Consumer extends Thread {
    private Fruit fruit;
 
    public Consumer(Fruit f) {
        this.fruit = f;
    }
 
    public void run() {
        int i = 0;
        do {
            fruit.consume();
            try {
                sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            i++;
        } while (i < fruit.getQuantity());
    }
}


public class ProducerConsumerTest {
    public static void main(String[] args) {
        Fruit f = new Fruit();
        Producer p = new Producer(f);
        Consumer c = new Consumer(f);
        p.start();
        c.start();
    }
}