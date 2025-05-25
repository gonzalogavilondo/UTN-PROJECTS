package excepciones;

public class VehiculoInexistenteException extends RuntimeException {
    public VehiculoInexistenteException(String message) {
        super(message);
    }
}
