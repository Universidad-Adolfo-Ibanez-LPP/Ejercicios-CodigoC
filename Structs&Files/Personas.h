//
// Created by Justo Vargas on 15-03-22.
//
struct Personas {
    int  id;
    char  *name;
    char  *surname;
    char  *email;
    char   *gender;
    int borrar;
} ;

// aca defino que el conjunto "struct Personas"
// será un nuevo tipo de datos conocido ahora
// conocido como Persona
typedef struct Personas Persona;

//habiendo creado el tipo de dato,
// defino un puntero a una coleccion de personas;
Persona *personas;

//uso la palabra clave extern para poder acceder
//desde afuera
extern int registryCount;

//operaciones con archivos
Persona* getPersonas(FILE *fp);
void writePersonas(Persona *personas, FILE *fp);

//otras operaciones
//contratos
void mostrarPersonas();
void buscarPersona();
void eliminarPersona();
void agregarPersona();
