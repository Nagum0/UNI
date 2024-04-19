import walking.game.*;

class Main {
    public static void main(String[] args) {
        WalkingBoardWithPlayers wbs = new WalkingBoardWithPlayers(5, 2);
        wbs.walk(2, 3, 4, 1, 8, 9, 10, 4, 5, 6);
    }
}