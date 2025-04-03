package Clases;

import Interfaces.I_VehiculoDePasajeros;

public class Autobus extends Vehiculo implements I_VehiculoDePasajeros {
    private int cantidadPasajeros;
    private int capacidadMaxima;

    public Autobus() {
        super();
        this.cantidadPasajeros = 0;
        this.capacidadMaxima = 50; // Asumiendo un autobús típico de 50 pasajeros
    }

    public Autobus(String marca, int modelo, double velocidadMaxima, int capacidadMaxima) {
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
        return this.capacidadMaxima;
    }

    public boolean isPasajerosCompletos() {
        return this.cantidadPasajeros == this.capacidadMaxima;
    }

    public boolean isPasajerosVacios() {
        return this.cantidadPasajeros == 0;
    }

    @Override
    public String toString() {
        return "Autobus{" +
                "cantidadPasajeros=" + cantidadPasajeros +
                ", capacidadMaxima=" + capacidadMaxima +
                '}';
    }
}
