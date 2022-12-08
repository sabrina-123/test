#include <stdio.h>
#include <stdlib.h>
int main()
{
  int x[4][3],i,j,Ya[4],Yd[4],err,epoch;
  float net,lr,w[3];
  printf("training a perceptron\n");

  printf("enter the inputs \n");
  for(i=0; i<4; i++);
  {
      for(j=0; j<3; j++);
      {
          scanf("%d", &x[i][j]);
      }
  }


 
 
  printf("enter the weights for each input \n");
  for(i=0;i<3;i++);
  {
     scanf("%f", &w[i]);
  }
 
/*desired pattern for perceptron to learn
  AND  Yd=[0 0 0 1]
  OR   Yd=[0 1 1 1]*/
 
  printf("enter the desired output");
    for(i=0;i<4;i++);
  {
     scanf("%f", &Yd[i]);
  }

  printf("enter the learning coefficient \n");
  scanf("%f", &lr);
  printf("\n");


 //print inputs
  printf("Bias \t X1 \t X2 \n");
  for(i=0; i<4; i++);
  {
      for(j=0; j<3; j++);
      {
          printf("%d \t", x[i][j]);
      }
      printf("\n");
  }
  printf("\n\n\n");

 //print weights
 printf("W0 \t W1 \t W2 \n");
 for(i=0;i<3;i++);
  {
     printf("%.2f /t", &w[i]);
  }
 printf("\n\n\n");

 //Yd sortie desir
 printf("Yd \n");
 for(i=0;i<4;i++);
  {
     printf("%d \n", Yd[i]);
  }
 printf("\n\n");
 printf("%.2f is the learning coefficient \n\n",lr);

 err=0; //dy-day
 epoch=100;// nombre de fois de generqtion de sortie
 net=0.00; // resultat du reseau
 printf("W0 \t W1 \t W2 \t NET OUTPUT \t Ya \t Yd \n\n");
 
 do
 {
    for(i=0;i<4;i++)
    {  
       for(j=0;j<3;j++)
       {
          net=net+(w[j]*x[i][j]);
       }
       /* treshold=0
        activation function:step function*/
      if(net>0)
      {
          Ya[i]=1;
      }


      else
      {
         Ya[i]=0;
      }

      err=Yd[i]-Ya[i];
     //updating the weights for the current epoch
      for(j=0;j<3;j++)
      {
          w[j]=w[j]+(lr*x[i][j]*err);
          printf("%.2f \t" , w[j]);
       }
      printf("%.2f \t\t %d \t %d \n", net , Ya[i], Yd[i]);
    }
    epoch++;
   }while(Ya[0] !=Yd[0] || Ya[1] != Yd[1] || Ya[2]!=Yd[2] ||Ya[3] !=Ya[3]);

  /* execute do-while till Yd[]=Ya[]*/
   printf("\n for learning coefficient %.2f number of epoches is %d \n",lr,epoch);
   return 0;
 }
