namespace HF7;

public class Customer {
    private string pin;
    private int withdraw;
    public List<Account> accounts;

    public Customer(string pin, int withdraw) {
        this.pin = pin;
        this.withdraw = withdraw;
        accounts = new List<Account>();
    }

    public void Withdrawal(ATM atm) {
        atm.Process(this);
    }

    public void AddAccount(Account a) {
        accounts.Add(a);
    }

    public Card ProvidesCard() {
        return accounts[0].cards[0];
    }

    public string ProvidesPIN() {
        return pin;
    }

    public int RequestMoney() {
        return withdraw;
    }
}
