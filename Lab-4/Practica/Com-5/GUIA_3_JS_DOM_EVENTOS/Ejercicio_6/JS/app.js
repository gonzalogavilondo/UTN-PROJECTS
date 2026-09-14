const formulario = document.querySelector("#formulario");

const inputTarea = document.querySelector("#inputTarea");

const listaTareas = document.querySelector("#listaTareas");

const mensajeVacio = document.querySelector("#mensajeVacio");

const btnTodas = document.querySelector("#todas");
const btnPendientes = document.querySelector("#pendientes");
const btnCompletadas = document.querySelector("#completadas");

// --------------------------------------------------
// AGREGAR TAREA
// --------------------------------------------------

formulario.addEventListener("submit", function (event) {

    // Evitar recarga
    event.preventDefault();

    // Obtener texto
    const texto = inputTarea.value.trim();

    // No crear tareas vacías
    if (texto === "") {
        return;
    }

    // Crear li
    const tarea = document.createElement("li");

    tarea.classList.add("tarea");

    // Crear texto
    const textoTarea = document.createElement("span");

    textoTarea.textContent = texto;

    // Crear contenedor de botones
    const acciones = document.createElement("div");

    acciones.classList.add("acciones");

    // Crear botón completar
    const btnCompletar = document.createElement("button");

    btnCompletar.textContent = "✓";

    // Crear botón eliminar
    const btnEliminar = document.createElement("button");

    btnEliminar.textContent = "Eliminar";

    // Agregar botones al contenedor
    acciones.appendChild(btnCompletar);

    acciones.appendChild(btnEliminar);

    // Agregar texto y acciones al li
    tarea.appendChild(textoTarea);

    tarea.appendChild(acciones);

    // Agregar li a la lista
    listaTareas.appendChild(tarea);

    // Limpiar input
    inputTarea.value = "";

    // Actualizar mensaje
    actualizarMensaje();

    // --------------------------------------------------
    // COMPLETAR TAREA
    // --------------------------------------------------

    btnCompletar.addEventListener("click", function () {

        tarea.classList.toggle("completada");

        actualizarMensaje();

    });

    // --------------------------------------------------
    // ELIMINAR TAREA
    // --------------------------------------------------

    btnEliminar.addEventListener("click", function () {

        tarea.remove();

        actualizarMensaje();

    });

});

// --------------------------------------------------
// ESTADO VACÍO
// --------------------------------------------------

function actualizarMensaje() {

    const cantidadTareas = listaTareas.children.length;

    if (cantidadTareas === 0) {

        mensajeVacio.style.display = "block";

    } else {

        mensajeVacio.style.display = "none";

    }

}

// --------------------------------------------------
// MOSTRAR TODAS
// --------------------------------------------------

btnTodas.addEventListener("click", function () {

    const tareas = document.querySelectorAll(".tarea");

    tareas.forEach(function (tarea) {

        tarea.style.display = "flex";

    });

});

// --------------------------------------------------
// MOSTRAR PENDIENTES
// --------------------------------------------------

btnPendientes.addEventListener("click", function () {

    const tareas = document.querySelectorAll(".tarea");

    tareas.forEach(function (tarea) {

        if (tarea.classList.contains("completada")) {

            tarea.style.display = "none";

        } else {

            tarea.style.display = "flex";

        }

    });

});

// --------------------------------------------------
// MOSTRAR COMPLETADAS
// --------------------------------------------------

btnCompletadas.addEventListener("click", function () {

    const tareas = document.querySelectorAll(".tarea");

    tareas.forEach(function (tarea) {

        if (tarea.classList.contains("completada")) {

            tarea.style.display = "flex";

        } else {

            tarea.style.display = "none";

        }

    });

});
