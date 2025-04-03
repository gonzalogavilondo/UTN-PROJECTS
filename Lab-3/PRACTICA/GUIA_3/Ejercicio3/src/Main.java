import Clases.Autobus;
import Clases.Automovil;
import Clases.Camion;
import Clases.Vehiculo;

import java.util.ArrayList;


public class Main {
    public static void main(String[] args) {

        // Instanciamos un Automovil
        Vehiculo vehiculo_1 = new Automovil("Chevrolet", 2023, 160, 5);
        Vehiculo vehiculo_2 = new Automovil("Gol", 2024, 180, 2);

        // Instanciamos un Camion
        Vehiculo vehiculo_3 = new Camion("Mercedes", 2020, 80, 12000);

        //Instanciamos un Autobus
        Vehiculo vehiculo_4 = new Autobus("Benzene", 2024, 100, 60);
        Vehiculo vehiculo_5 = new Autobus("Mercedes", 2023, 120, 55);

        //Probamos los metodos para cada objeto
        // Subimos pasajeros al automovil
        ((Automovil)vehiculo_1).subirPasajeros(3);
        ((Automovil)vehiculo_2).subirPasajeros(2);
        ((Automovil)vehiculo_2).bajarPasajeros(2);

        //Subimos pasajeros al autobus
        ((Autobus)vehiculo_4).subirPasajeros(10);
        ((Autobus)vehiculo_5).subirPasajeros(20);
        ((Autobus)vehiculo_5).bajarPasajeros(5);

        //Cargamos el camion
        ((Camion)vehiculo_3).cargar(5000);
        ((Camion)vehiculo_3).cargar(8000);
        ((Camion)vehiculo_3).descargar(2000);
        ((Camion)vehiculo_3).cargar(3000);
        ((Camion)vehiculo_3).cargar(5000);
        ((Camion)vehiculo_3).descargar(10000);

        // Declaramos un array generico para cada tipo de objeto
        ArrayList <Vehiculo> vehiculos = new ArrayList<>();

        // Agregamos los objetos al array
        vehiculos.add(vehiculo_1);
        vehiculos.add(vehiculo_2);
        vehiculos.add(vehiculo_3);
        vehiculos.add(vehiculo_4);
        vehiculos.add(vehiculo_5);

        int totalPasajeros = 0;
        int cntAutobuses = 0, cntAutomoviles = 0, cntCamiones = 0;
        //Recorrer el arreglo, contar la cantidad de Autobuses, Automoviles y  Camiones. Además sumar los ingresos de los estudiantes
        for(Vehiculo p : vehiculos) {
            if (p instanceof Autobus) {
                //Sumar total de pasajeros de todos los autobuses
                totalPasajeros += ((Autobus) p).getCantidadPasajeros();
                cntAutobuses++;
            } else if (p instanceof Camion) {
                cntCamiones++;
            }
            else {
                cntAutomoviles++;
            }
        }

        //Recorrer para imprimir cada tipo
        for(Vehiculo p : vehiculos) {
            if (p instanceof Autobus) {
                //Sumar total de pasajeros de todos los autobuses
                System.out.println(((Autobus) p).toString());
            } else if (p instanceof Camion) {
                System.out.println(((Camion) p).toString());
            }
            else {
                System.out.println(((Vehiculo) p).toString());
            }
        }

        System.out.println("=======================================================");
        System.out.println("cntAutobuses = " + cntAutobuses);
        System.out.println("Total de pasajeros en Autobuses: " + totalPasajeros);

        System.out.println("=======================================================");
        System.out.println("cntAutomoviles = " + cntAutomoviles);

        System.out.println("=======================================================");
        System.out.println("cntCamiones = " + cntCamiones);

    }
}