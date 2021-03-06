/* PLEASE DO NOT MODIFY A SINGLE STATEMENT IN THE TEXT BELOW.
READ THE FOLLOWING CAREFULLY AND FILL IN THE GAPS

I hereby declare that all the work that was required to 
solve the following problem including designing the algorithms
and writing the code below, is solely my own and that I received
no help in creating this solution and I have not discussed my solution 
with anybody. I affirm that I have read and understood
the Senate Policy on Academic honesty at 
https://secretariat-policies.info.yorku.ca/policies/academic-honesty-senate-policy-on/
and I am well aware of the seriousness of the matter and the penalties that I will face as a 
result of committing plagiarism in this assignment.

BY FILLING THE GAPS,YOU ARE SIGNING THE ABOVE STATEMENTS.

Full Name: Laura Toro
Student Number: 26650236
Course Section: Software Tools 2031
*/

#include<stdio.h>
#include <stdbool.h> 
#include<stdlib.h>
#define IMAGE_SIZE 10


// this function prints the array
void printImgArray(int array[IMAGE_SIZE][IMAGE_SIZE])
{
  
    printf("------ Image Contents -------\n");
    for (int i=0; i<IMAGE_SIZE; i++)
    {
    for (int j=0; j<IMAGE_SIZE; j++)
        printf("%2d, ",array[i][j]);
    printf("\n");
    }
    printf("-----------------------------\n");
}

/**
 * This function counts the number of distinct 
 * number (i.e. the number of cells)
 **/

int cellCount(int image[IMAGE_SIZE][IMAGE_SIZE]){
    
int max = 0; 

for (int i=0; i<IMAGE_SIZE; i++)
    {
    for (int j=0; j<IMAGE_SIZE; j++)
        if (max < image[i][j]){
            max = image[i][j];
        }
    }

    return max;
}
/**
 * This function colors each cell with a unique color
 * (i.e. unique number)
 **/

//offset to check surrounding 8 elements
int offsets[3] = {-1, 0, 1};

//checks if 8 surrounding neighbours are in range, and not visited
int checkForNeighbours(int image[][IMAGE_SIZE], int i, int j, int visited[][IMAGE_SIZE]){

if( (i >= 0) && (i < IMAGE_SIZE) && (j >= 0) && (j < IMAGE_SIZE) && (image[i][j] && (visited[i][j] == 0)) ){
    return 1;
} 
return 0;
}

void searchNeighbours(int image[][IMAGE_SIZE], int i, int j, int visited[][IMAGE_SIZE], int count){
  
     if (visited[i][j] == 0){
        visited[i][j] = 1;
     }
image[i][j] = count;
    
      int xOffset, yOffset;
      for (int l = 0; l < 4; ++l){
	        xOffset = offsets[l];
	        for (int m = 0; m < 4; ++m){
	                yOffset = offsets[m];

                         if (xOffset == 0 && yOffset == 0){
                        continue;
                         } else if (checkForNeighbours(image, i + xOffset, j + yOffset, visited) == 1 ){
                             
                        searchNeighbours(image, i + xOffset, j + yOffset, visited, count);
                        
                        }
             }
        }
}

void color(int image[IMAGE_SIZE][IMAGE_SIZE]){

//matrix which keeps track of visited elements
int visited[IMAGE_SIZE][IMAGE_SIZE]={{0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},
		               {0,0,0,0,0,0,0,0,0,0}};
int count = 0;
 for (int i=0; i<IMAGE_SIZE; i++)
    {
        for (int j=0; j<IMAGE_SIZE; j++){
       
        if (image[i][j] == 1 && visited[i][j] == 0){
        
        ++count; 
        
        searchNeighbours(image, i, j, visited, count);
        
        }   
    }
    }

}

/**
 * This function colors each cell with a unique color
 * (i.e., unique number). This function works with 
 * pointers
 * currentRow: shows the current row that is processed
 * currentCol: shows the current column that is process
 * currentIndex: show the index that is processed
 * color: is an integer that represents a color
 **/

int colorRecursively(int image[IMAGE_SIZE][IMAGE_SIZE], int currentRow, int currentCol, int currentIndex, int color) {
    // insert your code for task 2.1 here, in case you decided to complete this task
    // you may want to change the return value
    return 0;
 
}
void colorPtr(int* image){
    

int visited[IMAGE_SIZE][IMAGE_SIZE]={{0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},\
		               {0,0,0,0,0,0,0,0,0,0},
		               {0,0,0,0,0,0,0,0,0,0}};
int count = 0;

 for (int i=0; i<IMAGE_SIZE; i++)
    {
        for (int j=0; j<IMAGE_SIZE; j++){
       
        if (*(image+ (i * IMAGE_SIZE) + j) == 1 && visited[i][j] == 0){
        
        ++count; 
        
        searchNeighbours(image, i, j, visited, count);
        
        }
        
        
        
        }
    }


}




#ifndef __testing
int main(){

    // DO not change anything in main(), it will confuse the
    // auto-checker.  
    puts("testing the code with color() function");
    int count = 0;
    int cellImg[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    printImgArray(cellImg);
    color(cellImg);
    printImgArray(cellImg);
    count=cellCount(cellImg);
    printf("Total number of cells in the image: %d\n",count);
 

    puts("Testing the code with colorPtr");
    int cellImg_[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};

    int* ptr = cellImg_;
    printImgArray(ptr);
    colorPtr(ptr);
    printImgArray(ptr);
    count=cellCount(ptr);
    printf("Total number of cells in the image: %d\n",count); 
    puts("Testing the code with colorRecursively");
    int cellImg__[IMAGE_SIZE][IMAGE_SIZE]={{0,0,1,1,0,0,1,0,0,1},\
		               {1,0,1,1,0,0,1,1,0,1},\
		               {1,0,0,1,1,0,1,1,0,1},\
		               {1,1,0,0,0,0,0,0,0,0},\
		               {1,0,0,1,1,1,0,0,1,0},\
		               {0,0,0,0,1,0,0,1,1,0},\
		               {0,0,1,0,0,1,0,1,0,0},\
		               {0,0,1,1,0,0,1,0,0,0},\
		               {0,0,1,0,0,0,0,0,1,1},
		               {0,1,1,0,0,0,1,1,1,1}};
    printImgArray(cellImg__);
    colorRecursively(cellImg__, 0, 0, 1, 0);
    printImgArray(cellImg__);
    count=cellCount(cellImg__);
    printf("Total number of cells in the image: %d\n",count);
    return 0;
}


#endif