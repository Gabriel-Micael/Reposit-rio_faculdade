import java.sql.SQLOutput;

public class TesteBanco {
    public static void main(String[] args) {
        Cliente brunoHenrique = new Cliente("Bruno", "Henrique");
        System.out.println("Criando o Cliente Bruno Henrique");
        Conta contabrunoHenrique = new Conta(50000);
        brunoHenrique.setConta(contabrunoHenrique);
        Conta test = brunoHenrique.getConta();
        System.out.println("Criando conta para Bruno Henrique");
        System.out.println("Sacando R$1.200,00: " +test.sacar(1200));
        System.out.println("Depositando R$8.525,00: " +test.depositar(8525));
        System.out.println("Sacando R$1.200,00: " +test.sacar(12800));
        System.out.println("Sacando R$50.000,00: " +test.sacar(50000));
        System.out.println("O saldo da conta é R$" + test.getSaldo());
    }
}
