public class Main {
    public static void main(String[] args) {

        CuentaBanco cuenta = new CuentaBanco(1, "Galicia", 15000);

        // Imprimimos original
        System.out.println(cuenta.toString());

        // Se realiza operacion de credito
        System.out.println("Credito: " + cuenta.credito(2500));

        // Operacion de debito
        System.out.println("Debito: " + cuenta.debito(1500));

        // Intento de operacion de debito
        System.out.println("Debito: " + cuenta.debito(30000));

        // Imprimimos final
        System.out.println(cuenta.toString());
    }
}