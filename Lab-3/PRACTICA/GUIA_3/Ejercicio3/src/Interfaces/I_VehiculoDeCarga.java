package Interfaces;

public interface I_VehiculoDeCarga {
    public void cargar(double peso);
    public void descargar(double peso);
    public double getPesoCarga();
    public double getPesoMaximo();
    public boolean isCargaCompleta();
    public boolean isCargaVacia();
}
