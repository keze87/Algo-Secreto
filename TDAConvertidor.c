#include "TDAConvertidor.h"
#include "TDAJSON.h"
#include "TDAXML.h"

#define OK 0

int xml2json(TDAConvertidor *tc, char *rutaXml, char *rutaJson)
{

	int error;
	int cont;

	/*Esto vuela*/
	TElem Elem;
	/*Esto vuela*/

	/*Malloc*/
	tc = malloc(sizeof(TDAConvertidor));

	if ((tc->xml.tagPrincipal = malloc(255)) == NULL)
		return -1;

	if ((tc->xml.xmlFile = fopen(rutaXml, "r")) == NULL)
	{
		fprintf(stderr,"La ruta %s no es valida\n", rutaXml);
		return -2;
	}

	L_Crear(&(tc->xml.atributos),sizeof(TElem));
	/*Malloc*/

	error = xmlCargar(&tc->xml, rutaXml);

	if (error != OK)
	{
		fprintf(stderr,"%d\n",error);
		return error;
	}

	if (L_Vacia(tc->xml.atributos) == FALSE)
	{

		/*error = jsonGuardar(&tc->json, rutaJson);*/


		/*Esto tambien vuela*/
		printf("Esto tengo en la lista:\n\n");

		error = L_Mover_Cte(&tc->xml.atributos,L_Primero);

		while (error == TRUE)
		{

			cont = 0;

			while (cont != 51)
			{
				Elem.id[cont] = 0;
				cont++;
			}

			L_Elem_Cte(tc->xml.atributos,&Elem);

			if (Elem.estado == Valor)
				printf("Valor = %s\n", Elem.id);
			if (Elem.estado == Abierto)
				printf("EL Delim ES: %s (Abierto)\n", Elem.id);
			if (Elem.estado == Cerrado)
				printf("EL Delim ES: %s (Cerrado)\n", Elem.id);

			error = L_Mover_Cte(&tc->xml.atributos,L_Siguiente);

		}
		/*Esto tambien vuela*/


		error = xmlGuardar(&tc->xml, rutaJson);

		if (error != OK)
		{
			fprintf(stderr,"%d\n",error);
			return error;
		}

	}

	L_Vaciar(&tc->xml.atributos);
	free(tc->xml.tagPrincipal);
	free(tc);

	return error;

}

int json2xml(TDAConvertidor *tc, char *rutaJson, char *rutaXml)
{

	int error;
	int cont;

	/*Esto vuela*/
	TElem Elem;
	/*Esto vuela*/

	/*Malloc*/
	tc = malloc(sizeof(TDAConvertidor));

	if ((tc->json.tagPrincipal = malloc(255)) == NULL)
		return -1;

	if ((tc->json.jsonFile = fopen(rutaJson, "r")) == NULL)
	{
		fprintf(stderr,"La ruta %s no es valida\n", rutaJson);
		return -2;
	}

	L_Crear(&(tc->json.atributos),sizeof(TElem));
	/*Malloc*/

	error = jsonCargar(&tc->json, rutaJson);

	if (error != OK)
	{
		fprintf(stderr,"%d\n",error);
		return error;
	}

	if (L_Vacia(tc->json.atributos) == FALSE)
	{

		/*error = jsonGuardar(&tc->json, rutaJson);*/


		/*Esto tambien vuela*/
		printf("\n\nEsto tengo en la lista:\n\n");

		error = L_Mover_Cte(&tc->json.atributos,L_Primero);

		while (error == TRUE)
		{

			cont = 0;

			while (cont != 51)
			{
				Elem.id[0] = 0;
				cont++;
			}

			L_Elem_Cte(tc->json.atributos,&Elem);

			if (Elem.estado == Valor)
				printf("Valor = %s\n", Elem.id);
			if (Elem.estado == Abierto)
				printf("EL Delim ES: %s (Abierto)\n", Elem.id);
			if (Elem.estado == Cerrado)
				printf("EL Delim ES: %s (Cerrado)\n", Elem.id);

			error = L_Mover_Cte(&tc->json.atributos,L_Siguiente);

		}
		/*Esto tambien vuela*/


		error = jsonGuardar(&tc->json, rutaXml);

		if (error != OK)
		{
			fprintf(stderr,"%d\n",error);
			return error;
		}

	}

	L_Vaciar(&tc->json.atributos);
	free(tc->json.tagPrincipal);
	free(tc);

	return error;

}

int CrearTC(TDAConvertidor *tc)
{
	/*tc = (TDAConvertidor*)malloc(sizeof(TDAConvertidor));
	if (tc == NULL)
		return -1;*/

	printf("\n"); /*No deberia ser así*/
	return 0;
}

void DestruirTC(TDAConvertidor *tc)
{
	/*L_Vaciar(&tc->xml.atributos);
	free(tc->xml.tagPrincipal);
	free(tc);*/

	printf("\n"); /*No deberia ser así*/
}
