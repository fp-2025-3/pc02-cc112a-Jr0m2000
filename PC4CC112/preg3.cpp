#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

struct Producto
{
    int codigo;
    char* nombre;
    double precio;
    int stock;
};

Producto crearProducto(int codigo,const char* nombre,double precio, int stock);
Producto* crearInventario(int n);
Producto* buscarProducto(Producto* inventario,int n,int codigoBuscado);
void MostrarInventario(Producto* inventario, int n);
//void liberarInventario(Producto* inventario, int n);

int main()
{
    Producto* Inventario=crearInventario(5);
    MostrarInventario(Inventario,5);
    cout<<endl;
    int codigoBuscado=102;
    cout<<"buscando producto con el codigo "<<codigoBuscado<<"..."<<endl;
    Producto* buscado=buscarProducto(Inventario,5,codigoBuscado);
    if (buscado!=nullptr)
    {
        cout<<"Producto encontrado: "<<buscado->nombre<<" | Precio: "<<fixed<<setprecision(2)<<buscado->precio<<endl;
    }else
    {
        cout<<"Producto no encontrado"<<endl;
    }
    for (int i = 0; i < 5; i++)
    {
        delete [] (Inventario+i)->nombre;
    }
    delete[] Inventario;
    delete[]buscado->nombre;
    delete[] buscado;
    //liberarInventario(Inventario,5);
    return 0;
}

Producto crearProducto(int codigo,const char* nombre,double precio, int stock){
    Producto nuevo;
    int n=strlen(nombre);
    nuevo.nombre=new char [n+1];
    strcpy(nuevo.nombre,nombre);
    nuevo.codigo=codigo;
    nuevo.precio=precio;
    nuevo.stock=stock;
    return nuevo;//cada producto lleva un delete [] producto.nombre
}
Producto* crearInventario(int n){
    Producto* Inventario = new Producto[n];
    const char*temp[]={"Teclado","mouse","camara","monitor","audifonos"};
    for (int i = 0; i < n; i++)
    {
        crearProducto(100+i,temp[i],10.5*(1+i),5*(i+1));
    }
    return Inventario;//un inventario se libera como delete [] inventario
}

Producto* buscarProducto(Producto* inventario,int n,int codigoBuscado){
    for (int i = 0; i < n; i++)
    {
        if (inventario[i].codigo==codigoBuscado)
        {
            return (inventario+i);
        }
        
    }

    return nullptr;
}

void MostrarInventario(Producto* inventario, int n){
    cout<<"INVENTARIO: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Codigo: "<<inventario[i].codigo<<" | Nombre: "<<inventario[i].nombre<<" | Precio: "<<inventario[i].precio<<" | stock: "<<inventario[i].stock<<endl;

    }
    
}

/*void liberarInventario(Producto* inventario, int n){
    for (int i = 0; i < n; i++)
    {
        delete [] inventario[i].nombre;
        inventario[i].nombre=nullptr;
    }


}*/