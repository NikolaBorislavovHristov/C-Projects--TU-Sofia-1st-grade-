#include<stdio.h>
#include<conio.h>
void func1();  //ot ve4e vuveden masiv
void fileprint(int str[100],int f);
void func2(int str[100]);  //vuvejdane na nov masiv
main()
{
	char ch;
	int i,a,ff[100];
	do
	 {
     printf ("1. Zadavane na masiv ot klaviatyrata\n");
     printf ("2. Izpolzvane na veche zadaden\n");
     printf ("Q - Quit!\n");
     printf ("Napravete svoq izbor: ");
	 ch=getche();
	 printf ("\n ");
	 switch(ch)
	 {
	 case '1':	 
		 for(i=0;i<100;i++)
		 {
			 printf("Vuvedete stoinost za ff[%d]= ",i+1);
			 scanf("%d",&a);
			 ff[i]=a;
		 }
		 func2(ff);
		 break;

	 case '2':
		 func1();
		 break;
	 }
    if((ch!='1')&&(ch!='2')&&(ch!='q')&&(ch!='Q'))   
	{
			printf("\n\nOpitai pak!!!\n\n");
	}
	}while ((ch!='Q')&&(ch!='q'));

}
void func1()
{
	char ch;
	int broi, b, w, snd, m=0, x, t=0, r, f, s, a, i, neww[100];
	int str[] =  {2, 6, 6, 6, 6, 8, 0, 8, 0, 8, 6, 5, 4, 3, 2, 4, 6, 8, 0, 8, 7, 6, 5, 8, 0, 8, 7, 5, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 2, 6, 6, 6, 6, 8, 0, 8, 0, 8, 6, 5, 4, 3, 2, 4, 6, 8, 0, 8, 7, 6, 5, 8, 0, 8, 7, 5, 5, 6, 7, 7, 7, 7, 7, 0, 1, 0, 7, 7, 9, 5, 8, 8, -8, 2, 7, 9, 9, 9};
	printf("Zadadeniq masiv e: ");
	for(i=0;i<100;i++)  //printirane na masiva
	{
		printf(" %d ",str[i]);
	}
	printf("\n");
    for(a=str[0],i=0;i<100;i++)  //namirane na nai golqmoto 4islo v masiva
	{
		if(a<str[i])
		{
			a=str[i]; //a e nai golqmoto 4islo v masiva
		}
	}
	 for(b=str[0],i=0;i<100;i++)  //namirane na nai malkoto 4islo v masiva
	{
		if(b>str[i])
		{
			b=str[i]; //b e nai malkoto 4islo v masiva
		}
	}
	for(i=0;;i++)  // namira poziciqta v masiva na purvoto nai golqmo 4islo (ako to se povtarq)
	{
		if(a==str[i])
		{
			s=i;
			break;
		}
	}
	for(i=0,f=s;i<(100-f);i++,s++) //vuvejda 4islata sled nai golqmoto (vklu4itelno) v vtoriq masiv
	{
		neww[i]=str[s];
	}
	printf(" \n ");
	printf("Vtoriqt masiv podreden po golemina: ");
	for(r=0,i=0;i<(a+1);i++,r++,t=0) //printira vtoriq masiv po golemina polojitelnite i 0
	{
		
		do{
		if((a-r)==neww[t])
		{
			printf(" %d ",neww[t]);
		}
		if(t==(99-f))break;
		t++;
		}while(1);
	}
	for(r=1,w=0;w>(b-1);w--,r++,t=0) //printira vtoriq masiv po golemina
	{
		
		do{
		if((0-r)==neww[t])
		{
			printf(" %d ",neww[t]);
		}
		if(t==(99-f))break;
		t++;
		}while(1);
	}
        for(r=0,x=1;r<1;x++) //namirame vtoroto po golemina 4islo v vtoriq masiv
		{
			for(t=0;;)
			{
			if((a-x)==neww[t])
			{
				snd=neww[t]; //snd e vtoroto po golemina 4islo v masiv 2
				r=1;
			}
		    if(t==(99-f)) break;
			t++;
			}
			if((a-x)==0) break;
		}
		       for(broi=0,t=0;;)
			   {
			          if(snd==neww[t]) 
			            {
				        	broi++;
		            	}
			          if(t==(99-f)) break;
			          t++;
		    	}	
	printf("\nVtoroto po golemina 4islo ot vtoriq masiv se povtarq %d puti\n",broi);
	for(i=0,r=8;;r--)
	{
		if(i==2) break;
		if(r<0) break;
	           for(broi=0,t=0;;)
			   {
			          if(r==neww[t]) 
			            {
				        	broi++;
							i=2;
		            	}
					  if((-r)==neww[t])
					  {
						  broi++;
						  i=2;
					  }
			          if(t==(99-f)) break;
			          t++;
		    	}
	
	}
	 for(t=1,i=0;i<100;i++)
			   {
				   if(neww[i]!=neww[i+1])
				   {
						   t=0;
						   break;
				   }
			   }
	 if(t==1)
	 {
		 printf("\nCifrata s vtori po golemina ANCII cod ot vtoriq masiv e (%d) i se povtarq %d puti\n",r+1,broi);
	 }
	 else
	 {
		 printf("\nVsi4ki cifri v masiva sa ednakvi i nqma vtora po golemina\n");
	 }
	printf("Izka6 li da zapi6a masiva v fail (Y or something else)");
	fflush(stdin);
	ch=getche();
	if((ch=='y')||(ch=='Y'))
	{
		fileprint(neww,f);
	}

}
void func2(int str[100])
{
	char ccc;
	int broi, b, w, snd, m=0, x, t=0, r, f, s, a, i, neww[100];
	printf("Zadadeniq masiv e: ");
	for(i=0;i<100;i++)  //printirane na masiva
	{
		printf(" %d ", str[i]);
	}
	
    printf("\n");
    for(a=str[0],i=0;i<100;i++)  //namirane na nai golqmoto 4islo v masiva
	{
		if(a<str[i])
		{
			a=str[i]; //a e nai golqmoto 4islo v masiva
		}
	}
	 for(b=str[0],i=0;i<100;i++)  //namirane na nai malkoto 4islo v masiva
	{
		if(b>str[i])
		{
			b=str[i]; //b e nai malkoto 4islo v masiva
		}
	}
	for(i=0;;i++)  // namira poziciqta v masiva na purvoto nai golqmo 4islo (ako to se povtarq)
	{
		if(a==str[i])
		{
			s=i;
			break;
		}
	}
	for(i=0,f=s;i<(100-f);i++,s++) //vuvejda 4islata sled nai golqmoto (vklu4itelno) vuv vtoriq masiv
	{
		neww[i]=str[s];
	}
	printf(" \n ");
	printf("Vtoriqt masiv podreden po golemina: ");
	for(r=0,i=0;i<(a+1);i++,r++,t=0) //printira vtoriq masiv po golemina polojitelnite i 0
	{
		
		do{
		if((a-r)==neww[t])
		{
			printf(" %d ",neww[t]);
		}
		if(t==(99-f))break;
		t++;
		}while(1);
	}
	for(r=1,w=0;w>(b-1);w--,r++,t=0) //printira vtoriq masiv po golemina
	{
		
		do{
		if((0-r)==neww[t])
		{
			printf(" %d ",neww[t]);
		}
		if(t==(99-f))break;
		t++;
		}while(1);
	}
        for(r=0,x=1;r<1;x++) //namirame vtoroto po golemina 4islo v vtoriq masiv
		{
			for(t=0;;)
			{
			if((a-x)==neww[t])
			{
				snd=neww[t]; //snd e vtoroto po golemina 4islo v masiv 2
				r=1;
			}
		    if(t==(99-f)) break;
			t++;
			}
			if((a-x)==0) break;
		}
		       for(broi=0,t=0;;)
			   {
			          if(snd==neww[t]) 
			            {
				        	broi++;
		            	}
			          if(t==(99-f)) break;
			          t++;
		    	}	
	printf("\nVtoroto po golemina 4islo ot vtoriq masiv se povtarq %d puti\n",broi);
	for(i=0,r=8;;r--)
	{
		if(i==2) break;
		if(r<0) break;
	           for(broi=0,t=0;;)
			   {
			          if(r==neww[t]) 
			            {
				        	broi++;
							i=2;
		            	}
					  if((-r)==neww[t])
					  {
						  broi++;
						  i=2;
					  }
			          if(t==(99-f)) break;
			          t++;
		    	}
	}
	printf("\nCifrata s vtori po golemina ANCII cod ot vtoriq masiv e (%d) i se povtarq %d puti\n",r+1,broi);
	printf("Izka6 li da zapi6a masiva v fail (Y or something else)");
	fflush(stdin);
	ccc=getche();
	if((ccc=='y')||(ccc=='Y'))
	{
		fileprint(neww,f);
	}
}
void fileprint(int str[100],int f)
{

	char dir[500];
	FILE *fout;
	int a,i;
	printf("\nVuvedete mestopolojenieto na zapis na faila: ");
	scanf("%s",&dir);
      fout=fopen(dir,"a+");
	for(i=0;i<(100-f);i++)
	{
		a=str[i];
		if(((i+1)%4==0)&&(i!=0))
		{
			fprintf(fout," %d\n",a);
		}
		else fprintf(fout," %d ",a);
		
	}
	fclose(fout);
}