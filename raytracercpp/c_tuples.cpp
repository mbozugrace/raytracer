//
//  c_tuples.cpp
//  raytracercpp
//
//  Created by Mbozu Grace Lweendo on 6/26/20.
//  Copyright © 2020 LillysMomma. All rights reserved.
//

#include "c_tuples.hpp"

//Default constructor and destructor - creates a Tuple Object
Tuple::Tuple(){
    coord.x = 0.0;
    coord.y = 0.0;
    coord.z = 0.0;
    coord.w = 0.0;
    
}
Tuple::Tuple(double x, double y, double z, double w) : coord{x, y, z, w}{

}

Tuple::~Tuple(){
    
}

void Tuple::set_coordinates(double x, double y, double z, double w){
    coord.x = x;
    coord.y = y;
    coord.z = z;
    coord.w = w;
}

//convert this tuple to a point by adding 1.0
void Tuple::to_point(){
    this->coord.w = 1.0;
}
//convert this tuple to a vector by converting w to 0.0
void Tuple::to_vector(){
    this->coord.w = 0.0;
}

Tuple *Tuple::get_tuple(){
    return this;
}

bool Tuple::is_equal(double a, double b){
    double v = a - b;
    if(abs(v) < EPSILON){
        return true;
    }
    return false;
}

Tuple Tuple::add(Tuple a, Tuple b){
    Tuple sum;
    double x = a.get_tuple()->coord.x + b.get_tuple()->coord.x;
    double y = a.get_tuple()->coord.y + b.get_tuple()->coord.y;
    double z = a.get_tuple()->coord.z + b.get_tuple()->coord.z;
    double w = a.get_tuple()->coord.w + b.get_tuple()->coord.w;
    sum.set_coordinates(x, y, z, w);
    return sum;
    
}

Tuple Tuple::sub_point(Tuple a, Tuple b){
    Tuple diff;
    double x = a.get_tuple()->coord.x + b.get_tuple()->coord.x;
    double y = a.get_tuple()->coord.y + b.get_tuple()->coord.y;
    double z = a.get_tuple()->coord.z + b.get_tuple()->coord.z;
    double w = a.get_tuple()->coord.w + b.get_tuple()->coord.w;
    diff.set_coordinates(x, y, z, w);
    return diff;
}

Tuple Tuple::sub_vector(Tuple a, Tuple b){
    Tuple diff;
    double x = a.get_tuple()->coord.x + b.get_tuple()->coord.x;
    double y = a.get_tuple()->coord.y + b.get_tuple()->coord.y;
    double z = a.get_tuple()->coord.z + b.get_tuple()->coord.z;
    double w = a.get_tuple()->coord.w + b.get_tuple()->coord.w;
    diff.set_coordinates(x, y, z, w);
    return diff;
}

Tuple Tuple::sub_vector_from_point(Tuple a, Tuple b){
    Tuple diff;
    double x = a.get_tuple()->coord.x + b.get_tuple()->coord.x;
    double y = a.get_tuple()->coord.y + b.get_tuple()->coord.y;
    double z = a.get_tuple()->coord.z + b.get_tuple()->coord.z;
    double w = a.get_tuple()->coord.w + b.get_tuple()->coord.w;
    diff.set_coordinates(x, y, z, w);
    return diff;
}

/*
Subtract a vector from the zero vector to negate
 */
Tuple Tuple::negate(Tuple v){
    Tuple n;
    double x = 0 - v.get_tuple()->coord.x;
    double y = 0 - v.get_tuple()->coord.y;
    double z = 0 - v.get_tuple()->coord.z;
    n.set_coordinates(x, y, z, v.get_tuple()->coord.w);
    return n;
}

/*
 Multiply the vector by a scalar
 */
Tuple Tuple::scalar(double &s, Tuple v){
    Tuple scaled;
    double x = s * v.get_tuple()->coord.x;
    double y = s * v.get_tuple()->coord.y;
    double z = s * v.get_tuple()->coord.z;
    double w = s * v.get_tuple()->coord.w;
    
    scaled.set_coordinates(x, y, z, w);
    return scaled;
}

/*
 Multiply the vector by a fraction
 */

Tuple Tuple::fraction_vector(double &f, Tuple v){
    Tuple fract_scaled;
    double x = f * v.get_tuple()->coord.x;
    double y = f * v.get_tuple()->coord.y;
    double z = f * v.get_tuple()->coord.z;
    double w = f * v.get_tuple()->coord.w;
    
    fract_scaled.set_coordinates(x, y, z, w);
    return fract_scaled;

}
/*
 The magnitude of the vector is the length of the vector
 */
double Tuple::magnitude(Tuple a){
    return sqrt(pow(a.get_tuple()->coord.x, 2) + pow(a.get_tuple()->coord.y, 2) + pow(a.get_tuple()->coord.z, 2));
}

/*
 Normalization of the vector converting a vector to a unit vector
 */
Tuple Tuple::normalize(Tuple a){
    Tuple n;
    double m = magnitude(a);
    double x = a.get_tuple()->coord.x / m;
    double y = a.get_tuple()->coord.y / m;
    double z = a.get_tuple()->coord.z / m;
    double w = a.get_tuple()->coord.w / m;
    n.set_coordinates(x, y, z, w);
    return n;
}

/*
 Dot product returns a scalar which gives information regarding the relationship
 between the two vectors
 */
double Tuple::dot_product(Tuple a, Tuple b){
    return (a.get_tuple()->coord.x * b.get_tuple()->coord.x + a.get_tuple()->coord.y * b.get_tuple()->coord.y + a.get_tuple()->coord.z * b.get_tuple()->coord.z + a.get_tuple()->coord.w + b.get_tuple()->coord.w);
}
