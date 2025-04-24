package Clases;

import Enumeradores.Estado;
import Enumeradores.TipoMaterial;
import Interfaces.I_Prestable;

public class Revista extends Material implements I_Prestable {

    private boolean aColor;
    private Estado estado;

    public Revista(String titulo, String autor, String anio, TipoMaterial tipo, boolean aColor) {
        super(titulo, autor, anio, tipo);
        this.aColor = aColor;
        this.estado=Estado.DISPONIBLE;
    }

    @Override
    public void prestar() {
        this.estado=Estado.PRESTADO;
    }

    @Override
    public void devolver() {
        this.estado=Estado.DISPONIBLE;
    }

    @Override
    public String toString() {
        return "Revista{" +
                "aColor=" + aColor +
                ", estado=" + estado +
                "} " + super.toString();
    }
}
