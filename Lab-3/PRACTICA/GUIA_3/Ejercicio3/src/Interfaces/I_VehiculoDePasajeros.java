package Interfaces;

public interface I_VehiculoDePasajeros {
    public void subirPasajeros(int cantidad);
    public void bajarPasajeros(int cantidad);
    public int getCantidadPasajeros();
    public int getCapacidadMaxima();
    public boolean isPasajerosCompletos();
    public boolean isPasajerosVacios();
}
