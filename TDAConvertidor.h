#ifndef __TDAConvertidor_H__
#define __TDAConvertidor_H__

#include "TDAXML.h"
#include "TDAJSON.h"

typedef enum TInterruptor{
	Abierto = 0,
	Cerrado = 1
}TInterruptor;

typedef struct TDAConvertidor{
	TDAXML xml;
	TDAJSON json;
}TDAConvertidor;

typedef struct TDelimitador{
	char *id;
	TInterruptor estado;
}TDelimitador;

typedef struct TElem{
	char *id;
	char *value;
}TElem;

/* PRE: No tiene.
POST: Convierte xml a json según las rutas especificadas.
En caso de error devuelve el mensaje correspondiente. */
int xml2json(TDAConvertidor *tc, char *rutaXml, char *rutaJson);

/* PRE: No tiene.
POST: Convierte json a xml según las rutas especificadas.
En caso de error devuelve el mensaje correspondiente. */
int json2xml(TDAConvertidor *tc, char *rutaJson, char *rutaXml);

/* PRE:  No tiene
 * POST: Asigna memoria a la estructura
 *       En caso de error devuelve -1
 */
int CrearTC(TDAConvertidor *tc);

/* PRE:  tc creado
 * POST: Libera la memoria asignada a la estructura
 */
void DestruirTC(TDAConvertidor *tc);

#endif /* __TDAConvertidor_H__ */


