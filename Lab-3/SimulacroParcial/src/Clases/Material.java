package Clases;

import Enumeradores.TipoMaterial;

import java.util.List;

public abstract class Material implements Comparable<Material>{
     private int ID = ++Material.cantMateriales;
     protected String titulo;
     protected String autor;
     protected String anio;
     protected TipoMaterial tipo;
     public static int cantMateriales;

    public Material(String titulo, String autor, String anio, TipoMaterial tipo) {
        this.titulo = titulo;
        this.autor = autor;
        this.anio = anio;
        this.tipo = tipo;
    }

    public int getID() {
        return ID;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getAnio() {
        return anio;
    }

    public void setAnio(String anio) {
        this.anio = anio;
    }

    public TipoMaterial getTipo() {
        return tipo;
    }

    public void setTipo(TipoMaterial tipo) {
        this.tipo = tipo;
    }

    @Override
    public int compareTo(Material o) {
        return this.titulo.compareTo(o.titulo);
    }

    @Override
    public String toString() {
        return "Material{" +
                "ID=" + ID +
                ", titulo='" + titulo + '\'' +
                ", autor='" + autor + '\'' +
                ", anio='" + anio + '\'' +
                ", tipo=" + tipo +
                '}';
    }
}
