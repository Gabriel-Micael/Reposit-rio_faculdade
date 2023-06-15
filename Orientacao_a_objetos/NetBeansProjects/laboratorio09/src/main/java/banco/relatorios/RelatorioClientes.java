package banco.relatorios;

import banco.dominio.Banco;
import banco.dominio.Cliente;
import banco.dominio.ContaCorrente;
import banco.dominio.ContaPoupanca;

public class RelatorioClientes {
    private Banco banco = Banco.getBanco();

    public void gerarRelatorio() {
        System.out.println("=====================:\n" +
                "RELATÓRIO DE CLIENTES" + "\n" +
                "=====================:\n");
        for (int i = 0; i < banco.numeroDeClientes(); i++) {
            for (int j = 0; j < banco.getCliente(i).getNumeroDeContas(); j++) {
                System.out.println("Cliente........: " + banco.getBanco().getCliente(i).getNome() + " " + banco.getBanco().getCliente(i).getSobreNome());
                if (banco.getCliente(i).getConta(j) instanceof ContaCorrente) {
                    System.out.println("Tipo da Conta..: Conta corrente" + "\n" +
                            "Cheque especial: " + ((ContaCorrente) banco.getCliente(i).getConta(j)).getChequeEspecial() + "\n" +
                            "Saldo real.....: " + ((ContaCorrente) banco.getCliente(i).getConta(j)).getSaldo() + "\n");
                }
                if (banco.getCliente(i).getConta(j) instanceof ContaPoupanca) {
                    System.out.println("Tipo da Conta..: Conta corrente" +"\n" +
                            "Saldo real.....: " + banco.getCliente(i).getConta(j).getSaldo() + "\n");
                }
            }
        }
    }
}
