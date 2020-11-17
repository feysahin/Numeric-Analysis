#include<stdio.h>
int main(){
	
	int i, j, n, k, p, say, s, a=0, m;
	float A[5][5], X[5][5], Y[5][5], result[5][5], upper[5][5], lower[5][5], total=0;
	
	printf("The rank of matrix: ");
	scanf("%d", &n);
	printf("The elements: ");              //an example for 3X3 -> 3.6 2.4 -1.8 4.2 -5.8 2.1 0.8 3.5 6.5
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f", &A[i][j]);
		}
	}
	for(i=0; i<n; i++){                    //upper matrix		
		for(j=0; j<n; j++){
			if(i==j){
				upper[i][j]=1;
			}
			else{
			    upper[i][j]=0;
			}
		}
	}
	for(i=0; i<n; i++){                    //lower matrix
		for(j=0; j<n; j++){
			lower[i][j]=0;
		}
	}	
	for(i=0; i<n; i++){                    //X matrix
		X[i][0]=0;
	}
	for(i=0; i<n; i++){                    //Y matrix
		Y[i][0]=0;
	}	
	printf("Result matrix: ");             //y for 3X3->6.3 7.5 3.7
	for(i=0; i<n; i++){
		scanf("%f", &result[i][0]);
	}	
    printf("\nYour Equations:\n");
	for(i=0; i<n; i++){                                    //printing the equations
		for(j=0; j<n; j++){
			printf(" %f x%d ", A[i][j], j+1);
			if(j<n-1){
				printf("+");
			}
		}
		printf("= %f\n", result[i][0]);
	}
	for(i=0; i<n; i++){	                                              //i  the row number of Upper
	    say=a;                                                        //say  not to create the Upper elements above again
		a=0;	                                                      
		s=0;                                                          //s  the colomn number which is going to be used for Upper
		for(j=i; j<n; j++){	                                          //j  the raw number of Lower
		    if(i!=0){                                                 //a  not to evaluate the first colomn of Upper
		    	if(a==0){                                             //to prevent the Upper elements be formed again after j increases (except beginning)
		    	    for(m=0; m<say+1; m++){	                          //say+1: the # of elements which is going to be in Upper
				   	    total=A[m][i];	                              //equation to the element in A
					    for(k=0; k<i; k++){						      //k  the colomns of Lower
						    total=total-lower[s][k]*upper[k][i];	  //matrix multiplication
					    }					
				        upper[s][i]=total/lower[s][s];
					    a++;
					    s++;                                          
				    }
				}
			}		    
			total=A[j][i];
			for(p=0; p<n; p++){
				total=total-lower[j][p]*upper[p][i];						    
			}			
			lower[j][i]=total;    		
		}
	}	
	for(i=0; i<n; i++){                                        //counting Y with Lower and sonuc matrix
		total=result[i][0];
		for(j=0; j<i; j++){			
			total=total-lower[i][j]*Y[j][0];
		}
		Y[i][0]=total/lower[i][i];
	}
	
	for(i=n-1; i>=0; i--){                                     //counting X with Upper and Y matrix
		total=Y[i][0];
		for(j=n-1; j>i; j--){			
			total=total-upper[i][j]*X[j][0];
		}
		X[i][0]=total;
	}
		
	printf("\n\n");
	printf("Lower matrix:\n\n");                               //printing Lower
	for(i=0; i<n; i++){                                              
		for(j=0; j<n; j++){
			printf("  %f   ", lower[i][j]);
		}
		printf("\n");
	}		
	printf("\n\n");
	printf("Upper matrix:\n\n");                               //printing Upper
	for(i=0; i<n; i++){                                              
		for(j=0; j<n; j++){
			printf("  %f   ", upper[i][j]);
		}
		printf("\n");
	}	
	printf("\n\n");                                                  
	printf("Y matrix:\n\n");                                   //printing Y
	for(i=0; i<n; i++){
		printf("y %d: %f\n", i+1, Y[i][0]);
	}
	printf("\n\n");                                                  
	printf("The Roots (X matrix):\n\n");                       //printing X
	for(i=0; i<n; i++){
		printf("x %d: %f\n", i+1, X[i][0]);
	}
}
