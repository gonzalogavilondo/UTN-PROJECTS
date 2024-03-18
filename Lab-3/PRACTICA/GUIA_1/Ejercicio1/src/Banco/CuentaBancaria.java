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
        this.saldo -= n;//Se actualiza el saldo
        return n;
    }

    public float plazoFijo() {
        //Si tenemos una tasa de interes anual del 87%
        float tasaDeInteres = 0.87F;

        saldo += (saldo*tasaDeInteres);

        return this.saldo;
    }

}
