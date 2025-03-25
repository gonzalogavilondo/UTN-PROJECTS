public class Circulo {
    private double radio;
    private String color;

    public Circulo() {
        this.radio = 1.0;
        this.color = "Rojo";
    }

    public Circulo(double radio, String color) {
        this.radio = radio;
        this.color = color;
    }

    public double getRadio() {
        return radio;
    }

    public void setRadio(double radio) {
        this.radio = radio;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String toString() {
        return "Circulo{" +
                "radio=" + radio +
                ", color='" + color + '\'' +
                ", area circulo=" + getArea() +
                '}';
    }

    // Calcular Area
    public double getArea() {
        return Math.PI * Math.pow(radio, 2);
    }

    //Calcular volumen
    public double getVolumen() {
        return (4/3) * Math.PI * Math.pow(radio, 3);
    }


}
