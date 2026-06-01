#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
using namespace std;
#define MAXOP 250
#define MAXVAL  100
#define NUMBER '0'
class formula
{
public:
	formula(void);
	~formula(void);
protected:
	double val[MAXOP];
	int sp;

private:
	void push( double );
	double pop( void );
    bool cmpPRI( unsigned char a, unsigned char b);
	void E2Postfix(string expr, stack<string> &RExpr);
	double run_result( stack<string> rExper );
	int getop(string s);

	//stack<string> rExpr;
public:
	void clean_stack();
    double return_run_data(string temp);
};
