package election.candidate;

public enum Candidate {
    JACK("Judea Nepfront 1"),
    JILL("Judea Nepfront 2"),
    SAM("Judea Nepfront 3"),
    MAX("Judea Nepfront 4");

    public String party;

    Candidate(String party) {
        this.party = party;
    }
}
