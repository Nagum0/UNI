package walking.game;

class Main {
    public static void main(String[] args) {
        WalkingBoardWithPlayers wbs = new WalkingBoardWithPlayers(5, 3);
        System.out.println(wbs.toString());
        
        wbs.walk(
            1,2,3,
            4,5,6,
            2,1,1
        );

        System.out.println(wbs.toString());
        
        /* wbs.walk(1,2,3);
        System.out.println(wbs.toString());
        wbs.walk(4,5,6);
        System.out.println(wbs.toString());
        wbs.walk(2,1,1);
        System.out.println(wbs.toString()); */
    }

    /* public int[] walk(int... stepCounts)
    {
        int[] scores = new int[players.length];
        for(int j = 0; j<stepCounts.length; j++)
        {
            players[round].turn();
            for(int i = 0; i<stepCounts[round]; i++)
            {
                if (i < SCORE_EACH_STEP)
                    players[round].addToScore(super.moveAndSet(players[round].getDirection(), j));
                    
                else
                    players[round].addToScore(super.moveAndSet(players[round].getDirection(), SCORE_EACH_STEP));
            }

            for(int i = 0; i<players.length; i++)
            {
                scores[i] = players[i].getScore();
            }
            this.round++;
            while(this.round>=players.length)
                this.round-=players.length;
        }

        return scores;
    } */
}