import Clases.Murcielago;
import Clases.Pato;
import Clases.Pez;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Pato pato = new Pato("Donald");
        Murcielago murcielago = new Murcielago("Bruce");
        Pez pez = new Pez("Nemo");

        pato.comer();
        pato.dormir();
        pato.hacerSonido();
        pato.volar();
        pato.nadar();

        System.out.println();

        murcielago.comer();
        murcielago.dormir();
        murcielago.hacerSonido();
        murcielago.volar();
        murcielago.colgarse();

        System.out.println();

        pez.comer();
        pez.dormir();
        pez.hacerSonido();
        pez.nadar();

    }
}
