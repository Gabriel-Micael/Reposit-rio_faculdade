package banco.dominio;

import java.util.List;

public class Banco {
    private List<Cliente> clientes;
    private static final Banco banco = new Banco();

    private Banco(){
    }

    public static Banco getBanco() {
        return banco;
    }

    public void adicionarCliente(Cliente cliente){
        this.clientes.add(cliente);
    }

    public Cliente getCliente(int indice){
        return clientes.get(indice);
    }

    public List<Cliente> getCliente(String nome, String sobreNome){
        List<Cliente> pesquisados = null;
        for(int i = 0; i < clientes.size(); i++){
            if(clientes.get(i).getNome() == nome && clientes.get(i).getSobreNome() == sobreNome){
                pesquisados.add(clientes.get(i));
            }
        }
        return pesquisados;
    }

    public int numeroDeClientes(){
        int i = 0;
        for(Cliente cliente:clientes){
            i += 1;
        }
        return i;
    }
}
