package Banco;

public class CuentaBancaria {
    private float saldo;
    private String titular;

    public CuentaBancaria() {
    }

    public float consultar() {
        return this.saldo;
    }

    public void depositar(float saldo) {
        this.saldo = saldo;
    }

    public float retirar(float n) {
        //Si el saldo es menor al monto a retirar
        if (this.saldo < n) {
            System.out.println("Saldo insuficiente");
            return 0;
        }
        this.saldo -= n;//Se actualiza el saldo
        return n;
    }

    public float plazoFijo() {
        //Si tenemos una tasa de interes anual del 87%
        float tasaDeInteres = 0.87F;

        saldo += (saldo * tasaDeInteres);

        return this.saldo;
    }

    public String getTitular() {
        return titular;
    }

    public void setTitular(String titular) {
        this.titular = titular;
    }

    @Override
    public String toString() {
        return "CuentaBancaria{" +
                "saldo=" + this.saldo +
                ", titular='" + this.titular + '\'' +
                '}';
    }

}
