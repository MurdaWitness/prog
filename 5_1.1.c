float count(float);
float count (float n)
{
	float root = 0, int current = n;
	root = sqrt (n)
	return root;
}

int square(int n){
  float sqrt_n=sqrt(n), ost=sqrt_n-floor(sqrt_n);
  float epsilon=0.00000001;
  if ((ost<epsilon) || (1-ost<epsilon))
    return 1;
  else
    return 0;
}