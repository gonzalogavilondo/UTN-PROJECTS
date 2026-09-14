const formulario = document.querySelector("#formulario");

const nombre   = document.querySelector("#nombre");
const email    = document.querySelector("#email");
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
