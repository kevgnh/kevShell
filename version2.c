#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define size 1024





int string_comparaison(char string1[],char string2[]){
    int count=0;
    int len1=0;
    int len2=0;
    int iterateur=0;


    while (string1[iterateur] !='\0'){
        len1++ ;
        iterateur++ ;
    }    

    

    iterateur=0;

    while (string2[iterateur] !='\0')
    {
        len2++;
        iterateur++ ;   
    }
    if (len1<len2 || len2<len1)
    {
        return 0;
    }
    
    for(int i=0;i<len1;i++){
        if (string1[i]==string2[i])
        {
            count++ ;
        }
        
    }
    if (count==len1)
    {
        return 1;
    }
    return 0;
    
    
}
/*
int len(char string[]){

    int compteur_char=0;
    int longeur=0;

     while (string[compteur_char] !='\0'){
        longeur++;
        compteur_char++ ;
    }  
    return longeur;
   
}
*/

void echo_prime(char string[]){

    printf("%s ",string);  
    
}

int main()
{
      
    char commande[500];
    

    while (true)
    {
        int compteur=0;
        int position_dans_commande=0;

        printf("kevShell$$  ");
        
        fgets(commande,500,stdin);


        for (int i = 0; i < 500; i++)
        {
            if (commande[i] !='\0')
            {
                compteur++ ;
            }
            else{
                break;
            }
            
        }
        if (commande[compteur-1]=='\n')
        {
            commande[compteur-1]='\0';
        }
        
        

        char **commande_partielle=malloc(compteur*sizeof(char *));

        for(int i=0;i<compteur;i++){
            commande_partielle[i] = calloc(100,sizeof(char ));
        }

        bool var=true;

        for(int i=0;i< compteur && var; i++){
            for(int j=0;j<compteur;j++){
                if (commande[position_dans_commande] != ' ' && commande[position_dans_commande] !='\0')
                {
                    commande_partielle[i][j]=commande[position_dans_commande];
                }
                else if(position_dans_commande>0 && commande[position_dans_commande -1] != ' ' && commande[position_dans_commande] ==' '){
                    commande_partielle[i][j]='\0';

                    while (commande[position_dans_commande] == ' ')
                    {
                        position_dans_commande++ ;
                    }
                    
                    break;
                }
                else if(commande[position_dans_commande] == '\0'){
                    commande_partielle[i][j]='\0';
                    var=false;
                    break;
                }

                if (position_dans_commande <compteur)
                {
                    position_dans_commande++ ;
                }
                
            
                
            }
           
        } 
        int verifiecation=string_comparaison(commande_partielle[0],"exit");

        if(verifiecation==1){
            printf("END\n");
            break;
        }
        if(string_comparaison(commande_partielle[0],"echo")==1){

            int petit_compteur=1;

            while(commande_partielle[petit_compteur][0] != '\0'){
                echo_prime(commande_partielle[petit_compteur]);
                petit_compteur++ ;
            }
            printf("\n");
            
            
        }
        if(string_comparaison(commande_partielle[0],"pwd")==1){
            char tab[size];
            getcwd(tab,size);
            printf("%s \n",tab);
        }
        
        for(int i=0;i<compteur;i++){
            free(commande_partielle[i]);
        }
        free(commande_partielle);  
        
    }
    
    return 0;

}
