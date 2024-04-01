public class Carro {
    private String nome;
    private int velocidade;

    public Carro( String nome) {
        this.nome = nome;
        this.velocidade = 0;
    }
    
    public String getNome() {
        return this.nome;
    }

    public int getVelocidade() {
        return this.velocidade;
    }

    public void acelerar() {
        this.velocidade += 5;
    }

    public void reduzir() {
        if (this.velocidade >= 5) {
            this.velocidade -= 5;
        }
    }
}