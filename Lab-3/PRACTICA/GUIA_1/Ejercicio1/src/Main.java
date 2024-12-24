import Banco.CuentaBancaria;

public class Main {

    public static void main(String [] args)
    {
        CuentaBancaria cta = new CuentaBancaria();

        // Asignamos titular y depositamos dinero
        cta.depositar(10000);
        cta.setTitular("Juan Perez");

        //Consultamos el saldo luego de depositar
        System.out.println("El saldo ahora es = " + cta.consultar());

        //Retiramos dinero y luego consultamos el saldo
        cta.retirar(5000);
        System.out.println("El saldo luego de retirar es = " + cta.consultar());

        //Hacemos un plazo fijo ahora.
        cta.plazoFijo();

        //Nuevamente consultamos el saldo ahora luego de hacer el plazo fijo con su titular
        System.out.println("El saldo luego de hacer plazo fijo es = " + cta.toString());
    }
}