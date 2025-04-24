import java.util.ArrayList;
import java.util.List;

public class Tienda implements I_Filtrable {
    private List<Producto> inventario;

    public Tienda() {
        this.inventario = new ArrayList<>();
    }

   /**
    * Metodo para mostrar el inventario
    */
    public void agregarProducto(Producto producto) {
        inventario.add(producto);
    }

    /**
     *Metodo para eliminar un producto del inventario por ID
     */
    public String eliminarProducto(int id) {
        String mensaje = "El producto a eliminar no se encontró en el inventario";
        for (Producto producto : inventario) {
            if (producto.getId() == id) {
                inventario.remove(producto);
                mensaje = "El producto se encontró y se eliminó correctamente";
                break;
            }
        }
        return mensaje;
    }

    /**
     * Metodo para filtrar productos por categoria
     */
    public List<Producto> filtrarPorCategoria(Categorias categoria) {
        List<Producto> productosFiltrados = new ArrayList<>();
        for (Producto producto : inventario) {
            if (producto.getCategoria() == categoria) {
                productosFiltrados.add(producto);
            }
        }
        return productosFiltrados;
    }

    /**
    * Metodo para filtrar productos por rango de precios
    */
    public List<Producto> filtrarPorRangoDePrecios(double min, double max) {
        List<Producto> productosFiltrados = new ArrayList<>();
        for (Producto producto : inventario) {
            if (producto.getPrecio() >= min && producto.getPrecio() <= max) {
                productosFiltrados.add(producto);
            }
        }
        return productosFiltrados;
    }

    /**
     * Metodo para filtrar celulares por marca
     */
    public List<Celular> filtrarCelularesPorMarca(Marcas marca) {
        List<Celular> celularesFiltrados = new ArrayList<>();
        for (Producto producto : inventario) {
            if (producto instanceof Celular celular) {
                if (celular.getMarca() == marca) {
                    celularesFiltrados.add(celular);
                }
            }
        }
        return celularesFiltrados;
    }

    /**
     * Metodo para ordenar productos por precio ascendente, utilizando compareTo,
     * que esta en la clase Producto, que a su vez implementa la interfaz Comparable
     */
    public List<Producto> ordenarPorPrecio() {
        List<Producto> copiaInventario = new ArrayList<>(inventario);
        copiaInventario.sort((p1, p2) -> p1.compareTo(p2));
        return copiaInventario;
    }
}