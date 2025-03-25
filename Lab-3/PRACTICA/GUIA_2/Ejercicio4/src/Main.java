//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        //Instanciamos un cilindro
        Cilindro cilindro = new Cilindro();
        Cilindro cilindro2 = new Cilindro(5, "Azul", 10);

        //Imprimimos el objeto
        System.out.println("Cilindro 1: \n" + cilindro.toString());

        //Imprimimos el objeto cilindro 2
        System.out.println("\nCilindro 2: \n" + cilindro2.toString());

    }
}