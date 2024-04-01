import java.util.Scanner;

public class Raiz {

    public static void main(String[] args) {
        System.out.println("Digite um número: ");
        Scanner sc = new Scanner(System.in);
        double e = sc.nextDouble();
    
        System.out.println("Resultado: " + Math.sqrt(e));
    }
}
