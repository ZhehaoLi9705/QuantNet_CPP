//
//  main.cpp
//  Exercise 1
//
//  Created by Zhehao Li on 2020/2/28.
//  Copyright © 2020 Zhehao Li. All rights reserved.
//
//  Test Point class with extra constructor

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Create two double objects to for x- and y-coordinates
    double x;
    double y;
    
    // Ask the user for x- and y-coordinates
    cout << "Please enter the x- and y-coordinates:" << endl;
    cin >> x >> y;                                                          // Pass the value of input stream to objects
    
    // Create a Point object
    Point pt;                                                               // Initialize with default constructor
    pt.SetX(x);                                                             // Reset the value of x-coordinates
    pt.SetY(y);                                                             // Reset the value of y-coordinates
    
    // Create a string object
    string str_pt;
    str_pt = pt.ToString();                                                 // Get the description of Point object pt
    
    cout << str_pt << endl;                                                 // Print the descriotion of Point object pt
    cout << "Point(" << pt.GetX() << "," << pt.GetY() << ")" << endl;       // Print the coordinates of Point object pt
    
    // Create a new Point object to test the distance function
    Point pt2(3.0, 4.0);                                                    // Initialize with two values
    
    // Test the distance function
    cout << "The distance to Origin(0,0) is: " << pt.DistanceOrigin() << endl;              // Print the distance to origin
    cout << "The distance to " << pt2.ToString() << " is: " << pt.Distance(pt2) << endl;    // Print the distance to (3, 4)
    
    return 0;
}


//  Without Copy Constructor:
//      1. Default constructor called twice;
//      2. Destructor called three times;
//
//      That is because why we call the Distance() by value, the system automatically copy the Point pt2 to create a new Point object. (we get a copy constructor for free)

//  With Copy Constructor:
//      1. Default constructor called once;
//      2. Constructor with value called once;
//      3. Copy constructor called once;
//      4. Destructor called three times;
//
//      Now the number of calls of Default + Constructor + Copy constructor = Destructor

