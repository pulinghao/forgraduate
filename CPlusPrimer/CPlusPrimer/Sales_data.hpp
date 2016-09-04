//
//  Sales_data.hpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/3.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//

#ifndef Sales_data_hpp
#define Sales_data_hpp

#include <stdio.h>
#include <string>
#include <sstream>


#endif /* Sales_data_hpp */


//using namespace std;
//class Sales_data {
//    
//    friend Sales_data add(const Sales_data&, const Sales_data&);
//public:
//    Sales_data() = default;
//    
//    Sales_data(const string &s):bookNo(s){}
//    
//    Sales_data(const string &s, unsigned n, double p):bookNo(s),units_sold(n),revenue(p*n){}
//    
//    Sales_data(istream &);
//    
//    string isbn() const { return bookNo;};
//    
//    Sales_data &combine(const Sales_data&);
//    
//private:
//    double avg_price() const;
//    
//    string bookNo;
//    unsigned units_sold = 0;
//    double revenue = 0.0;
//};
//
//Sales_data add(const Sales_data&,const Sales_data&);
//
//ostream &print(ostream&,const Sales_data&);
//
//istream &read(istream&, const Sales_data&);