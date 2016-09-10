/*
 * FREAD.c
 *
 *  Created on: 8/9/2016
 *      Author: utnso
 */

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "/home/utnso/workspace2/LecturaFS/osada.h"
    #include "BitArray.h"

	int main()
	{
		FILE *ptr_myfile;


		osada_header HEADER;

		ptr_myfile=fopen("/home/utnso/Escritorio/FS/FS.jpg","rb");
		if (!ptr_myfile)
		{
			printf("No puedo abrir el archivo!");
			return 1;
		}
		// Leo el archivo y guardo en la estructura HEADER el PRIMER BLOQUE

		fread(&HEADER,sizeof(osada_header),1,ptr_myfile);

		//HEADER.magic_number[7]='\n';

		printf("Identificador: %s",HEADER.magic_number);
		printf("Version: %d \n",HEADER.version);
		printf("Total de Bloques: %d \n",HEADER.fs_blocks);
		printf("Total Bloques BITMAP: %d \n",HEADER.bitmap_blocks);
		printf("Posicion del Primer bloque de ASIG: %d \n",HEADER.allocations_table_offset);
		printf("Total Bloques: %d \n",HEADER.data_blocks);

		fseek(ptr_myfile, HEADER.allocations_table_offset, SEEK_SET);

		char* buffer; // note: 1 byte

		buffer=malloc(64*108);
		fread(buffer,64,108, ptr_myfile);
		printf("BUFFER: %s \n",buffer);






		fclose(ptr_myfile);
		free(buffer);
		return 0;
	}




