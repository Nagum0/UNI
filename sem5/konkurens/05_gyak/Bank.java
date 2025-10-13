class Bank {
    int loan;

    public Bank() {
        loan = 0;
    }

    synchronized int getLoan() {
        return loan;
    }

    synchronized void addLoan(int n) {
        loan += n;
    }
}
