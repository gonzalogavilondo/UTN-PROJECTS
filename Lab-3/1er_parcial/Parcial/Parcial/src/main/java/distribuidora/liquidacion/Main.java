package distribuidora.liquidacion;

import distribuidora.liquidacion.gestor.GestorEmpleados;
import distribuidora.liquidacion.menu.Menu;
import distribuidora.liquidacion.menu.MenuConsola;
import distribuidora.liquidacion.menu.MenuVisual;

public class Main {
    public static void main(String[] args) {
        GestorEmpleados gestorEmpleados = new GestorEmpleados(true);
        Menu menu = new MenuVisual(gestorEmpleados);
        menu.ejecutarMenuPrincipal();
    }
}