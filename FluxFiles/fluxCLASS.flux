export class Persona {
    public {
        string name;
        number age;

        Persona(string nombre, number edad) {
            this.name = nombre;
            this.age = edad;
        }

        func saludar() {
            print("Hola, que tal? Mi nombre es " + this.name);
        }

        string func getName() {
            return this.name;
        }
    }

    private {
        number func getAge() {
            return this.age;
        }

        func setAge() {
            this.age += 1; // soportar esto
        }
    }
}

export number func calcularBitcoing() {
    return 94909.42;
}

Persona persona = new Persona("Joe", 20);