import election.candidate.*;

public class Array {

    // Itt megadhatunk sok int argot:
    public static void foo(int... args) {
        for (int num : args) {
            System.out.println(num);
        }
    }

    public static void main(String args[]) {
        int array[] = new int[10];
        
        for (int i = 0; i < array.length; i++) {
            array[i] = i;
        }
        
        for (int num : array) {
            System.out.println(num);
        }
        
        // Ez csak uj pointert hoz letre:
        int copy[] = array;
            
        // Full copy:
        int fullCopy[] = java.util.Arrays.copyOf(array, array.length);

        foo(1,69,8);

        System.out.println(Candidate.JILL.party);
    }
}
