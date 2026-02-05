//austin vu
#include <iostream>
#include <fstream>
#include <cstring> //for strcmp
using namespace std;

/************************************************************************************************************
 * read an image from a given file, the file contains data in the following format:
 *              string_representing_an_identifier
 *              int_for_image_width int_for_image_height
 *              int_for_max_pixel_value
 *              2D_array_representing_pixel_values
 *
 * parameters: 
 *              filename: a string representing the name of the file containing the image
 *              image: a 2D array that holds the pixel values
 *              col: an integer that represents the width of an image (no. of pixels per row)
 *              row: an integer that represents the height of an image (no. of pixels per col)
 *              maxVal: an integer that represents the maximum pixel value
 *              p_val: a string that represents the image identifier
 *
 * return: no return values
 ************************************************************************************************************/
void readImage(char filename[700], int image[700][700], int &col, int &row, int &maxVal, char p_val[700]){
    
    ifstream myImage;
    myImage.open(filename);
    if ( !myImage.is_open() ) {
        cout << "The file could not be opened." << endl;
    }
    
    myImage >> p_val;
    myImage >> col;
    myImage >> row;
    myImage >> maxVal;
	
	// TODO: Read contents from file into image array
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
        myImage >> image[i][j];
    }
  } 
	
	// TODO: Display the image array when the input file reading is "sample_image.pgm"
  if(strcmp(filename, "sample_image.pgm") == 0){ //strcmp compares filename with string (from C)
   for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        cout << image[i][j] << " ";
    }
   std::cout << std::endl;
  } 
  }
    
    myImage.close();
}

/***************************************************************************************************************
 * saves an image to a given file, the file should contain data in the following format:
 *              string_representing_an_identifier
 *              int_for_image_width int_for_image_height
 *              int_for_max_pixel_value
 *              2D_array_representing_pixel_values
 *
 * parameters:
 *              filename: a string representing the name of the file into which the image should be saved
 *              pepper: a 2D array that holds the pixel values of the processed image
 *              col: an integer that represents the width of an image (no. of pixels per row)
 *              row: an integer that represents the height of an image (no. of pixels per col)
 *              maxVal: an integer that represents the maximum pixel value
 *              p_val: a string that represents the image identifier
 *
 * return: no return values
 ************************************************************************************************************/
/*void saveImage(char filename[], int pepper[700][700], int col, int row, int maxVal, char p_val[]){
    
    ofstream myImage;
    myImage.open (filename);
    
    cout << "p_val is " << p_val << endl;
    cout << "col is: " << col << endl;
    cout << "row is: " << row << endl;
    cout << "maxVal is: " << maxVal << endl;
    
    myImage << p_val << endl;
    myImage << col << " " << row << endl;
    myImage << maxVal << endl;
    
     for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
            myImage << pepper[i][j] << " ";
        }
        myImage << "\n";
    }
    myImage.close();

}
*/
void sumArray(int image[700][700], int sum[][700], int row, int col){
  for(int i = 0; i < row; i++){ //tracking row
      for(int j = 0; j < col; j++){ //tracking element
        int temptotal = 0; // temp total to help with summing
          // if left does not go out of bounds (not further then element 0)
        if(j - 1 >= 0) {
           temptotal += image[i][j - 1];
        } // if right does not go out of bounds (not further then the array size)
        else if(j + 1 < col) {
           temptotal += image[i][j + 1];
        } // if up does not go out of bounds
        else if(i - 1 >= 0){
          temptotal += image[i - 1][j];
        } // if down does not go out bounds
        else if(i + 1 < row){
         temptotal += image[i + 1][j];
        } //mirror because the sides don't exist
        else{
          temptotal += image[i][j];
        }
        sum[i][j] = temptotal;
  } 
  }
  //debug print
  for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        cout << sum[i][j] << " ";
    }
   std::cout << std::endl;
  } 


}


/*void averageArray(int sum[700][700], double avg[][700], int col, int row){

}*/

/*void pepperImage(int image[700][700], double avg[][700], int col, int row){
    
}*/

int main () {
   
    char filename[700]; //added size
    int image[700][700];
    int col;
    int row;
    int maxVal;
    char p_val[700]; //added size
    int sum[700][700]; //added size
    std::cout << "What is the name of the file (include file extension too.)" << std::endl;
    std::cin >> filename;       //grab filename for future use
    // TODO: Read the image.pgm
    readImage(filename, image, col, row, maxVal, p_val);

    std::cout << std::endl; 
    // TODO: Find the sum of pixels
    sumArray(image, sum, row, col);
    
    // TODO: Find the average of pixels
    
    // TODO: Pepper the image
    
    // TODO: Save the resulting image to peppered_image.pgm
    
    return 0;
}

