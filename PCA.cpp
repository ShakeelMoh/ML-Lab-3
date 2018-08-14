//PCA ALGORITHM
//SHAKEEL MOHAMED

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main (int argc, char *argv[]) {
   
   cout << "PCA Algorithm" << endl;
   
   //All the points
   ifstream dataPoints;
   dataPoints.open("dataPoints.txt");
   
   vector<float> points = vector<float>();
   
   string dataPoint;

   //Read from text file;
   while (getline(dataPoints, dataPoint)){
      istringstream iss(dataPoint);
      float xVal;
      iss >> xVal;
      float yVal;
      iss >> yVal;
      //cout << "XVAL: " << xVal << "YVALL " << yVal << endl;
      
      points.push_back(xVal);
      points.push_back(yVal);
      
   }
   //reverse(points.begin(), points.end());
   
   points.pop_back();
   points.pop_back();
   /*
   for (int i = 0; i < points.size(); ++i){
      cout << points[i] << endl;
   }
   */
   
   vector<float> xVals = vector<float>();
   vector<float> yVals = vector<float>();
   
   //Calculate mean x and y
   for (int i = 0; i < points.size(); i++){
      xVals.push_back(points[i]);
      yVals.push_back(points[i+1]);
      i++;
   }
   
   int xMean = 0;
   int yMean = 0;
   for (int i = 0; i < xVals.size(); ++i){
      xMean += xVals[i];
   }
  
   xMean = xMean/xVals.size();
   for (int i = 0; i < yVals.size(); ++i){
      yMean += yVals[i];
   }
   yMean = yMean/yVals.size();
   cout << "X mean: " << xMean << endl;
   cout << "Y mean: " << yMean << endl;
   
   //Now we centre the data around mean
   for (int i = 0; i < xVals.size(); ++i){
      xVals[i] -= xMean;
   }
   for (int i = 0; i < yVals.size(); ++i){
      yVals[i] -= yMean;
   }
   
   
   
   return 0;

}