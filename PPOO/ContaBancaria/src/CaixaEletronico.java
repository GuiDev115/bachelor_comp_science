import java.util.ArrayList;

import javax.swing.JOptionPane;

public class CaixaEletronico {
    
    private ArrayList<ContaBancaria> contas;

    public CaixaEletronico() {
        this.contas = new ArrayList<>();
    }

    public void renderConta() {
        String Str_numero = JOptionPane.showInputDialog("Digite o número da conta:");
        int numero = Integer.parseInt(Str_numero);

        ContaBancaria conta = this.encontrarConta(numero);

        if (conta != null) {
            conta.render();
            JOptionPane.showMessageDialog(null, "Rendimento aplicado. Novo saldo: " + conta.consultarSaldo());
        } else {
            JOptionPane.showMessageDialog(null, "Conta não encontrada.");
        }
    }

//-------------------------------------------------------------------------------------------------------------------------------------------

private void listarContas() {
    for (ContaBancaria conta : contas) {
        JOptionPane.showMessageDialog(null, "Número da conta: " + conta.getNumero() + ", Nome do cliente: " + conta.getTitular().getNome());
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

public void alterarTaxaRendimento() {
    String strTaxa = JOptionPane.showInputDialog("Digite a nova taxa de rendimento (em decimal):");
    double novaTaxa = Double.parseDouble(strTaxa);

    ContaBancaria.setTaxaRendimento(novaTaxa);

    JOptionPane.showMessageDialog(null, "Taxa de rendimento alterada para " + novaTaxa);
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void criarConta() {
        String nome = JOptionPane.showInputDialog("Digitte o nome do titular: ");
        String cpf = JOptionPane.showInputDialog("Digite o CPF:");
        Cliente cliente = new Cliente(nome, cpf);

        String limiteInicial = JOptionPane.showInputDialog("Digite o limite inicial:");
        double limiteInput = Double.parseDouble(limiteInicial);

        String opcao = JOptionPane.showInputDialog("Deseja informar saldo inicial? (s/n)");
        if (opcao.equals("s")) {
            String saldoInicialInput = JOptionPane.showInputDialog("Digite o saldo inicial:");
            double saldoInicial = Double.parseDouble(saldoInicialInput);

            contas.add(new ContaBancaria(saldoInicial, cliente, limiteInput));
        } else {
            contas.add(new ContaBancaria(cliente, limiteInput));
        }
        JOptionPane.showMessageDialog(null, "Conta criada com o número: " + contas.get(contas.size() - 1).getNumero() + "\n\nNome do titular: " + cliente.getNome());
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void consultarSaldo() {

        String Str_numero = JOptionPane.showInputDialog("Digite o número da conta:");
        int numero = Integer.parseInt(Str_numero);

        ContaBancaria conta = this.encontrarConta(numero);

        if (conta != null) {
            JOptionPane.showMessageDialog(null, "Titular: " + conta.getTitular().getNome() + "\n" + "CPF: " + conta.getTitular().getCpf() + "\nSaldo: " + conta.consultarSaldo());

        } else {
            System.out.println("Conta não encontrada.");
        }
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void depositar() {

        String Str_numero = JOptionPane.showInputDialog("Digite o número da conta:");
        int numero = Integer.parseInt(Str_numero);

        ContaBancaria conta = this.encontrarConta(numero);

        if (numero == conta.getNumero()) {
                String valorInput = JOptionPane.showInputDialog("Digite o valor a depositar:");
                double valor = Double.parseDouble(valorInput);
                conta.depositar(valor);
        }

        else{
            JOptionPane.showMessageDialog(null, "Nao foi possivel achar a conta");
        }
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void sacar() {
        String Str_numero = JOptionPane.showInputDialog("Digite o número da conta:");
        int numero = Integer.parseInt(Str_numero);
        String Str_valor = JOptionPane.showInputDialog("Digite o valor a ser sacado:");
        double valor = Double.parseDouble(Str_valor);

        ContaBancaria conta = this.encontrarConta(numero);

        if (numero == conta.getNumero()) {
            if (conta.sacar(valor)) {
                JOptionPane.showMessageDialog(null, "Saque realizado com sucesso.");
            } else {
                JOptionPane.showMessageDialog(null, "Saldo insuficiente.");
            }
        }

        else {
            JOptionPane.showMessageDialog(null, "Conta não encontrada.");
        }
    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------

public void removerConta() {
    String numeroConta = JOptionPane.showInputDialog("Informe o número da conta a ser removida:");
    int numero = Integer.parseInt(numeroConta);

    ContaBancaria contaARemover = null;
    for (ContaBancaria conta : contas) {
        if (conta.getNumero() == numero) {
            if (conta.consultarSaldo() > 0) {
                JOptionPane.showMessageDialog(null, "Não é possível cancelar contas com saldo disponível.");
                return;
            } else if (conta.consultarSaldo() < 0) {
                JOptionPane.showMessageDialog(null, "Não é possível cancelar contas em débito.");
                return;
            } else {
                contaARemover = conta;
                break;
            }
        }
    }

    if (contaARemover != null) {
        contas.remove(contaARemover);
        JOptionPane.showMessageDialog(null, "Conta removida com sucesso.");
    } else {
        JOptionPane.showMessageDialog(null, "Conta não encontrada.");
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void transferir() {
        String Str_numeroOrigem = JOptionPane.showInputDialog("Digite o número da conta de origem:");
        int numeroOrigem = Integer.parseInt(Str_numeroOrigem);
        String Str_numeroDestino = JOptionPane.showInputDialog("Digite o número da conta de destino:");
        int numeroDestino = Integer.parseInt(Str_numeroDestino);
        String Str_valor = JOptionPane.showInputDialog("Digite o valor a ser transferido:");
        double valor = Double.parseDouble(Str_valor);
    
        ContaBancaria contaOrigem = this.encontrarConta(numeroOrigem);
        ContaBancaria contaDestino = this.encontrarConta(numeroDestino);
    
        if (contaOrigem != null && contaDestino != null) {
            contaOrigem.transferir(valor, contaDestino);
        } else {
            JOptionPane.showMessageDialog(null, "Conta de origem ou de destino não encontrada.");
        }
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public ContaBancaria encontrarConta(int numero) {
        for (ContaBancaria conta : contas) {
            if (conta.getNumero() == numero) {
                return conta;
            }
        }
        return null;
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void executar(){
        String opcao;
        do{
            opcao = exibirMenu();
            executarMenu(opcao);
        }while (!opcao.equals("11"));
    }

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

private void filtrarContasPeloNomeDoCliente() {
    String nome = JOptionPane.showInputDialog("Informe o nome (ou parte do nome) do cliente:");
    boolean isEmpty = false;
    String juntador = "";
    for (ContaBancaria conta : contas) {
        if (conta.getTitular().getNome().contains(nome)) {
            juntador += conta.getNumero() + " - " + conta.getTitular().getNome() + "\n";
        isEmpty = true;
        }
    }
    if (!isEmpty){
        JOptionPane.showMessageDialog(null, "Conta Não Encontrada");
    }
    else{
        JOptionPane.showMessageDialog(null, juntador);
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public String exibirMenu(){
        return JOptionPane.showInputDialog(null, "1 - Criar conta\n2 - Consultar saldo\n3 - Depositar\n4 - Sacar\n5 - Transferir\n6 - Rendimento\n7 - Alterar Rendimento\n8 - Listar Contas\n9 - Remover Conta\n10 - Filtro de Conta\n\n Any - Sair");
    }

    public void executarMenu(String opcao) {    
            switch (opcao) {
                case "1":
                    criarConta();
                    break;
                case "2":
                    consultarSaldo();
                    break;
                case "3":
                    depositar();
                    break;
                case "4":
                    sacar();
                    break;
                case "5":
                    transferir();
                    break;
                case "6":
                    renderConta();
                    break;
                case "7":
                    alterarTaxaRendimento();
                    break;
                case "8":
                    listarContas();
                    break;
                case "9":
                    removerConta();
                    break;
                case "10":
                    filtrarContasPeloNomeDoCliente();
                    break;                 
                default:
                    JOptionPane.showMessageDialog(null, "Até mais !!!");
                    System.exit(0);
            }
    }
}