//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        // Crear un objeto de tipo Cliente
        Cliente cliente = new Cliente("Juan", "juan@mail.com", 50);

        // Crear objeto Factura con el cliente creado
        Factura factura = new Factura(1300, cliente);

        // Se imprime por pantalla
        System.out.println(cliente.toString());

        // Factura antes de aplicar descuento
        System.out.println(factura.toString());

        System.out.println("\nMonto total, luego de aplicar descuento: " + factura.calcularMontoFinal());

        // Se imprime la Factura
        factura.toString();

    }
}