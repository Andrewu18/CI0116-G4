// Se escoge la variante 2 por que no atendi a clases ese dia por lo cual no tengo una variante asignada y no pude conseguir equipo, la variante 2 me parecio 
// util para practicar algo como queue que sera la estructura que voy a usar

#include <iostream>
#include <string>
#include <queue> 
using namespace std;


//implementacion de la clase para el objectivo Evento
class Evento {
public:
    string id_evento;
    long timestamp;
    int prioridad;
    string mensaje;

    Evento(string id, long ts, int prio, string msg) 
    {
        id_evento = id;
        timestamp = ts;
        prioridad = prio;
        mensaje = msg;
    }
};

//mplementacion de la clase para el objectivo de procesadorEventos
class ProcesadorEventos {
private:
//Uso cola ya que la variante 2 describe un evento de FIFO
    queue<Evento> eventos;

public:
    //Aqui impllementa el constructor que me pide el enunciado, una lista inicial de eventos
    ProcesadorEventos() 
    {

    }

    //Metodo para agregar eventos
    void agregar_evento(Evento e) 
    {
        eventos.push(e);
    }

    
    void procesar_siguiente_evento() 
    {
        if (eventos.empty()) {
            cout << "No hay eventos para procesar." << endl;
            return;
        }

        // Aqui obtiene el primer elemento del queue y lo elimina para asi implementar el FIFO correctamente
        Evento e = eventos.front(); 
        eventos.pop();              

        // Impresion de los mensajes 
        cout << "Evento:" << endl;
        cout << "ID: " << e.id_evento << endl;
        cout << "Timestamp: " << e.timestamp << endl;
        cout << "Prioridad: " << e.prioridad << endl;
        cout << "Mensaje: " << e.mensaje << endl;
        cout << "========================================================================" << endl;
    }

    //Metodo para mostrar el resto de los eventos, osea, para observr la cola
    void mostrar_cola() 
    {
        cout << "Eventos en cola: " << eventos.size() << endl;
    }
};

//Main principal
int main() 
{
    ProcesadorEventos procesador;

    //4 eventos de prueba, los coloca en la cola siguiendo el modelo anterior de FIFO
    procesador.agregar_evento(Evento("evt2-z831iz", 1678886400, 2, "ERROR: Fallo de autenticacion"));
    procesador.agregar_evento(Evento("evt2-z19x9z", 1678887400, 1, "ERRROR: Se ha caido el sistema"));
    procesador.agregar_evento(Evento("evt2-a2323a", 1678888400, 3, "AVISO: Se realizara mantenimiento en los proximos 5 minutos"));
    procesador.agregar_evento(Evento("evt2-a2392a", 1678888400, 4, "AVISO: El sistema se cerrara por inactividad en 5 minutos"));
    procesador.mostrar_cola();

    //Procesa el numero de eventos y si no hay termina, se podria adaptar a hacer estas cosas automaticamente/de mejor manera pero no se realiza por motivos de tiempo 
    //y ya que no esta contemplado en el enunciado
    procesador.procesar_siguiente_evento();
    procesador.procesar_siguiente_evento();
    procesador.procesar_siguiente_evento();
    procesador.procesar_siguiente_evento();
    procesador.procesar_siguiente_evento();

    return 0;
}
