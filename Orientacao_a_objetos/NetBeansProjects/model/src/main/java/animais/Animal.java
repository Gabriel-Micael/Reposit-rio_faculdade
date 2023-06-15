package animais;

public class Animal {
    private String nome;
    private int numeroDePernas;

    protected Animal(String nome, int numeroDePernas) {
        this.setNome(nome);
        this.setNumeroDePernas(numeroDePernas);
    }


    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getNumeroDePernas() {
        return numeroDePernas;
    }

    public void setNumeroDePernas(int numeroDePernas) {
        this.numeroDePernas = numeroDePernas;
    }

    public void caminhar() {
        System.out.println(nome + " anda com " + numeroDePernas + "pernas.");
    }

    public void comer() {

    }
}
