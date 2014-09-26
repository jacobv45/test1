#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

main(int argc, char* argv)
{
   int n1=100,n2=10000,n3=1000000;      //number of iterations we will use
   double x1,y1,x2,y2,x3,y3;            //pairs used for points in the unit square
   int i,count1=0,count2=0,count3=0;    //i, for looping. count number of hits in the circle
   double z;                            //length of x,y pair
   double pi1,pi2,pi3;                  //final estimate of pi for each

   srand((unsigned)time(NULL));         //seed random numbers with time

   for ( i=0; i<n1; i++) {              //100 iterations of generating points, calculating
      x1 = (double)rand()/RAND_MAX;     //length and counting if less than one
      y1 = (double)rand()/RAND_MAX;
      z = x1*x1+y1*y1;
      if (z<=1) count1++;
      }
   pi1=(double)count1/n1*4;

      for ( i=0; i<n2; i++) {           //again for 10,000 iterations
      x2 = (double)rand()/RAND_MAX;
      y2 = (double)rand()/RAND_MAX;
      z = x2*x2+y2*y2;
      if (z<=1) count2++;
      }
   pi2=(double)count2/n2*4;

      for ( i=0; i<n3; i++) {           //again for 1,000,000 iterations
      x3 = (double)rand()/RAND_MAX;
      y3 = (double)rand()/RAND_MAX;
      z = x3*x3+y3*y3;
      if (z<=1) count3++;
      }
   pi3=(double)count3/n3*4;


   printf("# of trials= %d , estimate of pi is %g \\n",n1,pi1);
   printf("# of trials= %d , estimate of pi is %g \\n",n2,pi2);
   printf("# of trials= %d , estimate of pi is %g \\n",n3,pi3);

   //printing out the results
   }
