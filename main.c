#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>





int string_comparaison(char string1[],char string2[],int len1,int len2){
    int count=0;
    if (len1 != len2)
    {
        return 0 ;
    }
    else{
        for(int i=0; i<len1;i++){
            if (string1[i]==string2[i])
            {
                count++ ;
            }
            
        }
    }
    if (count == len1)
    {
        return 1;
    }
    else{
        return 0 ;
    }
}




int main(){
    char commande[500];
    int compteur=0;

    while (true)
    {
        printf("kevShell$$  ");
        fgets(commande,500,stdin);
        for (int i = 0; i < 500; i++)
        {
            if (commande[i] !='\0')
            {
                compteur++ ;
            }
            
        }
        char **commande_partielle=malloc(compteur*sizeof(char*));
        for(int j=0;j< compteur; j++){
            for (int  w=j+1; w < compteur; w++)
            {
                if (commande[w] !=' ')
                {
                    commande_partielle[j]+=commande[w];

                }
                else{
                    break;
                }
            }
            
        }
        if(string_comparaison(commande_partielle[0],"exit")==1){
            printf("END");
            break;
        }
        
    }
    
    return 0;

}