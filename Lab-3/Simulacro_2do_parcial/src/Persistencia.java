import org.json.JSONArray;
import org.json.JSONObject;
import org.json.JSONException;
import java.util.List;
import java.util.ArrayList;

public class Persistencia {

    //Persistencia para la consecionaria
    public static void guardarConcesionaria(Concesionaria concesionaria, String File) throws JSONException {
        JSONObject obj = new JSONObject();
        try {
            JSONObject conc = new JSONObject();
            conc.put("nombre", concesionaria.getNombre());
            conc.put("ubicacion", concesionaria.getUbicacion());

            // Serializar vehículos
            JSONArray vehiculosArr = new JSONArray();
            for (Vehiculo v : concesionaria.getVehiculos()) {
                if (v instanceof Deportivo) {
                    vehiculosArr.put(((Deportivo) v).toJSON());
                } else if (v instanceof Camioneta) {
                    vehiculosArr.put(((Camioneta) v).toJSON());
                } else if (v instanceof Auto) {
                    vehiculosArr.put(((Auto) v).toJSON());
                }
            }
            conc.put("vehiculos", vehiculosArr);

            obj.put("concesionaria", conc);
            JSONUtiles.grabar(obj.toString(4), File);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    public static Concesionaria cargarConcesionaria() throws JSONException {
        try {
            JSONObject obj = new JSONObject(JSONUtiles.leer("concesionaria.json"));
            JSONObject conc = obj.getJSONObject("concesionaria");
            String nombre = conc.getString("nombre");
            String ubicacion = conc.getString("ubicacion");

            // Deserializar vehículos
            List<Vehiculo> vehiculos = new ArrayList<>();
            JSONArray vehiculosArr = conc.getJSONArray("vehiculos");
            for (int i = 0; i < vehiculosArr.length(); i++) {
                JSONObject vObj = vehiculosArr.getJSONObject(i);
                String tipo = vObj.getString("tipo");
                if (tipo.equals("Deportivo")) {
                    vehiculos.add(Deportivo.fromJSON(vObj));
                } else if (tipo.equals("Camioneta")) {
                    vehiculos.add(Camioneta.fromJSON(vObj));
                } else if (tipo.equals("Auto")) {
                    vehiculos.add(Auto.fromJSON(vObj));
                }
            }
            return new Concesionaria(nombre, ubicacion, vehiculos);
        } catch (JSONException e) {
            e.printStackTrace();
            return null;
        }
    }
}