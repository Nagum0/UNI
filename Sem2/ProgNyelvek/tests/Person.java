package tests;

public class Person {
    public String name;
    int age;
    String[] hobbies;
    boolean employed;

    public Person(String name, int age, String[] hobbies, boolean employed) {
        this.name = name;
        this.age = age;
        this.hobbies = hobbies;
        this.employed = employed;
    }

    public void getData() {
        System.out.println("Person =\n\tName: " + this.name + "\n\tAge: " + this.age + "\n\tHobbies: " + this.hobbies + "\n\tEmployed: " + this.employed);
    }
}