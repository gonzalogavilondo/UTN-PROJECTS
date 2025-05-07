public class OperacionMatematica<T> {
    private T valor1;
    private T valor2;

    public OperacionMatematica(T valor1, T valor2) {
        this.valor1 = valor1;
        this.valor2 = valor2;
    }

    private double convertirADouble(T valor) {
        if (valor instanceof String) {
            return Double.parseDouble((String) valor);
        } else if (valor instanceof Number) {
            return ((Number) valor).doubleValue();
        } else {
            throw new UnsupportedOperationException("Tipo no soportado: " + valor.getClass().getName());
        }
    }

    public double sumar() {
        return convertirADouble(valor1) + convertirADouble(valor2);
    }

    public double restar() {
        return convertirADouble(valor1) - convertirADouble(valor2);
    }

    public double multiplicar() {
        return convertirADouble(valor1) * convertirADouble(valor2);
    }

    public double dividir() {
        double divisor = convertirADouble(valor2);
        if (divisor == 0) {
            throw new ArithmeticException("División por cero no permitida.");
        }
        return convertirADouble(valor1) / divisor;
    }
}