package Clases;

import Interfaces.I_Nadador;

public class Pez extends Animal implements I_Nadador {

    public Pez() {
    }

    public Pez(String nombre) {
        super(nombre);
    }

    @Override
    public void comer() {
        System.out.println("El pez " + this.getNombre() + " está comiendo");
    }

    @Override
    public void dormir() {
        System.out.println("El pez " + this.getNombre() + " está durmiendo en el agua");
    }

    @Override
    public void hacerSonido() {
        System.out.println("El pez " + this.getNombre() + " no hace sonidos");
    }

    @Override
    public void nadar() {
        System.out.println("El pez " + this.getNombre() + " está nadando con agilidad en las profundidades del oceano");
    }

    @Override
    public String toString() {
        return "Pez{}";
    }
}
