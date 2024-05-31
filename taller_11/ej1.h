#ifndef PALABRAADT_H_INCLUDED
#define PALABRAADT_H_INCLUDED

/* crear un ADT que maneje palabras (palabra ADT) 
Funcionalidades:
crear instancia: crear
liberar recursos: destruir
mostrar instancia: mostrar
agregar letras: agregarLetra
concatenar
pasar a mayúsculas
pasar a minúsculas */

typedef struct palabraCDT *palabraADT;

palabraADT crearVacia();
palabraADT crearDesde(char *palabra);
void destruirPalabra(palabraADT pal);
void mostrarPalabra(palabraADT pal);
palabraADT agregarLetra(palabraADT pal, char letra);
palabraADT concatenar(palabraADT pal1, palabraADT pal2);
palabraADT pasarAMayusculas(palabraADT pal);
palabraADT pasarAMinusculas(palabraADT pal);

#endif