//
//  main.c
//  linkedList
//
//  Created by Vincent Tomie on 9/20/17.
//  Copyright © 2017 boom. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getInverse(double **matrix1, double **tempmatrix, int rows, int cols)
{
	
	//double **tempmatrix2;
	int i, j, k;
	double multiplier;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			//tempmatrix2[i][j] == matrix1[i][j];
			if (i == j)
				tempmatrix[i][j] = 1;
		   else 
		   	tempmatrix[i][j] = 0;
		   	
		   //printf("%lf ", tempmatrix[i][j]);
		}
		//printf("\n");
	}
	
	if (rows == 1)
		return;
	//printf("\n\n");
	
	for (i = 0; i < cols; i++)
	{
		double pivot = matrix1[i][i];
		//double pivotinverse = tempmatrix[i][i];
		
		if (pivot != 1)
		{
			for (k = i; k < cols; k++)
			{
				matrix1[i][k] = matrix1[i][k]/pivot;
				//printf("row pivot is not 1, new element is %lf\n", matrix1[i][k]);
			}
			for (k = 0; k < cols; k++)
			{
				tempmatrix[i][k] = tempmatrix[i][k]/pivot;
				//printf("row pivot is not 1, new element is %lf\n\n", tempmatrix[i][k]);
			}
		}
		
		for (j = 0; j < rows; j++)
		{
			if (i != j)
			{
				if (matrix1[j][i] != 0)
				{
					multiplier = matrix1[j][i];
					//the number is not equal to 0, but does it only work for positives?
					for (k = i; k < cols; k++)
					{
						//printf("matrixjk = matrixjk - multiplier * matrixik\n");
						//printf("%lf %lf %lf\n", matrix1[j][k], multiplier, matrix1[i][k]);
						matrix1[j][k] = matrix1[j][k] - multiplier * matrix1[i][k];
						//printf("%lf\n", matrix1[j][k]);
						//this element = 5 - 5 * 1, which is pivot
						/*for (l = 0; l < rows; l++)
						{	
							for (m = 0; m < cols; m++)
							{
								printf("%lf ", matrix1[l][m]);
							}
							printf("\n");
						}
						printf("\n");*/
					}
					for (k = 0; k < cols; k++)
					{
						//printf("tempmatrixjk = tempmatrixjk - multiplier * tempmatrixik\n");
						//printf("%lf %lf %lf\n\n", tempmatrix[j][k], multiplier, tempmatrix[i][k]);			
					   tempmatrix[j][k] = tempmatrix[j][k] - multiplier * tempmatrix[i][k];
					   /*for (l = 0; l < rows; l++)
						{	
							for (m = 0; m < cols; m++)
							{
								printf("%lf ", tempmatrix[l][m]);
							}
							printf("\n");
						}
						printf("\n");*/
					}
				}
			}
		}
	}
	
	/*for (i = 0; i < rows; i++)
	{	
		for (j = 0; j < cols; j++)
		{
			printf("%lf ", matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for (i = 0; i < rows; i++)
	{	
		for (j = 0; j < cols; j++)
		{
			printf("%lf ", tempmatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	
	



}

void doTheMath(double** matrix1, double** matrix2, double** matrix3, int row1, int col2, int row2col1)
{
    double sum = 0;
    int i, j, k;
    
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            sum = 0;
            for (k = 0; k < row2col1; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
        }

    }
    
    /*for (i = 0; i < row1; i++)
    {
    	for (j = 0; j < col2; j++)
    	{
    		printf("%lf ", matrix3[i][j]);
    	}
    	printf("\n");
	 }*/
    
}

int main(int argc, const char * argv[])
{
    //printf("Hello World!\n");
    
    FILE *ptr_file = fopen(argv[1], "r");
    FILE *pt_file = fopen(argv[2], "r");
    int housepoints;
    fscanf(pt_file, "%d", &housepoints);
    //printf("%d\n", housepoints);
    
    int vectorSize;
    int matrixSize;
    int count = 0;
    int i, j;
    int row = 0, col = 0;
        
    fscanf(ptr_file, "%d", &matrixSize);
    //printf("%d\n", matrixSize);
    matrixSize++;
    col = matrixSize;
    fscanf(ptr_file, "%d", &vectorSize);
    //printf("%d\n", vectorSize);
    row = vectorSize;
    
    double **vector;
    vector = malloc(vectorSize * sizeof(*vector));
    double **weights;
    weights = malloc(col * sizeof(weights));
    double **finalPricematrix;
    finalPricematrix = malloc(housepoints * sizeof(*finalPricematrix));
    for (i = 0; i < vectorSize; i++)
    {
    	vector[i] = malloc(sizeof(*vector[i]));
    	//printf("%lf ", vector[i][0]);	
	 }
	 //printf("\nPrice vector\n");
	 
	 for (i = 0; i < col; i++)
	 {
	 	weights[i] = malloc(sizeof(*weights[i]));
	 	//printf("%lf ", weights[i][0]);
	 }
	 for (i = 0; i < housepoints; i++)
	 {
	 	finalPricematrix[i] = malloc(sizeof(*finalPricematrix[i]));
	 }
	 
	 //printf("\nWeight Vector\n");
	 //printf("\n");
    
    double **testdatamatrix;
    double **matrix1;
    double **tempmatrix;
    double **finalmatrix;
    double **transpose;
    double **transposetemp;
    double **matrix1temp;
    matrix1 = malloc(row * sizeof(*matrix1));
    matrix1temp = malloc(row * sizeof(*matrix1temp));
    tempmatrix = malloc(col * sizeof(*tempmatrix));
    finalmatrix = malloc(col * sizeof(*finalmatrix));
    transpose = malloc(col * sizeof(*transpose));
    transposetemp = malloc(col * sizeof(*transposetemp));
    testdatamatrix = malloc(housepoints * sizeof(*testdatamatrix));
    
    //printf("We have made the matrices\n");
    
    for (i = 0; i < row; i++)
    {
        matrix1[i] = malloc(matrixSize * sizeof(*matrix1[i]));
        matrix1[i][0] = 1;
        matrix1temp[i] = malloc(matrixSize * sizeof(*matrix1temp[i]));
        matrix1temp[i][0] = 1;
    }
    //printf("allocated basics\n");
    for (i = 0; i < col; i++)
    {
    	  tempmatrix[i] = malloc(col * sizeof(*tempmatrix[i]));
    	  finalmatrix[i] = malloc(col * sizeof(*finalmatrix[i]));
    	  transpose[i] = malloc(row * sizeof(*transpose[i]));
    	  transposetemp[i] = malloc(row * sizeof(*transposetemp[i]));
    }
    //printf("allocated transposes\n");
    for (i = 0; i < housepoints; i++)
    {
    	  testdatamatrix[i] = malloc(matrixSize * sizeof(*testdatamatrix[i]));
    	  testdatamatrix[i][0] = 1;
    }
    
    //printf("We have malloced the matrices\n");
    
    for(i = 0; i < housepoints; i++)
    {
        for (j = 1; j < matrixSize; j++)
        {
            fscanf(pt_file, "%lf,", &testdatamatrix[i][j]);
        }
        fscanf(pt_file, "\n");
        //printf("\n");
    }
    
    /*for(i = 0; i < housepoints; i++)
    {
        for (j = 0; j < matrixSize; j++)
        {
            printf("%lf ", testdatamatrix[i][j]);
        }
        printf("\n");
    }*/
    
    //printf("we made it this far\n");
    
    for(i = 0; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            fscanf(ptr_file, "%lf,", &matrix1[i][j]);
            //printf("%lf ", matrix1[i][j]);
            
        }
        fscanf(ptr_file, "%lf", &vector[count][0]);
        count++;
        fscanf(ptr_file, "\n");
        //printf("\n");
    }
    
    //printf("\n");
    
    for (i = 0; i < col; i++)
	{
		for (j = 0; j < col; j++)
		{
			finalmatrix[i][j] = 0;
			if (i == j)
				tempmatrix[i][j] = 1;
		   else 
		   	tempmatrix[i][j] = 0;
		   	
		   //printf("%lf ", tempmatrix[i][j]);
		}
		//printf("\n");
	}
	//printf("\n\n");
    
    /*for (i = 0; i < vectorSize; i++)
    {	
    		printf("%lf ", vector[i][0]);

	 }*/
    //printf("\n");
    //printf("\n");
    
    //printf("We are over here now\n");
    
    for (i = 0; i < row; i++)
    {
    	for (j = 0; j < col; j++)
    	{
    		//printf("%lf ", matrix1[i][j]);
    		
    		matrix1temp[i][j] = matrix1[i][j];
         //tempmatrix[i][j] = matrix1[i][j];
    		transpose[j][i] = matrix1[i][j];
    		transposetemp[j][i] = 0;
    	}
    	//printf("\n");
    }
    
    //printf("We are at the point of making the transpose\n");
    
    /*for (i = 0; i < col; i++)
    {
    	for (j = 0; j < row; j++)
    	{
    		printf("%lf ", transpose[i][j]);
		}	
		printf("\n");
    }
    printf("\n");*/
    
    
    
    
    //finalmatrix should be equivilant to the first matrix element
    doTheMath(transpose, matrix1, finalmatrix, col, col, row);
    //printf("a\n");
    getInverse(finalmatrix, tempmatrix, col, col);
    //printf("b\n");
    doTheMath(tempmatrix, transpose, transposetemp, col, row, col);
    //printf("c\n");
    doTheMath(transposetemp, vector,  weights, col, 1, row);    
    //printf("d\n");
    
    doTheMath(testdatamatrix, weights, finalPricematrix, housepoints, 1, col);
    //printf("e\n");
    
    for (i = 0; i < housepoints; i++)
    {
    	printf("%0.0lf\n", finalPricematrix[i][0]);
	 }
    
    
    
    
    for (i = 0; i < matrixSize; i++)
    {
        free(matrix1[i]);
        free(tempmatrix[i]);
        free(finalmatrix[i]);
        free(transpose[i]);
    }
    
    fclose(ptr_file);
    return 0;
}
