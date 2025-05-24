package clases;

public class Numero {

    private String compania;
    private long numero;

    public String getCompania() {
        return compania;
    }

    public void setCompania(String compania) {
        this.compania = compania;
    }

    public long getNumero() {
        return numero;
    }

    public void setNumero(long numero) {
        this.numero = numero;
    }

    @Override
    public String toString() {
        return "Numero{" +
                "compania='" + compania + '\'' +
                ", numero=" + numero +
                '}';
    }
}
