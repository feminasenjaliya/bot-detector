#include<stdio.h>
#include<stdlib.h>

void check_comt (char) ;  
void block_comt () ;   
void single_comt () ;  
/*this is a 
coment*/

FILE *fp;

int main()
{
    char c;
    fp = fopen ("1.c","r") ;   
 

    while((c=fgetc(fp))!=EOF)      
        check_comt(c);   

        fclose(fp);
  

    return 0;
}


void check_comt(char c)
{
    char d;

    if( c == '/')   
    {
        if((d=fgetc(fp))=='*')   
         block_comt();  

        else if( d == '/')  
        {
          single_comt();

        }
        else
        {
            // if both the cases fail, it is not a comment
           
		   printf("%c",c);
		   
        }
    }

    
    else
       printf("%c",c);
}



void block_comt()
{

 char d,e;

    while((d=fgetc(fp))!=EOF)   
    {
  
        if(d=='*')    
        {
            e=fgetc(fp);  

            if(e=='/')  
                return;
        }
   }

}



void single_comt()
{
 char d,e;

    while((d=fgetc(fp))!=EOF)  
    {
  
        if(d=='\n')   
            return;  
    }

}
