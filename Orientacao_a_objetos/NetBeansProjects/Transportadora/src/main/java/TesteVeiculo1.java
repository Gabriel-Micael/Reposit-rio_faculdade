import encapsulamento.versao1.Veiculo;

public class TesteVeiculo1 {
    public static void main(String[] args) {
        Veiculo teste1 = new Veiculo(10000);
        teste1.carga += 500;
        System.out.println("Adicionando 500kg");
        teste1.carga += 250;
        System.out.println("Adicionando 250kg");
        teste1.carga += 5000;
        System.out.println("Adicionando 5000kg");
        teste1.carga += 4000;
        System.out.println("Adicionando 4000kg");
        teste1.carga += 300;
        System.out.println("Adicionando 300kg");
        System.out.println("Peso no momento é " + teste1.getCarga());
    }
}
