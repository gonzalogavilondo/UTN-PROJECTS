#include "registroArchivo.h"


/// El usuario ingresa la cantidad de datos que quiera
void ingresarRegistros(){
    char opcion;
    stRegistroArchivo r;

    do{
        system("pause");
        r = ingresarUnRegistro();
        agregarRegistro(r);
        printf("\n\t\t ESC para salir ...  ");
        opcion = getch();
    }
    while(opcion!=27);
}

/// Se pide un dato al usuario y se retorna
stRegistroArchivo ingresarUnRegistro(){
    stRegistroArchivo r;

    printf("\n Animal.......................: ");
    gets(r.animal);
    fflush(stdin);
    printf("\n Cantidad.....................: ");
    scanf("%d",&r.cant);
    printf("\n ID Especie...................: ");
    scanf("%d",&r.idEspecie);
    printf("\n Especie......................: ");
    gets(r.especie);
    fflush(stdin);
    printf("\n Habitat......................: ");
    scanf("%d",&r.habitat);

    return r;
}

/// se guarda un dato en el archivo
void agregarRegistro(stRegistroArchivo r){
    FILE* pArchRegistro = fopen(arRegistro,"ab");
    if(pArchRegistro){
        fwrite(&r,sizeof(stRegistroArchivo),1,pArchRegistro);
        fclose(pArchRegistro);
    }
}

/// Se muestra un dato de tipo stRegistroArchivo
void mostrarUnRegistro(stRegistroArchivo r){
    char habitat[10];
    getHabitatChar(r.habitat,habitat);
    printf("\n Animal.....................: %s",r.animal);
    printf("\n Cantidad...................: %d",r.cant);
    printf("\n ID Especie.................: %d",r.idEspecie);
    printf("\n Especie....................: %s",r.especie);
    printf("\n Habitat....................: %d - %s\n",r.habitat,habitat);
    replicante('-',50);
}

/// Se recorre el archivo y usando la funcion mostrarUnRegistro() se muestran los datos del archivo
void mostrarRegistros(char archivo[]){
    stRegistroArchivo r;
    FILE* pArchRegistro = fopen(archivo,"rb");
    if(pArchRegistro){
        while(fread(&r,sizeof(stRegistroArchivo),1,pArchRegistro)>0){
            mostrarUnRegistro(r);
        }
        fclose(pArchRegistro);
    }
}

/// funcion que asigna en la variable recibida un nombre al azar
int getEspecie(char e[]){
    char especies[][10] = {"Mamifero","Ave","Reptil","Pez"};
    int idEspecie = randomRango(0,sizeof(especies)/(sizeof(char)*10));
    strcpy(e,especies[idEspecie]);
    return idEspecie;
}

/// funcion que asigna en la variable recibida un apellido al azar
void getAnimal(char a[], int idEspecie){
    char mamiferos[][20] = {"Canguro", "Mono", "Antilope", "Vaca", "Caballo", "Cerdo", "Oveja", "Cabra", "Leon", "Jirafa",
                            "Tapir", "Cebra", "Burro", "Gato", "Perro", "Mangosta", "Leopardo", "Guepardo", "Jirafa", "Okapi",
                            "Camello", "Llama", "Pacari", "Hipopotamo", "Elefante", "Zorro", "Panda", "Oso", "Conejo", "Liebre" };

    char aves[][20] = {"Cisne", "Pato", "Suiriri", "Anade", "Gorrion", "Aguila", "Condor", "Paloma", "Gaviota", "Ganzo"};

    char reptiles[][20] = {"Cobra", "Caiman", "Iguana", "Dragon", "Camaleon", "Vibora", "Tortuga", "Cocodrilo", "Gecko", "Culebra"};

    char peces[][20] = {"Tiburon", "Raya", "Arenque", "Carpa", "Anchoa", "Barracuda", "Salmon", "Anguila", "Morena", "Corvina"};

    switch(idEspecie){
        case 0:
            strcpy(a,mamiferos[randomRango(0,sizeof(mamiferos)/(sizeof(char)*20))]);
            break;
        case 1:
            strcpy(a,aves[randomRango(0,sizeof(aves)/(sizeof(char)*20))]);
            break;
        case 2:
            strcpy(a,reptiles[randomRango(0,sizeof(reptiles)/(sizeof(char)*20))]);
            break;
        case 3:
            strcpy(a,peces[randomRango(0,sizeof(peces)/(sizeof(char)*20))]);
            break;
        default:
            strcpy(a,"Error");
    }
}

/// Funcion que retorna un numero de habitat de 0 a 3 al azar
int getHabitat(int idEspecie){
    return ((idEspecie)>=0&&(idEspecie<=2))?randomRango(0,3):3;
}


/// Funcion que retorna cantidad de animales
int getCantidad(){
    return randomRango(0,8000);
}

/// funcion que asigna en la variable recibida el tipo correspondiente de habitat
void getHabitatChar(int n, char h[]){
    switch(n){
        case 0:
            strcpy(h,"Selva");
            break;
        case 1:
            strcpy(h,"Savana");
            break;
        case 2:
            strcpy(h,"Bosque");
            break;
        case 3:
            strcpy(h,"Mar");
            break;
        default:
            strcpy(h,"Error");
    }
}

/// Funcion que genera un registro al azar y lo retorna
stRegistroArchivo cargoRegistroArchivoRandom(){
    stRegistroArchivo r;
    r.idEspecie=getEspecie(r.especie);
    getAnimal(r.animal,r.idEspecie);
    r.habitat=getHabitat(r.idEspecie);
    r.cant=getCantidad();
    return r;
}

/// funcion que guarda un dato de tipo stRegistroArchivo en el archivo especificado
void guardaRegistroArchivo(char archivo[], stRegistroArchivo r){
    FILE * pArch = fopen(archivo,"ab");
    if(pArch){
        fwrite(&r,sizeof(stRegistroArchivo),1,pArch);
        fclose(pArch);
    }
}

/// Funcion que llama a las funciones anteriores y genera y guarda en el archivo la cantidad de registros deseados
void generaArchivoRandom(int cantidad){
    stRegistroArchivo r;
    int i=0;
    printf("Generando archivo.");
    while(i<cantidad){
        (i % 400 == 0) ? printf("."):0;
        r = cargoRegistroArchivoRandom();
        guardaRegistroArchivo(arRegistro,r);
        i++;
    }
}

/// Funcion que cuenta la cantidad de registros en cualquier archivo, recibe el nombre de archivo y el sizeof del tipo de dato usado
int cuentaRegistros(char nombreArchivo[], int tamStruct){
    FILE* pArchi = fopen(nombreArchivo,"rb");
    int cantReg=0;
    if(pArchi){
        fseek(pArchi,0,SEEK_END);
        cantReg = ftell(pArchi)/tamStruct;
        fclose(pArchi);
    }
    return cantReg;
}
