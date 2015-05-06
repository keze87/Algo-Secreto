#ifndef __TDAConvertidor_H__
#define __TDAConvertidor_H__

#include "TDAXML.h"
#include "TDAJSON.h"

typedef enum TInterruptor{
	Abierto = 0,
	Cerrado = 1,
	Valor = 2
}TInterruptor;

typedef struct TDAConvertidor{
	TDAXML xml;
	TDAJSON json;
}TDAConvertidor;

typedef struct TElem{
	char *id;
	TInterruptor estado;
}TElem;


/* @param  rutaXml   ruta dónde se encuentra el archivo XML
 * @param  rutaJson  ruta dónde se grabará el archivo JSON
 * @pre    -
 * @post   Si se puede realizar la conversión y guardar el nuevo archivo en la ruta especificada, devuelve 0
 * @post   Si no existe suficiente memoria, devuelve -1
 * @post   Si no se puede acceder a rutaXml para lectura, devuelve -2
 * @post   Si no se puede acceder a rutaJson para escritura, devuelve -3
 * @post   Si existe un error de sintaxis en el archivo XML, devuelve el número de línea
 */
int xml2json(TDAConvertidor *tc, char *rutaXml, char *rutaJson);

/* @param  rutaJson  ruta dónde se se encuentra el archivo JSON
 * @param  rutaXml   ruta dónde se grabará el archivo XML
 * @pre    -
 * @post   Si se puede realizar la conversión y guardar el nuevo archivo en la ruta especificada, devuelve 0
 * @post   Si no existe suficiente memoria, devuelve -1
 * @post   Si no se puede acceder a rutaJson para lectura, devuelve -2
 * @post   Si no se puede acceder a rutaXml para escritura, devuelve -3
 * @post   Si existe un error de sintaxis en el archivo JSON, devuelve el número de línea
 */
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


