package Vuelo;

public class Horario {
    private int hora;
    private int minutos;
    private int segundos;

    public int getHora() {
        return hora;
    }

    public void setHora(int hora) {
        this.hora = hora;
    }

    public int getMinutos() {
        return minutos;
    }

    public void setMinutos(int minutos) {
        this.minutos = minutos;
    }

    public int getSegundos() {
        return segundos;
    }

    public void setSegundos(int segundos) {
        this.segundos = segundos;
    }

    public void setHorario(int hora, int min, int seg)
    {
        this.hora = hora;
        this.minutos = min;
        this.segundos = seg;
    }

    public Horario getHorario()
    {
        Horario hora = new Horario();

        hora.hora = this.hora;
        hora.minutos = this.minutos;
        hora.segundos = this.segundos;

        return hora;
    }

    @Override
    public String toString() {
        return "Horario{" +
                "hora=" + hora +
                ", minutos=" + minutos +
                ", segundos=" + segundos +
                '}';
    }
}
