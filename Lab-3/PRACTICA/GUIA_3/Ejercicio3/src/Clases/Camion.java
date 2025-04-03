package Clases;

import Interfaces.I_VehiculoDeCarga;

public class Camion extends Vehiculo implements I_VehiculoDeCarga {
    private double pesoCarga;
    private double pesoMaximo;

    public Camion() {
        super();
        this.pesoCarga = 0;
        this.pesoMaximo = 10000; // Asumiendo un camión típico de 10 toneladas
    }

    public Camion(String marca, int modelo, double velocidadMaxima, double pesoMaximo) {
        super(marca, modelo, velocidadMaxima);
        this.pesoCarga = 0;
        this.pesoMaximo = pesoMaximo;
    }

    public void cargar(double peso) {
        if (peso + pesoCarga <= pesoMaximo) {
            pesoCarga += peso;
        } else {
            System.out.println("No se puede cargar más. Peso máximo alcanzado.");
        }
    }

    public void descargar(double peso) {
        if (peso <= pesoCarga) {
            pesoCarga -= peso;
        } else {
            System.out.println("No hay suficiente carga para descargar.");
        }
    }

    public double getPesoCarga() {
        return pesoCarga;
    }

    public double getPesoMaximo() {
        return pesoMaximo;
    }

    public boolean isCargaCompleta() {
        return pesoCarga == pesoMaximo;
    }

    public boolean isCargaVacia() {
        return pesoCarga == 0;
    }

    @Override
    public String toString() {
        return "Camion{" +
                "pesoCarga=" + pesoCarga +
                ", pesoMaximo=" + pesoMaximo +
                "} " + super.toString();
    }
}
