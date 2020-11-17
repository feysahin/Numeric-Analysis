#include<stdio.h>
int main(){
	int  i, j, a, b, p, k=1, m=0, n, say=0, neg=1;
	float arr[5][5], arr2[5][5], result[5][5], total, tmp[10], det[5], determinant=0, product;
	
	printf("The rank of matrix: ");
	scanf("%d", &n);
	if(n==3){                                           //an ex. for 3X3: 2 -3 3 1 1 -2 3 -2 -1
		printf("Enter the matrix:");	                   
	    for(i=0; i<3; i++){
		    for(j=0; j<3; j++){
			    scanf("%f", &arr[i][j]);
	    	}
    	}	
	    printf("result matrisi girin: ");
    	for(i=0; i<3; i++){		
	    	scanf("%f", &result[i][0]);
	    }
	    printf("\n");
	    for(i=0; i<3; i++){
		    printf("%fx + %fy + %fz = %f\n", arr[i][0], arr[i][1], arr[i][2], result[i][0]);
	    }	
    	for(j=0; j<3; j++){                                                                       //counting the determinant of arr matrix
	    	if(j==0){
		    	total=arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1]);
		    }
		    else if(j==1){
			    total=total - arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0]);
	    	}
		    else{
			    total=total + arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
		    }
	    }
	    printf("\nDeterminant: %f\n\n", total);
	    
	    for(j=0; j<3; j++){                                                                         
		    for(i=0; i<3; i++){                                                                    //placement of the result matrix on the arr matrix respectively
			    tmp[i]=arr[i][j];                                                                  //storing the result matrix in a new matrix to use it back
			    arr[i][j]=result[i][0];
		    }
		    for(i=0; i<3; i++){                                                                    //counting determinant
		        if(i==0){
			        det[k]=arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1]);
		        }
		        else if(i==1){
			        det[k]=det[k] + (-1)*arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0]);
	    	    }
		        else{
			        det[k]=det[k] + arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
		        }
	        }
	        printf("Determinant %d: %f\n", k, det[k]);

	        for(i=0; i<3; i++){
			    arr[i][j]=tmp[i];                                                                  //storing 'the arr' back
		    }	    
		    k++;
	    }    	
	    printf("\nx: %f\n", det[1]/total);
	    printf("y: %f\n", det[2]/total);
	    printf("z: %f\n", det[3]/total);
	}	
	
	else if(n==4){                                           //an ex. for 4X4: 2 4 -3 1 -4 -1 6 2 1 -2 5 3 3 4 -8 4
		printf("Enter the matrix:");	                       
	    for(i=0; i<4; i++){
		    for(j=0; j<4; j++){
			    scanf("%f", &arr[i][j]);
	    	}
    	}	
	    printf("Enter the result matrix: ");
    	for(i=0; i<4; i++){		
	    	scanf("%f", &result[i][0]);
	    }
	    printf("\n");
	    for(i=0; i<4; i++){
		    printf("%fx + %fy + %fz %ft = %f\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], result[i][0]);
	    }
		for(i=0; i<n; i++){                                  //holding the first elements of the colomns in every turn  i->colomn number
			product=arr[0][i];			
			for(j=1; j<n; j++){                                                               // j->row number
				say=0;                                                                        // say->the colomn of the new matrix
				for(k=0; k<n; k++){                          //creating a new matrix
					if(k!=i){
						arr2[j-1][say]=arr[j][k];
						say++;
					}
				}
			}			
		    for(p=0; p<3; p++){                                                                //counting the determinant of arr matrix
		        if(p==0){
			        total=arr2[0][0]*(arr2[1][1]*arr2[2][2]-arr2[1][2]*arr2[2][1]);
		        }
		        else if(p==1){
			        total=total - arr2[0][1]*(arr2[1][0]*arr2[2][2]-arr2[1][2]*arr2[2][0]);
	    	    }
		        else{
			        total=total + arr2[0][2]*(arr2[1][0]*arr2[2][1]-arr2[1][1]*arr2[2][0]);
		        }
	        }
	        determinant=determinant+neg*product*total;
	        neg=(-1)*neg;
		}
		printf("\n\nDeterminant: %f\n\n", determinant);
		
		for(a=0; a<4; a++){         //storing the 4 determinants for 4X4 matrix                 
			det[a]=0;
		}
		for(a=0; a<4; a++){                                      //determinant x y z t 
			for(b=0; b<4; b++){
			    tmp[b]=arr[b][a];
			    arr[b][a]=result[b][0];
		    }
		    for(i=0; i<n; i++){
			    product=arr[0][i];
			    for(j=1; j<n; j++){
			    	say=0;
				    for(k=0; k<n; k++){                          //creating a new matrix
    					if(k!=i){
	    					arr2[j-1][say]=arr[j][k];
		    				say++;
			    		}
				    }
		    	}			
		        for(p=0; p<3; p++){
		            if(p==0){
			            total=arr2[0][0]*(arr2[1][1]*arr2[2][2]-arr2[1][2]*arr2[2][1]);
		            }
		            else if(p==1){
			            total=total - arr2[0][1]*(arr2[1][0]*arr2[2][2]-arr2[1][2]*arr2[2][0]);
	    	        }
		            else{
			            total=total + arr2[0][2]*(arr2[1][0]*arr2[2][1]-arr2[1][1]*arr2[2][0]);
		            }
	            }
	            det[m]=det[m]+neg*product*total;
	            neg=(-1)*neg;	            
		    }
			m++;
		    for(b=0; b<4; b++){
			    arr[b][a]=tmp[b];
		    }
		}
		printf("x : %f\n", det[0]/determinant);
	    printf("y : %f\n", det[1]/determinant);
		printf("z : %f\n", det[2]/determinant);
		printf("t : %f\n", det[3]/determinant);
	}   
}
