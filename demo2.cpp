// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image3[SIZE][SIZE][RGB];
unsigned char image4[SIZE][SIZE][RGB];

void loadImage ();
void loadImage2();
void saveImage ();
void saveImage2();
void saveImage3();
void doSomethingForImage ();
void doSomethingForImage2();
void doSomethingForImage3();
void doSomethingForImage4();
void doSomethingForImage5();
void doSomethingForImage6();
void doSomethingForImage7();
void doSomethingForImage8();
void doSomethingForImage9();
int main()

{
     cout << "Ahlan ya User Ya Habibi " <<endl;
    cout << "please choose a filter from 1 to 8 :"<<endl;
    cout << "1- RGB filter "<<endl;
    cout << "2- Invert Filter " <<endl;
    cout << "3- Merge Filter" << endl;
    cout << "4- Flip Image " << endl ;
    cout << "5- Rotate Image "<<endl;
    cout << "6- Darken and Lighten Image " <<endl ;
    cout << "7- Detect Image Edges " << endl;
    cout << "8- Enlarge Image " << endl ;
    cout << "9- Shrink Image" << endl;
    cout << "0- Exit " << endl;
    int k ;
    cin >> k;
    if (k == 1){
  loadImage();
  doSomethingForImage();
  saveImage();}
  else if (k == 2){
     loadImage();
  doSomethingForImage2();
  saveImage();
  }
  else if (k == 3){
        loadImage();
        loadImage2();
        doSomethingForImage3();
        saveImage3();


    }else if (k == 4){
        loadImage();
        doSomethingForImage4();

    }else if (k == 5){
        loadImage();
        doSomethingForImage5();

    }else if (k == 6){
        loadImage();
        doSomethingForImage6();
        saveImage();

    }else if (k == 7){
        loadImage();
        doSomethingForImage7();
        saveImage();

    }else if (k == 8){
        loadImage();
        doSomethingForImage8();

    }else if (k == 9){
        loadImage();
        doSomethingForImage9();

    }else if (k == 0){
        cout << "press any key to exit : ";
    }
    return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}

//_________________________________________
void loadImage2 ()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image2);
}
//____________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//_________________________________________
void saveImage2 ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}
//_________________________________________
void saveImage3 ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image3);
}

//_________________________________________

void doSomethingForImage() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            for(int k = 0 ; k< RGB ; k++){



// Example code to invert the image

        if (image[i][j][k] > 127)
            image[i][j][k] = 255;
        else
            image[i][j][k] = 0;

// do something with the image
    }}
  }
}
//_____________________________________________
void doSomethingForImage2(){

     for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        { for(int k = 0 ; k< RGB ; k++){
            for(int k = 0 ; k< RGB ; k++){


image[i][j][k] = 255 - image[i][j][k] ;


        }
    }
}}}
//________________________________________________
void doSomethingForImage3()
{
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j< SIZE; j++)
        {
             for(int k = 0 ; k< RGB ; k++){

            image3[i][j][k]=(image[i][j][k] + image2[i][j][k] ) / 2 ;

             }


}        }


    }


//_________________________________________
void doSomethingForImage4()
{
    cout << "choose 1 to mirror or 2 to vertically :"<<endl ;
    cout << "1- mirror  "<< endl;
    cout << "2- vertically  " << endl;
    int g ;
    cin>> g ;
    if (g == 1){
        for (int i = 0 ; i < SIZE ; i++){
            for (int j = 0 ; j < SIZE/2 ; j++){
                     for(int k = 0 ; k< RGB ; k++){

                swap(image[i][j][k] , image[i][SIZE - j][k]);
            }
        }}
    saveImage();
    }
    if (g == 2){
        for (int j = 0 ; j < SIZE ; j++){
            for (int i = 0 ; i < (SIZE) ; i++){
                     for(int k = 0 ; k< RGB ; k++){

                image2[j][i][k]=image[SIZE - j][i][k];
            }
            }}
    saveImage2();
    }
}

//_________________________________________
void doSomethingForImage5(){
    cout << "choose rotate 90 or 180 or 270 :"<< endl ;
    cout << " 1- rotate 90 "<<endl;
    cout << " 2- rotate 180"<<endl;
    cout << " 3- rotate 270"<<endl;
    int d ;
    cin >> d ;
      if (d == 1){
        for (int i = 0 ; i < SIZE ; i++){
            for (int j = 0 ; j < SIZE ; j++){
                     for(int k = 0 ; k< RGB ; k++){

                image2[i][j][k]=image[SIZE - j][i][k];
            }
        }
        }
       saveImage2();
      }
      else if (d == 2){
             for(int k = 0 ; k< RGB ; k++){

        for (int j = 0 ; j < SIZE ; j++){
            for (int i = 0 ; i < SIZE ; i++){
                image2[i][j][k]=image[SIZE - i][SIZE - j][k];
                }
        }}

        saveImage2();
        }


    else if (d == 3){
        for (int i = 0 ; i < SIZE ; i++){
            for (int j = 0 ; j < SIZE ; j++){
                     for(int k = 0 ; k< RGB ; k++){

                image2[j][i][k]=image [i][SIZE - j][k];
            }
 }       }
    saveImage2();
    }
}

//_________________________________________
void doSomethingForImage6(){
    cout << " choose 1 to lighten or 2 to darken : "<< endl;
    cout << "1- Lighten " << endl;
    cout << "2- Darken  " << endl;
    int q ;
    cin >> q ;
    if (q==1){
        for (int i = 0 ; i < SIZE ; i++){
            for (int j = 0 ; j < SIZE ; j++){
                     for(int k = 0 ; k< RGB ; k++){

                image[i][j][k]= image[i][j][k] + ((255 - image[i][j][k]) / 2 );

        }
    }
    }}
    else if (q==2){
        for (int i = 0 ; i < SIZE ; i++){
            for (int j = 0 ; j < SIZE ; j++){
                     for(int k = 0 ; k< RGB ; k++){

                image[i][j][k]= image[i][j][k] - ((image[i][j][k]) / 2 );

        }
    }
    }
}}

//_________________________________________
void doSomethingForImage7(){
    for (int i = 0 ; i< SIZE - 1  ; i++){
        for (int j = 0 ; j < SIZE ; j++){
                 for(int k = 0 ; k< RGB ; k++){

            if (   abs(image[i][j][k] - image[i][j+1][k])  >=50 ||   abs(image[i][j][k]- image[i+1][j][k])   >=50       ){
                 image[i][j][k] = 0 ;

            }
            else
                image[i][j][k] = 255 ;
            }

            }

}}

//_________________________________________
void doSomethingForImage8(){
    cout << "choose from part 1 to part 4 :" <<endl;
    cout << "1- part 1 : "<<endl;
    cout << "2- part 2 : " <<endl;
    cout << "3- part 3 : "<<endl;
    cout << "4- part 4 : "<<endl;
    int z ;
    cin >> z ;
    if (z == 1){
        int x = 0 ;
        for (int i = 0 ; i< SIZE/2   ; i++){
        int y = 0 ;
            for (int j = 0 ; j < SIZE/2 ; j++ ){
        int q = 0 ;
                 for(int k = 0 ; k< RGB ; k++){

                image2[x][y][q] = image[i][j][k];
                image2[x][y+1][q] = image[i][j][k];
                image2[x+1][y][q]= image[i][j][k];
                image2[x+1][y+1][q] = image[i][j][k];
                y = y + 2 ;
            }
        x = x + 2 ;
        }}
    saveImage2();

    }
    else if (z == 2){
        int x = 0 ;
        for (int i = 0 ; i< SIZE/2   ; i++){
            int y = 0 ;
            for (int j = SIZE/2 ; j < SIZE ; j++ ){
                    int q = 0;
             for(int k = 0 ; k< RGB ; k++){

                image2[x][y][q] = image[i][j][k];
                image2[x][y+1][q] = image[i][j][k];
                image2[x+1][y][q] = image[i][j][k];
                image2[x+1][y+1][q] = image[i][j][k];
                y = y + 2 ;
            }
        x = x + 2 ;
        }}
    saveImage2();
    }
    else if (z == 3){
        int x = 0 ;
        for (int i = SIZE/2 ; i< SIZE   ; i++){
            int y = 0 ;
            for (int j = 0 ; j < SIZE/2 ; j++ ){
            int q = 0 ;
             for(int k = 0 ; k< RGB ; k++){

                image2[x][y][q] = image[i][j][k];
                image2[x][y+1][q] = image[i][j][k];
                image2[x+1][y][q] = image[i][j][k];
                image2[x+1][y+1][q] = image[i][j][k];
                y = y + 2 ;
            }
        x = x + 2 ;
        }}

    saveImage2();
    }
    else if (z == 4){
        int x = 0 ;
        for (int i = SIZE/2 ; i< SIZE   ; i++){
            int y = 0 ;
            for (int j = SIZE/2 ; j < SIZE ; j++ ){
                    int q = 0 ;
             for(int k = 0 ; k< RGB ; k++){

                image2[x][y][q] = image[i][j][k];
                image2[x][y+1][q] = image[i][j][k];
                image2[x+1][y][q] = image[i][j][k];
                image2[x+1][y+1][q] = image[i][j][k];
                y = y + 2 ;
            }
        x = x + 2 ;
        }}

    saveImage2();
    }
}

//_________________________________________
void doSomethingForImage9()
{
    int m;
    cout<<"choose from 1 or 2 or 3 to shrink :"<<endl;
    cout<<"1- shrink 1/2 "<<endl;
    cout<<"2- shrink 1/3 "<<endl;
    cout<<"3- shrink 1/4 "<<endl;
    cin>>m;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        { for(int k = 0 ; k< RGB ; k++){

            if(m==1){
            image[i/2][j/2][k]=image[i][j][k];//1/2
            image[i][j][k]=255;
            }
            else if(m==2){
            image[i/3][j/3][k]=image[i][j][k]; //1/3
            image[i][j][k]=255;
            }
            else if(m==3){
            image[i/4][j/4][k]=image[i][j][k];  //1/4
            image[i][j][k]=255;
            }
        }
    }}
    saveImage();

}
