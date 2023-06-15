package banco.dominio;

import java.util.ArrayList;

public class Banco {
    private ArrayList<Cliente> clientes = new ArrayList<Cliente>();
    private static final Banco banco = new Banco();

    private Banco() {
    }

    public static Banco getBanco() {
        return banco;
    }

    public void adicionarCliente(Cliente cliente) {
        clientes.add(cliente);
    }

    public Cliente getCliente(int indice) {
        return clientes.get(indice);
    }

    public ArrayList<Cliente> getCliente(String nome, String sobreNome) {
        ArrayList<Cliente> pesquisados = null;
        for (int i = 0; i < clientes.size(); i++) {
            if (clientes.get(i).getNome() == nome && clientes.get(i).getSobreNome() == sobreNome) {
                pesquisados.add(clientes.get(i));
            }
        }
        return pesquisados;
    }

    public int numeroDeClientes() {
        int i = 0;
        for (Cliente cliente : clientes) {
            i += 1;
        }
        return i;
    }
}
