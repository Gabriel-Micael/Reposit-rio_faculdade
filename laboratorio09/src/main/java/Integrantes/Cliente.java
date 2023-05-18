package Integrantes;

import java.util.List;

public class Cliente {
    private String nome;
    private String sobreNome;
    private List<Conta> contas;

    public Cliente(String nome, String sobreNome){
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

    public void adicionarConta(Conta conta){
        this.contas.add(conta);
    }

    public Conta getConta(Integer id){
        return this.contas.get(id);
    }

    public int getNumeroDeContas(){
        return this.contas.size();
    }
}
