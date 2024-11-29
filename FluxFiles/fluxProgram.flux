// Importar módulos
from utils import print, range;

// Declarar una constante
const number MAX_COUNT = 100;

/**
    c
    o
    m
    e
    n
    t
    a
    r
    i
    o
**/

/
/=
!
!=

// Declarar una clase
class Person {
    public {
        // Atributos públicos
        number age;
        string name;

        // Constructor público
        Person(string name, number age) {
            this.name = name;
            this.age = age;
        }

        // Método público
        func greet() {
            print("Hello, my name is " + this.name + " and I am " + this.age + " years old.");
        }
    }

    private {
        // Atributos privados
        string secretCode;

        // Método privado
        func setSecretCode(string code) {
            this.secretCode = code;
        }
    }
}

// Declarar una función global
number func factorial(number n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Programa principal
func main() {
    // Crear una instancia de la clase Person
    Person person = new Person("Alice", 25);
    person.greet();

    // Usar un bucle for con un rango
    for (i in range(1, 11)) {
        print("Factorial of " + i + " is " + factorial(i));
    }

    // Declarar una variable y usar un bucle while
    number counter = 0;
    while (counter < 5) {
        print("Counter: " + counter);
        counter += 1;
    }

    // Usar un bloque if-else
    if (counter == 5) {
        print("Counter reached 5!");
    } else {
        print("Counter did not reach 5.");
    }

    // Usar un array
    number numbers = [1, 2, 3, 4, 5];
    for (num in numbers) {
        print("Array item: " + num);
    }

    // Llamar a una función incorporada
    print("Range example:");
    for (i in range(0, 10, 2)) {
        print(i);
    }
}

// Ejecutar el programa principal
main();
