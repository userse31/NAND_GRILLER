#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIGNATURE_TEXT "I have abandoned all hope.\n"

char *magic_cmd;
char *signature_buffer;
char signature_check[]=SIGNATURE_TEXT;

int abandon_hope(){
	printf("c");
	printf("ABANDON ALL HOPE YE WHO ENTER HERE!\nBy continuing you accept that you ***WILL LOSE ALL DATA ON THE DRIVE YOU ARE TESTING** and that ***THERE IS A REALLY GOOD CHANCE YOUR STORAGE DEVICE WILL BE DEAD AFTER THIS***.\n");
	printf("To continue, type \"I have abandoned all hope.\"\n");
	signature_buffer=malloc(sizeof(char)*64);
	fgets(signature_buffer,64,stdin);	
	if(!strcmp(signature_buffer,signature_check)){
		printf("pass\n");
	}else{
		printf("Exiting...\n");
		exit(0);
	}
}

int main(int argc, char *argv[]){
	printf("Qwerty's NAND Griller.\n***WARNING!*** This program is ***INTENTIONALLY DESTRUCTIVE!***\nThis intentionally writes large amounts of data to intentinally cause faulty NAND flash to ***FAIL!***\nONLY USE THIS PROGRAM ON STORAGE YOU BOTH DON'T CARE ABOUT AND DON'T HAVE SENSITIVE DATA ON!\nThis program is intended to test nand flash stright out of the packaging, not already used storage.\n\n");
	if(argc!=4){
		printf("Usage: ./nand_griller <block device> <loop count> <device size (in 512 byte blocks)>\n");
		exit(0);
	}
	abandon_hope();
	magic_cmd=malloc(sizeof(char)*256);
	snprintf(magic_cmd,sizeof(char)*256,"dd if=/dev/urandom of=%s bs=512 count=%s status=progress",argv[1],argv[3]);
	//printf("%s\n",magic_cmd);
	int ret_val;
	if(atoi(argv[2])<=0){
		printf("%s is not a natural number.\n",argv[2]);
		exit(0);
	}
	for(int i=0;i<atoi(argv[2]);i++){
		printf("Written to drive %i times.\n",i);
		ret_val=system(magic_cmd);
		if(ret_val!=0){
			printf("BREAK\n");
			exit(0);
		}
		//printf("Returned: %i",ret_val);
	}
}
