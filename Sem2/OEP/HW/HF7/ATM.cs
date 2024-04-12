namespace HF7;

public class ATM {
    private Center center;
    public string site;

    public ATM(string site, Center center) {
        this.center = center;
        this.site = site;
    }

    public void Process(Customer c) {
        Card card = c.ProvidesCard();

        if (card.CheckPIN(c.ProvidesPIN())) {
            int a = c.RequestMoney();
            if (center.GetBalance(card.cNum) >= a) {
                center.Transaction(card.cNum, -a);
            }
        }
    }
}
