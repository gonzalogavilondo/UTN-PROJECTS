import Vuelo.Vuelo;
import Vuelo.Horario;

public class Main {
    public static void main(String[] args) {
        Vuelo vuelo = new Vuelo();
        Horario duracionVuelo = new Horario();

        //Seteamos el origen y el destino
        vuelo.setOrigen("Argentina");
        vuelo.setDestino("Colombia");

        //Seteamos el horario
        vuelo.setHoraSalida(12, 00, 00);
        vuelo.setHoraLlegada(16, 40, 10);

        //Mostramos la informacion del vuelo
        vuelo.toString();

        //Ahora, calculamos cuanto duro el vuelo y lo mostramos
        duracionVuelo = vuelo.calcularDuracion();

        //Mostramos resultado
        System.out.println("duracionVuelo = " + duracionVuelo.toString());



    }
}