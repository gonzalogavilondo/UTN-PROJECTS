import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {

        ItemVenta item = new ItemVenta();
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            imprimirMenu();
            opcion = scanner.nextInt();
            scanner.nextLine(); // Consumir el resto de la línea
            switch (opcion) {
                case 1:
                    cargarDatos(item);
                    pausarYLimpiar();
                    break;

                case 2:
                    System.out.println("\n:");
                    System.out.println(item.toString());
                    pausarYLimpiar();
                    break;

                case 3:
                    System.out.println("\nIngrese la nueva cantidad:");
                    actualizarCnt(item);
                    pausarYLimpiar();
                    break;

                case 4:
                    System.out.println("\nIngrese el nuevo precio:");
                    actualizarPrecio(item);
                    pausarYLimpiar();
                    break;

                case 5:
                    System.out.println("\n\nPrecio total = " + item.calcularPrecioTotal());
                    pausarYLimpiar();
                    break;

                case 6:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Opción no válida");
                    pausarYLimpiar();
                    break;
            }
        }while(opcion != 6);

    }

    public static void cargarDatos(ItemVenta item){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Ingrese la descripción del ítem:");
        item.setDescripcion(scanner.nextLine());

        System.out.println("Ingrese la cantidad:");
        item.setCantidad(scanner.nextInt());
        scanner.nextLine(); // Consumir el resto de la línea

        System.out.println("Ingrese el precio unitario:");
        item.setPrecioUnitario(scanner.nextDouble());
        scanner.nextLine(); // Consumir el resto de la línea
    }

    public static void imprimirMenu(){
        System.out.println("\nMenú:");
        System.out.println("1. Agregar ítem");
        System.out.println("2. Imprimir item");
        System.out.println("3. Ingresar nueva cantidad");
        System.out.println("4. Ingresar nuevo precio unitario");
        System.out.println("5. Imprimir precio total");
        System.out.println("6. Salir");
        System.out.println("Ingrese una opción:");
    }

    public static void actualizarCnt(ItemVenta item){
        int cantidad = 0;
        Scanner scanner = new Scanner(System.in);
        cantidad = scanner.nextInt();
        scanner.nextLine(); // Consumir el resto de la línea
        item.setCantidad(cantidad);
    }

    public static void actualizarPrecio(ItemVenta item){
        double precio = 0.0F;
        Scanner scanner = new Scanner(System.in);
        precio = scanner.nextDouble();
        scanner.nextLine(); // Consumir el resto de la línea
        item.setPrecioUnitario(precio);
    }

    public static void pausarYLimpiar() throws IOException {
        System.out.println("Presione Enter para continuar...");
        System.in.read();
        for (int i = 0; i < 10; ++i) System.out.println();
    }
}
