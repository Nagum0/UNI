package string.utils;

public class IterLetter {
    private String s;
    private int count;
    
    public IterLetter(String s) {
        if (s == null) {
            throw new IllegalArgumentException("NULL XOXO");
        }
        this.s = s;
        this.count = count;
    }

    public void printNext() {
        if (this.count >= this.s.length()) {
            System.out.println();
            return;
        }
        System.out.println(this.s.charAt(this.count));
        this.count++;
    }
}