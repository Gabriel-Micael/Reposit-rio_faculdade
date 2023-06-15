public class ContaPoupanca extends Conta{
    private double taxaRendimento;

    public ContaPoupanca(double saldoInicial, double rendimento){
        super(saldoInicial);
        taxaRendimento = saldoInicial * rendimento;
    }

    public double getTaxaRendimento() {
        return taxaRendimento;
    }

    public void setTaxaRendimento(double saldo, double rendimento) {
        this.taxaRendimento = taxaRendimento;
    }
}
