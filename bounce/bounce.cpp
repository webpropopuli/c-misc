#include <stdio.h>
#include <stdlib.h>

int deBounce(double, double, double);
#define  calcBounce(rate, height) rate*height

//input: bounce rate, kid height, mom height
int main(int argc, char **argv )
{
  int rc = 0;
  if(argc < 4) {
    printf("Pass in bounce rate, kid height and mom height");
    return -1;
  }

  double rateBounce = atof(argv[1]);
  double htKid = atof(argv[2]);
  double htMom = atof(argv[3]);

rc = deBounce(rateBounce, htKid, htMom);
printf("Mom saw the ball %d times\n", rc);
return rc;
}


/********for Cliff**********************/
int deBounce(double rateBounce, double htKid, double htMom) {
 // Validate params
  if (htKid <= 0 || rateBounce >= 1 || rateBounce <= 0 || htMom >= htKid)
  {
    printf("Initial conditions violated. Mom says 'no cookie for you'.");
    return -1;
  }
  printf("Kid is at %.02f, Mom is at %.02f\n", htKid, htMom);

  int seen = 1;  // as long as kid > mom, always seen on the 1st drop. Unless Mom watching TV

  double htBounce = calcBounce(rateBounce, htKid);
  printf("bounce to %.02f\n", htBounce );

// if bounce higher than mom...
while(htBounce > htMom)
  {
    seen +=2;
    htBounce = calcBounce(rateBounce, htBounce);
     printf("bounce to %.02f\n", htBounce );
  }

return seen;
}