
enum generos {DRAMA, COMEDIA, FICCION, SUSPENSO,
              TERROR, ROMANTICA, HISTORICA = 6};

const std::string POEMA = "P";  // Surgio un error de doble inicializacion tras crear el switch de agregar lectura en el menu
const std::string NOVELA = "N";
const std::string CUENTO = "C";

enum tipo_lectura {POEMA, CUENTO, NOVELA, NOVELA_HISTORICA};        // ESTO ORIGINÓ EL PROBLEMA!!

const int DESCONOCIDO = -1;

const string ARCHIVO_LECTURAS = "Lecturas.txt";
const string ARCHIVO_ESCRITORES = "Autores.txt";

string OPCIONES [] = {"Agregar una nueva lectura",
                    "Quitar lectura","Agregar un escritor",
                    "Actualizar fallecimiento autor",
                    "Listar los escritores",
                    "Sortear una lectura",
                    "Listar lecturas",
                    "Listar lecturas por anio",
                    "Listar lecturas por escritor",
                    "Listar Novelas por genero",
                    "Listar proximas lecturas",
                    "Salir"};

const int LECTURAS_DESDE = 0;
const int LECTURAS_HASTA = 1;
