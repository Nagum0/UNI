import tests.Person;

public class HelloWorld {
    public static void main(String[] args) {
        String[] hbs = {"Coding", "Gaming", "Manga"};
        Person person = new Person("Zeki", 19, hbs, false);
        person.getData();
    }
}