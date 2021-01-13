/*This program allocates memory for a vector,integer vector & mxn matrix*/
   /*  prototypes */
   float *vecalloc(int n);
   int *vecint_alloc(int n);
   float **matalloc(int m,int n);


/* program for allocation of memory space for an n vector */
float *vecalloc(int n)
{
  float *x;
  x=(float*)calloc(n,sizeof(float)) ;
  if (x==NULL)
  {  fprintf(stderr,"unable to allocate memory");
	 exit(1);
  }return (x-1);
}


   /* program for allocation of mem space with integer return */


    int *vecint_alloc(int n)
   {
   int *v;
	v=(int *) calloc(n,sizeof(int));
	if (v==NULL) {
	  fprintf(stderr,"could not allocate memory");
	  exit (1);
	  }
	  return (v-1);
	}



/* program for allocation of memory space for an mxn matrix */


float **matalloc(int m, int n)
{
   float **a;
   int i;
   a=(float **)calloc(m,sizeof(float*));
   if (a==NULL)
   {  fprintf(stderr,"could not allocate row memory");
	  exit (1);
   }
   a-=1;
   for (i=1;i<=m;i++)
   {  a[i]=(float *) calloc(n,sizeof(float));
   if (a[i]==NULL)
   {
   fprintf(stderr,"could not allocate column memory");
	  exit (1);
   }
   a[i]-=1;
   }
   return a;
}
