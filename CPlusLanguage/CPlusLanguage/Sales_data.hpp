//
//  Sales_data.hpp
//  CPlusLanguage
//
//  Created by LinghaoPu on 16/9/2.
//  Copyright © 2016年 pulinghao. All rights reserved.
//

#ifndef Sales_data_hpp
#define Sales_data_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#endif /* Sales_data_hpp */


using namespace std;
struct Sales_data{
    string isbn() const{ return bookNo;};
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};