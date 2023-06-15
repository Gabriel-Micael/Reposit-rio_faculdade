import encapsulamento.versao3.Veiculo;

public class TesteVeiculo3 {
    public static void main(String[] args) {
        Veiculo teste = new Veiculo(10000.00);
        System.out.println("Adicionando caixa numero 1 (500kg) : " + teste.adicionaCaixa(500));
        System.out.println("Adicionando caixa numero 1 (500kg) : " + teste.adicionaCaixa(250));
        System.out.println("Adicionando caixa numero 1 (500kg) : " + teste.adicionaCaixa(5000));
        System.out.println("Adicionando caixa numero 1 (500kg) : " + teste.adicionaCaixa(4000));
        System.out.println("Adicionando caixa numero 1 (500kg) : " + teste.adicionaCaixa(300));
        System.out.println("A carga do veículo é: " + teste.getCarga() + "Kg");
    }
}