package Integrantes;

public class ContaCorrente extends Conta{
    private double chequeEspecial;

    public ContaCorrente(double saldoinicial, double chequeEspecial){
        super(saldoinicial);
        this.setChequeEspecial(chequeEspecial);
    }

    public ContaCorrente(){
        this(0,0);
    }

    public boolean sacar(double valor){
        if(super.getSaldo() + this.getChequeEspecial() >= valor){
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
