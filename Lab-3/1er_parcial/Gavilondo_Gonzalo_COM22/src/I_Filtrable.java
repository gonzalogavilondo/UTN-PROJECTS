import java.util.List;

public interface I_Filtrable {
    List<Producto> filtrarPorCategoria(Categorias categoria);
    List<Producto> filtrarPorRangoDePrecios(double min, double max);
    List<Celular> filtrarCelularesPorMarca(Marcas marca);
}
