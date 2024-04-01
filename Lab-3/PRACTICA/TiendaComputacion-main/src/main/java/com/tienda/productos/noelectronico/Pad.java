package com.tienda.productos.noelectronico;

public class Pad extends ProductoNoElectronico {
    private int tamanio;

    public Pad(String nombre, float precio) {
        super(nombre, precio);
    }

    public Pad(String nombre, float precio, int stock) {
        super(nombre, precio, stock);
    }

    public int getTamanio() {
        return tamanio;
    }

    public void setTamanio(int tamanio) {
        this.tamanio = tamanio;
    }

    @Override
    public String toString() {
        return super.toString() + String.format("Tamaño: %d. ", this.tamanio);
    }
}
