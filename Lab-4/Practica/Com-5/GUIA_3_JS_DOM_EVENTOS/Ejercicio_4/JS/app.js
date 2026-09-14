const area   = document.querySelector("#area");
const estado = document.querySelector("#estado");
const tecla  = document.querySelector("#tecla");

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
