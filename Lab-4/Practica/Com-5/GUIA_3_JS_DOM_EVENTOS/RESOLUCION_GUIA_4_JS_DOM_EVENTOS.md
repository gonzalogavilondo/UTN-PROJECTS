# Resolucion de ejercicios de DOM y Eventos js

---

# Ejercicio 1 — Estructura y DOM

## HTML

```html
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ejercicio 1 - DOM</title>

    <link rel="stylesheet" href="style.css">
</head>

<body>

    <header>
        <h1>Mi página</h1>
    </header>

    <main>

        <section>
            <h2>Sección 1</h2>

            <p>
                Este es el contenido de la primera sección.
            </p>

            <ul>
                <li>Elemento 1</li>
                <li>Elemento 2</li>
                <li>Elemento 3</li>
            </ul>
        </section>

        <section>
            <h2>Sección 2</h2>

            <p>
                Este es el contenido de la segunda sección.
            </p>

            <ul>
                <li>Elemento A</li>
                <li>Elemento B</li>
                <li>Elemento C</li>
            </ul>
        </section>

    </main>

    <footer>
        <p>Pie de página</p>
    </footer>

</body>
</html>
```

## CSS

```css
* {
    box-sizing: border-box;
}

body {
    margin: 0;
    font-family: Arial, sans-serif;
}

header {
    width: 100%;
    height: 100px;

    display: flex;
    justify-content: center;
    align-items: center;

    background-color: #333;
    color: white;
}

main {
    min-height: 500px;

    display: flex;
    justify-content: center;
    align-items: center;

    gap: 20px;
}

section {
    width: 300px;

    padding: 20px;

    border: 2px solid #333;
    background-color: #f2f2f2;
}

footer {
    width: 100%;
    height: 60px;

    display: flex;
    justify-content: center;
    align-items: center;

    background-color: #333;
    color: white;
}
```

## JavaScript

En este ejercicio **no necesitamos JavaScript para que la página funcione**.

La Parte B consiste en inspeccionar el DOM desde el navegador.

Si queremos utilizar JavaScript simplemente para observar la estructura:

```jsx
const main = document.querySelector("main");

console.log(main);
console.log(main.children);
```

También podemos observar las secciones:

```jsx
const secciones = document.querySelectorAll("section");

console.log(secciones);
```

### Respuestas

**a. ¿Qué relación existe entre la estructura HTML y el árbol del DOM?**

El navegador transforma el HTML en un **árbol de nodos llamado DOM**. La estructura de padres, hijos y hermanos del HTML se representa en ese árbol.

**b. ¿Qué elementos son hijos directos de `main`?**

Las dos etiquetas `<section>`.

```
main
├── section
└── section
```

**c. ¿Qué función cumplió Flexbox?**

Flexbox organizó las dos secciones horizontalmente y permitió controlar su alineación y separación.

**d. ¿El uso de Flexbox modifica el DOM?**

No.

Flexbox solamente modifica **cómo se presentan visualmente los elementos**. La estructura del DOM permanece igual.

---

# Ejercicio 2 — Tarjetas y selección

## HTML

```html
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Ejercicio 2 - Tarjetas</title>

    <link rel="stylesheet" href="style.css">
</head>

<body>

    <main>

        <section class="tarjetas">

            <article class="tarjeta">
                <h2>Producto 1</h2>
                <p>Descripción del producto 1.</p>
                <button>Comprar</button>
            </article>

            <article class="tarjeta">
                <h2>Producto 2</h2>
                <p>Descripción del producto 2.</p>
                <button>Comprar</button>
            </article>

            <article class="tarjeta">
                <h2>Producto 3</h2>
                <p>Descripción del producto 3.</p>
                <button>Comprar</button>
            </article>

            <article class="tarjeta">
                <h2>Producto 4</h2>
                <p>Descripción del producto 4.</p>
                <button>Comprar</button>
            </article>

            <article class="tarjeta">
                <h2>Producto 5</h2>
                <p>Descripción del producto 5.</p>
                <button>Comprar</button>
            </article>

            <article class="tarjeta">
                <h2>Producto 6</h2>
                <p>Descripción del producto 6.</p>
                <button>Comprar</button>
            </article>

        </section>

    </main>

    <script src="script.js"></script>
</body>
</html>
```

## CSS

```css
* {
    box-sizing: border-box;
}

body {
    margin: 0;
    font-family: Arial, sans-serif;
}

.tarjetas {
    display: grid;

    grid-template-columns: repeat(3, 200px);

    gap: 20px;

    justify-content: center;

    padding: 40px;
}

.tarjeta {
    min-height: 180px;

    padding: 15px;

    border: 2px solid #333;

    display: flex;
    flex-direction: column;
}

.tarjeta button {
    margin-top: auto;
}
```

La línea:

```css
margin-top: auto;
```

hace que el botón se vaya hacia abajo, aprovechando el espacio disponible.

## JavaScript

```jsx
// Seleccionar UNA tarjeta
const tarjeta = document.querySelector(".tarjeta");

console.log("Una tarjeta:");
console.log(tarjeta);

// Seleccionar TODAS las tarjetas
const tarjetas = document.querySelectorAll(".tarjeta");

console.log("Todas las tarjetas:");
console.log(tarjetas);

// Seleccionar TODOS los botones
const botones = document.querySelectorAll("button");

console.log("Todos los botones:");
console.log(botones);
```

### Respuestas

**a. `querySelector()` vs `querySelectorAll()`**

`querySelector()` devuelve el **primer elemento** que coincide.

```jsx
document.querySelector(".tarjeta");
```

`querySelectorAll()` devuelve **todos los elementos** que coinciden.

```jsx
document.querySelectorAll(".tarjeta");
```

**b. ¿Por qué Grid resulta adecuado?**

Porque tenemos una estructura bidimensional: **filas y columnas**.

```
┌──────┐ ┌──────┐ ┌──────┐
│  1   │ │  2   │ │  3   │
└──────┘ └──────┘ └──────┘

┌──────┐ ┌──────┐ ┌──────┐
│  4   │ │  5   │ │  6   │
└──────┘ └──────┘ └──────┘
```

**c. ¿La distribución pertenece al DOM o al CSS?**

Al **CSS**.

El DOM sabe que existen seis tarjetas, pero Grid determina cómo se distribuyen visualmente.

---

# Ejercicio 3 — Cambiar el estado de una tarjeta

## HTML

```html
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Ejercicio 3 - Estado</title>

    <link rel="stylesheet" href="style.css">
</head>

<body>

    <main>

        <section class="tarjetas">

            <article class="tarjeta">
                <h2>Producto 1</h2>
                <p>Descripción del producto.</p>
                <button>Comprar</button>
            </article>

            <article class="tarjeta">
                <h2>Producto 2</h2>
                <p>Otra descripción.</p>
                <button>Comprar</button>
            </article>

        </section>

        <div class="controles">
            <button id="btnDestacar">
                Destacar tarjeta
            </button>

            <button id="btnAlternar">
                Alternar estado
            </button>
        </div>

    </main>

    <script src="script.js"></script>
</body>
</html>
```

## CSS

```css
* {
    box-sizing: border-box;
}

body {
    margin: 0;
    font-family: Arial, sans-serif;
}

.tarjetas {
    display: flex;
    justify-content: center;
    gap: 20px;

    padding: 40px;
}

.tarjeta {
    width: 200px;
    min-height: 180px;

    padding: 15px;

    border: 2px solid #333;

    display: flex;
    flex-direction: column;
}

.tarjeta button {
    margin-top: auto;
}

.destacada {
    background-color: gold;
    color: #222;

    border: 3px solid orange;

    box-shadow: 0 0 15px rgba(0, 0, 0, 0.4);
}

.controles {
    display: flex;
    justify-content: center;
    gap: 10px;
}
```

## JavaScript

```jsx
const tarjeta = document.querySelector(".tarjeta");

const btnDestacar = document.querySelector("#btnDestacar");
const btnAlternar = document.querySelector("#btnAlternar");

// Botón "Destacar tarjeta"
btnDestacar.addEventListener("click", function () {

    tarjeta.querySelector("h2").textContent = "¡Producto destacado!";

    tarjeta.querySelector("p").textContent =
        "Este producto fue seleccionado como destacado.";

    tarjeta.classList.add("destacada");

});

// Botón "Alternar estado"
btnAlternar.addEventListener("click", function () {

    tarjeta.classList.toggle("destacada");

});
```

### Respuestas

**a. ¿Qué parte del cambio visual está definida en CSS?**

La clase:

```css
.destacada
```

define cómo se ve la tarjeta cuando está destacada.

**b. ¿Qué hace JavaScript?**

JavaScript modifica el DOM:

```jsx
tarjeta.classList.add("destacada");
```

Es decir, agrega la clase al elemento.

**c. ¿Qué sucede en el DOM cuando agregamos una clase?**

El atributo `class` del elemento cambia.

Antes:

```html
<article class="tarjeta">
```

Después:

```html
<article class="tarjeta destacada">
```

El CSS detecta esa clase y aplica sus estilos.

**d. `style` vs agregar una clase**

Podríamos hacer:

```jsx
tarjeta.style.backgroundColor = "gold";
```

Pero eso mezcla comportamiento y presentación.

Es más organizado hacer:

```jsx
tarjeta.classList.add("destacada");
```

y dejar la apariencia en CSS:

```css
.destacada {
    background-color: gold;
}
```

---

# Ejercicio 4 — Área interactiva

## HTML

```html
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Ejercicio 4 - Eventos</title>

    <link rel="stylesheet" href="style.css">
</head>

<body>

    <main>

        <div id="area">
            ÁREA INTERACTIVA
        </div>

        <p id="estado">
            Estado: esperando interacción
        </p>

        <p id="tecla">
            Última tecla: ninguna
        </p>

    </main>

    <script src="script.js"></script>
</body>
</html>
```

## CSS

```css
* {
    box-sizing: border-box;
}

body {
    margin: 0;
    font-family: Arial, sans-serif;
}

main {
    min-height: 100vh;

    display: flex;
    flex-direction: column;

    justify-content: center;
    align-items: center;

    gap: 20px;
}

#area {
    width: 400px;
    height: 200px;

    display: flex;

    justify-content: center;
    align-items: center;

    border: 3px solid #333;

    background-color: #eee;

    border-radius: 15px;

    cursor: pointer;
}

#area.activa {
    background-color: gold;
    border-color: orange;
}
```

## JavaScript

```jsx
const area = document.querySelector("#area");
const estado = document.querySelector("#estado");
const tecla = document.querySelector("#tecla");

// CLICK
area.addEventListener("click", function () {

    area.classList.toggle("activa");

    estado.textContent = "Estado: hiciste click";

});

// MOUSEOVER
area.addEventListener("mouseover", function () {

    estado.textContent = "Estado: mouse sobre el área";

});

// MOUSEOUT
area.addEventListener("mouseout", function () {

    estado.textContent = "Estado: mouse fuera del área";

});

// KEYDOWN
document.addEventListener("keydown", function (event) {

    tecla.textContent = "Última tecla: " + event.key;

});
```

### Respuestas

**a. `mouseover` vs `click`**

`mouseover` ocurre cuando el mouse entra o pasa sobre el elemento.

`click` ocurre cuando el usuario hace clic.

**b. ¿Qué elemento recibe `keydown`?**

En este caso:

```jsx
document.addEventListener("keydown", ...)
```

el evento se escucha sobre `document`.

Esto permite detectar las teclas presionadas mientras la página tiene el foco.

**c. ¿Qué proporciona `event.key`?**

Indica qué tecla fue presionada.

Por ejemplo:

```
a
Enter
Escape
ArrowUp
1
```

**d. ¿Qué resolvimos con CSS antes de JavaScript?**

Prácticamente toda la interfaz:

- tamaño;
- posición;
- centrado;
- borde;
- fondo;
- bordes redondeados;
- distribución del contenido mediante Flexbox.

JavaScript solamente agrega **comportamiento**.

---

# Ejercicio 5 — Formulario

## HTML

```html
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Ejercicio 5 - Formulario</title>

    <link rel="stylesheet" href="style.css">
</head>

<body>

    <main>

        <form id="formulario">

            <h1>Registro</h1>

            <label for="nombre">
                Nombre
            </label>

            <input
                type="text"
                id="nombre"
                placeholder="Ingrese su nombre"
            >

            <label for="email">
                Email
            </label>

            <input
                type="email"
                id="email"
                placeholder="Ingrese su email"
            >

            <label for="password">
                Contraseña
            </label>

            <input
                type="password"
                id="password"
                placeholder="Ingrese su contraseña"
            >

            <button type="submit">
                Registrarse
            </button>

            <p id="mensaje"></p>

        </form>

    </main>

    <script src="script.js"></script>
</body>
</html>
```

## CSS

```css
* {
    box-sizing: border-box;
}

body {
    margin: 0;
    font-family: Arial, sans-serif;
}

main {
    min-height: 100vh;

    display: flex;
    justify-content: center;
    align-items: center;
}

form {
    width: 400px;

    padding: 20px;

    display: flex;
    flex-direction: column;

    gap: 10px;

    border: 2px solid #333;
}

input {
    width: 100%;
    height: 40px;

    padding: 8px;

    border: 2px solid #ccc;
}

button {
    height: 40px;

    cursor: pointer;
}

.error {
    border-color: red;
    background-color: #ffe5e5;
}

.correcto {
    border-color: green;
    background-color: #e5ffe5;
}

#mensaje {
    font-weight: bold;
}
```

## JavaScript

```jsx
const formulario = document.querySelector("#formulario");

const nombre = document.querySelector("#nombre");
const email = document.querySelector("#email");
const password = document.querySelector("#password");

const mensaje = document.querySelector("#mensaje");

formulario.addEventListener("submit", function (event) {

    // Evita que el formulario recargue la página
    event.preventDefault();

    let formularioValido = true;

    // Validar nombre
    if (nombre.value.trim() === "") {

        nombre.classList.add("error");
        nombre.classList.remove("correcto");

        formularioValido = false;

    } else {

        nombre.classList.remove("error");
        nombre.classList.add("correcto");

    }

    // Validar email
    if (email.value.trim() === "") {

        email.classList.add("error");
        email.classList.remove("correcto");

        formularioValido = false;

    } else {

        email.classList.remove("error");
        email.classList.add("correcto");

    }

    // Validar contraseña
    if (password.value.trim() === "") {

        password.classList.add("error");
        password.classList.remove("correcto");

        formularioValido = false;

    } else {

        password.classList.remove("error");
        password.classList.add("correcto");

    }

    // Mensaje general
    if (formularioValido) {

        mensaje.textContent = "Formulario enviado correctamente.";

    } else {

        mensaje.textContent =
            "Por favor, completá todos los campos.";

    }

});
```

### Respuestas

**a. ¿Qué evita `preventDefault()`?**

Evita el comportamiento predeterminado del formulario: **enviar los datos y recargar/navegar la página**.

```jsx
event.preventDefault();
```

Nos permite controlar el envío mediante JavaScript.

**b. ¿Qué hace JavaScript y qué hace CSS?**

JavaScript determina el estado:

```jsx
nombre.classList.add("error");
```

CSS determina cómo se ve:

```css
.error {
    border-color: red;
}
```

**c. ¿Por qué podemos usar Flexbox sin JavaScript?**

Porque Flexbox pertenece al **sistema de estilos CSS**.

JavaScript no es necesario para organizar visualmente elementos.

---

# Ejercicio 6 — Proyecto integrador

Acá está la parte más importante porque combina prácticamente todo lo anterior.

---

## HTML

```html
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>Mis tareas</title>

    <link rel="stylesheet" href="style.css">
</head>

<body>

    <main class="app">

        <h1>Mis tareas</h1>

        <form id="formulario">

            <input
                type="text"
                id="inputTarea"
                placeholder="Nueva tarea..."
            >

            <button type="submit">
                Agregar
            </button>

        </form>

        <div class="filtros">

            <button type="button" id="todas">
                Todas
            </button>

            <button type="button" id="pendientes">
                Pendientes
            </button>

            <button type="button" id="completadas">
                Completadas
            </button>

        </div>

        <ul id="listaTareas">

            <!-- Las tareas serán creadas por JavaScript -->

        </ul>

        <p id="mensajeVacio">
            No hay tareas pendientes.
        </p>

    </main>

    <script src="script.js"></script>

</body>
</html>
```

---

# CSS

```css
* {
    box-sizing: border-box;
}

body {
    margin: 0;

    font-family: Arial, sans-serif;

    background-color: #eee;
}

/* CONTENEDOR PRINCIPAL */

.app {
    width: 500px;

    margin: 50px auto;

    padding: 20px;

    background-color: white;

    border: 2px solid #333;

    border-radius: 10px;
}

/* TÍTULO */

h1 {
    text-align: center;
}

/* FORMULARIO */

#formulario {
    display: flex;

    gap: 10px;
}

/* INPUT */

#inputTarea {
    flex: 1;

    height: 40px;

    padding: 10px;
}

/* BOTÓN AGREGAR */

#formulario button {
    height: 40px;

    padding: 0 15px;
}

/* FILTROS */

.filtros {
    display: flex;

    gap: 10px;

    margin-top: 20px;
}

/* LISTA */

#listaTareas {
    display: flex;

    flex-direction: column;

    gap: 10px;

    padding: 0;

    margin-top: 20px;

    list-style: none;
}

/* TAREA */

.tarea {
    display: flex;

    justify-content: space-between;

    align-items: center;

    gap: 10px;

    padding: 10px;

    border: 1px solid #999;

    background-color: #f5f5f5;
}

/* TEXTO DE LA TAREA */

.tarea span {
    flex: 1;
}

/* BOTONES DE LA TAREA */

.tarea .acciones {
    display: flex;

    gap: 10px;
}

/* TAREA COMPLETADA */

.completada {
    background-color: #d9ffd9;

    text-decoration: line-through;

    opacity: 0.7;
}

/* MENSAJE */

#mensajeVacio {
    text-align: center;

    color: #666;
}
```

---

# JavaScript

```jsx
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
```

---

# ¿Qué está pasando en el proyecto?

Este ejercicio permite ver muy claramente la separación entre las tres tecnologías.

### HTML

Define **qué elementos existen inicialmente**:

```html
<form>
    <input>
    <button>
</form>

<ul></ul>
```

No necesitamos crear las tareas en HTML porque las vamos a crear dinámicamente.

---

### CSS

Define **cómo se ven y cómo se organizan**:

```css
.app {
    width: 500px;
}
```

```css
#formulario {
    display: flex;
}
```

```css
.tarea {
    display: flex;
}
```

```css
.completada {
    text-decoration: line-through;
}
```

CSS no necesita saber cuándo el usuario agrega una tarea.

---

### JavaScript

Define **qué sucede cuando el usuario interactúa**.

Por ejemplo:

```jsx
formulario.addEventListener("submit", ...)
```

significa:

> "Cuando ocurra un envío del formulario, ejecutá esta función."
> 

Después JavaScript modifica el DOM:

```jsx
const tarea = document.createElement("li");
```

Creamos un elemento que **antes no existía**.

Luego:

```jsx
listaTareas.appendChild(tarea);
```

lo incorporamos al DOM.

Y cuando eliminamos:

```jsx
tarea.remove();
```

lo sacamos del DOM.

---

# El recorrido completo

Este proyecto resume muy bien el concepto que querés trabajar con los alumnos:

```
              HTML
                ↓
        Creo la estructura
                ↓
              CSS
                ↓
       Organizo y diseño
                ↓
          Usuario actúa
                ↓
          ocurre un evento
                ↓
         JavaScript detecta
                ↓
       JavaScript modifica
              el DOM
                ↓
          CSS responde
                ↓
       cambia la apariencia
```

Por ejemplo, al completar una tarea:

```jsx
btnCompletar.addEventListener("click", function () {

    tarea.classList.toggle("completada");

});
```

JavaScript **no define cómo se ve una tarea completada**.

Solamente cambia el DOM:

```html
<li class="tarea">
```

pasa a:

```html
<li class="tarea completada">
```

Y entonces CSS entra en acción:

```css
.completada {
    background-color: #d9ffd9;
    text-decoration: line-through;
}
```

Esa separación es justamente uno de los conceptos más importantes que deberían llevarse de esta guía.

---

# Respuestas finales

### a. ¿Qué parte de la aplicación construiste sin JavaScript?

La estructura HTML, los formularios, botones, contenedores, lista y toda la apariencia y distribución mediante CSS.

### b. ¿Qué elementos fueron creados mediante JavaScript?

Principalmente las tareas:

```jsx
document.createElement("li");
document.createElement("span");
document.createElement("button");
document.createElement("div");
```

### c. ¿Qué eventos utilizaste?

En los ejercicios aparecen:

```
click
mouseover
mouseout
keydown
submit
```

### d. ¿Qué función cumplió Flexbox?

Organizar elementos en una dimensión.

Por ejemplo:

```css
#formulario {
    display: flex;
}
```

permite colocar el input y el botón dentro del formulario.

También:

```css
.tarea {
    display: flex;
    justify-content: space-between;
}
```

permite colocar el texto de la tarea de un lado y los botones del otro.

### e. ¿En qué parte podría resultar útil Grid?

Podría utilizarse, por ejemplo, para una vista de tarjetas:

```
┌──────┐ ┌──────┐ ┌──────┐
│      │ │      │ │      │
├──────┤ ├──────┤ ├──────┤
│      │ │      │ │      │
└──────┘ └──────┘ └──────┘
```

Grid resulta especialmente cómodo cuando necesitamos controlar **filas y columnas**.

### f. ¿Qué modificaciones realiza JavaScript sobre el DOM?

Por ejemplo:

```jsx
createElement()
```

crea elementos.

```jsx
appendChild()
```

agrega elementos.

```jsx
remove()
```

elimina elementos.

```jsx
classList.add()
```

agrega clases.

```jsx
classList.remove()
```

elimina clases.

```jsx
classList.toggle()
```

agrega o quita una clase.

```jsx
textContent
```

modifica el contenido de un elemento.

### g. ¿Qué cambios visuales son responsabilidad de CSS?

Por ejemplo:

- colores;
- fondos;
- bordes;
- sombras;
- tamaños;
- márgenes;
- padding;
- Flexbox;
- Grid;
- alineación;
- distribución;
- tipografía.

### h. Si eliminás JavaScript, ¿qué parte sigue funcionando?

La **estructura y apariencia**.

La página HTML y CSS sigue existiendo, pero la aplicación deja de ser interactiva.

En el proyecto de tareas, por ejemplo, podríamos ver el formulario, pero no podríamos agregar, completar ni eliminar tareas.

### i. Si eliminás CSS, ¿qué parte sigue funcionando?

HTML y JavaScript seguirían funcionando.

Podríamos agregar y eliminar tareas, pero la interfaz tendría una apariencia mucho más básica y perderíamos toda la distribución y presentación definida mediante CSS.

### j. ¿Por qué HTML, CSS y JavaScript cumplen funciones diferentes pero complementarias?

Porque cada tecnología resuelve un problema diferente:

```
HTML
¿Qué elementos existen?
        ↓
CSS
¿Cómo se ven y cómo se distribuyen?
        ↓
JavaScript
¿Qué hacen cuando interactúa el usuario?
```

O, dicho de una manera todavía más simple:

**HTML construye, CSS organiza y pinta, JavaScript hace que pasen cosas.**