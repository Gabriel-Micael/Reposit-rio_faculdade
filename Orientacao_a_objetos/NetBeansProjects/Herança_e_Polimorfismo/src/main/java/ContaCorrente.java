public class ContaCorrente extends Conta{
    private double chequeEspecial;

    public ContaCorrente(double saldoInicial){
        super(saldoInicial);
    }

    public ContaCorrente(double saldoInicial, double chequeEspecial){
        super(saldoInicial);
        this.setChequeEspecial(chequeEspecial);
    }
    public boolean sacar(double valor){
        if(this.getSaldo() + this.getChequeEspecial() >= valor){
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
