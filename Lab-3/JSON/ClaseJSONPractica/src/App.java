import clases.Direccion;
import clases.Numero;
import clases.Persona;
import manejoJSON.JSONUtiles;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class App {
    public static void main(String[] args) {

        List<Persona> personas = new ArrayList<>();

        try {
            JSONArray Jpersonas = new JSONArray(JSONUtiles.leer("prueba.json"));
            for(int i = 0; i<Jpersonas.length() ; i++){

                JSONObject Jpersona = Jpersonas.getJSONObject(i);
                Persona p = new Persona();
                p.setNombre(Jpersona.getString("nombre"));
                p.setEdad(Jpersona.getInt("edad"));
                p.setDni(Jpersona.getInt("dni"));

                JSONObject Jdireccion = Jpersona.getJSONObject("direccion");
                Direccion d = new Direccion();
                d.setCalle(Jdireccion.getString("calle"));
                d.setNumero(Jdireccion.getInt("numero"));

                p.setDireccion(d);

                JSONArray Jnumeros = Jpersona.getJSONArray("numeros");
                List<Numero> numeros = new ArrayList<>();
                for (int j =0 ; j<Jnumeros.length(); j++){
                    JSONObject Jnumero = Jnumeros.getJSONObject(j);
                    Numero n = new Numero();
                    n.setCompania(Jnumero.getString("compania"));
                    n.setNumero(Jnumero.getLong("numero"));
                    numeros.add(n);
                }
                p.setNumeros(numeros);
                personas.add(p);
            }
        } catch (JSONException e) {
            throw new RuntimeException(e);
        }

        for(Persona p : personas){
            System.out.println(p);
        }
    }
}
