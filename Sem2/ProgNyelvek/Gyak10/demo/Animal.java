public class Animal {
    private String color;

    public Animal(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Animal color: " + color;
    }
}