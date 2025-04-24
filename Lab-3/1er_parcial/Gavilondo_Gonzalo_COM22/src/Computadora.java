public class Computadora extends Producto implements I_Wifi {
    private String procesador;
    private int ram;

    /**
     * Constructor de la clase Computadora
     */
    public Computadora(String nombre, Categorias categoria, double precio, Marcas marca, String procesador, int ram) {
        super(nombre, categoria, precio, marca);
        if (categoria != Categorias.COMPUTADORA) {
            System.out.println("Error: La categoría debe ser COMPUTADORA.");
            System.exit(1);
        }
        this.procesador = procesador;
        this.ram = ram;
    }

    /**
     * Getters and setters
     */
    public void setProcesador(String procesador) {
        this.procesador = procesador;
    }

    public void setRam(int ram) {
        this.ram = ram;
    }

    public String getProcesador() {
        return procesador;
    }

    public int getRam() {
        return ram;
    }

    @Override
    public String toString() {
        return super.toString() + ", Procesador: " + procesador + ", RAM: " + ram + "GB";
    }

    /**
     * Metodo de la interfaz I_Wifi
     */
    @Override
    public void conectarWifi(String nombreRed, String contrasena) {
        //Implementación del metodo conectarWifi
        System.out.println("Conectando a la red WiFi " + nombreRed + " con contraseña " + contrasena + "...");
    }
}