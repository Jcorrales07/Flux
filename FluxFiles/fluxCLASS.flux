class Persona {
    string name;
    number age;

    Persona(nombre, edad) {
        this.name;
        this.age;
    }

    void func saludar() {
        print("Hola, que tal? Mi nombre es " + this.name);
    }

    string func getName() {
        return this.name;
    }

    number func getAge() {
        return this.age;
    }

    void func setAge() {
        this.age += 1;
    }
}


class Empleado extends Persona {
    number salary;
    string jobPosition;

    Empleado(name, age, salary, jobPosition) {
        super(name, age);
        this.salary = salary;
        this.jobPosition = jobPosition;
    }

    number func getSalary() {
        return this.salary;
    }

    void func setSalary(newSalary) {
        this.salary = newSalary;
    }
}