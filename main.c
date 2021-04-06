#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
void motus();
void pendu();
void menu();
void Color(int couleurDuTexte,int couleurDeFond) //procédure pour les couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int main()
{
    int choix;
    Color(10,0);
    printf("\t\t\t*************************\n");
    Sleep(1000);
    printf("\t\t\t*                       *\n");
    Sleep(1000);
    printf("\t\t\t**                     **\n");
    Sleep(1000);
    printf("\t\t\t***                   ***\n");
    Sleep(1000);
    printf("\t\t\t****                 ****\n");
    Sleep(1000);
    printf("\t\t\t*****BIENVENUE AU JEU****\n");
    Sleep(1000);
    printf("\t\t\t****                 ****\n");
    Sleep(1000);
    printf("\t\t\t***                   ***\n");
    Sleep(1000);
    printf("\t\t\t**                     **\n");
    Sleep(1000);
    printf("\t\t\t*                       *\n");
    Sleep(1000);
    printf("\t\t\t*************************\n");

    printf("\t\t\t_________________________\n");
    Sleep(3000);

    do
    {
        printf("\t\t\t1-le pendu\n");
        Sleep(1000);
        printf("\t\t\t2-Motus\n");
        Sleep(1000);
        printf("\t\t\t3-Quitter\n");
        Color(15,0);
        scanf("%i",&choix);
    }
    while ((choix!=1)&&(choix!=2)&&(choix!=3));
    switch(choix)
    {
    case 1 :
        pendu();
        break;
    case 2 :
        motus();
        break;
    case 3 :
    {
        printf("\t\t\t|--------------|\n");
        Sleep(1000);
        printf("\t\t\t|~ au revoir !~|\n");
        Sleep(1000);
        printf("\t\t\t|--------------|");
    }
    break;
    default :
        printf("choix incorrect\n");
    }
    return 0;
}



void motus()
{
    int score[5]= {0,0,0,0,0},scoretri[5];
    int i,choix,nbj,v,slen,pos,j,k,ok,ne=0,x,timef,a,choice,chix;
    char T[100][100]= {"PROGRAMME","TRAIN","BALLON","INFORMATIQUE","ORDINATEUR","TABLE","CHIEN","CHAT","RAT","VACHE","EAU","VOITURE","FILM","PORTABLE","VALISE","CABLE","SALLON","TAPIS","MUSIQUE","ART","CARTE","FAMILLE","SALAIRE","BAVETTE","MALADIE","CASQUE","PORTE","JUS","CITRON","FRAISE","VANILLE","BANNANE","MEUBLE","DATA","INTERNET","CONNEXION","OLIVE","ORANGE","PROJET","HIVER","PRINTEMPS","SOLEIL","CIEL","AMANDE","DEMANDE","TRAVAIL","COURS","PLAGE","SABLE","DEVOIR"};
    char pseu[5][30],pseutri[5][30];
    char mj[15],aux1[30];
    int mot[15];

    int tenta =7,permut,z;
    int trouve =0,aux;
    char prop[30];

    char motresultat[15];
    char tableau[30];



    time_t start_t,end_t;
    printf("\n\n\n\n\n\n\n");
    Color(5,0);
    printf("\t\t\t================================\n");
    printf("\t\t\t|  Bienvenu dans le jeu MOTUS! |\n");
    Sleep(1000);
    printf("\t\t\t|______________________________|\n");
    printf("\t\t\t|    si vous voulez connaitre  |\n");
    printf("\t\t\t| le reglement du jeu cliquez 1|\n");
    Sleep(2000);
    printf("\t\t\t|______________________________|\n");
    printf("\t\t\t|si vous voulez jouer cliquez 2|\n");
    Sleep(2000);
    printf("\t\t\t|______________________________|\n");
    printf("\t\t\t|    pour quitter cliquez 3    |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t================================\n");
    Color(15,0);
    scanf("%i",&choix);
    switch(choix)
    {
    case 1 :
    {
        printf("alors pour ce jeu on va vous choisir un mot aleatoirement de notre liste,on va le masquer sauf que la premiere lettre et vous devez le devenir \n");
        Sleep(9000);
        printf("le principe de notre jeu est facile \n le joueur doit saisir successivement des mots entiers \n Le programme l'informe des lettres bien placées , des lettres mal placées et de celles qui n appartiennent pas au mot recherché. \n");
        Sleep(14000);
        printf("les regles du jeu : \n");
        Sleep(2000);
        printf("\t - regle 1 : vous avez 6 tentatives\n");
        Sleep(2000);
        printf("\t - regle 2:cher joueur vous avez un defi contre la montre on vous accorde 60 s pour deviner le mot.\n");
        Sleep(7000);
        printf("Un joueur peut demander l aide de l ordinateur uniquement une fois en tapant < ? > et ce qui cause la perte d un point de son score mais ca ne change pas le nombre de tentatives.\n");
        Sleep(12000);
        printf("remarque :  ca ne differe pas que vous entrez les lettres en majuscules ou en miniscules\n");
        printf("\t\t\t~ bonne chance !~\n");
        Sleep(5000);
        printf("si vous voulez revenir au menu du jeu cliquez 1 sinon cliquez 2 pour quitter\n");
        Sleep(1000);
        scanf("%i",&chix);
        switch(chix)
        {
        case 1 :
            motus();
            break ;
        case 2 :
        {
            printf("\t\t\t|--------------|\n");
            Sleep(1000);
            printf("\t\t\t|~ au revoir !~|\n");
            Sleep(1000);
            printf("\t\t\t|--------------|");
        }
        break;
        default:
            printf("erreur\n");
        }
    }

    break;
    case 2 :
    {
        do
        {
            printf("tapez le nombre de joueurs sachant que le maximum est 5\n");  //saisie du nbr de joueurs
            scanf("%i",&nbj);
        }
        while ((nbj<=0)||(nbj>5));//condition pr le nbr

        for(k=0; k<nbj; k++) //boucle pour que le traitement se repete pour tout les joueurs
        {
            printf("\n donnez le pseudo du %i e joueur\n",k+1);
            scanf("%s",pseu[k]);
            ok=0;
            a=1;
            ne=0;
            tenta=7;
            trouve=0;
            x=60;
            motresultat[0]=mj[0];


            srand(time( NULL ));
            v=rand()%50;      //random number between 0 and 49
            strcpy(mj,T[v]);
            slen=strlen (mj);

            printf(" \n voici votre mot secret que vous devez deviner :\n");
            printf("%c",mj[0]);
            mot[0]=1;
            for(i=1; i<slen; i++)
            {
                printf("*");  //affichage du mot sous la forme codée
                mot[i]=0;
            }
            printf("\n");




            while((trouve==0)&&(tenta>0)&&(x>0))
            {
                time(&start_t); //start counting time



                printf("\n il vous reste %i tentatives et %i secondes",tenta,x);
                printf(" donner votre proposition compose de %i caracteres:",slen);


                if( x <=0 ) 		// verif temps ( si temps s'est ecoule on quitte )
                {

                    break;
                }

                    fflush(stdin);
                    scanf("%s",&prop);

                    if ((prop[0]=='?')&&(strlen(prop)==1)) //help !
                    {
                        while ((ok==0)&&(a<slen))
                        {
                            if (mot[a]==0)
                            {
                                mot[a]=1;
                                motresultat[a]=mj[a];
                                ok=1;
                                printf(" \n vous avez utlise la totalite d aide \n");//utilisation de l'aide
                            }
                                a++;

                        }
                      if(strcmp(motresultat,mj)==0)
                        {trouve=1;
                        }

                    }

                    for (i=0; i<slen; i++)
                    {


                        prop[i]=toupper(prop[i]);
                    } //majuscule
                    if (strcmp (prop,mj)==0) //mot deviné
                    {
                        trouve=1;
                    }
                    else
                    {
                        if(prop[0]!='?') //si il s'agit pas de l'aide et le mot n'est découvert les tenta diminuent
                        {

                            ne++;
                            tenta--;
                        }

                        for(i=0; i<slen; i++) //verification des lettres bien placées
                        {
                            if(mj[i]==prop[i])
                            {


                                motresultat[i]=mj[i];
                                mot[i]=1;

                            }
                        }
                        for (j=0; j<slen; j++)
                        {
                            if (mot[j]==0)
                                printf("*");
                            else
                                printf("%c",mj[j]);//affichage des lettres qui sont bien placées
                        }
                        i=1;
                        while(i<slen)
                        {
                            for(j=1; j<slen; j++)
                            {
                                if(mj[i]==prop[j])
                                    tableau[i]=mj[i];  //enregistrer les lettres mal placées
                            }
                            i++;
                        }

                        for(i=1; i<slen; i++)
                        {


                            if(motresultat[i]!=tableau[i]) //pour ne pas afficher aussi les lettres bien placées
                            {



                                printf("[%c]",tableau [i] ); //affichage des lettres qui sont dans le mot mais ne sont pas bien placés


                            }
                        }
                        printf("\n");
                    }

                    x=x-difftime(time(&end_t),start_t); //temps

                    if(strcmp(motresultat,mj)==0)
                        trouve=1;
            }

            if(x<=0)
            {
                printf("\n Desole, le temps s'est ecoule le mot etait bien %s\n",mj);
            }
            else if (trouve==1)
            {
                printf("\n bien joue! le mot etait bien %s\n",mj);
                switch(ne)
                {
                case 0 :
                case 1 :
                    score[k]=score[k]+4;
                    break;
                case 2 :
                case 3 :
                    score[k]=score[k]+3;
                    break;
                case 4 :
                case 5 :
                    score[k]=score[k]+2;
                    break;
                case 6 :
                    score[k]=score[k]+1;
                    break;
                default :
                    score[k]=score[k];


                }
                if(ok==1)
                {
                    score[k]=score[k]-1;
                }
            }
            else
            {
                printf("vous avez perdu le mot secret etait bien %s\n",mj);
            }
            menu(); //eppel pour le menu final
            scanf("%i",&choice);
            switch(choice)
            {
            case 1 :
                motus ();  //rejouer(fausse)
                break;
            case 2 :
                printf("votre score est %i",score[k]); //affichage score
                break;
            case 3 :
            {
                printf("\t~~~~pseudo~~~~~~~~~~~~~~~~~score~~~~\n");
                for(int i=0; i<nbj; i++)
                {

                    {
                        strcpy(pseutri[i],pseu[i]);
                    }
                }

                for(int i=0; i<nbj; i++)
                {
                    scoretri[i]=score[i];
                }


                    for(int i = 0 ; i < nbj-1; i++ )
                    {

                            if ( scoretri [i] > scoretri [i+1] )
                            {
                                aux = scoretri[i];
                                strcpy(aux1,pseutri[i]);
                                scoretri[i] = scoretri[i+1];
                                strcpy(pseutri[i],pseutri[i+1]);
                                scoretri[i+1] = aux ;
                                strcpy(pseutri[i+1],aux1);

                            }

                    }


                for (int p=nbj; p<0; p--)
                {
                    printf("\t~~~~%s~~~~~~~~~~~~~~~~~%i~~~~\n",pseutri[p],scoretri[p]);
                }
            }
            break ;
            case 4 :
                main(); //menu principal
                break ;
            case 5 :
            {
                printf("\t\t\t|--------------|\n"); //quitter
                Sleep(1000);
                printf("\t\t\t|~ au revoir !~|\n");
                Sleep(1000);
                printf("\t\t\t|--------------|");
            }
            break;
            default :
                printf("choix incorrecte");
            }
        }
    }
    break;
    case 3: //quitter du premier menu
    {
        printf("\t\t\t|--------------|\n");
        Sleep(1000);
        printf("\t\t\t|~ au revoir !~|\n");
        Sleep(1000);
        printf("\t\t\t|--------------|");
    }
    break;
    default :
        printf("erreur") ;
    }


}




void pendu()
{
    int nbrj,i,len,trouve,k,x,ne=0,ok=0,a=0,choice,chix,y,aux,permut;
    char T[50][30]= {"PROGRAMME","TRAIN","BALLON","INFORMATIQUE","ORDINATEUR","TABLE","CHIEN","CHAT","RAT","VACHE","EAU","VOITURE","FILM","PORTABLE","VALISE","CABLE","SALLON","TAPIS","MUSIQUE","ART","CARTE","FAMILLE","SALAIRE","BAVETTE","MALADIE","CASQUE","PORTE","JUS","CITRON","FRAISE","VANILLE","BANNANE","MEUBLE","DATA","INTERNET","CONNEXION","OLIVE","ORANGE","PROJET","HIVER","PRINTEMPS","SOLEIL","CIEL","AMANDE","DEMANDE","TRAVAIL","COURS","PLAGE","SABLE","DEVOIR"};
    char pseu[5][30],pseutri[5][30],aux1[30];
    char motj[15];
    int mots[15]; //tableau de 0 et 1.
    char lettre;
    int tenta=7;
    int choix,score[5]= {0,0,0,0,0},scoretri[5];
    time_t start_t,end_t;
    printf("\n\n\n\n\n\n\n");
    Color(5,0);
    printf("\t\t\t================================\n");
    printf("\t\t\t|  Bienvenu dans le jeu PENDU! |\n");
    Sleep(1000);
    printf("\t\t\t|______________________________|\n");
    printf("\t\t\t|   si vous voulez connaitre   |\n");
    printf("\t\t\t| le reglement du jeu cliquez 1|\n");
    Sleep(1000);
    printf("\t\t\t|______________________________|\n");
    printf("\t\t\t|si vous voulez jouer cliquez 2|\n");
    Sleep(1000);
    printf("\t\t\t|______________________________|\n");
    printf("\t\t\t|     pour quitter cliquez 3   |\n");
    printf("\t\t\t|                              |\n");
    printf("\t\t\t================================\n");
    Color(15,0);
    scanf("%i",&choix);
    switch(choix)
    {
    case 1 :
    {
        printf("Alors pour ce jeu on va vous choisir un mot aleatoirement de notre liste , on va le masquer et vous devez le deviner lettre par lettre\n");
        Sleep(6000);
        printf("le principe de notre jeu est assez facile \n A chaque fois que vous choisissez une lettre qui existe dans le mot, toutes les occurrences de celle ci dans le mot seront devoilees\n");
        Sleep(10000);
        printf("les regles du jeu :\n");
        Sleep(1000);
        printf("\t -Regle 1 : vous avez 5 tentatives sachant que a chaque fois vous devoilez une lettre qui existe le nombre de tentatives n est pas decremente.\n");
        Sleep(7000);
        printf("\t -Regle 2 : cher joueur vous avez un defi contre la montre on vous accorde 60 s pour deviner le mot.\n");
        Sleep(6000);
        printf("Un joueur peut demander l aide de l ordinateur uniquement une fois en tapant < ? > et ce qui cause la perte d un point de son score mais ca ne change pas le nombre de tentatives.\n");
        Sleep(9000);
        printf("Remarque : ca ne differe pas que vous entrez les lettres en majuscules ou en miniscules\n");
        Sleep(5000);
        printf("\t\t\t~Bonne chance !~\n");
        Sleep(1000);
        printf("si vous voulez revenir au menu du jeu cliquez 1 sinon cliquez 2 pour quitter\n");
        scanf("%i",&chix);
        switch(chix)
        {
        case 1 :
            pendu();
            break ;
        case 2 :
        {
            printf("\t\t\t|--------------|\n");
            Sleep(1000);
            printf("\t\t\t|~ au revoir !~|\n");
            Sleep(1000);
            printf("\t\t\t|--------------|");
        }
        break;
        default:
            printf("erreur\n");
        }
    }
    break;
    case 2:
    {

        do
        {
            printf("tapez le nombre de joueurs sachant que le maximum est 5\n");
            scanf("%i",&nbrj);
        }
        while ((nbrj<=0)||(nbrj>5));
        for(k=0; k<nbrj; k++) //repeter a tout les joueurs
        {
            printf("\ndonnez le pseudo du %i e joueur\n",k+1);
            scanf("%s",pseu[k]);
            tenta=7;
            ok=0;
            a=0;
            ne=0;
            y=60;
            srand(time( NULL ));
            x=rand()%50;      //random number between 0 and 49
            strcpy(motj,T[x]);
            len=strlen (motj);
            printf("voici votre mot secret que vous devez deviner :\n");
            for(i=0; i<len; i++)
            {
                printf("\t*");  //affichage du mot sous la forme codée
                mots[i]=0; //intialisation du tableau
            }
            printf("\n");
            trouve=0;

            while((trouve==0)&&(tenta>0)&&(y>0))
            {
                time(&start_t); //start counting time
                printf(" \ncher joueur il vous reste %i coups et %i secondes veuillez proposez une lettre :",tenta,y);
                fflush(stdin);
                scanf("%c",&lettre);
                if (y<=0)
                {
                    break;
                }
                printf("\n");
                lettre=toupper(lettre); //majuscule
                for(i=0; i<len; i++)
                {
                    if (motj[i]==lettre) //lettre trouvé
                    {
                        mots[i]=1;
                    }
                    else if (lettre=='?') //aide
                    {
                        while((ok==0)&&(a<len))
                        {
                            if(mots[a]==0)
                            {
                                mots[a]=1;
                                ok=1;
                                printf("vous avez utilise votre seule tentative d aide\n");
                            }
                            a++;
                        }
                    }
                    if(mots[i]==0)
                        printf("\t*");
                    else
                        printf("\t%c",motj[i]); //affichage des lettres trouvées
                }

                printf("\n");
                i=0;
                while((i<len)&&(lettre != motj[i])&&(lettre!='?'))    //recherche de la lettre dans le mot secret
                {
                    i++;
                }
                if(i>=len)
                {
                    tenta--; //perte dune tentative si la lettre nexiste pas et il ne s'agit pas d'une demande d'aide
                    ne++;
                }

                i=0;
                while((i<len)&&(0!=mots[i])) //recherche de lelement 0 dans le tab boleen
                {
                    i++;
                }
                if(i<len)
                    trouve=0;
                else
                    trouve=1;  //si le 0 nexiste pas donc  le joueur a gagne
                switch (tenta) //dessiner le pendu avec printf
                {
                case 1:
                {
                    printf("\t  __________\n");
                    printf("\t  |/\t |\n");
                    printf("\t  |\t |\n");
                    printf("\t  |\t O\n");
                    printf("\t  |\t/0\\ \n");
                    printf("\t  |\t/   \n");
                    printf("\t__|__\n");
                }
                break;
                case 2 :
                {
                    printf("\t  __________\n");
                    printf("\t  |/\t |\n");
                    printf("\t  |\t |\n");
                    printf("\t  |\t O\n");
                    printf("\t  |\t/0\\ \n");
                    printf("\t  |\t  \n");
                    printf("\t__|__\n");
                }
                break;
                case 3 :
                {
                    printf("\t  __________\n");
                    printf("\t  |/\t |\n");
                    printf("\t  |\t |\n");
                    printf("\t  |\t O\n");
                    printf("\t  |\t/0 \n");
                    printf("\t  |\t  \n");
                    printf("\t__|__\n");
                }
                break;
                case 4 :
                {
                    printf("\t  __________\n");
                    printf("\t  |/\t |\n");
                    printf("\t  |\t |\n");
                    printf("\t  |\t O\n");
                    printf("\t  |\t 0 \n");
                    printf("\t  |\t  \n");
                    printf("\t__|__\n");
                }
                break;
                case 5 :
                {
                    printf("\t  __________\n");
                    printf("\t  |/\t |\n");
                    printf("\t  |\t |\n");
                    printf("\t  |\t O\n");
                    printf("\t  |\t \n");
                    printf("\t  |\t  \n");
                    printf("\t__|__\n");
                }
                break;
                case 6 :
                {
                    printf("\t  __________\n");
                    printf("\t  |/\t |\n");
                    printf("\t  |\t |\n");
                    printf("\t  |\t \n");
                    printf("\t  |\t \n");
                    printf("\t  |\t  \n");
                    printf("\t__|__\n");
                }
                break;

                }

                y=y-difftime(time(&end_t),start_t);
            }//end while jeu

            if(y<=0)
            {
                printf("le temps s est ecoule ! le mot etait bien %s\n",motj);
            }
            else if (trouve==1)
            {
                printf("Bien joue ! le mot etait bien %s\n",motj);
                switch(ne)
                {
                case 0 :
                case 1 :
                    score[k]=score[k]+4;
                    break;
                case 2 :
                case 3 :
                    score[k]=score[k]+3;
                    break;
                case 4 :
                case 5 :
                    score[k]=score[k]+2;
                    break;
                case 6 :
                    score[k]=score[k]+1;
                    break;
                default :
                    score[k]=score[k];
                }
                if(ok==1) //si il a demandé de laide son score diminue
                {
                    score[k]=score[k]-1;
                }
            }
            else
            {
                printf("\t  __________\n");
                printf("\t  |/\t |\n");
                printf("\t  |\t |\n");
                printf("\t  |\t O\n");
                printf("\t  |\t/0\\ \n");
                printf("\t  |\t/ \\  \n");
                printf("\t__|__");
                printf("\npendu! vous avez perdu le mot secret etait bien %s\n",motj);
            }
            menu();
            scanf("%i",&choice);
            switch(choice)
            {
            case 1 :
                pendu();
                break;
            case 2 :
            {
                if(score[k]>2)
                    printf("EXCELENT ! votre score est %i",score[k]);
                else
                    printf("DESOLE ! votre score est %i",score[k]);


            }
            break;
            case 3 :
            {
                printf("\t~~~~pseudo~~~~~~~~~~~~~~~~~score~~~~\n");
                for(int i=0; i<nbrj; i++)
                {
                    for(int j=0; j<strlen(pseu[i]); j++)
                    {
                        strcpy(pseutri[i],pseu[i]);
                    }
                }

                for(int i=0; i<nbrj; i++)
                {
                    scoretri[i]=score[i];
                }

                do
                {
                    permut = 0;
                    for(int i = 0 ; i < nbrj-1 ; i++ )
                    {
                        for( int j=0; j<strlen(pseutri[i]); j++)
                        {
                            if ( scoretri [i] < scoretri [i+1] )
                            {
                                aux = scoretri[i];
                                strcpy(aux1[j],pseutri[i][j]);
                                scoretri[i] = scoretri[i+1];
                                strcpy(pseutri[i][j],pseutri[i+1][j]);
                                scoretri[i+1] = aux ;
                                strcpy(pseutri[i+1][j],aux1[j]);
                                permut = 1;
                            }
                        }
                    }
                }
                while (permut == 1);
                for (int p=0; p<nbrj; p++)
                {
                    printf("\t~~~~%s~~~~~~~~~~~~~~~~~%i~~~~\n",pseutri[p],scoretri[p]);
                }
            }
            break ;
            case 4 :
                main();
                break ;
            case 5 :
            {
                printf("\t\t\t|--------------|\n");
                Sleep(1000);
                printf("\t\t\t|~ au revoir !~|\n");
                Sleep(1000);
                printf("\t\t\t|--------------|");
            }
            break;
            default :
                printf("choix incorrecte");
            }

        }//end for joueurs
    }
    break;
    case 3 :
    {
        printf("\t\t\t|--------------|\n");
        Sleep(1000);
        printf("\t\t\t|~ au revoir !~|\n");
        Sleep(1000);
        printf("\t\t\t|--------------|");
    }
    break;
    default :
        printf("erreur!");
    }


}




void menu()
{
    printf("\t\t\t ===========================\n");
    printf("\t\t\t|         1-REJOUER        |\n");
    printf("\t\t\t ===========================\n");
    Sleep(1000);
    printf("\t\t\t|     2-VERIFIER SCORE     |\n");
    printf("\t\t\t ===========================\n");
    Sleep(1000);
    printf("\t\t\t|       3-CLASSEMENT       |\n");
    printf("\t\t\t ===========================\n");
    Sleep(1000);
    printf("\t\t\t|4-RETOUR AU MENU PRINCIPAL|\n");
    printf("\t\t\t ===========================\n");
    Sleep(1000);
    printf("\t\t\t|        5-QUITTER         |\n");
    printf("\t\t\t ===========================\n");
}




