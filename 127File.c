#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dirent.h>
int broi_redove(FILE *fin);
int broi_redovete(FILE *fin);
void func_sredno(FILE *fin);
int coment(FILE *fin);
main()
{
	int m=0;
	FILE *fin;
	char ch,filename[100],dirr[1000];
	DIR *dir;
	struct dirent *ent;
	dirr[1]=0;
	do
	 {
     printf ("\n1. Zadavane na direktoriq i izbor na fail\n");
     printf ("2. Izvejdane na broq na praznite redove v faila\n");
     printf ("3. Namirane na otno6enieto zapetai v red kum ob6tiqt im broi\n");
	 printf ("4. Namirane na boq na komentarite ot tipa //\n");
     printf ("5. Quit \n");
     printf ("Make your choise: ");
	 ch=getche();
	 switch(ch)
	 {
	 case '1':
		 printf("\nVuvedete direktoriq: ");
         scanf("%s",&dirr);
		 strcat(dirr,"\\");
         dir=opendir(dirr);
         if (dir!=NULL) 
         {
			 while((ent=readdir(dir))!=NULL) 
			 {
				 printf ("%s\n",ent->d_name);
			 }
			 closedir(dir);
		 }
		 else 
		 {
			 printf("Error");
			 return 0;
		 }
		 for(;;)
		 {
			 printf("\n\n\nVuvedete imeto na faila: ");
     		 scanf("%s",&filename);
			 strcat(dirr,filename);
			 fin=fopen(dirr,"r");
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
		 break;
	 case '2':
		 if(!(dirr[1]))
		 {
			 printf("\n\n\nPurvo vavedete direktoriq sled tova izberete fail!\n\n\n");
			 break;
		 }
		 printf("\n\n\nBroq na praznite redove e %d.\n\n\n",broi_redove(fin));
		 break;
	 case '3':
		 if(!(dirr[1]))
		 {
			 printf("\n\n\nPurvo vavedete direktoriq sled tova izberete fail!\n\n\n");
			 break;
		 }
		 func_sredno(fin);
		 break;
	 case '4':
		 if(!(dirr[1]))
		 {
			 printf("\n\n\nPurvo vavedete direktoriq sled tova izberete fail!\n\n\n");
			 break;
		 }
		 printf("\n\n\nBroq na komentarite ot tipa // e raven na %d.\n\n\n",coment(fin));
		 break;
	 }
	if ((ch!='1')&&(ch!='2')&&(ch!='3')&&(ch!='4')&&(ch!='5'))   
	{
			printf("\n\nWrong option.Try again!\n\n");
	}
	}while(ch!='5');
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
			while((ch=fgetc(fin))=='\n')
			{
				broiredove++;
			}
		}
	}
	return broiredove;
}
void func_sredno(FILE *fin)
{
	char ch;
	int i,broiredove,broi_simvoli=0,broi_simvoli3=0;

	broiredove=broi_redovete(fin);
	rewind(fin);
	while((ch=fgetc(fin))!=EOF)
		{
			if(ch==',')
			{
				broi_simvoli++;
			}
		}
	rewind(fin);
    printf("\n\n\n");
	for(i=0;i<broiredove;i++)
	{
		while((ch=fgetc(fin))!='\n')
		{
			if(ch==',')
			{
				broi_simvoli3++;
			}
			if(ch==EOF)
			{
				break;
			}
		}
		printf("\nRed nomer %d ima %d zapetaiki\nOtno6enieto na broq na zapetaite kum ob6tiq im broi e %d/%d\n\n",i+1,broi_simvoli3,broi_simvoli3,broi_simvoli);	
		broi_simvoli3=0;
	}
}
int broi_redovete(FILE *fin)
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
int coment(FILE *fin)
{
	int comen=0,c1=0,c2=0;
	char ch;
	rewind(fin);
	while((ch=fgetc(fin))!=EOF)
	{
		if(ch=='\"')
		{
			for(;;)
			{
				ch=fgetc(fin);
				if(ch=='\\')
				{
						ch=fgetc(fin);
						if(ch=='\"') continue;
				}
				if(ch=='\"') break;
				if(ch=='\n') break;
			}
		}
		if((c1==1)&&(ch=='*'))
		{
			for(;;)
			{
				ch=fgetc(fin);
				if(ch=='*')
				{
					ch=fgetc(fin);
					if(ch=='/')
					{
						break;
					}
				}
				if(ch==EOF)
				{
					break;
				}
			}
			c1=0;
			c2=0;
			continue;
		}
		else
		{
			c1=0;
		}
		if((c2==1)&&(ch=='/'))
		{
			comen++;
			c2=0;
			do{
				ch=fgetc(fin);
				if(ch==EOF) break;
			}while(ch!='\n');
			continue;
		}
		else
		{
			c2=0;
		}
		if(ch=='/')
		{
			c2=1;
			c1=1;
		}
	}
	return comen;
}