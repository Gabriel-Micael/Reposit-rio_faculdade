package banco.dominio;

import java.util.ArrayList;

public class Cliente {
    private String nome;
    private String sobreNome;
    private ArrayList<Conta> contas = new ArrayList<Conta>();

    public Cliente(String nome, String sobreNome) {
        this.setNome(nome);
        this.setSobreNome(sobreNome);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobreNome() {
        return sobreNome;
    }

    public void setSobreNome(String sobreNome) {
        this.sobreNome = sobreNome;
    }

    public void adicionarConta(Conta conta) {
        contas.add(conta);
    }

    public Conta getConta(Integer id) {
        return contas.get(id);
    }

    public int getNumeroDeContas() {
        return contas.size();
    }
}
