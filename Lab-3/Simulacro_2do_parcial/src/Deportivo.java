import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class Deportivo extends Vehiculo {
    private int potencia;

    public Deportivo(String marca, String modelo, double precio, int anio, List<String> caracteristicas, Proveedor proveedor, int potencia) {
        super("Deportivo", marca, modelo, precio, anio, caracteristicas, proveedor);
        this.potencia = potencia;
    }

    public int getPotencia() {
        return potencia;
    }

    public void setPotencia(int potencia) {
        this.potencia = potencia;
    }

    @Override
    public String toString() {
        return "Deportivo{" +
                "potencia=" + potencia +
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
            obj.put("potencia", getPotencia());
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

    public static Deportivo fromJSON(JSONObject obj) {
        try {
            String marca = obj.getString("marca");
            String modelo = obj.getString("modelo");
            double precio = obj.getDouble("precio");
            int anio = obj.getInt("anio");
            int potencia = obj.getInt("potencia");
            JSONArray arr = obj.getJSONArray("caracteristicas");
            List<String> caracteristicas = new ArrayList<>();
            for (int i = 0; i < arr.length(); i++) {
                caracteristicas.add(arr.getString(i));
            }
            JSONObject prov = obj.getJSONObject("proveedor");
            Proveedor proveedor = new Proveedor(prov.getString("nombre"), prov.getString("pais"));
            return new Deportivo(marca, modelo, precio, anio, caracteristicas, proveedor, potencia);
        } catch (org.json.JSONException e) {
            e.printStackTrace();
            return null;
        }
    }
}