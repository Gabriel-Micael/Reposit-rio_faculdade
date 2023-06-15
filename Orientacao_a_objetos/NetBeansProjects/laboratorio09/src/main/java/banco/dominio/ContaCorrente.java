package banco.dominio;

public class ContaCorrente extends Conta {
    private double chequeEspecial;

    public ContaCorrente(double saldoInicial, double chequeEspecial) {
        super(saldoInicial);
        this.setChequeEspecial(chequeEspecial);
    }

    public ContaCorrente() {
        this(0, 0);
    }

    public ContaCorrente(double saldoInicial) {
        super(saldoInicial);
    }

    public boolean sacar(double valor) {
        if (super.getSaldo() + this.getChequeEspecial() >= valor) {
            super.sacar(valor);
            return true;
        }
        return false;
    }

    public double getChequeEspecial() {
        return chequeEspecial;
    }

    public void setChequeEspecial(double chequeEspecial) {
        this.chequeEspecial = chequeEspecial;
    }
}
