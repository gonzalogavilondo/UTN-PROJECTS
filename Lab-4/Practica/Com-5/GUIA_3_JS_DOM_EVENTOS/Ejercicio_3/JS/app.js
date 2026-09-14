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
btnAlternar.addEventListener("click", () => {

    tarjeta.classList.toggle("destacada");

});
