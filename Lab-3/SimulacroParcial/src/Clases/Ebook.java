package Clases;

import Enumeradores.TipoMaterial;
import Interfaces.I_Digital;

public class Ebook extends Material implements I_Digital {
    private String formato;

    public Ebook(String titulo, String autor, String anio, TipoMaterial tipo, String formato) {
        super(titulo, autor, anio, tipo);
        this.formato = formato;
    }

    @Override
    public void resaltarTexto() {

    }

    @Override
    public void narrarParrafo() {

    }

    @Override
    public void cambiarFormato() {

    }

    @Override
    public void descargar() {

    }

    @Override
    public void leer() {

    }

    @Override
    public String toString() {
        return "Ebook{" +
                "formato='" + formato + '\'' +
                "} " + super.toString();
    }
}
