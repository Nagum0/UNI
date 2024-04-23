import walking.game.*;

class Main {
    public static void main(String[] args) {
        WalkingBoardWithPlayers wbs = new WalkingBoardWithPlayers(4, 3);
        System.out.println(wbs.toString());
        int[] ps = wbs.walk(2, 3, 2, 4, 1, 2, 5, 2, 4);
        System.out.println(wbs.toString());
    }
}