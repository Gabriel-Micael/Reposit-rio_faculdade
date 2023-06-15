package encapsulamento.versao3;

public class Veiculo {
    private double carga;
    private double cargaMaxima;

    public Veiculo(double cargaMaxima){
        this.cargaMaxima = cargaMaxima;
    }

    public double getCarga() {
        return newtonsParaQuilos(carga);
    }

    public double getCargaMaxima() {
        return newtonsParaQuilos(cargaMaxima);
    }

    public boolean adicionaCaixa(double peso){
        if(this.carga + quilosParaNewtons(peso) <= quilosParaNewtons(cargaMaxima)){
            this.carga += quilosParaNewtons(peso);
            return true;
        }
        return false;
    }

    private double newtonsParaQuilos(double peso){
        return peso*9.8;
    }

    private double quilosParaNewtons(double peso){
        return peso/9.8;
    }
}
