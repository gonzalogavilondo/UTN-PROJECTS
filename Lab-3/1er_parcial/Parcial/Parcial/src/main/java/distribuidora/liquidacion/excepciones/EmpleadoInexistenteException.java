package distribuidora.liquidacion.excepciones;

public class EmpleadoInexistenteException extends Exception {

    private String legajo;

    public EmpleadoInexistenteException(String legajo) {
        this.legajo = legajo;
    }

    @Override
    public String getMessage() {
        return String.format("El empleado con legajo %s no existe.", legajo);
    }
}
