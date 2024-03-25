# Lambdas

* **Lambdas **can only be used with certain types of interfaces

## Interfaces

* **Interface**
    * An interface is like a contract
    * Any class that implements that interfact has to provide an implementation
      of methods specified in that interface  

Take for example, an interface `Printable`, which has a method `print()`. Notice 
that by itself, it does not have an implementation. It does not need one, as any 
class that implements this interface will provide its own implementation.  

```java
public interface Printable {
    void print();
}
```

How do we implement an interface? We need to do two things. Use the `implements` 
keyword to define which interface we are implementing, and to define all of 
our interfact implementations.  

```java
public class Cat implements Printable {
    public String name;
    public int age;

    public Cat() {}

    public void print() {
        System.out.print("Meow\n");
    }
}
```

Now we can use the `print` method to print our `Printable` object in main.  

```java
public class Lambdas {
    public static void main(String[] args) {
        Cat cat = new Cat();
        cat.print();
    }

    static void printThing(Printable thing) {
        thing.print();
    }
}
```

Notice that we also have a static void function `printThing`, which takes in a
`Printable` object. Since it is a printable object, we know that it has access
to the `print` method.

```java
public class Lambdas {
    public static void main(String[] args) {
        Cat cat = new Cat();
        printThing(cat);
    }

    static void printThing(Printable thing) {
        thing.print();
    }
}
```

## Lambdas

With the above example, here are the things that we did in order to print to 
the screen.

1. Class has to implement our interface (using `implement` keyword)
2. Class has to actually provide an implementation of the `print` method
3. Create a new object of that class (in main)
4. Only at that point could we pass that object into the method that takes
   a `Printable` parameter  

*Lambdas* allow us to pass in the implementation of the method as the Printable 
parameter itself. Note that lambdas are defined using the arrow `->` operator.

```java
public class Lambdas {
    public static void main(String[] args) {
        printThing(
            () -> { System.out.println("Meow"); }
        );
    }

    // This function is still required, we just pass the implementation
    // of the thing into the function
    public static void printThing(Printable thing) {
        thing.print();
    }
}
```

i.e. Instead of sending in an object that contains an actions, we just send 
the action itself. See that we no longer have to instantiate a `Cat` for there
to be a 'Meow' (lambda = ghost cat?).

### More Lambda Buffoonery

We can also save our lambda as a `Printable` object (this is fucking wizardry).

```java
public class Lambdas {
    Printable ghostCat = () -> System.out.println("Meow);
    printThing(ghostCat);
}
```

## The "Simple" Summary

Java allows you to use lambdas in order to make method implementations INTO objects 
that can be saved into variables or passed into functions.
