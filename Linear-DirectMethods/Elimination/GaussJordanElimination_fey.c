#include<stdio.h>
int main(){
	
	int i, j, n, k, p;
	float equation[5][5], root[5][5], result[5][5], total=0;
	
	printf("The rank of your matrix: ");
	scanf("%d", &n);
	printf("Matrix elements: ");                           //an ex. for 4X4 -> 2 4 -3 1 -4 -1 6 2 1 -2 5 3 3 4 -8 4
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			scanf("%f", &equation[i][j]);
		}
	}
	for(i=0; i<n; i++){                                    //creating a new matrix for root matrix
		root[i][0]=0;
	}
	printf("Result matrix: ");                             //4X4 -> 15 -5 11 12                            
	for(i=0; i<n; i++){
		scanf("%f", &result[i][0]);
	}	
	printf("\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf(" %f x%d ", equation[i][j], j+1);
			if(j<n-1){
				printf("+");
			}
		}
		printf("= %f\n", result[i][0]);
	}
	for(i=0; i<n; i++){                                                    //row division
		result[i][0]=result[i][0]/equation[i][i];
		for(j=n-1; j>=0; j--){
			equation[i][j]=equation[i][j]/equation[i][i];			
		}				
		for(k=i+1; k<n; k++){                                              //multiply-subtract rows            
			result[k][0]=result[k][0] - result[i][0]*equation[k][i];
			for(p=n-1; p>=0; p--){
				equation[k][p]=equation[k][p] - equation[i][p]*equation[k][i];
			}
		}
	}
	printf("\n\n");
	printf("Upper matrix:\n\n");
	for(i=0; i<n; i++){                                              //Upper matris
		for(j=0; j<n; j++){
			printf("  %f   ", equation[i][j]);
		}
		printf("\n");
	}		
	for(i=n-1; i>0; i--){                                                  //Identity matrix
    	for(k=i-1; k>=0; k--){		   
		    result[k][0]=result[k][0] - result[i][0]*equation[k][i];	       
		    for(p=n-1; p>=0; p--){
	        	equation[k][p]=equation[k][p] - equation[i][p]*equation[k][i];
	    	}
	    }
	}    
	printf("\n\n");                                                     
	printf("Identity matrix:\n\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("  %f    ", equation[i][j]);
		}
		printf("\n");
	}		
	
	printf("\n\n");                                                        //result matrix
	printf("Result matrix:\n\n");
	for(i=0; i<n; i++){
		printf("  %f\n", result[i][0]);
	}
	
	printf("\n\n");
	printf("The roots:\n\n");
	for(i=0; i<n; i++){
		root[i][0]=result[i][0];
		printf(" x %d:  %f\n", i+1, root[i][0]);
	}	
}
