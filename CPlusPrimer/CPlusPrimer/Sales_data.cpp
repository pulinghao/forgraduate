//
//  Sales_data.cpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/3.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//

//#include "Sales_data.hpp"
//
//
//Sales_data::Sales_data(istream &is)
//{
//    read(is,*this);
//}
//
//
//istream &read(istream &is, Sales_data &item)
//{
//    double price;
//    is >> item.bookNo >> item.units_sold >> price;
//    item.revenue = price * item.units_sold;
//    return is;
//}
//
//ostream &print(ostream &os, const Sales_data &item)
//{
//    os << item.isbn()<< " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
//    return os;
//}