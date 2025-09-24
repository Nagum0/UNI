namespace HF7;

public class Center {
    private List<Bank> banks;

    public Center(List<Bank> banks) {
        this.banks = banks;
    }

    public int GetBalance(string cNum) {
        (bool l, Bank bank) = FindBank(cNum);
        if (l)
            return bank.GetBalance(cNum);
        return -1;
    }

    public void Transaction(string cNum, int amount) {
        (bool l, Bank bank) = FindBank(cNum);
        if (l)
            bank.Transaction(cNum, amount);
    }

    private (bool, Bank) FindBank(string cNum) {
        foreach (Bank b in banks) {
            if (b.CheckAccount(cNum))
                return (true, b);
        }

        return (false, null);
    }
}
