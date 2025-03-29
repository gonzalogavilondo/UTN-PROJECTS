package Clases;

import Interfaces.I_Transporte;

public class Tranvia implements I_Transporte {
    private String ruta;
    private int capacidad;
    private TipoTransporte tipo;

    public Tranvia() {
    }

    public Tranvia(String ruta, int capacidad, TipoTransporte tipo) {
        this.ruta = ruta;
        this.capacidad = capacidad;
        this.tipo = tipo;
    }

    public int getCapacidad() {
        return capacidad;
    }

    public void setCapacidad(int capacidad) {
        this.capacidad = capacidad;
    }

    public TipoTransporte getTipo() {
        return tipo;
    }

    public void setTipo(TipoTransporte tipo) {
        this.tipo = tipo;
    }

    public String getRuta() {
        return ruta;
    }

    public void setRuta(String ruta) {
        this.ruta = ruta;
    }

    @Override
    public String toString() {
        return "Tranvia{" +
                "ruta='" + ruta + '\'' +
                ", capacidad=" + capacidad +
                ", tipo=" + tipo +
                '}';
    }

    @Override
    public void arrancar() {
        System.out.println("Arrancando tranvía");
    }

    @Override
    public void detener() {
        System.out.println("Deteniendo tranvía");
    }

    @Override
    public int obtenerCapacidad() {
        return this.capacidad;
    }

    public void cambiarVia(int nuevaVia)
    {
        System.out.println("Cambiando a la vía: " + nuevaVia);
    }
}
