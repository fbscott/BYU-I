package currell;

public class Hello {

    public void sayHello(String name) {
        // same as cout in C++
        System.out.println("Hello, " + name + "!");
    }

    public static void main(String[] args) {
        Hello hello = new Hello();

        hello.sayHello("Scott");
    }

}
