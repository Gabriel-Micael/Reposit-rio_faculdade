package encapsulamento.versao1;

public class Conta {
    private double saldo;

    public  Conta(double saldoInicial){
        this.saldo = saldoInicial;
    }

    public double getSaldo() {
        return saldo;
    }

    public void depositar(double saldo) {
        this.saldo += saldo;
    }

    public void sacar(double amount){
        saldo -= amount;
    }
}
