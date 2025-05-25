import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class Camioneta extends Vehiculo {
    private String traccion;

    public Camioneta(String marca, String modelo, double precio, int anio, List<String> caracteristicas, Proveedor proveedor, String traccion) {
        super("Camioneta", marca, modelo, precio, anio, caracteristicas, proveedor);
        this.traccion = traccion;
    }

    public String getTraccion() {
        return traccion;
    }

    public void setTraccion(String traccion) {
        this.traccion = traccion;
    }

    @Override
    public String toString() {
        return "Camioneta{" +
                "traccion='" + traccion + '\'' +
                ", " + super.toString() +
                '}';
    }

    //Persistencia JSON
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        try {
            obj.put("tipo", getTipo());
            obj.put("marca", getMarca());
            obj.put("modelo", getModelo());
            obj.put("precio", getPrecio());
            obj.put("anio", getAnio());
            obj.put("traccion", getTraccion());
            obj.put("caracteristicas", new JSONArray(getCaracteristicas()));
            JSONObject prov = new JSONObject();
            prov.put("nombre", getProveedor().getNombre());
            prov.put("pais", getProveedor().getPais());
            obj.put("proveedor", prov);
        } catch (org.json.JSONException e) {
            e.printStackTrace();
        }
        return obj;
    }

    public static Camioneta fromJSON(JSONObject obj) {
        try {
            String marca = obj.getString("marca");
            String modelo = obj.getString("modelo");
            double precio = obj.getDouble("precio");
            int anio = obj.getInt("anio");
            String traccion = obj.getString("traccion");
            JSONArray arr = obj.getJSONArray("caracteristicas");
            List<String> caracteristicas = new ArrayList<>();
            for (int i = 0; i < arr.length(); i++) {
                caracteristicas.add(arr.getString(i));
            }
            JSONObject prov = obj.getJSONObject("proveedor");
            Proveedor proveedor = new Proveedor(prov.getString("nombre"), prov.getString("pais"));
            return new Camioneta(marca, modelo, precio, anio, caracteristicas, proveedor, traccion);
        } catch (org.json.JSONException e) {
            e.printStackTrace();
            return null;
        }
    }

}