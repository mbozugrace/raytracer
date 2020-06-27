//
//  c_tuples.hpp
//  raytracercpp
//
//  Created by Mbozu Grace Lweendo on 6/26/20.
//  Copyright © 2020 LillysMomma. All rights reserved.
//

#ifndef c_tuples_hpp
#define c_tuples_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

/* Class Name: Tuple
 Interface for a custom Tuple Class
 */

class Tuple{
public:
    //Default constructor and destructor - creates a Tuple Object
    Tuple();
    ~Tuple();

    Tuple(double x, double y, double z, double w);
    
    //set tuple
    void set_coordinates(double x, double y, double z, double w);
    
    //convert this tuple to a point by adding 1.0
    void to_point();
    //convert this tuple to a vector by converting w to 0.0
    void to_vector();
    
    //comparison
    bool is_equal(double one, double two);
    
    
    //accessors
    Tuple *get_tuple();
    
    //operations - addition, subtraction
    Tuple add(Tuple a, Tuple b);
    Tuple sub_point(Tuple point_a, Tuple point_b);
    Tuple sub_vector(Tuple vect_a, Tuple vect_b);
    Tuple sub_vector_from_point(Tuple vect, Tuple point);
    Tuple negate(Tuple vect);
    
private:
    struct coordinates{
        double x, y, z, w;
    };
    coordinates coord;
    static constexpr double EPSILON = 0.00001;
    
};

#endif /* c_tuples_hpp */
