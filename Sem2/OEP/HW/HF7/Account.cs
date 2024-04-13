namespace HF7;

public class Account {
    public string accNum;
    private int balance;
    public List<Card> cards;

    public Account(string cNum) {
        accNum = cNum;
        balance = 0;
        cards = new List<Card>();
    }

    public int GetBalance() {
        return balance;
    }

    public void Change(int a) {
        balance += a;
        /* Console.WriteLine($"\t-- accNum: {this.accNum}; balance: {this.balance} -> Account.Change()"); */
    }
}
