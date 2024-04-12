namespace HF7;

public class Bank {
    private List<Account> accounts;

    public Bank() {
        accounts = new List<Account>();
    }

    public void OpenAccount(string cNum, Customer c) {
        accounts.Add(new Account(cNum));
        c.AddAccount(new Account(cNum));
    }

    public void ProvidesCard(string cNum) {
        (bool l, Account acc) = FindAccount(cNum);
        
        if (l) {
            Card card = new Card(cNum, "0000");
            acc.cards.Add(card);
        }
    }

    public int GetBalance(string cNum) {
        (bool l, Account acc) = FindAccount(cNum);
        if (l) 
            return acc.GetBalance();
        return -1;

    }

    public void Transaction(string cNum, int amount) {
        (bool l, Account acc) = FindAccount(cNum);
        if (l)
            acc.Change(amount);
    } 

    public bool CheckAccount(string cNum) {
        (bool l, Account acc) = FindAccount(cNum);
        return l;
    }

    private (bool, Account) FindAccount(string cNum) {
        foreach (Account a in accounts) {
            if (a.accNum == cNum)
                return (true, a);
        }

        return (false, null);
    }
}
