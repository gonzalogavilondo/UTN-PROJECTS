package Clases;

import Interfaces.I_Transporte;

public class Bicicleta implements I_Transporte {
    private String numeroSerie;
    private TipoTransporte tipo;

    public Bicicleta() {
    }

    public Bicicleta(String numeroSerie, TipoTransporte tipo) {
        this.numeroSerie = numeroSerie;
        this.tipo = tipo;
    }

    public String getNumeroSerie() {
        return numeroSerie;
    }

    public void setNumeroSerie(String numeroSerie) {
        this.numeroSerie = numeroSerie;
    }

    public TipoTransporte getTipo() {
        return tipo;
    }

    public void setTipo(TipoTransporte tipo) {
        this.tipo = tipo;
    }

    @Override
    public String toString() {
        return "Bicicleta{" +
                "numeroSerie='" + numeroSerie + '\'' +
                ", tipo=" + tipo +
                '}';
    }

    @Override
    public void arrancar() {
        System.out.println("Arrancando bicicleta");
    }

    @Override
    public void detener() {
        System.out.println("Deteniendo bicicleta");
    }
    @Override
    public int obtenerCapacidad() {
        return 1;
    }

    public void ajustarAsiento(int altura) {
        System.out.println("Ajustando asiento a " + altura + " cm");
    }

}
