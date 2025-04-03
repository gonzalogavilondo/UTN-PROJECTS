package Clases;

import Interfaces.I_Nadador;
import Interfaces.I_Volador;

public class Pato extends Animal implements I_Nadador, I_Volador {

    public Pato() {
    }

    public Pato(String nombre) {
        super(nombre);
    }

    @Override
    public void comer() {
        System.out.println("El pato " + this.getNombre() + " está comiendo");
    }

    @Override
    public void dormir() {
        System.out.println("El pato " + this.getNombre() + " está durmiendo");

    }

    @Override
    public void hacerSonido() {
        System.out.println("El pato " + this.getNombre() + " está haciendo cuac cuac");
    }

    @Override
    public void nadar() {
        System.out.println("El pato " + this.getNombre() + " está nadando");
    }

    @Override
    public void volar() {
        System.out.println("El pato " + this.getNombre() + " está volando sobre el agua");
    }

    @Override
    public String toString() {
        return "Pato{}";
    }
}
