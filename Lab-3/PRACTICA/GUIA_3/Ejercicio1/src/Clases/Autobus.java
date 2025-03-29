package Clases;

import Interfaces.I_Transporte;

public class Autobus implements I_Transporte {
    private int numeroLinea;
    private int capacidad;
    private TipoTransporte tipo;

    public Autobus() {
    }

    public Autobus(int numeroLinea, int capacidad, TipoTransporte tipo) {
        this.numeroLinea = numeroLinea;
        this.capacidad = capacidad;
        this.tipo = tipo;
    }

    public int getNumeroLinea() {
        return numeroLinea;
    }

    public void setNumeroLinea(int numeroLinea) {
        this.numeroLinea = numeroLinea;
    }

    public TipoTransporte getTipo() {
        return tipo;
    }

    public void setTipo(TipoTransporte tipo) {
        this.tipo = tipo;
    }

    public int getCapacidad() {
        return capacidad;
    }

    public void setCapacidad(int capacidad) {
        this.capacidad = capacidad;
    }

    @Override
    public String toString() {
        return "Autobus{" +
                "numeroLinea=" + numeroLinea +
                ", capacidad=" + capacidad +
                ", tipo=" + tipo +
                '}';
    }

    @Override
    public void arrancar() {
        System.out.println("Arrancando autobús");
    }

    @Override
    public void detener() {
        System.out.println("Deteniendo autobús");
    }

    @Override
    public int obtenerCapacidad() {
        return this.capacidad;
    }

    public void anunciarParada(String parada) {
        System.out.println("Parada: " + parada);
    }
}
