import walking.game.*;

class Main {
    public static void main(String[] args) {
        WalkingBoardWithPlayers wbs = new WalkingBoardWithPlayers(5, 2);
        int[] ps = wbs.walk(2,3,2,4,2,2,1,2);
        
        System.out.println(wbs.toString());

        for (int i : ps)
            System.out.println(i);
    }
}