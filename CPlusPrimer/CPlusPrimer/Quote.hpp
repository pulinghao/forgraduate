//
//  Quote.hpp
//  CPlusPrimer
//
//  Created by 浦灵昊 on 16/9/4.
//  Copyright © 2016年 浦灵昊. All rights reserved.
//

#ifndef Quote_hpp
#define Quote_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#endif /* Quote_hpp */

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price):bookNo(book),price(sales_price){};
    
    string isbn() const;
    virtual double net_price(size_t n) const { return n * price;}
    
    virtual ~Quote() = default;
private:
    string bookNo;
    
protected:
    double price = 0.0;
};



class Disc_quote:public Quote
{
public:
    Disc_quote() = default;
    
    Disc_quote(const string& book, double price, size_t qty, double disc):Quote(book,price),quantity(qty),discount(disc){};
    
    double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote:public Disc_quote
{
public:
    Bulk_quote() = default;
//    Bulk_quote(const string&, double , size_t,double);
    Bulk_quote(const string& book, double price, size_t qty, double disc):Disc_quote(book,price,qty,disc){};
    double net_price(size_t n) const override;
    
private:
    size_t min_qty = 0;
    double discount = 0.0;
};



double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty) {
        return  cnt * (1 - discount) * price; //price是基类成员
    } else {
        return cnt * price;
    }
}


double print_total(ostream &os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
//    os << "ISBN" << item.isbn() << "#sold :" << n << "total due:" <<ret <<endl;
    return ret;
}