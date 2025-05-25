import clases.Concesionaria;
import manejoJSON.GestionJSON;

public class App {
    public static void main(String[] args) {
        Concesionaria concesionaria = GestionJSON.mapeoConcesionaria();

        concesionaria.filtrado1(100000);
        concesionaria.filtrado2(700,"Turbo");
        concesionaria.filtrado3(2020,"EEUU");
    }
}
