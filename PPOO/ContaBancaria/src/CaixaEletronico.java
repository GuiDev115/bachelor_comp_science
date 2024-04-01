import javax.swing.JOptionPane;

public class CaixaEletronico {
    private ContaBancaria conta;
    private ContaBancaria conta1;

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void criarConta() {
        String nome = JOptionPane.showInputDialog("Digitte o nome do titular: ");
        String cpf = JOptionPane.showInputDialog("Digite o CPF:");
        Cliente cliente = new Cliente(nome, cpf);

        String opcao = JOptionPane.showInputDialog("Deseja informar saldo inicial? (s/n)");
        if (opcao.equals("s")) {
            String saldoInicialInput = JOptionPane.showInputDialog("Digite o saldo inicial:");
            double saldoInicial = Double.parseDouble(saldoInicialInput);
            conta = new ContaBancaria(saldoInicial, cliente);
        } else {
            conta = new ContaBancaria(cliente);
        }
        JOptionPane.showMessageDialog(null, "Conta criada com o número: " + conta.getNumero());



        nome = JOptionPane.showInputDialog("Criando segunda conta\n\n" + "Digite o nome do titular:");
        cpf = JOptionPane.showInputDialog("Digite o CPF:");
        Cliente cliente1 = new Cliente(nome, cpf);

        opcao = JOptionPane.showInputDialog("Deseja informar saldo inicial? (s/n)");
        if (opcao.equals("s")) {
            String saldoInicialInput = JOptionPane.showInputDialog("Digite o saldo inicial:");
            double saldoInicial = Double.parseDouble(saldoInicialInput);
            conta1 = new ContaBancaria(saldoInicial, cliente1);
        } else {
            conta1 = new ContaBancaria(cliente1);
        }
        JOptionPane.showMessageDialog(null, "Conta criada com o número: " + conta1.getNumero());
        
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public void consultarSaldo() {

        String Str_numero = JOptionPane.showInputDialog("Digite o número da conta:");
        int numero = Integer.parseInt(Str_numero);

        if (numero == conta.getNumero()) {

            if (conta == null) {
                JOptionPane.showMessageDialog(null, "Conta não criada.");
            } else {
                JOptionPane.showMessageDialog(null, "Titular: " + conta.getTitular().getNome());
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

        if (numero == conta.getNumero()) {
            String valorInput = JOptionPane.showInputDialog("Digite o valor a sacar:");
            double valor = Double.parseDouble(valorInput);
            if (!conta.sacar(valor)) {
                JOptionPane.showMessageDialog(null, "Saldo insuficiente.");
            }
        }

        else if (numero == conta1.getNumero()) {
            String valorInput = JOptionPane.showInputDialog("Digite o valor a sacar:");
            double valor = Double.parseDouble(valorInput);
            if (!conta.sacar(valor)) {
                JOptionPane.showMessageDialog(null, "Saldo insuficiente.");
            }
            else{
                JOptionPane.showMessageDialog(null, "Nao foi possivel achar a conta");
            }
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

        JOptionPane.showMessageDialog(null, "Tranferido com sucesso");
    
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
        }while (!opcao.equals("6"));
    }

//---------------------------------------------------------------------------------------------------------------------------------------------------------

    public String exibirMenu(){
        return JOptionPane.showInputDialog(null, "1 - Criar conta\n2 - Consultar saldo\n3 - Depositar\n4 - Sacar\n5 - Transferir\n\n Any - Sair");
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
                default:
                    JOptionPane.showMessageDialog(null, "Até mais !!!");
                    System.exit(0);
            }
    }
}