package manejoJSON;

import clases.*;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class GestionJSON {

    public static Concesionaria mapeoConcesionaria(){
        Concesionaria c = new Concesionaria();
        Inventario<Vehiculo> inventario = new Inventario<>();

        try {
            JSONObject json = new JSONObject(JSONUtiles.leer("concesionaria.json"));
            JSONObject jConcesionaria = json.getJSONObject("concesionaria");
            c.setNombre(jConcesionaria.getString("nombre"));
            c.setUbicacion(jConcesionaria.getString("ubicacion"));
            JSONArray jVehiculos = jConcesionaria.getJSONArray("vehiculos");
            inventario.setVehiculos(mapeoVehiculos(jVehiculos));
            c.setInventario(inventario);

        } catch (JSONException e) {
            throw new RuntimeException(e);
        }

        return c;
    }

    public static List<Vehiculo> mapeoVehiculos(JSONArray jVehiculos){
        List<Vehiculo> vehiculos = new ArrayList<>();

        for (int i=0; i<jVehiculos.length(); i++){
            try {
                JSONObject jVehiculo = jVehiculos.getJSONObject(i);
                if (jVehiculo.getString("tipo").equals("Auto")){
                    Vehiculo a = new Auto();
                    mapeoVehiculo(jVehiculo, a);
                    vehiculos.add(a);
                }else if(jVehiculo.getString("tipo").equals("Deportivo")){
                    Deportivo d = new Deportivo();
                    d.setPotencia(jVehiculo.getInt("potencia"));
                    mapeoVehiculo(jVehiculo, d);
                    vehiculos.add(d);
                } else if (jVehiculo.getString("tipo").equals("Camioneta")) {
                    Camioneta c = new Camioneta();
                    c.setTraccion(jVehiculo.getString("traccion"));
                    mapeoVehiculo(jVehiculo,c);
                    vehiculos.add(c);
                }

            } catch (JSONException e) {
                throw new RuntimeException(e);
            }
        }

        return vehiculos;
    }

    public static void mapeoVehiculo(JSONObject jVehiculo, Vehiculo vehiculo){

        try {
            vehiculo.setTipo(jVehiculo.getString("tipo"));
            vehiculo.setMarca(jVehiculo.getString("marca"));
            vehiculo.setModelo(jVehiculo.getString("modelo"));
            vehiculo.setPrecio(jVehiculo.getDouble("precio"));
            vehiculo.setAnio(jVehiculo.getInt("anio"));

            JSONArray jCaracteristicas = jVehiculo.getJSONArray("caracteristicas");
            List<String> caracteristicas = new ArrayList<>();
            for (int i=0; i<jCaracteristicas.length(); i++){
                caracteristicas.add(jCaracteristicas.getString(i));
            }
            vehiculo.setCaracteristicas(caracteristicas);

            JSONObject jProovedor = jVehiculo.getJSONObject("proveedor");
            Proveedor p = new Proveedor();
            p.setNombre(jProovedor.getString("nombre"));
            p.setPais(jProovedor.getString("pais"));
            vehiculo.setProveedor(p);
        } catch (JSONException e) {
            throw new RuntimeException(e);
        }
    }
}
