package clases;

public class Deportivo extends Vehiculo{
    private int potencia;

    public Deportivo() {
    }

    public int getPotencia() {
        return potencia;
    }

    public void setPotencia(int potencia) {
        this.potencia = potencia;
    }

    @Override
    public String toString() {
        return "Deportivo{" +
                "potencia=" + potencia +
                "} \n" + super.toString();
    }
}
