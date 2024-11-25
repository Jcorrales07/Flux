// Test de operador NOT
bool a = true;
bool b = false;

// NOT básico
print(!a);       // false
print(!b);       // true

// NOT con paréntesis
print(!(a && b));  // true
print(!(a || b));  // false

// NOT en condiciones
if (!b) {
    print("b es falso");
}

// NOT en while
while (!a) {
    print("Este mensaje no se imprime");
    break;
}

// NOT con expresiones compuestas
bool c = !(a && b) || (!a && b);
print(c);

// NOT con comparaciones
number x = 5;
number y = 10;
bool d = !(x > y);
print(d);  // true

// NOT anidado
print(!!a);  // true
print(!!!a); // false

// NOT en operaciones lógicas complejas
bool result = !a && !b || !(a && b);
print(result);