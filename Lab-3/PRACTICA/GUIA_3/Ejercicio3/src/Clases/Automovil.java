package Clases;

import Interfaces.I_VehiculoDePasajeros;

public class Automovil extends Vehiculo implements I_VehiculoDePasajeros {
    private int cantidadPasajeros;
    private int capacidadMaxima;
    
    public Automovil() {
        super();
        this.cantidadPasajeros = 0;
        this.capacidadMaxima = 5; // Asumiendo un auto típico de 5 pasajeros
    }

    public Automovil(String marca, int modelo, double velocidadMaxima, int capacidadMaxima) {
        super(marca, modelo, velocidadMaxima);
        this.cantidadPasajeros = 0;
        this.capacidadMaxima = capacidadMaxima;
    }

    public void subirPasajeros(int cantidad) {
        if (cantidad + cantidadPasajeros <= capacidadMaxima) {
            cantidadPasajeros += cantidad;
        } else {
            System.out.println("No se pueden subir más pasajeros. Capacidad máxima alcanzada.");
        }
    }

    public void bajarPasajeros(int cantidad) {
        if (cantidad <= cantidadPasajeros) {
            cantidadPasajeros -= cantidad;
        } else {
            System.out.println("No hay suficientes pasajeros para bajar.");
        }
    }

    public int getCantidadPasajeros() {
        return cantidadPasajeros;
    }

    public int getCapacidadMaxima() {
        return capacidadMaxima;
    }

    public boolean isPasajerosCompletos() {
        return cantidadPasajeros == capacidadMaxima;
    }

    public boolean isPasajerosVacios() {
        return cantidadPasajeros == 0;
    }

    @Override
    public String toString() {
        return "Automovil{" +
                "cantidadPasajeros=" + cantidadPasajeros +
                ", capacidadMaxima=" + capacidadMaxima +
                "} " + super.toString();
    }
}
