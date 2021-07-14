#include<stdio.h>
#include<string.h>
struct selection 
    {
        char csk[30];
        char rcb[30];
        char mi[30];
        char pk[30];
        char a[100];
        char b[100];
        char c[100];
        char d[100];
        char cap[100];
        char uncap[100];
        char foregn[100];
        char fpl[100];
}s[50];
void getplayers();
void getinput(int );
void display();
void showplayers();
int i,j,k;
int main()
{
	int n;
	getplayers();
	getinput(n);
	showplayers();
    display();
    return 0;
}
void showplayers(){
	FILE *fp;
	int n=0;
	fp=fopen("cap.txt","r");
	char a;
	printf("Capped players:\n");
	while((a=fgetc(fp)) != EOF){
		printf("%c",a);
	}
	fclose(fp);
	printf("Please select your capped players:\n");
	getinput(n);
	
	fp=fopen("uncap.txt","r");
	printf("Uncapped players:\n");
	while((a=fgetc(fp)) != EOF){
		printf("%c",a);
	}
	fclose(fp);
	n+=3;
	printf("Please select your uncapped players:\n");
	getinput(n);

	fp=fopen("for.txt","r");
	printf("Foreign players:\n");
	while((a=fgetc(fp)) != EOF){
		printf("%c",a);
	}
	fclose(fp);
	n+=3;
	printf("Please select your foreign players:\n");
	getinput(n);

}
void getplayers(){
	FILE *fp;
	int r;
	int i;
	for(i=0;i<5;i++){
		printf("Name: ");
		scanf("%s",s[i].fpl);
		printf("\nEnter   1 for capped player\n\t2 for uncapped player\n\t3 for forign player\nEnter your choice: ");
		scanf("%d",&r);
		switch(r){
			case 1:
				fp=fopen("cap.txt","r");
				if(fp!=NULL){
					fclose(fp);
					fp=fopen("cap.txt","a");
					fprintf(fp,"%s\n",s[i].fpl);
				}
				else{
					fclose(fp);
					fp=fopen("cap.txt","w");
					fprintf(fp,"%s\n",s[i].fpl);
				}
				fclose(fp);
				break;
			case 2:
				fp=fopen("uncap.txt","r");
				if(fp!=NULL){
					fclose(fp);
					fp=fopen("uncap.txt","a");
					fprintf(fp,"%s\n",s[i].fpl);
				}
				else{
					fclose(fp);
					fp=fopen("uncap.txt","w");
					fprintf(fp,"%s\n",s[i].fpl);
				}
				fclose(fp);
				break;
			case 3:
				fp=fopen("for.txt","r");
				if(fp!=NULL){
					fclose(fp);
					fp=fopen("for.txt","a");
					fprintf(fp,"%s\n",s[i].fpl);
				}
				else{
					fclose(fp);
					fp=fopen("for.txt","w");
					fprintf(fp,"%s\n",s[i].fpl);
				}
				fclose(fp);
				break;
		}
	}
}
void getinput(int n) 
{
    for(i=n;i<n+3;i++)
    {
        printf("CSK: ");
        gets(s[i].a);
        for(j=0;j<i;j++)
        {
            if(strcmpi(s[i].a,s[j].b)==0)
            {
                printf("Player is ALready selected by RCB");
                
            }
            else
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].a,s[j].c)==0)
            {
                printf("Player is ALready selected by MI");
            }
            else
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].a,s[j].d)==0)
            
            {
                printf("Player is ALready selected by PK");
            }
            else
            {
                k=1;
                break;
            }
        }
        if(k==1)
        {
            strcpy(s[i].csk,s[i].a);
        }
        printf("\nRCB: ");
        gets(s[i].b);
        for(j=0;j<=i;j++)
        {
            if(strcmpi(s[i].b,s[j].a)==0)
            {
                printf("The player is already selected by CSK");
            }
            else 
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].b,s[j].c)==0)
            {
                printf("The player is already selected by MI");    
        	}
            else 
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].b,s[j].d)==0)
            {
                printf("The player is already selected by PK");
            }
            else 
            {
                k=1;
                break;
            }
        }
        if(k==1)
        {
            strcpy(s[i].rcb,s[i].b);
        }
        printf("\nMI: ");
        gets(s[i].c);
        for(j=0;j<=i;j++)
        {
            if(strcmpi(s[i].c,s[j].a)==0)
            {
                printf("The player is already selected by CSK");
            }
            else 
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].c,s[j].b)==0)
            {
                printf("The player is already selected by RCB");
            }
            else 
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].c,s[j].d)==0)
            {
                printf("The player is already selected by PK");
            }
            else 
            {
                k=1;
                break;
            }
        }
        if (k==1)
        {
             strcpy(s[i].mi,s[i].c);
        }
        printf("\nPK: ");
        gets(s[i].d);
        for(j=0;j<=i;j++)
        {
            if(strcmpi(s[i].d,s[j].a)==0)
            {
                printf("The player is already selected by CSK");
            }
            else 
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].d,s[j].b)==0)
            {
                printf("The player is already selected by RCB");
            }
            else 
            {
                k=1;
                break;
            }
            if(strcmpi(s[i].d,s[j].c)==0)
            {
                printf("The player is already selected by MI");
            }
            else 
            {
                k=1;
                break;
            }
        }
        if (k==1)
        {
            strcpy(s[i].pk,s[i].d);
        }
        printf("\n***************************\n");
	}       
}	
void display(){
	int i;
    printf("\nCSK\tRCB\tMI\tPK\n");
    for(i=0;i<3;i++)
    {
            printf("%s\t%s\t%s\t%s\n\n",s[i].csk,s[i].rcb,s[i].mi,s[i].pk);
    }
}
