number contador = 0;
while (contador >= 10) {
    print(contador);
    contador += 1;
}

while (true) {
    contador += 1;

    if (contador == 369) {
        print(contador);
        break;
    }
}


// Test 1: While básico con break
number contador = 0;
while (contador < 5) {
    print(contador);
    contador += 1;
}

// Test 2: While con break condicional
number i = 0;
while (true) {
    i += 1;
    if (i == 10) {
        break;
    }
    print(i);
}

// Test 3: While con continue
number j = 0;
while (j < 10) {
    j += 1;
    if (j % 2 == 0) {
        continue;
    }
    print(j);  // Solo imprime números impares
}

// Test 4: Do-while
number k = 0;
do {
    print(k);
    k += 1;
} while (k < 3);

// Test 5: While anidado con break y continue
number x = 0;
number y = 0;
while (x < 3) {
    y = 0;
    while (y < 3) {
        if (x == 1 && y == 1) {
            y += 1;
            continue;
        }
        if (x == 2 && y == 2) {
            break;
        }
        print("x: " + x + ", y: " + y);
        y += 1;
    }
    x += 1;
}

// Test 6: While con múltiples condiciones
number a = 0;
bool done = false;
while (a < 5 && done) {
    print(a);
    if (a == 3) {
        done = true;
    }
    a += 1;
}

// Test 7: Do-while con break
do {
    print("Ejecutando...");
    if (true) {
        break;
    }
} while (true);

// Test 8: While con operaciones matemáticas en la condición
number suma = 0;
number n = 1;
while (suma <= 100) {
    suma += n;
    print("Suma actual: " + suma);
    n += 1;
}