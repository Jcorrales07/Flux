string func saludarA(nombre) {
    return "Hola " + nombre;
}

number func calcularEdadEn(annioInicial, annioFuturo) {
    return annioFuturo - annioInicial;
}

bool func esMayorDeEdad(annioNacimiento, annioActual) {
    return (annioActual - annioNacimiento) > 18;
}

// Hace falta las funciones que retornan objetos de clases