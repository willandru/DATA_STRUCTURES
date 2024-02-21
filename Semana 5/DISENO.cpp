//_____________________________________________________________________________________________________
//DISEÑO: ASIGNAR TURNO

// pasos a seguir:

//-Se recibe un usuario con id, priodidad y tema.
//-Se utiliza el tema para buscar la cola correspondiente a ese tema en el vector de colas
//-Si el usuario tiene prioridad, se asigna el turno 1 y la cola se reordena.
//-De lo contrario, el usuario se le asigna el ultimo turno de la cola.
//-Se retorna el turno asignado al usuario para el tema especificado.


//IMPLEMENTACION: ASIGNAR TURNO

string CAU::asignarTurno(int id, bool prioridad, string tema){
    
std::vector<std::queue<Usuario> > vecColas = obtenerColasAtencion();


int numCola;
switch(tema){
    case "ventas":
        numCola=0;
        break;
    case "servicio tecnico":
        numCola=1;
        break;
    case "reclamos":
        numCola=2;
        break;
}

std::queue cola = vecColas[numCola];

if (prioridad){
std::queue<Usuario> newCola;
newCola.push()

}else{

}


}

//____________________________________________________________________________________________________

//DISEÑO: ATENDER UN USUARIO

// pasos a seguir:

//-Se busca la cola más larga, si hay mas de una, se escoge cualquiera.
//-Se busca un asesor libre que pueda atender el tema de la cola anterior.
//-Si no encuentra un asesor disponible, continua con la siguiente cola mas larga.
//-Retira al usuario de la cola de turnos 
//-Registra el turno del usuario




//IMPLEMENTACION: ATENDER UN USUARIO

bool CAU::AtenderUsuario(){

std::vector<std::queue> vecColas = obtenerColasAtencion();

int tam=0;
int indiceMayor;
for (int i =0; i< vecColas.size(); i++){
    if(vecColas[i].size() > tam){
        tam=vecColas[i].size();
        indiceMayor=i;
    }
}

std::queue longestCola = vecColas[indiceMayor];

}

//____________________________________________________________________________________________________

//DISEÑO: CONTEO DE USUARIOS ATENDIDOS

// pasos a seguir:
//-Obtener la lista de asesores
//-Revisa el numero de usuarios atendidos en cada asesor
//-Genera el total de usuarios atendidos.




//IMPLEMENTACION: CONTEO DE USUARIOS ATENDIDOS

int CAU::conteoAtendidos(){

}
