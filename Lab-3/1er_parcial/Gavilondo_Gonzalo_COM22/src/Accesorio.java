public class Accesorio extends Producto implements I_Bluetooth {
    private String tipo;

    /**
     * Constructor de la clase Accesorio
     */
    public Accesorio(String nombre, Categorias categoria, double precio, Marcas marca, String tipo) {
        super(nombre, categoria, precio, marca);
        if (categoria != Categorias.ACCESORIO) {
            System.out.println("Error: La categoría debe ser ACCESORIO.");
            System.exit(1);
        }
        this.tipo = tipo;
    }

    /**
     * Getters and setters
     */
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getTipo() {
        return tipo;
    }

    @Override
    public String toString() {
        return super.toString() + ", Tipo: " + tipo;
    }

    /**
     * Metodo de la interfaz I_Bluetooth
     */
    @Override
    public void conectarBluetooth(String dispositivo) {
        //Metodo de la interfaz I_Bluetooth
        System.out.println("Conectando a " + dispositivo + " mediante Bluetooth...");
    }
}