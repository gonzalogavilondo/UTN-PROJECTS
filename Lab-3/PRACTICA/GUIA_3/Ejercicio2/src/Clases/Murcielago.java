package Clases;

import Interfaces.I_Volador;

public class Murcielago extends Animal implements I_Volador {

    public Murcielago() {
    }

    public Murcielago(String nombre) {
        super(nombre);
    }

    @Override
    public void comer() {
        System.out.println("El murciélago " + this.getNombre() + " está comiendo");
    }

    @Override
    public void dormir() {
        System.out.println("El murciélago " + this.getNombre() + " está durmiendo en la cueva");
    }

    @Override
    public void hacerSonido() {
        System.out.println("El murciélago " + this.getNombre() + " está haciendo sonidos de ultrasonido");
    }

    @Override
    public void volar() {
        System.out.println("El murciélago " + this.getNombre() + " está volando en la noche");
    }

    @Override
    public String toString() {
        return "Murcielago{}";
    }

    public void colgarse() {
        System.out.println("El murciélago " + this.getNombre() + "se ha colgado boca abajo en la cueva");
    }
}
