package excepciones;

public class PrecioNegativoException extends RuntimeException {
    public PrecioNegativoException(String message) {
        super(message);
    }
}
