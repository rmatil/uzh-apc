//
//  combineops_t.h
//  apc-ex-04-4
//
//  Created by Raphael Matile on 31.10.13.
//  Copyright (c) 2013 Raphael Matile. All rights reserved.
//

#ifndef __apc_ex_04_4__combineops_t__
#define __apc_ex_04_4__combineops_t__

#include <iostream>

/*
 * Mit der Klasse combineops_t kann man auf einer variable zuerst
 * zwei verschiedene unäre Funktionen ausgeführt werden, und
 * danach mit dem ergebnis dieser beiden unären Funktionen
 * eine binäre operation ausgeführt werden.
 */

template<typename BinOp, typename Op1, typename Op2>
class combineops_t: public std::unary_function<typename Op1::argument_type, typename BinOp::result_type> {
protected:
	BinOp o;
	Op1 o1;
	Op2 o2;
public:
	combineops_t(BinOp binop, Op1 op1, Op2 op2) :
	o(binop), o1(op1), o2(op2) {
	}
	
	typename BinOp::result_type operator()(const typename Op1::argument_type &x) {
		return o(o1(x), o2(x));
	}
};

#endif /* defined(__apc_ex_04_4__combineops_t__) */
