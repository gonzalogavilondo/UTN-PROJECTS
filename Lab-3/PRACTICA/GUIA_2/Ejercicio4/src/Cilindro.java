public class Cilindro extends Circulo {
    private double altura;

    public Cilindro() {
        super();
        this.altura = 1.0;
    }

    public Cilindro(double radio, String color, double altura) {
        super(radio, color);
        this.altura = altura;
    }

    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    // Calcular Volumen
    public double getVolumen() {
        return super.getArea() * altura;
    }

    @Override
    public double getArea() {
        return (2 * Math.PI * super.getRadio() * altura) + (2 * Math.PI * Math.pow(super.getRadio(), 2));
    }

    @Override
    public String toString() {
        return "Cilindro{" +
                " subclase de: " +
                super.toString() +
                " altura=" + altura +
                " " +
                ", volumen=" + getVolumen() +
                ", area cilindro=" + getArea() +
                '}'
                ;
    }
}
