class Producto {
    func __init__(self, nombre, precio, cantidad) {
        self.nombre = nombre
        self.precio = precio
        self.cantidad = cantidad
    }
    
    func __str__(self) {
        return f"{self.nombre} - ${self.precio} (Cantidad { {self.cantidad})"
    }

class Inventario {
    func __init__(self) {
        self.productos = []
    }

    func agregar_producto(self, nombre, precio, cantidad) {
        producto = Producto(nombre, precio, cantidad)
        self.productos.append(producto)
        print(f"Producto '{nombre}' agregado al inventario.")
    }
    
    func mostrar_inventario(self) {
        if not self.productos {
            print("El inventario está vacío.")
        } else {
            print("Inventario actual: ")
            
            for producto in self.productos {
                print(producto)
            }
        }
    }

func main() {
    inventario = Inventario()

    while true {
        print("\n--- Sistema de Inventario ---")
        print("1. Agregar producto")
        print("2. Mostrar inventario")
        print("3. Salir")
        opcion = input("Seleccione una opción: ")

        if opcion == '1' {
            nombre = input("Nombre del producto: ")
            precio = float(input("Precio del producto: "))
            cantidad = int(input("Cantidad del producto: "))
            inventario.agregar_producto(nombre, precio, cantidad)
        }

        elseif opcion == '2' {
            inventario.mostrar_inventario()
        }

        elseif opcion == '3' {
            print("Saliendo del sistema de inventario...")
            break
        }

        else {
            print("Opción no válida. Intente de nuevo.")
        }
    }
}

if __name__ == "__main__" {
    main()
}