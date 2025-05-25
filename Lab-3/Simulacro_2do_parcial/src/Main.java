import org.json.JSONException;

import java.util.List;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        // Cargar los datos de la concesionaria al iniciar desde el json
        Concesionaria concesionaria = new Concesionaria();
        try {
            concesionaria = Persistencia.cargarConcesionaria();
            Menu menu = new Menu(concesionaria);
            menu.mostrar();
        } catch (JSONException e) {
            System.out.println("Error al cargar los datos de la concesionaria: " + e.getMessage());
        }

        // Guardar los datos de la concesionaria al salir
        try {
            Persistencia.guardarConcesionaria(concesionaria, "backup.json");
        } catch (JSONException e) {
            System.out.println("Error al guardar los datos de la concesionaria: " + e.getMessage());
        }
    }
}