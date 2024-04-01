import javax.swing.JOptionPane;

public class ExibirTela {
    private Carro[] carros;
    private int contadorCarros;

    public ExibirTela() {
        carros = new Carro[5];
        contadorCarros = 0;
    }

    public void executar() {
        String opcao;
        do {
            opcao = exibirMenu();
            tratarOpcaoMenu(opcao);
        } while (!opcao.equals("5"));
    }

    private String exibirMenu() {
        return JOptionPane.showInputDialog("1. Criar o carro\n2. Acelerar o carro\n3. Reduzir a velocidade\n4. Exibir os dados do carro\n5. Sair");
    }

    private void tratarOpcaoMenu(String opcao) {
        switch (opcao) {
            case "1":
                if (contadorCarros < carros.length) {
                    String modelo = JOptionPane.showInputDialog("Digite o modelo do carro:");
                    carros[contadorCarros] = new Carro(modelo);
                    contadorCarros++;
                } else {
                    JOptionPane.showMessageDialog(null, "Não é possível criar mais carros.");
                }
                break;
            case "2":
            case "3":
                String modelo = JOptionPane.showInputDialog("Digite o modelo do carro:");
                for (int i = 0; i < contadorCarros; i++) {
                    if (carros[i].getNome().equals(modelo)) {
                        if (opcao.equals("2")) {
                            carros[i].acelerar();
                        } else {
                            carros[i].reduzir();
                        }
                        break;
                    }
                }
                break;
            case "4":
                for (int i = 0; i < contadorCarros; i++) {
                    JOptionPane.showMessageDialog(null, "O modelo do carro é: " + carros[i].getNome() + "\nA velocidade do carro é: " + carros[i].getVelocidade());
                }
                break;
            case "5":
                break;
            default:
                JOptionPane.showMessageDialog(null, "Opção inválida.");
        }
    }
}