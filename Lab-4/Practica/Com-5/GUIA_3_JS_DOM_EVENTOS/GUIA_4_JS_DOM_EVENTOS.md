# Guía Práctica: DOM y Eventos en JavaScript

## Objetivo

En esta guía vas a integrar **HTML, CSS y JavaScript**.

En cada ejercicio vas a construir primero la interfaz utilizando **HTML y CSS, sin JavaScript**, y luego agregarás comportamiento mediante JavaScript.

Recordá:

```
HTML → estructura
CSS → apariencia y distribución
JavaScript → comportamiento e interacción
```

---

# Ejercicio 1 — Estructura y DOM

### Consigna

Creá una página que contenga:

- un `header`;
- un `main`;
- dos secciones;
- un `footer`.

Dentro de cada sección colocá un título, un párrafo y una lista.

### Parte A — HTML y CSS **SIN JAVASCRIPT**

Utilizá **Flexbox** para organizar las dos secciones una al lado de la otra.

La página debe cumplir:

- `header` y `footer`: `100%` de ancho;
- `header`: `100px` de alto;
- `footer`: `60px` de alto;
- las secciones: `300px` de ancho;
- separación de `20px` entre las secciones;
- contenido centrado;
- borde y fondo para cada sección.

### Parte B — DOM

Inspeccioná la página desde las herramientas de desarrollador.

Identificá:

- padres;
- hijos;
- hermanos;
- elementos anidados.

### Preguntas

a. ¿Qué relación existe entre la estructura HTML y el árbol del DOM?

b. ¿Qué elementos son hijos directos de `main`?

c. ¿Qué función cumplió Flexbox en este ejercicio?

d. ¿El uso de Flexbox modifica el DOM?

---

# Ejercicio 2 — Tarjetas y selección

### Consigna

Creá una sección con **seis tarjetas**.

Cada tarjeta debe contener:

- título;
- descripción;
- botón.

### Parte A — HTML y CSS **SIN JAVASCRIPT**

Utilizá **CSS Grid** para distribuir las tarjetas.

La cuadrícula debe tener:

- `3 columnas`;
- tarjetas de `200px` de ancho aproximadamente;
- `20px` de separación entre filas y columnas;
- tarjetas con borde;
- `15px` de padding;
- altura mínima de `180px`.

Los botones deben quedar alineados en la parte inferior de cada tarjeta.

### Parte B — JavaScript

Seleccioná:

- una tarjeta mediante `querySelector()`;
- todas las tarjetas mediante `querySelectorAll()`;
- todos los botones.

Mostrá los resultados en la consola.

### Preguntas

a. ¿Qué diferencia existe entre `querySelector()` y `querySelectorAll()`?

b. ¿Por qué Grid resulta adecuado para distribuir las seis tarjetas?

c. ¿La distribución de las tarjetas pertenece al DOM o al CSS?

---

# Ejercicio 3 — Cambiar el estado de una tarjeta

### Consigna

Utilizá una de las tarjetas del ejercicio anterior.

### Parte A — HTML y CSS **SIN JAVASCRIPT**

Creá una clase:

```css
.destacada
```

La clase debe modificar:

- color de fondo;
- color del texto;
- borde;
- sombra.

Además, agregá un botón fuera de las tarjetas:

```
[ Destacar tarjeta ]
```

### Parte B — JavaScript

Al hacer clic:

1. Seleccioná la tarjeta.
2. Cambiá su contenido.
3. Agregá la clase `.destacada`.

Agregá otro botón:

```
[ Alternar estado ]
```

que utilice:

```jsx
classList.toggle()
```

### Preguntas

a. ¿Qué parte del cambio visual está definida en CSS?

b. ¿Qué hace JavaScript para que ese cambio ocurra?

c. ¿Qué sucede en el DOM cuando agregás una clase?

d. ¿Qué diferencia existe entre cambiar una propiedad con `style` y agregar una clase?

---

# Ejercicio 4 — Área interactiva

### Consigna

Creá una interfaz que tenga:

```
┌─────────────────────────────┐
│                             │
│      ÁREA INTERACTIVA       │
│                             │
└─────────────────────────────┘

Estado: esperando interacción
```

### Parte A — HTML y CSS **SIN JAVASCRIPT**

El área debe:

- medir `400px × 200px`;
- estar centrada;
- utilizar **Flexbox** para centrar el texto horizontal y verticalmente;
- tener un borde de `3px`;
- tener un fondo;
- tener bordes redondeados.

Creá una clase:

```css
.activa
```

que modifique visualmente el área.

### Parte B — JavaScript

Agregá eventos para:

- `click`;
- `mouseover`;
- `mouseout`.

Cada evento debe generar un cambio visible.

Además, utilizá `keydown` para mostrar en pantalla la última tecla presionada.

### Preguntas

a. ¿Qué diferencia existe entre `mouseover` y `click`?

b. ¿Qué elemento recibe el evento `keydown`?

c. ¿Qué información proporciona `event.key`?

d. ¿Qué parte de la interfaz fue resuelta completamente con Flexbox y CSS, antes de utilizar JavaScript?

---

# Ejercicio 5 — Formulario

### Consigna

Creá un formulario de registro con:

- nombre;
- email;
- contraseña;
- botón de envío;
- mensaje de validación.

### Parte A — HTML y CSS **SIN JAVASCRIPT**

El formulario debe:

- tener `400px` de ancho;
- estar centrado;
- tener `20px` de padding;
- utilizar **Flexbox** para organizar los campos verticalmente;
- tener `10px` de separación entre los elementos;
- tener inputs de ancho completo;
- tener un botón de `40px` de alto.

Creá las clases:

```css
.error
.correcto
```

para representar los diferentes estados de los campos.

### Parte B — JavaScript

Al enviar el formulario:

1. Utilizá `preventDefault()`.
2. Verificá que los campos no estén vacíos.
3. Aplicá `.error` cuando exista un problema.
4. Aplicá `.correcto` cuando el dato sea válido.
5. Mostrá un mensaje general.

### Preguntas

a. ¿Qué comportamiento estamos evitando con `preventDefault()`?

b. ¿Qué hace JavaScript y qué hace CSS al mostrar un campo como incorrecto?

c. ¿Por qué el formulario puede estar organizado con Flexbox sin necesidad de JavaScript?

---

# Ejercicio 6 — Proyecto integrador: Lista de tareas

### Consigna

Construí una aplicación de tareas.

```
┌───────────────────────────────────┐
│             MIS TAREAS            │
│                                   │
│ [ Nueva tarea........ ] [Agregar] │
│                                   │
│ ┌───────────────────────────────┐ │
│ │ Estudiar DOM   [✓] [Eliminar] │ │
│ ├───────────────────────────────┤ │
│ │ Practicar CSS   [✓] [Eliminar]│ │
│ └───────────────────────────────┘ │
└───────────────────────────────────┘
```

## Parte A — HTML y CSS **SIN JAVASCRIPT**

Construí primero la interfaz.

La aplicación debe:

- tener `500px` de ancho;
- estar centrada horizontalmente;
- tener `20px` de padding;
- utilizar **Flexbox** para organizar el formulario;
- hacer que el input ocupe el espacio disponible;
- utilizar **Flexbox** para distribuir el contenido de cada tarea;
- separar los botones mediante `10px`;
- tener `10px` de separación entre tareas;
- utilizar bordes y fondos para diferenciar las tareas.

Creá:

```css
.completada
```

para representar visualmente una tarea terminada.

**Esta parte debe funcionar completamente sin JavaScript.**

---

## Parte B — JavaScript

Ahora agregá comportamiento.

### Agregar tareas

Al enviar el formulario:

- evitar la recarga;
- obtener el texto;
- crear un `li`;
- agregarlo a la lista;
- limpiar el input.

Utilizá:

```jsx
createElement()
appendChild()
```

### Completar tareas

El botón correspondiente debe agregar o quitar:

```jsx
.completada
```

utilizando:

```jsx
classList.toggle()
```

### Eliminar tareas

El botón eliminar debe quitar la tarea del DOM utilizando:

```jsx
remove()
```

### Estado vacío

Cuando no existan tareas, mostrar:

```
No hay tareas pendientes.
```

---

# Desafío adicional

Agregá tres botones:

```
[Todas] [Pendientes] [Completadas]
```

Al seleccionar cada opción, la lista debe mostrar solamente las tareas correspondientes.

No es necesario modificar la estructura HTML original: resolvelo modificando el estado o la visibilidad de los elementos mediante JavaScript.

---

# Preguntas finales

a. ¿Qué parte de la aplicación construiste sin JavaScript?

b. ¿Qué elementos fueron creados mediante JavaScript?

c. ¿Qué eventos utilizaste?

d. ¿Qué función cumplió Flexbox?

e. ¿En qué parte podría resultar útil Grid?

f. ¿Qué modificaciones realiza JavaScript sobre el DOM?

g. ¿Qué cambios visuales son responsabilidad de CSS?

h. Si eliminás JavaScript, ¿qué parte de la aplicación sigue funcionando?

i. Si eliminás CSS, ¿qué parte de la aplicación sigue funcionando?

j. ¿Por qué HTML, CSS y JavaScript cumplen funciones diferentes pero complementarias?

---

# Para resolver los ejercicios

Antes de escribir JavaScript, preguntate:

```
¿Qué elementos tengo?
       ↓
¿Cómo están organizados?
       ↓
¿Cómo deben verse?
       ↓
¿Qué acción realiza el usuario?
       ↓
¿Qué evento se produce?
       ↓
¿Qué elemento debo modificar?
       ↓
¿Qué debe cambiar?
```

**Primero construí la interfaz con HTML y CSS. Después agregá JavaScript para darle comportamiento.**