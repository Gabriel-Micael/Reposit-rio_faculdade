package banco.relatorios;

import banco.dominio.Banco;
import banco.dominio.Cliente;
import banco.dominio.ContaCorrente;

public class RelatorioClientes {
    private Banco banco;

    private void gerarRelatorio(){
        System.out.println("=====================:\n" +
                           "RELATÓRIO DE CLIENTES" +
                           "=====================:\n");
        for(int i = 0; i < banco.numeroDeClientes(); i++) {
            if(banco.getCliente(i).getConta(0) instanceof ContaCorrente){
                System.out.println( "Cliente......: " + banco.getBanco().getCliente(i).getNome() + " " + banco.getBanco().getCliente(i).getSobreNome() + "\n" +
                                    "ContaCorrente: " + banco.getBanco().getCliente(i).getConta(0).getSaldo() +
                                    "" +
                                    "" );
            }
        }
    }
}
