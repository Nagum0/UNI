namespace HF7;

public class Bank {
    private List<Account> accounts;

    public Bank() {
        accounts = new List<Account>();
    }

    public void OpenAccount(string cNum, Customer c) {
        Account acc = new Account(cNum);
        accounts.Add(acc);
        c.AddAccount(acc);
    }

    public void ProvidesCard(string cNum) {
        (bool l, Account acc) = FindAccount(cNum);
        
        if (l) {
            Card card = new Card(cNum, "1234");
            acc.cards.Add(card);
            /* Console.WriteLine("\t-- Account found! -> Bank.ProvidesCard()");
            Console.WriteLine($"\t-- accNum: {cNum} cards1: {acc.cards[0].cNum} -> Bank.ProvidesCard()"); */
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
        if (l) {
            acc.Change(amount);
            /* Console.WriteLine("\t-- Account found! -> Bank.Transaction()"); */
        }
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
