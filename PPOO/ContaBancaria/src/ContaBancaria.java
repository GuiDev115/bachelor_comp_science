import javax.swing.JOptionPane;

public class ContaBancaria {
    private double saldo;
    private double limite;
    private Cliente titular;
    private int numero;
    private static int ultimaContaCriada = 100;
    private static double taxaRendimento = 0.01; // 1% por exemplo


    public ContaBancaria(double saldoInicial, Cliente titular, double limite) {
        this.numero = ++ultimaContaCriada;
        this.saldo = saldoInicial;
        this.titular = titular;
        this.limite = limite;
    }

    public ContaBancaria( Cliente titular, double limite) {
        this(0, titular, limite);  // Chama o outro construtor com saldo inicial zero
    }

    public void render() {
        this.saldo += this.saldo * taxaRendimento;
    }

    public int getNumero(){
        return numero;
    }

    public double consultarSaldo() {
        return this.saldo;
    }

    public void depositar(double valor) {
        this.saldo += valor;
    }

    public boolean sacar(double valor) {
        if (this.saldo - valor < -this.limite) {
            return false;  // Não permite que o saldo fique abaixo do limite
        } else {
            this.saldo -= valor;
            return true;
        }
    }

    public static void setTaxaRendimento(double novaTaxa) {
        taxaRendimento = novaTaxa;
    }

    public void transferir(double valor, ContaBancaria destino) {
        if (this.saldo - valor < -this.limite) {
            JOptionPane.showMessageDialog(null, "Saldo insuficiente.");
        } else {
            JOptionPane.showMessageDialog(null, "Tranferido com sucesso");
            this.sacar(valor);
            destino.depositar(valor);
        }
    }

    public Cliente getTitular(){
        return titular;
    }
}