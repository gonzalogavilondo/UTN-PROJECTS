public class Celular extends Producto implements I_NFC {
    private boolean tieneConectividadNFC;

    /**
     * Constructor de la clase Celular.
     */
    public Celular(String nombre, Categorias categoria, double precio, Marcas marca, boolean tieneConectividadNFC) {
        super(nombre, categoria, precio, marca);
        if (categoria != Categorias.CELULAR) {
            System.out.println("Error: La categoría debe ser CELULAR.");
            System.exit(1);
        }
        this.tieneConectividadNFC = tieneConectividadNFC;
    }

    public void setTieneConectividadNFC(boolean tieneConectividadNFC) {
        this.tieneConectividadNFC = tieneConectividadNFC;
    }

    public boolean isTieneConectividadNFC() {
        return tieneConectividadNFC;
    }

    @Override
    public String toString() {
        return super.toString() + ", Conectividad Inalámbrica: " + (tieneConectividadNFC ? "Sí" : "No");
    }

    /**
     * Metodo de la interfaz I_NFC
     */
    @Override
    public void conectarNFC(String dispositivo) {
        // Implementación del metodo conectarNFC
        System.out.println("Conectando a " + dispositivo + " mediante NFC...");
    }
}