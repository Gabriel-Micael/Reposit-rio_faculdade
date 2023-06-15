public class Conta {
    private double saldo;

    public Conta(double saldoInicial){
        saldo = saldoInicial;
    }

    public double getSaldo() {
        return saldo;
    }

    public boolean depositar(double valor){
        if(valor >= 0){
            saldo += valor;
            return true;
        }
        return false;
    }

    public boolean sacar(double valor){
        if(saldo >= valor ){
            saldo -= valor;
            return true;
        }
        return false;
    }
}
