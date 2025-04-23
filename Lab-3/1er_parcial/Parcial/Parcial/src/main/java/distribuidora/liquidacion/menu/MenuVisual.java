package distribuidora.liquidacion.menu;

import distribuidora.liquidacion.empleado.*;
import distribuidora.liquidacion.excepciones.EmpleadoInexistenteException;
import distribuidora.liquidacion.gestor.GestorEmpleados;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;

public class MenuVisual implements Menu {
    private final GestorEmpleados gestorEmpleados;

    private final JFrame frame;

    public MenuVisual(GestorEmpleados gestorEmpleados) {
        this.gestorEmpleados = gestorEmpleados;
        this.frame = new JFrame("Sistema de liquidación de sueldos");
        this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.frame.setLocationRelativeTo(null);
    }

    /*
     * Ejecuta las opciones:
     * 1. Buscar empleado
     * 2. Listar empleados
     * 3. Finalizar
     */
    @Override
    public void ejecutarMenuPrincipal() {
        // Crear el panel
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        // Crear los botones
        JButton buttonBuscarEmpleados = new JButton("Buscar empleado");
        buttonBuscarEmpleados.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    ejecutarBuscarEmpleado();
                } catch (EmpleadoInexistenteException exception) {
                    ejecutarError(exception.getMessage());
                }
            }
        });
        JButton buttonListarEmpleados = new JButton("Listar empleados");
        buttonListarEmpleados.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ejecutarListarEmpleados();
            }
        });

        // Añadir los botones al panel
        panel.add(buttonBuscarEmpleados);
        panel.add(buttonListarEmpleados);

        // Añadir el panel al frame
        mostrar(panel, Size.MINIMO);
    }

    /*
     * Busca un empleado, muestra su información y ejecuta las opciones:
     * 1. Actualizar nombre
     * 2. Actualizar adicional mensual
     * 3. Eliminar empleado
     * 4. Finalizar
     */
    private void ejecutarBuscarEmpleado() throws EmpleadoInexistenteException {
        Empleado empleado = buscarEmpleado();
        if (empleado != null) {

            mostrarObjeto(empleado);

            JPanel panel = new JPanel();
            panel.setLayout(new FlowLayout());

            JButton buttonActualizarNombre = new JButton("Actualizar nombre");
            buttonActualizarNombre.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    ejecutarActualizarNombreEmpleado(empleado);
                }
            });
            JButton buttonActualizarAdicional = new JButton("Actualizar adicional mensual");
            buttonActualizarAdicional.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    ejecutarActualizarAdicionalEmpleado(empleado);
                }
            });
            JButton buttonEliminarEmpleado = new JButton("Eliminar empleado");
            buttonActualizarAdicional.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    ejecutarEliminarEmpleado(empleado);
                }
            });

            panel.add(buttonActualizarNombre);
            panel.add(buttonActualizarAdicional);
            panel.add(buttonEliminarEmpleado);

            limpiar();
            mostrar(panel, Size.MINIMO);
        }
    }

    private Empleado buscarEmpleado() throws EmpleadoInexistenteException {
        // Mostrar un cuadro de diálogo para ingresar el legajo del empleado
        String legajo = JOptionPane.showInputDialog(this.frame, "Legajo:", "Buscar empleado",
                                                    JOptionPane.QUESTION_MESSAGE);

        return gestorEmpleados.buscarEmpleado(legajo);
    }

    private void ejecutarActualizarNombreEmpleado(Empleado empleado) {
        String nombre = JOptionPane.showInputDialog(this.frame, "Nuevo nombre:",
                                                    STR."Actualizar nombre del empleado \{empleado.getNombre()}",
                                                    JOptionPane.QUESTION_MESSAGE);
        empleado.setNombre(nombre);
        mostrarObjeto(empleado);
    }

    private void ejecutarActualizarAdicionalEmpleado(Empleado empleado) {
        if (empleado.isVendedor()) actualizarAdicionalEmpleado((Vendedor) empleado);
        else if (empleado.isRepartidor()) actualizarAdicionalEmpleado((Repartidor) empleado);
        else mostrarObjeto("Tipo de empleado no soportado.");
    }

    private void actualizarAdicionalEmpleado(Vendedor vendedor) {
        String entrada = JOptionPane.showInputDialog(this.frame, "Ventas mensuales:", STR."Actualizar ventas mensuales de \{vendedor.getNombre()}",
                                                     JOptionPane.QUESTION_MESSAGE);
        try {
            float ventas = Float.parseFloat(entrada);
            vendedor.setVentas(ventas);
            mostrarObjeto(vendedor);
        } catch (Exception e) {
            ejecutarError("Valor incorrecto, no se puede convertir a número");
        }
    }

    private void actualizarAdicionalEmpleado(Repartidor repartidor) {
        String entrada = JOptionPane.showInputDialog(this.frame, "Km recorridos:",
                                                     STR."Actualizar viáticos de \{repartidor.getNombre()}",
                                                     JOptionPane.QUESTION_MESSAGE);
        try {
            float distancia = Float.parseFloat(entrada);
            repartidor.setKmRecorridos(distancia);
            mostrarObjeto(repartidor);
        } catch (Exception e) {
            ejecutarError("Valor incorrecto, no se puede convertir a número");
        }
    }

    private void ejecutarEliminarEmpleado(Empleado empleado) {
        boolean resultado = gestorEmpleados.eliminarEmpleado(empleado);
        if (!resultado) ejecutarError("No fue posible eliminar el empleado");
    }

    /*
     * Ejecuta las siguientes opciones:
     * 1. Todos
     * 2. Vendedores
     * 3. Repartidores
     * 4. Administradores
     * 5. Supervisores
     * 6. Salir
     */
    private void ejecutarListarEmpleados() {
        String menu = """
                                
                1. Todos
                2. Vendedores
                3. Repartidores
                4. Administradores
                5. Supervisores
                6. Salir
                """;
        int opcion = 0;

        do {
            System.out.println(menu);

            switch (opcion) {
                case 1 -> {
                    for (Empleado empleado : gestorEmpleados.empleados()) {
                        System.out.println(empleado);
                    }
                }
                case 2 -> {
                    for (Vendedor vendedor : gestorEmpleados.filtrarVendedores()) {
                        System.out.println(vendedor);
                    }
                }
                case 3 -> {
                    for (Repartidor repartidor : gestorEmpleados.filtrarRepartidores()) {
                        System.out.println(repartidor);
                    }
                }
                case 4 -> {
                    for (Administrador administrador : gestorEmpleados.filtrarAdministradores()) {
                        System.out.println(administrador);
                    }
                }
                case 5 -> {
                    for (Supervisor supervisor : gestorEmpleados.filtrarSupervisores()) {
                        System.out.println(supervisor);
                    }
                }
            }

        } while (opcion != 6);
    }

    private void mostrar(JComponent panel, Size size) {
        this.frame.add(panel);
        switch (size) {
            case MINIMO -> this.frame.pack();
            case MAXIMO -> this.frame.setExtendedState(Frame.MAXIMIZED_BOTH);
        }
        this.frame.setVisible(true);
    }

    private void mostrarObjeto(Object object) {
        JOptionPane.showMessageDialog(this.frame, object, "Resultado", JOptionPane.INFORMATION_MESSAGE);
    }

    private void ejecutarError(String mensaje) {
        JOptionPane.showMessageDialog(this.frame, mensaje, "Error", JOptionPane.ERROR_MESSAGE);
    }

    private void limpiar() {
        this.frame.getContentPane().removeAll();
    }

    private enum Size {
        MINIMO, MAXIMO
    }
}
