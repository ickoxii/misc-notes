public class Main {
    public static void main(String[] args) {
        Printable ghostCat = () -> System.out.println("Meow");
        printThing(ghostCat);
    }

    public static void printThing(Printable thing) {
        thing.print();
    }
}
