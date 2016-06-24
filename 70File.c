#include<stdio.h>
#include<string.h>
#include<conio.h>
int broi_redove(FILE *fin);
void func_sredno(FILE *fin);
main()
{
	int m=0,n=0;
	FILE *fin;
	char ch,filename[100],filepointer[10];
	do
	 {
     printf ("\n1. Zadavane na mestopolojenie na faila\n");
     printf ("2. Izvejdane na broq na redovete na programata\n");
     printf ("3. Namirane na otno6enieto simvoli v red kum ob6t broi simvoli\n");
     printf ("4. Quit \n");
     printf ("Make your choise: ");
	 ch=getche();
	 switch(ch)
	 {
	 case '1':	
               n=1; 
		 for(;;)
		 {
			 printf("\n\n\nEnter input file location and name: ");
     		 scanf("%s",&filename);
			 printf("Vuvedete raz6irenieto na faila: ");
			 scanf("%s",&filepointer);
			 printf("\n\n\n");
			 if(strcmp(filepointer,".c"))
			 {
				 printf("Raz6irenieto na faila ne e \".c\"");
			 }
			 else
			 {
				 strcat(filename,".c");
				 fin=fopen(filename,"r");
				 if(fin==NULL)
				 {
					 printf("\nFILE EORROR\n");
					 break;
				 }
				 else
				 {
					 m=1;
				 }
				 break;
			 }
		 }
		 break;
	 case '2':
               if(n)
              {
		 printf("\n\n\nBroq na redovete e %d.\n\n\n",broi_redove(fin));
		 break;
              }
              else
              {
               printf("Zapo4nete ot opciq 1!!!");
               }
	 case '3':
               if(n)
              {
		 func_sredno(fin);
		 break;
              }
              else
              {
               printf("Zapo4nete ot opciq 1!!!");
               }
	 case '4':
		 break;
	 }
	if ((ch!='1')&&(ch!='2')&&(ch!='3')&&(ch!='4'))   
	{
			printf("\n\nWrong option.Try again!\n\n");
	}
	}while(ch!='4');
    if(m==1)
    {
       fclose(fin);
    }
}
int broi_redove(FILE *fin)
{
	int broiredove=0;
	char ch;
	rewind(fin);
	while((ch=fgetc(fin))!=EOF)
	{
		if(ch=='\n')
		{
			broiredove++;
		}
	}
	broiredove++;
	return broiredove;
}
void func_sredno(FILE *fin)
{
	char ch;
	int i,broiredove,broi_simvoli2=0,broi_simvoli=0;
	broiredove=broi_redove(fin);
	rewind(fin);
	while((ch=fgetc(fin))!=EOF)
		{
			broi_simvoli2++;
		}
	broi_simvoli2++;
	rewind(fin);
    printf("\n\n\n");
	for(i=0;i<broiredove;i++)
	{
		while((ch=fgetc(fin))!=EOF)
		{
			broi_simvoli++;
			if(ch=='\n')
			{
				break;
			}
		}
		if(ch==EOF)
			{
				broi_simvoli++;
			}
		printf("\nRed nomer %d ima %d simvola(EOF i \\n sa vklu4eni)\nOtno6enieto na broq na simvolite na reda kum broq na simvolite v cqlata programa e %d/%d\n\n",i+1,broi_simvoli,broi_simvoli,broi_simvoli2);	
	    broi_simvoli=0;
	}
}