import java.util.List;
import java.util.Scanner;

/**
 * Autor: Gonzalo Gavilondo
 * Fecha: 24-04-2025
 * Descripción programa: Gestion de inventario de una tienda.
 * Comision: 22
 */

public class Main {
    public static void main(String[] args) {
        Tienda tienda = new Tienda();
        Scanner scanner = new Scanner(System.in);
        int opcion;

        // Agregar productos de ejemplo
        tienda.agregarProducto(new Computadora("Laptop Dell", Categorias.COMPUTADORA, 1200.0, Marcas.DELL, "Intel i7", 16));
        tienda.agregarProducto(new Celular("Samsung A22", Categorias.CELULAR, 999.0, Marcas.SAMSUNG, true));
        tienda.agregarProducto(new Accesorio("Airpods", Categorias.ACCESORIO, 25.0, Marcas.APPLE, "Inalámbrico"));

        do {
            System.out.println("####################################");
            System.out.println("########## Menu de Tienda ##########");
            System.out.println("####################################");
            System.out.println("1. Mostrar inventario");
            System.out.println("2. Agregar producto");
            System.out.println("3. Eliminar producto por ID");
            System.out.println("4. Filtrar productos por categoria");
            System.out.println("5. Filtrar productos por rango de precios");
            System.out.println("6. Filtrar celulares por marca");
            System.out.println("7. Ordenar productos por precio");
            System.out.println("8. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1 -> {
                    System.out.println("\nInventario:");
                    for (Producto producto : tienda.ordenarPorPrecio()) {
                        System.out.println(producto);
                    }
                }
                case 2 -> {
                    System.out.println("\nSeleccione el tipo de producto:");
                    System.out.println("1. Computadora");
                    System.out.println("2. Celular");
                    System.out.println("3. Accesorio");
                    int tipo = scanner.nextInt();
                    scanner.nextLine(); // Consumir salto de línea

                    System.out.print("Nombre: ");
                    String nombre = scanner.nextLine();
                    System.out.print("Precio: ");
                    double precio = scanner.nextDouble();
                    System.out.print("Marca (1. APPLE, 2. SAMSUNG, 3. DELL): ");
                    int marcaOpcion = scanner.nextInt();
                    Marcas marca = switch (marcaOpcion) {
                        case 1 -> Marcas.APPLE;
                        case 2 -> Marcas.SAMSUNG;
                        case 3 -> Marcas.DELL;
                        default -> throw new IllegalStateException("Marca no valida " + marcaOpcion);
                    };

                    switch (tipo) {
                        case 1 -> {
                            scanner.nextLine(); // Consumir salto de línea
                            System.out.print("Procesador: ");
                            String procesador = scanner.nextLine();
                            System.out.print("RAM (GB): ");
                            int ram = scanner.nextInt();
                            tienda.agregarProducto(new Computadora(nombre, Categorias.COMPUTADORA, precio, marca, procesador, ram));
                        }
                        case 2 -> {
                            System.out.print("¿Tiene conectividad NFC? (true/false): ");
                            boolean conectividad = scanner.nextBoolean();
                            tienda.agregarProducto(new Celular(nombre, Categorias.CELULAR, precio, marca, conectividad));
                        }
                        case 3 -> {
                            scanner.nextLine(); // Consumir salto de línea
                            System.out.print("Tipo: ");
                            String tipoAccesorio = scanner.nextLine();
                            tienda.agregarProducto(new Accesorio(nombre, Categorias.ACCESORIO, precio, marca, tipoAccesorio));
                        }
                        default -> System.out.println("Tipo de producto no válido.");
                    }
                }
                case 3 -> {
                    //Imprimir el inventario antes de eliminar,
                    // para que pueda elegir el ID viendo el producto
                    System.out.println("\nInventario:");
                    for (Producto producto : tienda.ordenarPorPrecio()) {
                        System.out.println(producto);
                    }
                    System.out.print("\nIngrese el ID del producto a eliminar: ");
                    int id = scanner.nextInt();
                    System.out.println(tienda.eliminarProducto(id));
                }
                case 4 -> {
                    System.out.println("\nSeleccione la categoría:");
                    System.out.println("1. COMPUTADORA");
                    System.out.println("2. CELULAR");
                    System.out.println("3. ACCESORIO");
                    int categoriaOpcion = scanner.nextInt();
                    Categorias categoria = switch (categoriaOpcion) {
                        case 1 -> Categorias.COMPUTADORA;
                        case 2 -> Categorias.CELULAR;
                        case 3 -> Categorias.ACCESORIO;
                        default -> throw new IllegalStateException("Categoria no valida: " + categoriaOpcion);
                    };
                    List<Producto> productosPorCategoria = tienda.filtrarPorCategoria(categoria);
                    System.out.println("\nProductos en la categoría seleccionada:");
                    for (Producto producto : productosPorCategoria) {
                        System.out.println(producto);
                    }
                }
                case 5 -> {
                    System.out.print("\nIngrese el precio mínimo: ");
                    double min = scanner.nextDouble();
                    System.out.print("Ingrese el precio máximo: ");
                    double max = scanner.nextDouble();
                    List<Producto> productosPorPrecio = tienda.filtrarPorRangoDePrecios(min, max);
                    System.out.println("\nProductos en el rango de precios:");
                    if (productosPorPrecio.isEmpty()) {
                        System.out.println("No hay productos con ese rango de precios.");
                    } else {
                        for (Producto producto : productosPorPrecio) {
                            System.out.println(producto);
                        }
                    }
                }
                case 6 -> {
                    //Nota: No se pone DELL, a pesarde estar disponible, ya que no existen celulares DELL.
                    System.out.println("\nSeleccione la marca:");
                    System.out.println("1. APPLE");
                    System.out.println("2. SAMSUNG");
                    int marcaOpcion = scanner.nextInt();
                    Marcas marca = switch (marcaOpcion) {
                        case 1 -> Marcas.APPLE;
                        case 2 -> Marcas.SAMSUNG;
                        default -> throw new IllegalStateException("Marca no valida: " + marcaOpcion);
                    };
                    List<Celular> celularesPorMarca = tienda.filtrarCelularesPorMarca(marca);
                    if (celularesPorMarca.isEmpty()) {
                        System.out.println("No hay celulares de la marca seleccionada.");
                    } else {
                        System.out.println("\nCelulares de la marca seleccionada:");
                        for (Celular celular : celularesPorMarca) {
                            System.out.println(celular);
                        }
                    }
                }
                case 7 -> {
                    System.out.println("\nProductos ordenados por precio:");
                    for (Producto producto : tienda.ordenarPorPrecio()) {
                        System.out.println(producto);
                    }
                }
                case 8 -> System.out.println("Saliendo del programa...");
                default -> System.out.println("Opción no válida.");
            }
        } while (opcion != 8);

        //Imprimir metodos especificos de la interfaz para cada tipo, simplemente
        //para mostrar que funcionan y que se implementaron, no se me ocurrio
        //donde ponerlos en el menu.
        System.out.println("\nProbando métodos específicos de cada tipo de producto antes de salir:\n");
        Computadora computadora = new Computadora("Laptop Dell", Categorias.COMPUTADORA, 1200.0, Marcas.DELL, "Intel i7", 16);
        computadora.conectarWifi("MiRed", "MiContrasena");
        Accesorio accesorio = new Accesorio("Airpods", Categorias.ACCESORIO, 25.0, Marcas.APPLE, "Inalámbrico");
        accesorio.conectarBluetooth("MiCelular");
        Celular celular = new Celular("Samsung A22", Categorias.CELULAR, 999.0, Marcas.SAMSUNG, true);
        celular.conectarNFC("MiLaptop");

        scanner.close();
    }
}