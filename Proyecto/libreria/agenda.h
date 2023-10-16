#ifndef AGENDA_H
#define AGENDA_H

#include "contacto.h"
#define MaxDefault 5

const sContacto ContactoNulo = { "", "", "", "", "", {0, 0, 0}, eGrupo::NINGUNO };

// enum Agenda { ErrAgenda = -4 };
enum agrContacto  { ErrAgrEspacio = -1,  ExitoAgregar = 1 };
enum updContacto  { ErrUpdContacto = -2, ErrUpdIndex = -1,  ExitoModificar = 1 };
enum rmContacto   { ErrRmGrup = -4, ErrRmNomApe = -3,    ErrRmIndex = -2,   ErrRmContacto = -1, ExitoRemover = 1 }; //ErrRmGrup agregado
enum srchContacto { ErrSrchValor = -2,   ErrSrchIndex = -1, ExitoBuscar = 1 };
enum printContacto { ErrPrintContactos = -1, ExitoPrint = 1}; //mio

typedef enum agrContacto  eAgrContacto;
typedef enum updContacto  eUpdContacto;
typedef enum rmContacto   eRmContacto;
typedef enum srchContacto eSrchContacto;
typedef enum printContacto ePrintContacto; //mio

struct Agenda {
    sContacto* misContactos;
    u_int CantMaxima;
    u_int CantContactos;
}; typedef struct Agenda sAgenda;

/* Otras funciones */
bool hayEspacio(sAgenda* miAgenda);

/* Funcion de agregar contacto */
eAgrContacto agregarContacto(sAgenda* miAgenda, sContacto miContacto);
eAgrContacto agregarContactoOrdenado(sAgenda* miAgenda, sContacto miContacto); //mio

/* Funciones de actualización del contacto */
eUpdContacto actualizarContacto(sAgenda* miAgenda, sContacto miContacto);
eUpdContacto actualizarContacto(sAgenda* miAgenda, u_int indexContacto, sContacto miContacto);

/* Funciones de eliminación del contacto */
eRmContacto removerContacto(sAgenda* miAgenda, str Nombre, str Apellido);
eRmContacto removerContacto(sAgenda* miAgenda, sContacto miContacto);
eRmContacto removerContacto(sAgenda* miAgenda, u_int indexContacto);
eRmContacto removerContacto(sAgenda* miAgenda, eGrupo Grupo); //mio

/* Funciones de busqueda de contacto */
sContacto buscarContacto(sAgenda* miAgenda, str valorBusqueda);
sContacto buscarContacto(sAgenda* miAgenda, u_int indexContacto);

/* Funciones que imprimen por grupo (mio) */
ePrintContacto imprimirContacto(sAgenda* miAgenda, eGrupo Grupo);
ePrintContacto imprimirContacto(sAgenda* miAgenda);

#endif // AGENDA_H
