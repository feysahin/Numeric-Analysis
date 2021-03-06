#include<stdio.h>
#include<math.h>
int main(){
	
	int i, j, n, say=0, control=0;
	float result[5][5], eps, total2=0;
	double root[5][5], total[5], equation[5][5];
	
	printf("The rank of your matrix: ");
	scanf("%d", &n);
	
	printf("Matrix elements: ");                             //an ex. for 3X3 -> 3 1 -2 -1 4 -3 1 -1 4 
	while(control!=3){                                       //convergence controller
		control=0;
	    for(i=0; i<n; i++){
		    for(j=0; j<n; j++){
			    scanf("%lf", &equation[i][j]);
		    }
	    }
	    for(i=0; i<n; i++){
	    	for(j=0; j<n; j++){
	    		if(i!=j){
	    			total2=total2+fabs(equation[i][j]);
				}
			}
			if(equation[i][i]>=total2){
				control++;
			}	
			total2=0;			
		}
		if(control!=3){
			printf("The result might not converge. Enter the equations again in different order, please: ");
		}
	}	
	
	printf("The first iteration values: ");
	for(i=0; i<n; i++){                                        //roots 
		scanf("%lf", &root[i][0]);
	}
	
	printf("Epsilon: ");                                       //epsilon
	scanf("%f", &eps);                                         
	
	printf("Result matrix: ");                                  //3X3 ->  9 -8 1                          
	for(i=0; i<n; i++){
		scanf("%f", &result[i][0]);
	}	
	printf("\n");
	for(i=0; i<n; i++){                                        //printing the equations
		for(j=0; j<n; j++){
			printf(" %f x%d ", equation[i][j], j+1);
			if(j<n-1){
				printf("+");
			}
		}
		printf("= %f\n", result[i][0]);
	}
	for(i=0; i<n; i++){                                        //recreating the first equations and 2nd values
		total[i]=result[i][0];
		for(j=0; j<n; j++){
			if(i!=j){
				total[i]=total[i]-equation[i][j]*root[j][0];
			} 
		}
		total[i]=total[i]/equation[i][i];
	}
	
	while(say<n){                                              
		say=0;
		for(i=0; i<n; i++){                                    //control of whole differences
	    	if(fabs(total[i]-root[i][0])<eps){
		    	say++;
		    }
	    }
	    if(say<n){                                             //not to change the values when say=n
	    	for(i=0; i<n; i++){
			    root[i][0]=total[i];                           //total array is for every unknown values
		    }
		    for(i=0; i<n; i++){
		        total[i]=result[i][0];
		        for(j=0; j<n; j++){
			        if(i!=j){
				        total[i]=total[i]-equation[i][j]*root[j][0];     //element-wise multiplication (except the same coefficients)  
			        }                                                    
	    	    }
		        total[i]=total[i]/equation[i][i];
	        }
		}	
	}
	printf("\n\n");
	printf("Roots:\n\n");
	for(i=0; i<n; i++){
		printf("Approximately root x%d: %lf\n", i+1, total[i]);
	}	
} 
