import encapsulamento.versao2.Veiculo;

public class TesteVeiculo2 {
    public static void main(String[] args) {
        Veiculo teste = new Veiculo(10000.00);
        if(teste.adicionaCaixa(500)){
            System.out.println("Adicionando 500kg...");
        }else{
            System.out.println("Ultapassou o limite de carga");
        }
        if(teste.adicionaCaixa(250)){
            System.out.println("Adicionando 250kg...");
        }else{
            System.out.println("Ultapassou o limite de carga");
        }
        if(teste.adicionaCaixa(5000)){
            System.out.println("Adicionando 500kg...");
        }else{
            System.out.println("Ultapassou o limite de carga");
        }
        if(teste.adicionaCaixa(4000)){
            System.out.println("Adicionando 500kg...");
        }else{
            System.out.println("Ultapassou o limite de carga");
        }
        if(teste.adicionaCaixa(300)){
            System.out.println("Adicionando 500kg...");
        }else{
            System.out.println("Ultapassou o limite de carga");
        }
        System.out.println("A carga no momento é: " + teste.getCarga());
    }
}
