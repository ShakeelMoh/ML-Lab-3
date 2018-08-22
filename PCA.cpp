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
   
   cout << "PCA Algorithm\n" << endl;
   
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
   
   double xMean = 0;
   double yMean = 0;
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
   
   double xVariance;
   double xSquared;
   double yVariance;
   double ySquared;
   //Now we centre the data around mean
   //Also calculate variance
   for (int i = 0; i < xVals.size(); ++i){
      xVals[i] -= xMean;
      xVariance += xVals[i]*xVals[i];
   }
   xVariance /= 63;
   
   cout << "X Variance (January): " << xVariance << endl;
   for (int i = 0; i < yVals.size(); ++i){
      yVals[i] -= yMean;
      yVariance +=yVals[i]*yVals[i];
   }
   yVariance /= 63;
   cout << "Y Variance (July): " << yVariance << endl;
   //Compute covariance
   cout << "\nCompute the covariance\n" << endl;
   
   vector<float> covarianceSum = vector<float>(4);
   
   for (int i = 0; i < xVals.size(); ++i){
      double val1 = xVals[i]*xVals[i];
      covarianceSum[0] += val1;
      double val2 = xVals[i]*yVals[i];
      covarianceSum[1] += val2;
      covarianceSum[2] += val2;
      double val4 = yVals[i]*yVals[i];
      covarianceSum[3] += val4;   
   }
   
   //Divide covariance by 64
   covarianceSum[0] /= (xVals.size()-1);
   covarianceSum[1] /= (xVals.size()-1);
   covarianceSum[2] /= (xVals.size()-1);
   covarianceSum[3] /= (xVals.size()-1);
   
   cout << "\nJan July Variance: " << covarianceSum[1] << endl;
   
   cout << "\nCovariance matrix divided by the number of data points (64)" << endl;
   cout << "\n" << covarianceSum[0] << "  " << covarianceSum[1] << endl;
   cout << "\n" << covarianceSum[2] << "  " << covarianceSum[3] << endl;
   
   return 0;

}