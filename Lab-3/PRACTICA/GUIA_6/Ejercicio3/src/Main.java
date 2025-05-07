//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        // Crear una instancia de OperacionMatematica con valores enteros, capturando excepciones
        try {
            OperacionMatematica<Integer> operacionEnteros = new OperacionMatematica<>(10, 5);
            System.out.println("Suma: " + operacionEnteros.sumar());
            System.out.println("Resta: " + operacionEnteros.restar());
            System.out.println("Multiplicación: " + operacionEnteros.multiplicar());
            System.out.println("División: " + operacionEnteros.dividir());


            System.out.println("------------------------------------------------- ");

            // Crear una instancia de OperacionMatematica con valores decimales, capturando excepciones
            OperacionMatematica<Double> operacionDecimales = new OperacionMatematica<>(11.5, 6.2);
            System.out.println("Suma: " + operacionDecimales.sumar());
            System.out.println("Resta: " + operacionDecimales.restar());
            System.out.println("Multiplicación: " + operacionDecimales.multiplicar());
            System.out.println("División: " + operacionDecimales.dividir());


            System.out.println("------------------------------------------------- ");

            // Crear una instancia de OperacionMatematica con valores de tipo String, capturando excepciones
            OperacionMatematica<String> operacionStrings = new OperacionMatematica<>("20", "5");
            System.out.println("Suma: " + operacionStrings.sumar());
            System.out.println("Resta: " + operacionStrings.restar());
            System.out.println("Multiplicación: " + operacionStrings.multiplicar());
            System.out.println("División: " + operacionStrings.dividir());


            System.out.println("------------------------------------------------- ");

            // Crear una instancia de OperacionMatematica haciendo que se lance una excepcion
            OperacionMatematica<String> operacionStrings2 = new OperacionMatematica<>("10", "0");
            System.out.println("Division: " + operacionStrings2.dividir());

        } catch (UnsupportedOperationException | ArithmeticException e) {
            System.err.println("Error: " + e.getMessage());
        }
        catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }

    }
}