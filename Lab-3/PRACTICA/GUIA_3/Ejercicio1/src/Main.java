import Clases.Bicicleta;
import Clases.TipoTransporte;
import Clases.Autobus;
import Clases.Tranvia;

public class Main {

    public static void main(String[] args) {

        //1. Crear una instancia de la clase Bicicleta.Crea instancias de cada clase (Autobus, Tranvía, Bicicleta).
        Bicicleta bicicleta = new Bicicleta("1234", TipoTransporte.BICICLETA);
        Autobus autobus = new Autobus(1, 50, TipoTransporte.AUTOBUS);
        Tranvia tranvia = new Tranvia("A", 100, TipoTransporte.TRANVIA);

        // 2. Simula el arranque, la detención y la obtención de la capacidad de cada transporte.
        bicicleta.arrancar();
        bicicleta.detener();
        System.out.println("Capacidad de bicicleta: " + bicicleta.obtenerCapacidad());
        System.out.println();

        autobus.arrancar();
        autobus.detener();
        System.out.println("Capacidad de autobus: " + autobus.obtenerCapacidad());

        System.out.println();
        tranvia.arrancar();
        tranvia.detener();
        System.out.println("Capacidad de tranvia: " + tranvia.obtenerCapacidad());

        // 3. Muestra el tipo de transporte y el estado de cada uno en la consola
        System.out.println();
        System.out.println(bicicleta.toString());
        System.out.println(autobus.toString());
        System.out.println(tranvia.toString());

    }
}