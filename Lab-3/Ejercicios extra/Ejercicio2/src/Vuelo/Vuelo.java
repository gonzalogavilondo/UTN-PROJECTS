package Vuelo;

public class Vuelo {

    private String origen;
    private String destino;
    private Horario horaSalida;
    private Horario horaLlegada;

    public Vuelo() {
    }

    public String getOrigen() {
        return origen;
    }

    public void setOrigen(String origen) {
        this.origen = origen;
    }

    public String getDestino() {
        return destino;
    }

    public void setDestino(String destino) {
        this.destino = destino;
    }

    public Horario getHoraSalida() {
        Horario horaSalida = new Horario();
        return horaSalida.getHorario();
    }

    public void setHoraSalida(int h, int m, int s) {
        Horario horaSalida = new Horario();
        horaSalida.setHorario(h, m, s);
    }

    public Horario getHoraLlegada() {
        Horario horaLlegada = new Horario();
        return horaLlegada.getHorario();
    }

    public void setHoraLlegada(int h, int m, int s) {
        Horario horaLlegada = new Horario();
        horaLlegada.setHorario(h, m, s);
    }

    @Override
    public String toString() {
        return "Vuelo{" +
                "origen='" + origen + '\'' +
                ", destino='" + destino + '\'' +
                ", horaSalida='" + horaSalida.toString() + '\'' +
                ", horaLlegada='" + horaLlegada.toString() + '\'' +
                '}';
    }

    public Horario calcularDuracion()
    {
        int h, m, s;
        Horario duracionVuelo = new Horario();
        h = horaLlegada.getHora() - horaSalida.getHora();
        m = horaLlegada.getMinutos() - horaSalida.getMinutos();
        s = horaLlegada.getSegundos() - horaSalida.getMinutos();

        //Seteamos la duracion
        duracionVuelo.setHorario(h, m, s);
        return duracionVuelo;
    }
}
