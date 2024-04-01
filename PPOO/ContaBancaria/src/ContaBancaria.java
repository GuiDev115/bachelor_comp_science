import javax.swing.JOptionPane;

public class ContaBancaria {
    private double saldo;
    private double limite;
    private Cliente titular;
    private int numero;
    private static int ultimaContaCriada = 100;


    public ContaBancaria(double saldoInicial, Cliente titular) {
        this.numero = ++ultimaContaCriada;
        this.saldo = saldoInicial;
        this.titular = titular;
    }

    public ContaBancaria( Cliente titular) {
        this(0, titular);  // Chama o outro construtor com saldo inicial zero
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

    public void transferir(double valor, ContaBancaria destino) {
        if (this.saldo <  valor) {
            JOptionPane.showMessageDialog(null, "Saldo insuficiente.");
        } else {
            this.sacar(valor);
            destino.depositar(valor);
        }
    }

    public Cliente getTitular(){
        return titular;
    }
}