package Clases;

import Enumeradores.Estado;
import Enumeradores.Genero;
import Enumeradores.TipoMaterial;
import Interfaces.I_Prestable;

public class Libro extends Material implements I_Prestable{
    private String cantPaginas;
    private Genero genero;
    private Estado estado;

    public Libro(String titulo, String autor, String anio, TipoMaterial tipo, String cantPaginas, Genero genero) {
        super(titulo, autor, anio, tipo);
        this.cantPaginas = cantPaginas;
        this.genero = genero;
        this.estado=Estado.DISPONIBLE;
    }

    public String getCantPaginas() {
        return cantPaginas;
    }

    public void setCantPaginas(String cantPaginas) {
        this.cantPaginas = cantPaginas;
    }

    public Genero getGenero() {
        return genero;
    }

    public void setGenero(Genero genero) {
        this.genero = genero;
    }

    public Estado getEstado() {
        return estado;
    }

    public void setEstado(Estado estado) {
        this.estado = estado;
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
        return "Libro{" +
                "cantPaginas='" + cantPaginas + '\'' +
                ", genero=" + genero +
                ", estado=" + estado +
                "} " + super.toString();
    }
}
