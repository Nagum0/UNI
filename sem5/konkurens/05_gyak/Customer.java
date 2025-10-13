class Customer {
    Bank bank;
    int loan;

    public Customer(Bank bank) {
        this.bank = bank;
        loan = 0;
    }

    synchronized int getLoan() {
        return loan;
    }

    synchronized void addLoan(int n) {
        loan += n;
        bank.addLoan(n);
    }
}
