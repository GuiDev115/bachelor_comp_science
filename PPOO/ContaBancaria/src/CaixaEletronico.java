import javax.swing.JOptionPane;

public class CaixaEletronico {
    private ContaBancaria conta;
    private ContaBancaria conta1;

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

            conta = new ContaBancaria(saldoInicial, cliente, limiteInput);
        } else {
            conta = new ContaBancaria(cliente, limiteInput);
        }
        JOptionPane.showMessageDialog(null, "Conta criada com o número: " + conta.getNumero() + "\n\nNome do titular: " + cliente.getNome());

        nome = JOptionPane.showInputDialog("Criando segunda conta\n\n" + "Digite o nome do titular:");
        cpf = JOptionPane.showInputDialog("Digite o CPF:");
        Cliente cliente1 = new Cliente(nome, cpf);

        String limiteInicial1 = JOptionPane.showInputDialog("Digite o limite inicial:");
        double limiteInput1 = Double.parseDouble(limiteInicial1);

        opcao = JOptionPane.showInputDialog("Deseja informar saldo inicial? (s/n)");
        if (opcao.equals("s")) {
            String saldoInicialInput = JOptionPane.showInputDialog("Digite o saldo inicial:");
            double saldoInicial = Double.parseDouble(saldoInicialInput);

            conta1 = new ContaBancaria(saldoInicial, cliente1, limiteInput1);
        } else {
            conta1 = new ContaBancaria(cliente1, limiteInput1);
        }
        JOptionPane.showMessageDialog(null, "Conta criada com o número: " + conta1.getNumero() + "\n\nNome do titular: " + cliente1.getNome());
        
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void consultarSaldo() {

        String Str_numero = JOptionPane.showInputDialog("Digite o número da conta:");
        int numero = Integer.parseInt(Str_numero);

        if (numero == conta.getNumero()) {

            if (conta == null) {
                JOptionPane.showMessageDialog(null, "Conta não criada.");
            } else {
                JOptionPane.showMessageDialog(null, "Titular: " + conta.getTitular().getNome() + "\n" + "CPF: " + conta.getTitular().getCpf());
                JOptionPane.showMessageDialog(null, "Saldo: " + conta.consultarSaldo());
            }
        }

        else if (numero == conta1.getNumero()) {

            if (conta1 == null) {
                JOptionPane.showMessageDialog(null, "Conta não criada.");
            } else {
                JOptionPane.showMessageDialog(null, "Titular: " + conta1.getTitular().getNome());
                JOptionPane.showMessageDialog(null, "Saldo: " + conta1.consultarSaldo());
            }
        } else {
            System.out.println("Conta não encontrada.");
        }
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void depositar() {

        String Str_numero = JOptionPane.showInputDialog("Digite o número da conta:");
        int numero = Integer.parseInt(Str_numero);

        if (numero == conta.getNumero()) {
                String valorInput = JOptionPane.showInputDialog("Digite o valor a depositar:");
                double valor = Double.parseDouble(valorInput);
                conta.depositar(valor);
        }
        
        else if (numero == conta1.getNumero()) {
                String valorInput = JOptionPane.showInputDialog("Digite o valor a depositar:");
                double valor = Double.parseDouble(valorInput);
                conta1.depositar(valor);
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

        if (numero == conta.getNumero()) {
            if (conta.sacar(valor)) {
                JOptionPane.showMessageDialog(null, "Saque realizado com sucesso.");
            } else {
                JOptionPane.showMessageDialog(null, "Saldo insuficiente.");
            }
        }

        else if (numero == conta1.getNumero()) {
            if (conta1.sacar(valor)) {
                JOptionPane.showMessageDialog(null, "Saque realizado com sucesso.");
            } else {
                JOptionPane.showMessageDialog(null, "Saldo insuficiente.");
            }
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
        if (conta != null && conta.getNumero() == numero) {
            return conta;
        } else if (conta1 != null && conta1.getNumero() == numero) {
            return conta1;
        } else {
            return null;
        }
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void executar(){
        String opcao;
        do{
            opcao = exibirMenu();
            executarMenu(opcao);
        }while (!opcao.equals("8"));
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public String exibirMenu(){
        return JOptionPane.showInputDialog(null, "1 - Criar conta\n2 - Consultar saldo\n3 - Depositar\n4 - Sacar\n5 - Transferir\n6 - Rendimento\n7 - Alterar Rendimento\n\n Any - Sair");
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
                default:
                    JOptionPane.showMessageDialog(null, "Até mais !!!");
                    System.exit(0);
            }
    }
}