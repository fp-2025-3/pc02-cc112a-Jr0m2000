#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>

using namespace std;

struct item
{
    char* descripcion;
    int cantidad;
    double precioUnitario;

};

struct Pedido
{
    int numeroPedido;
    char* nombreCliente;
    item* items;
    int cantidadItems;
};

item crearItem(const char* descripcion,int cantidad,double precio);
Pedido* crearPedido(int numero, const char* cliente, int cantidadItems);
double calcularTotal(const Pedido* p);
item* itemMasCaro(Pedido* p);
void liberarPedido(Pedido* p);


int main()
{
    srand(time(NULL));
    Pedido* p = crearPedido(101, "Carlos Perez", 5);
    cout << "Pedido N: " << p->numeroPedido << endl;
    cout << "Cliente : " << p->nombreCliente << endl;
    cout << "Items:" << endl;
    for(int i = 0; i < p->cantidadItems; i++){
        cout << "- " << p->items[i].descripcion<< " | cant : " << p->items[i].cantidad<< " | Precio: " << p->items[i].precioUnitario<< endl;
    }
    double total = calcularTotal(p);
    cout << "Total: " << total << endl;
    item* caro = itemMasCaro(p);
    if(caro != nullptr){
        cout << "Item mas caro: "<< caro->descripcion<< " | Precio: "<< caro->precioUnitario<< endl;
    }
    liberarPedido(p);

    return 0;
}


item crearItem(const char* descripcion,int cantidad,double precio){
    item nuevo;
    nuevo.descripcion=new char[strlen(descripcion)+1];
    strcpy(nuevo.descripcion,descripcion);
    nuevo.cantidad=cantidad;
    nuevo.precioUnitario=precio;
    return nuevo;
}


Pedido* crearPedido(int numero, const char* cliente, int cantidadItems){
    Pedido* nuevo = new Pedido;
    nuevo->numeroPedido=numero;
    nuevo->nombreCliente=new char[strlen(cliente)+1];
    strcpy(nuevo->nombreCliente,cliente);
    nuevo->cantidadItems=cantidadItems;
    nuevo->items=new item[cantidadItems];
    const char* descripciones[] = {
    "Laptop",
    "Mouse",
    "Teclado",
    "Monitor",
    "Impresora",
    "Escaner",
    "Auriculares",
    "Microfono",
    "Webcam",
    "Parlantes",
    "Tablet",
    "Telefono",
    "DiscoDuro",
    "MemoriaUSB",
    "Router",
    "PS5",
    "TarjetaGrafica",
    "Procesador",
    "PlacaBase",
    "FuentePoder"
    };
    for (int i = 0; i < cantidadItems; i++)
    {
        nuevo->items[i]=crearItem(descripciones[rand()%20],1 + rand() % 10,50+rand()%550);
    }
    
    return nuevo;
}
double calcularTotal(const Pedido* p){
    if(p == nullptr) return 0.0;

    double total = 0.0;

    for(int i = 0; i < p->cantidadItems; i++){
        total += p->items[i].cantidad * p->items[i].precioUnitario;
    }

    return total;
}
item* itemMasCaro(Pedido* p){
    if(p == nullptr || p->cantidadItems == 0)
        return nullptr;

    int indiceMayor = 0;

    for(int i = 1; i < p->cantidadItems; i++){
        if(p->items[i].precioUnitario > p->items[indiceMayor].precioUnitario){
            indiceMayor = i;
        }
    }

    return &(p->items[indiceMayor]);
}
void liberarPedido(Pedido* p){

    for(int i = 0; i < p->cantidadItems; i++){
        delete[] p->items[i].descripcion;
    }
    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}
