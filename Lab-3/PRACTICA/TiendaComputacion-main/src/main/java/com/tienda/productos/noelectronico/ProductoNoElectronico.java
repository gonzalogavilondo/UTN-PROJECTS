package com.tienda.productos.noelectronico;

import com.tienda.productos.Producto;

/**
 * Responsabilidad de la clase ProductoNoElectronico:
 * 1. Especificar atributos únicos de productos no electrónicos
 * 2. Implementar comportamientos específicos
 * 3. Facilitar el polimorfismo con especificidad
 * <p>
 * Las clases derivadas de ProductoNoElectronico llevan la especialización un paso más allá dentro de la jerarquía de herencia,
 * enfodcándose en características y comportamientos específicos de tipos particulares de productos.
 */
public abstract class ProductoNoElectronico extends Producto {
    private boolean ergonomico;

    public ProductoNoElectronico(String nombre, float precio) {
        super(nombre, precio, 0);
        this.ergonomico = false;
    }

    public ProductoNoElectronico(String nombre, float precio, int stock) {
        super(nombre, precio, stock);
        this.ergonomico = false;
    }

    public boolean isErgonomico() {
        return ergonomico;
    }

    public void setErgonomico(boolean ergonomico) {
        this.ergonomico = ergonomico;
    }

    @Override
    public String toString() {
        return super.toString() + String.format("Ergonómico: %s. ", (this.ergonomico) ? "sí" : "no");
    }
}
