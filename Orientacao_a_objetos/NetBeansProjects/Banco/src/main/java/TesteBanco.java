import encapsulamento.versao1.Conta;

public class TesteBanco {
    public static void main(String[] args) {
        Conta test = new Conta(1000);
        System.out.println("Sacando R$ 250,00");
        test.sacar(250);
        System.out.println("Depoitando R$ 320,50");
        test.depositar(320.50);
        System.out.println("Sacando R$ 120,00");
        test.sacar(120);
        System.out.println("O saldo da conta  é R$" + test.getSaldo());
    }
}
