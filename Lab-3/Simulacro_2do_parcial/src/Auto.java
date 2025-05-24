import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class Auto extends Vehiculo {

    public Auto(String marca, String modelo, double precio, int anio, List<String> caracteristicas, Proveedor proveedor) {
        super("Auto", marca, modelo, precio, anio, caracteristicas, proveedor);
    }


    @Override
    public String toString() {
        return "Auto{" + super.toString() + "}";
    }

    public static Auto fromJSON(JSONObject obj) {
        try {
            String marca = obj.getString("marca");
            String modelo = obj.getString("modelo");
            double precio = obj.getDouble("precio");
            int anio = obj.getInt("anio");
            JSONArray arr = obj.getJSONArray("caracteristicas");
            List<String> caracteristicas = new ArrayList<>();
            for (int i = 0; i < arr.length(); i++) {
                caracteristicas.add(arr.getString(i));
            }
            JSONObject prov = obj.getJSONObject("proveedor");
            Proveedor proveedor = new Proveedor(prov.getString("nombre"), prov.getString("pais"));
            return new Auto(marca, modelo, precio, anio, caracteristicas, proveedor);
        } catch (org.json.JSONException e) {
            e.printStackTrace();
            return null;
        }
    }

    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        try {
            obj.put("tipo", getTipo());
            obj.put("marca", getMarca());
            obj.put("modelo", getModelo());
            obj.put("precio", getPrecio());
            obj.put("anio", getAnio());
            obj.put("caracteristicas", new JSONArray(getCaracteristicas()));
            JSONObject prov = new JSONObject();
            prov.put("nombre", getFabricante().getNombre());
            prov.put("pais", getFabricante().getPais());
            obj.put("proveedor", prov);
        } catch (org.json.JSONException e) {
            e.printStackTrace();
        }
        return obj;
    }

}